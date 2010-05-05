#! /usr/bin/env python
import xml.etree.ElementTree as ET
import matplotlib.pyplot as plt

tree = ET.parse("0.xml")

agents =  tree.findall("xagent")

for agent in agents:
    #print agent.tag
    agent.find("name").text == "Pheromone":
        X = agent.find("pheromoneX")
        print X.text 

X=[0.1,0.5,0.5]
Y=[3,0.9,0.5]

plt.plot(X,Y,"ro")
plt.show()

