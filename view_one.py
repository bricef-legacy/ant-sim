#! /usr/bin/env python
import xml.etree.ElementTree as ET
import matplotlib.pyplot as plt
import numpy as np
import sys

tree = ET.parse(sys.argv[1])

agents =  tree.findall("xagent")

ANTx = []
ANTy = []

PHEx = []
PHEy = []

NESx = []
NESy = []

FOOx = []
FOOy = []

for agent in agents:
    type = agent.find("name").text
    if type == "Pheromone":
        X = agent.find("pheromoneX")
        Y = agent.find("pheromoneY")
        PHEx.append(float(X.text))
        PHEy.append(float(Y.text))
    elif type == "Nest":
        X = agent.find("nestX")
        Y = agent.find("nestY")
        NESx.append(float(X.text))
        NESy.append(float(Y.text))
    elif type == "Food":
        X = agent.find("foodX")
        Y = agent.find("foodY")
        FOOx.append(float(X.text))
        FOOy.append(float(Y.text))
       
    elif type == "Ant":
        X = agent.find("antX")
        Y = agent.find("antY")
        ANTx.append(float(X.text))
        ANTy.append(float(Y.text))

alphas=np.random.rand(len(PHEx))

for x,y,alpha in zip(PHEx,PHEy,alphas):
    plt.scatter(x, y, color="green", alpha=alpha, edgecolors='none')
    #this seems like a really ugly way of doing it, 
    #adding a scatter for every point, but I cannot 
    #find a way to set the alphas of a serie.
    
plt.plot(NESx, NESy, "go", label="nest")
plt.plot(FOOx, FOOy, "bo", label="food")
plt.plot(ANTx, ANTy, "ro", label="ants")
#plt.legend(loc="lower right")
plt.savefig(sys.argv[2])


