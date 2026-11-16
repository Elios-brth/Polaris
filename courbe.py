import numpy as np
import matplotlib.pyplot as plt


nom=['soleil','mercure','venus','terre','mars','jupiter','saturne','uranus','neptune','pluton']

i=0

distance = np.zeros((10,5000))

E,p,L = np.loadtxt('energies_10.txt',delimiter=',',unpack=True)

temps = np.loadtxt('temps_10.txt',unpack=True)


j=0
with open('distance_10.txt','r') as fichier:
    for ligne in fichier:
        
        distance[i,j]=ligne
        i+=1
        if i == 10:
            i = 0
            j+=1
            


fig = plt.figure()
ax = plt.axes(projection='3d')
plt.show
for j in range (0,10):
    
    x,y,z=np.loadtxt(nom[j]+'_10.txt',delimiter = ',',unpack=True)
    ax.plot3D(x,y,z)
    #ax.view_init(elev=90,azim=115,roll=0)
    
    r = distance[j,:]
    plt.figure(5)
    plt.plot(temps,r,label = nom[j])
    plt.title("distance au soleil")
    r= []
    plt.legend()
plt.figure(2)
plt.plot(temps,E)
plt.title("energie")
plt.figure(3)
plt.plot(temps,p)
plt.title("impulsion")
plt.figure(4)  
plt.plot(temps,L)
plt.title("moment cinétique")