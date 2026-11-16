import numpy as np
import matplotlib.pyplot as plt


nom=['mercure','venus','terre','mars','jupiter','saturne','uranus','neptune','pluton']

energie = {planete : [] for planete in nom}
distance = np.zeros((10,50000))

j=0
i=0
with open('energies.txt','r') as fichier:
    for ligne in fichier:
        valeurs = ligne.split(",")
        energie[nom[i]].append([float(valeurs[0]),float(valeurs[1]),float(valeurs[2])])
        j+=1
        if j == 50000:
            i+=1
            j=0
            
j=0
i=0
with open('distance.txt','r') as fichier:
    for ligne in fichier:
        distance[i,j]=ligne
        j+=1
        if j == 50000:
            i+=1
            j=0
            
temps = np.loadtxt('temps.txt',unpack=True)


for j in range (0,9):
    
    x,y=np.loadtxt(nom[j]+'.txt',delimiter = ',',unpack=True)
    
    plt.figure(1)
    plt.plot(x,y,label = nom[j])
    plt.title("orbite")
    x = []
    y = []
    
    E = [p[0] for p in energie[nom[j]]]
    p = [p[1] for p in energie[nom[j]]]
    L = [p[2] for p in energie[nom[j]]]
    plt.figure(2)
    plt.plot(temps,E,label = nom[j])
    plt.title("energie")
    plt.figure(3)
    plt.plot(temps,p,label = nom[j])
    plt.title("impulsion")
    plt.figure(4)
    plt.plot(temps,L,label = nom[j])
    plt.title("moment cinétique")
    E = []
    p = []
    L = []
    
    r = distance[j,:]
    plt.figure(5)
    plt.plot(temps,r,label = nom[j])
    plt.title("distance au soleil")
    r= []
    plt.legend()

