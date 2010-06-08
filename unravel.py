#! /usr/bin/env python
import random
import frames
import Image
import ImageDraw

ANT_STEPSIZE = 1
ANT_FOODLOSS_TICK = 0.02
ANT_PHERO_AMOUNT = 0.2
ANT_FOOD_MIN = 5.0
DIRECTIONS = ['N', 'NE', 'E', 'SE', 'S', 'SW', 'W', 'NW']
ANT_BITESIZE = 50
ANT_SMELL_DISTANCE = 2
PHEROMONE_DECAY_RATE = {"A":0.02, "B":0.05}
PHEROMONE_CHOICE_THRESHOLD = {"A":0.4, "B":0.4}

IDLE = 1
WALK = 2
RETURN = 3
DEAD = 4

def flatten(iterables):
    return [elem for iterable in iterables for elem in iterable]

def distance_between(agent1, agent2):
    return sqrt(pow(agent1.x - agent2.x,2) + pow(agent1.y - agent2.y,2) )

class Ant:
    def __init__(self, environment, nest):
        self.state = IDLE
        self.cell = nest.cell
        self.food = random.uniform(0,10)
        self.env = environment
        self.nest = nest
    
    def tick(self):
        
        self.food -= ANT_FOODLOSS_TICK
        
        if self.food < 0:
            self.state = DEAD
        
        if self.state == DEAD:
            pass
        elif self.state == IDLE:
            if self.food < ANT_FOOD_MIN:
                self.state = WALK
        elif self.state == WALK:
            self.cell = self._pick_new_cell()
            self.cell.put_pheromone("A", ANT_PHERO_AMOUNT)
            
            if self.cell.food:
                if self.cell.food.amount > 0:
                    self.food += cell.food.take_morcel(ANT_BITESIZE)
                
        elif self.state == RETURN:
            self.cell = self._pick_new_cell()
            self.cell.put_pheromone("B", ANT_PHERO_AMOUNT)
            if self.nest.cell is self.cell: #we are at nest 
                self.state=IDLE
    
    def _pick_new_cell(self):
        neighbours = self.env.get_locals(self)
        chosen = self.cell
        for row in neighbours:
            for cell in row:
                if (cell.pheromone["A"] > PHEROMONE_CHOICE_THRESHOLD) and (cell.pheromone["A"] > chosen.pheromone["A"]):
                    chosen = cell
        
        if chosen is self.cell:
            chosen = random.choice(flatten(neighbours))
        
        return chosen
    
    def get_xml(self):
        return """<xagent>
    <name>Ant</name>
    <antX>%d</antX>
    <antY>%d</antY>
    <foodLevel>%f</foodLevel>
    <state>%d</state>
  </xagent>"""%(self.cell.x, self.cell.y, self.food, self.state)

class Nest:
    def __init__(self):
        self.cell=None
    def tick(self):
        pass
    def get_xml(self):
        return """<xagent>
    <name>Nest</name>
    <nestX>%d</nestX>
    <nestY>%d</nestY>
    <nestRadius>10</nestRadius>
  </xagent>"""%(self.cell.x, self.cell.y)

        
class Cell:
    def __init__(self, x, y):
        self.pheromone = {"A":0, "B":0}
        self.x=x
        self.y=y
        self.food=None
    def put_pheromone(self, type, amount):
        self.pheromone[type] = amount + self.pheromone[type]
        if self.pheromone[type] > 1:
            self.pheromone[type] = 1
    def get_pheromone(self, type):
        return self.pheromone[type]
    def tick(self):
        for key in self.pheromone.keys():
            new_val = self.pheromone[key] - PHEROMONE_DECAY_RATE[key]
            if new_val > 0:
                self.pheromone[key] = new_val
            else:
                self.pheromone[key] = 0

class Food:
    def __init__(self, amount, concentration):
        self.amount=amount
        self.cell = None
        self.conc = concentration
    def tick(self):
        pass
    def take_morcel(self, amount):
        if self.food > amount:
            self.food -= amount
            return amount
        else:
            amount = self.food
            self.food = 0
            return amount
    def get_xml(self):
        return """<xagent>
    <name>Food</name>
    <size>%f</size>
    <foodX>%d</foodX>
    <foodY>%d</foodY>
    <concentration>%f</concentration>
  </xagent>"""%(self.amount, self.cell.x, self.cell.y, self.conc)

class Environment:
    def __init__(self, size=300):
        self.tick_counter=0
        self.cells=[ [Cell(x,y) for x in range(0,size) ] for y in range(0,size)]
        self.agents=[]
    
    def remove(self, part):
        self.agents.remove(part)
    
    def get_locals(self, agent, radius=1):
        locals = [[self.cells[y][x] for x in range(agent.cell.x-radius, agent.cell.x+radius+1)] for y in range(agent.cell.y-radius, agent.cell.y+radius+1)]
        return locals
    
    def get_cell(self, x,y):
        return self.cells[y][x]
    
    def do_tick(self):
        self.tick_counter+=1
        for row in self.cells:
            for cell in row:
                cell.tick()
        for agent in self.agents:
            agent.tick()
    
    def add(self, agent, x, y):
        self.agents.append(agent)
        agent.cell = self.cells[y][x]
        if agent is Food:
            self.cells[y][x].food = agent
        
    def get_xml(self):
        xmlo = []
        xmlo.append("<states>\n<itno>%d</itno>"%(self.tick_counter))
        for agent in self.agents:
            xmlo.append(agent.get_xml())
        xmlo.append("<xagent><name>Environment</name>")
        for row in self.cells:
            xmlo.append("<row>")
            for cell in row:
                xmlo.append("""<cell><posx>%d</posx><posy>%d</posy><pheromones>
                <pheromoneA>%f</pheromoneA>
                <pheromoneB>%f</pheromoneB>
                </pheromones></cell>"""%(cell.x, cell.y, cell.pheromone["A"], cell.pheromone["B"]))
            xmlo.append("</row>")
            
        xmlo.append("</xagent>")
        xmlo.append("</states>")
        return "\n".join(xmlo)
        
    def pic(self):
        im = Image.new("RGB", (300,300), (0,0,0))
        pix=im.load()
        #draw=ImageDraw.Draw(im)
        
        for row in self.cells:
            for cell in row:
                if cell.pheromone["A"]>0:
                    pix[cell.x, cell.y]= ( int(255*cell.pheromone["A"]), 0, 0 )
        
        for agent in self.agents:
            if isinstance(agent, Ant):
                pix[agent.cell.x,agent.cell.y]=(0,255,0)
            elif isinstance(agent, Nest):
                pix[agent.cell.x,agent.cell.y]=(125,125,125)
            elif isinstance(agent, Food):
                pix[agent.cell.x,agent.cell.y]=(0,0,255)
        
        return im
        #return frames.xml2img(self.get_xml())
    
def run(ticks=102):
    print "Running for %d"%ticks
    print "creating environment"
    env=Environment()
    
    print "creating nestcell"
    nestcell = env.get_cell(150,150)
    nest_a = Nest()
    env.add(nest_a, 150,150)
    
    print "adding ants"
    for i in range(0, 50):
        env.add(Ant(env, nest=nest_a), 150, 150)
    
    print "adding food"
    env.add(Food(10000, 1.0), 50, 150)
    env.add(Food(10000, 0.1), 250, 150)
    
    print "tick: 0"
    print "saving pic"
    env.pic().save("0.png")
    
    for i in range(1, 100):
        print "tick: %d"%i
        env.do_tick()
    
    for i in range(100, ticks):
        print "tick: "+str(i)
        env.do_tick()
        print "saving pic"
        env.pic().save("%d.png"%(i))

if __name__=="__main__":
    run()
    
