<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dvector.h"

dvector f(double t,dvector s,double G);
dvector runge_kutta(dvector s,double h,double t,double G);
std::vector<dvector> cond_init();
int main(){
    //conditions initiales
    std::vector<dvector> s(9);
    s = cond_init();

    double t=0;
    double G=2.959122e-4;
    double r , v , E , p , L ;
    double Mt=3.0032e-6;
    double n = 10000;
    double T[9] = {90,230,370,700,4400,11000,31000,61000,91000};
    double tfin, h;

    FILE *position;
    FILE *energie;
    FILE *distance;
    position = fopen("2_corps.txt","w");
    energie = fopen("energies.txt","w");
    distance = fopen("distance.txt","w");
    dvector R;
    for (int i=0;i<9;i+=1){
        R = s[i];
        tfin = T[i];
        h = tfin/n;
        for (t=0;t<tfin;t+=h){
            R=runge_kutta(R,h,t,G);
            printf("%lf,%lf\n", R[0],R[2]);
            fprintf(position, "%lf,%lf\n", R[0],R[2]);
            r = sqrt(R[0]*R[0]+R[2]*R[2]);
            v = sqrt(R[1]*R[1]+R[3]*R[3]);
            E=0.5*v*v-G/r; //energie totale divisée par Mt
            p = v; //impulsion divisée par Mt
            L = R[0]*R[3]-R[2]*R[1]; //moment cinétique divisé par Mt (L/Mt = x*vy-y*vx)
            fprintf(energie, "%lf,%lf,%lf\n", E,p,L);
            fprintf(distance, "%lf,%lf\n", r,t);
        }
        fprintf(position, "\n");
    }
    fclose(position);
    fclose(energie);
    fclose(distance);
}

dvector f(double t,dvector s,double G){
    double r=sqrt(s[0]*s[0]+s[2]*s[2]);
    dvector s2(s);
    s2[0]=s[1];
    s2[1]=-G*s[0]/(r*r*r);
    s2[2]=s[3];
    s2[3]=-G*s[2]/(r*r*r);
    return s2;
}


dvector runge_kutta(dvector s,double h,double t,double G){
    dvector k1(s),k2(s),k3(s),k4(s);
    k1=h*f(t,s,G);
    k2=h*f(t+h/2,s+k1/2,G);
    k3=h*f(t+h/2,s+k2/2,G);
    k4=h*f(t+h,s+k3,G);
    return s+(k1+2*k2+2*k3+k4)/6;
}

std::vector<dvector> cond_init(){
    dvector Mercure(4);
    Mercure[0]=3.4942761e-01; //x0
    Mercure[2]=1.0619088e-02 ; //y0
    Mercure[1]=-6.4674481e-03; //vx0
    Mercure[3]= 2.9372684e-02; //vy0
    dvector Venus(4);
    Venus[0]=-5.7685710e-01; //x0
    Venus[2]=4.2639983e-01; //y0
    Venus[1]=-1.2159929e-02; //vx0
    Venus[3]=-1.6321487e-02; //vy0
    dvector Terre(4);
    Terre[0]=6.8900355e-1; //x0
    Terre[2]=7.0799513e-1; //y0
    Terre[1]=-1.2606830e-2; //vx0
    Terre[3]=1.1932472e-2; //vy0
    dvector Mars(4);
    Mars[0]=4.3534005e-01; //x0
    Mars[2]=-1.3548686e+00; //y0
    Mars[1]=1.3851438e-02; //vx0
    Mars[3]=5.5002850e-03; //vy0
    dvector Jupiter(4);
    Jupiter[0]=1.8147606e+00; //x0
    Jupiter[2]=4.7059241e+00; //y0
    Jupiter[1]=-7.1329432e-03; //vx0
    Jupiter[3]=3.0767709e-03; //vy0
    dvector Saturne(4);
    Saturne[0]=-8.2319838e+00; //x0
    Saturne[2]=-5.2651142e+00; //y0
    Saturne[1]=2.7027945e-03; //vx0
    Saturne[3]=-4.7129500e-03; //vy0
    dvector Uranus(4);
    Uranus[0]=1.9916762e+01; //x0
    Uranus[2]=2.3700466e+00; //y0
    Uranus[1]=-4.9354675e-04; //vx0
    Uranus[3]=3.7222065e-03; //vy0
    dvector Neptune(4);
    Neptune[0]=2.6481558e+01; //x0
    Neptune[2]=-1.4076556e+01; //y0
    Neptune[1]=1.4527105e-03; //vx0
    Neptune[3]=2.7901455e-03; //vy0
    dvector Pluton(4);
    Pluton[0]=4.9371124e+0; //x0
    Pluton[2]=-3.1890424e+1; //y0
    Pluton[1]=3.1711953e-3; //vx0
    Pluton[3]=-1.4100225e-4; //vy0
    std::vector<dvector> CI(9, dvector(4));
    CI[0]=Mercure;
    CI[1]=Venus;
    CI[2]=Terre;
    CI[3]=Mars;
    CI[4]=Jupiter;
    CI[5]=Saturne;
    CI[6]=Uranus;
    CI[7]=Neptune;
    CI[8]=Pluton;
    return CI;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dvector.h"

dvector f(double t,dvector s,double G);
dvector runge_kutta(dvector s,double h,double t,double G);
std::vector<dvector> cond_init();
int main(){
    //conditions initiales
    std::vector<dvector> s(9);
    s = cond_init();

    double t=0;
    double G=2.959122e-4;
    double r , v , E , p , L ;
    double Mt=3.0032e-6;
    double n = 1000;
    double T[9] = {90,230,370,700,4400,11000,31000,61000,91000};
    double tfin, h;

    FILE *position;
    FILE *energie;
    FILE *distance;
    position = fopen("positions.txt","w");
    energie = fopen("energies.txt","w");
    distance = fopen("distance.txt","w");
    dvector R;
    for (int i=0;i<9;i+=1){
        R = s[i];
        tfin = T[i];
        h = tfin/n;
        for (t=0;t<tfin;t+=h){
            R=runge_kutta(R,h,t,G);
            printf("%lf,%lf\n", R[0],R[2]);
            fprintf(position, "%lf,%lf\n", R[0],R[2]);
            r = sqrt(R[0]*R[0]+R[2]*R[2]);
            v = sqrt(R[1]*R[1]+R[3]*R[3]);
            E=0.5*v*v-G/r; //energie totale divisée par Mt
            p = v; //impulsion divisée par Mt
            L = R[0]*R[3]-R[2]*R[1]; //moment cinétique divisé par Mt (L/Mt = x*vy-y*vx)
            fprintf(energie, "%lf,%lf,%lf\n", E,p,L);
            fprintf(distance, "%lf,%lf\n", r,t);
        }
        fprintf(position, "\n");
    }
    fclose(position);
    fclose(energie);
    fclose(distance);
}

dvector f(double t,dvector s,double G){
    double r=sqrt(s[0]*s[0]+s[2]*s[2]);
    dvector s2(s);
    s2[0]=s[1];
    s2[1]=-G*s[0]/(r*r*r);
    s2[2]=s[3];
    s2[3]=-G*s[2]/(r*r*r);
    return s2;
}


dvector runge_kutta(dvector s,double h,double t,double G){
    dvector k1(s),k2(s),k3(s),k4(s);
    k1=h*f(t,s,G);
    k2=h*f(t+h/2,s+k1/2,G);
    k3=h*f(t+h/2,s+k2/2,G);
    k4=h*f(t+h,s+k3,G);
    return s+(k1+2*k2+2*k3+k4)/6;
}

std::vector<dvector> cond_init(){
    dvector Mercure(4);
    Mercure[0]=3.4942761e-01; //x0
    Mercure[2]=1.0619088e-02 ; //y0
    Mercure[1]=-6.4674481e-03; //vx0
    Mercure[3]= 2.9372684e-02; //vy0
    dvector Venus(4);
    Venus[0]=-5.7685710e-01; //x0
    Venus[2]=4.2639983e-01; //y0
    Venus[1]=-1.2159929e-02; //vx0
    Venus[3]=-1.6321487e-02; //vy0
    dvector Terre(4);
    Terre[0]=6.8900355e-1; //x0
    Terre[2]=7.0799513e-1; //y0
    Terre[1]=-1.2606830e-2; //vx0
    Terre[3]=1.1932472e-2; //vy0
    dvector Mars(4);
    Mars[0]=4.3534005e-01; //x0
    Mars[2]=-1.3548686e+00; //y0
    Mars[1]=1.3851438e-02; //vx0
    Mars[3]=5.5002850e-03; //vy0
    dvector Jupiter(4);
    Jupiter[0]=1.8147606e+00; //x0
    Jupiter[2]=4.7059241e+00; //y0
    Jupiter[1]=-7.1329432e-03; //vx0
    Jupiter[3]=3.0767709e-03; //vy0
    dvector Saturne(4);
    Saturne[0]=-8.2319838e+00; //x0
    Saturne[2]=-5.2651142e+00; //y0
    Saturne[1]=2.7027945e-03; //vx0
    Saturne[3]=-4.7129500e-03; //vy0
    dvector Uranus(4);
    Uranus[0]=1.9916762e+01; //x0
    Uranus[2]=2.3700466e+00; //y0
    Uranus[1]=-4.9354675e-04; //vx0
    Uranus[3]=3.7222065e-03; //vy0
    dvector Neptune(4);
    Neptune[0]=2.6481558e+01; //x0
    Neptune[2]=-1.4076556e+01; //y0
    Neptune[1]=1.4527105e-03; //vx0
    Neptune[3]=2.7901455e-03; //vy0
    dvector Pluton(4);
    Pluton[0]=4.9371124e+0; //x0
    Pluton[2]=-3.1890424e+1; //y0
    Pluton[1]=3.1711953e-3; //vx0
    Pluton[3]=-1.4100225e-4; //vy0
    std::vector<dvector> CI(9, dvector(4));
    CI[0]=Mercure;
    CI[1]=Venus;
    CI[2]=Terre;
    CI[3]=Mars;
    CI[4]=Jupiter;
    CI[5]=Saturne;
    CI[6]=Uranus;
    CI[7]=Neptune;
    CI[8]=Pluton;
    return CI;
}
>>>>>>> c36bd14af9e525462fdf78155a048eb60bc4b722
