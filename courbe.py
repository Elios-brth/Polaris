import numpy as np
import matplotlib.pyplot as plt


nom=['Soleil','Mercure','Venus','Terre','Mars','Jupiter','Saturne','Uranus','Neptune','Pluton']

Soleil=[]
Mercure=[]
Venus=[]
Terre=[]
Mars=[]
Jupiter=[]
Saturne=[]
Uranus=[]
Neptune=[]
Pluton=[]
i=0
positions = {planete : [] for planete in nom}
with open('positions.txt','r') as fichier:
    for ligne in fichier:
        valeurs = ligne.split(",")
        positions[nom[i]].append([float(valeurs[0]),float(valeurs[1]),float(valeurs[2])])
        i+=1
        if i == 10:
            i = 0
for j in range (0,10):
    x = [p[0] for p in positions[nom[j]]]
    y = [p[1] for p in positions[nom[j]]]
    z = [p[2] for p in positions[nom[j]]]
    x_2 = np.array(x)
    y_2 = np.array(y)
    z_2 = np.array(z)
    plt.plot(x,y,label=nom[j])
    x = []
    y = []
    z = []