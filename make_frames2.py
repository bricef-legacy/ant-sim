#! /usr/bin/env python
import xml.etree.ElementTree as ET
import Image
import ImageDraw
import numpy as np
import sys, re, os

files = os.listdir(sys.argv[1])
files.sort()
regex = re.compile("[0-9]+\.xml")

for afile in files:
    if  regex.match(afile): #IE: we have xml, and numeric name
        
        im = Image.new("RGB", (560,560), (0,0,0))
        pix=im.load()
        draw=ImageDraw.Draw(im)
                
        print("== Processing "+afile+" -> "+afile[:-4]+".png")
        fullpath=os.path.join(sys.argv[1], afile)
        tree=ET.parse(fullpath)
        agents=tree.findall("xagent")
        
        #reinit the arrays
        ANTx = [] #ants
        ANTy = []
        PHEx = [] #pheromones
        PHEy = []
        PHEl = []
        NESx = [] #nest
        NESy = []
        FOOx = [] #food
        FOOy = []

        for agent in agents:
            type = agent.find("name").text
            if type == "Pheromone":
                X = agent.find("pheromoneX")
                Y = agent.find("pheromoneY")
                L = agent.find("life")
                PHEx.append(int(float(X.text)))
                PHEy.append(int(float(Y.text)))
                PHEl.append(float(L.text))
            elif type == "Nest":
                X = agent.find("nestX")
                Y = agent.find("nestY")
                NESx.append(int(float(X.text)))
                NESy.append(int(float(Y.text)))
            elif type == "Food":
                X = agent.find("foodX")
                Y = agent.find("foodY")
                FOOx.append(int(float(X.text)))
                FOOy.append(int(float(Y.text)))
            elif type == "Ant":
                X = agent.find("antX")
                Y = agent.find("antY")
                ANTx.append(int(float(X.text)))
                ANTy.append(int(float(Y.text)))


        #PHEROMONE
        if PHEl:
            max_life = np.max(PHEl)
        
        PHEa=[]        
        for life in PHEl:
            if life > 0:
                PHEa.append(life/max_life)
            else:
                PHEa.append(0)
        
        #NES
        for x,y in zip(NESx,NESy):
            s=5
            draw.ellipse([((x*2)-s,(y*2)-s),((x*2)+s,(y*2)+s)] ,(255,255,255))
        
        #PHE
        for x,y,alpha in zip(PHEx,PHEy,PHEa):
            
            s=1
            draw.ellipse([((x*2)-s,(y*2)-s),((x*2)+s,(y*2)+s)] ,(int(alpha*255),0,0,))
        
        #ANT
        for x,y in zip(ANTx,ANTy):
            s=2
            draw.ellipse([((x*2)-s,(y*2)-s),((x*2)+s,(y*2)+s)] ,(0,255,0))
        
        #FOO
        for x,y in zip(FOOx,FOOy):
            s=4
            draw.ellipse([((x*2)-s,(y*2)-s),((x*2)+s,(y*2)+s)] ,(0,0,255))
        
        
        im.save(os.path.join(sys.argv[2],afile[:-4]+".png"))
