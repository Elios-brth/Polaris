#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dvector.h"

dvector f(double t,dvector s,double G,std::vector<dvector> R,double M[]);
std::vector<dvector> runge_kutta(double h,double t,double G,std::vector<dvector> R,double M[]);
std::vector<dvector> cond_init();
int main(){
    //conditions initiales
    std::vector<dvector> R(10);
    R = cond_init();

    double t=0;
    double G=2.959122e-4;
    double M[10]={1,1.6e-7,2.4476e-6,3.0032e-6,3.2268e-7,9.5425e-4,2.8572e-4,4.3643e-5,5.1486e-5,6.6060e-9};
    double n = 50000;
    double tfin=100000;
    double h=tfin/n;

    FILE *position;
    position = fopen("positions.txt","w");
    for (t=0;t<tfin;t+=h){
        R=runge_kutta(h,t,G,R,M);
        for (int i=0;i<10;i+=1){
        printf("%lf,%lf,%lf\n", R[i][0],R[i][2],R[i][4]);
        fprintf(position, "%lf,%lf,%lf\n", R[i][0],R[i][2],R[i][4]);
        }
    }
    fclose(position);

}

dvector f(double t,dvector s,double G,std::vector<dvector> R,double M[]){
    double r;
    double somme_x=0;
    double somme_y=0;
    double somme_z=0;
    for(int i=0;i<10;i+=1){
        r=sqrt(pow((R[i][0]-s[0]),2)+pow((R[i][2]-s[2]),2)+pow((R[i][4]-s[4]),2));
        if (r!=0){
        somme_x+=M[i]*(R[i][0]-s[0])/pow(r,3);
        somme_y+=M[i]*(R[i][2]-s[2])/pow(r,3);
        somme_z+=M[i]*(R[i][4]-s[4])/pow(r,3);
    }
}
    dvector s2(s);
    s2[0]=s[1];
    s2[1]=G*somme_x;
    s2[2]=s[3];
    s2[3]=G*somme_y;
    s2[4]=s[5];
    s2[5]=G*somme_z;
    return s2;
}


std::vector<dvector> runge_kutta(double h,double t,double G,std::vector<dvector> R,double M[]){
    std::vector<dvector> k1(R),k2(R),k3(R),k4(R);
    std::vector<dvector> R2(R),R3(R),R4(R),Rfin(R);
    for (int i=0;i<10;i+=1){
        k1[i]=h*f(t,R[i],G,R,M);}
    for (int i=0;i<10;i+=1){
        R2[i]=R[i]+k1[i]/2;}
    for (int i=0;i<10;i+=1){
        k2[i]=h*f(t+h/2,R2[i],G,R2,M);}
    for (int i=0;i<10;i+=1){
        R3[i]=R[i]+k2[i]/2;}
    for (int i=0;i<10;i+=1){
        k3[i]=h*f(t+h/2,R3[i],G,R3,M);}
    for (int i=0;i<10;i+=1){
        R4[i]=R[i]+k3[i];}
    for (int i=0;i<10;i+=1){
        k4[i]=h*f(t+h,R4[i],G,R4,M);}
    for (int i=0;i<10;i+=1){
        R[i]=R[i]+(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6;}
    return R;
}

std::vector<dvector> cond_init(){
    dvector Soleil(6);
    Soleil[0]=-1.6132380e-03; //x0
    Soleil[2]=-2.3674938e-03; //y0
    Soleil[4]=-3.4999903e-05; //z0
    Soleil[1]=6.0453208e-06; //vx0
    Soleil[3]=-1.8980631e-06; //vy0
    Soleil[5]=-1.3060634e-07; //vz0
    dvector Mercure(6);
    Mercure[0]=3.4942761e-01; //x0
    Mercure[2]=1.0619088e-02; //y0
    Mercure[4]=-3.1182970e-02; //z0
    Mercure[1]=-6.4674481e-03; //vx0
    Mercure[3]=2.9372684e-02; //vy0
    Mercure[5]=2.9939160e-03; //vz0
    dvector Venus(6);
    Venus[0]=-5.7685710e-01; //x0
    Venus[2]=4.2639983e-01; //y0
    Venus[4]=3.9039256e-02; //z0
    Venus[1]=-1.2159929e-02; //vx0
    Venus[3]=-1.6321487e-02; //vy0
    Venus[5]=4.7839154e-04; //vz0
    dvector Terre(6);
    Terre[0]=6.8900355e-1; //x0
    Terre[2]=7.0799513e-1; //y0
    Terre[4]=-5.4762805e-05; //z0
    Terre[1]=-1.2606830e-2; //vx0
    Terre[3]=1.1932472e-2; //vy0
    Terre[5]=-5.3326343e-07; //vz0
    dvector Mars(6);
    Mars[0]=4.3534005e-01; //x0
    Mars[2]=-1.3548686e+00; //y0
    Mars[4]=-3.9100527e-02; //z0
    Mars[1]=1.3851438e-02; //vx0
    Mars[3]=5.5002850e-03; //vy0
    Mars[5]=-2.2479471e-04; //vz0
    dvector Jupiter(6);
    Jupiter[0]=1.8147606e+00; //x0
    Jupiter[2]=4.7059241e+00; //y0
    Jupiter[4]=-6.0234633e-02; //z0
    Jupiter[1]=-7.1329432e-03; //vx0
    Jupiter[3]=3.0767709e-03; //vy0
    Jupiter[5]=1.4683761e-04; //vz0
    dvector Saturne(6);
    Saturne[0]=-8.2319838e+00; //x0
    Saturne[2]=-5.2651142e+00; //y0
    Saturne[4]=4.1915711e-01; //z0
    Saturne[1]=2.7027945e-03; //vx0
    Saturne[3]=-4.7129500e-03; //vy0
    Saturne[5]=-2.5483556e-05; //vz0
    dvector Uranus(6);
    Uranus[0]=1.9916762e+01; //x0
    Uranus[2]=2.3700466e+00; //y0
    Uranus[4]=-2.4922728e-01; //z0
    Uranus[1]=-4.9354675e-04; //vx0
    Uranus[3]=3.7222065e-03; //vy0
    Uranus[5]=2.0227673e-05; //vz0
    dvector Neptune(6);
    Neptune[0]=2.6481558e+01; //x0
    Neptune[2]=-1.4076556e+01; //y0
    Neptune[4]=-3.2040642e-01; //z0
    Neptune[1]=1.4527105e-03; //vx0
    Neptune[3]=2.7901455e-03; //vy0
    Neptune[5]=-9.1342324e-05; //vz0
    dvector Pluton(6);
    Pluton[0]=4.9371124e+0; //x0
    Pluton[2]=-3.1890424e+1; //y0
    Pluton[4]=1.9843679e+00; //z0
    Pluton[1]=3.1711953e-3; //vx0
    Pluton[3]=-1.4100225e-4; //vy0
    Pluton[5]=-9.0807325e-04; //vz0
    std::vector<dvector> CI(10, dvector(6));
    CI[0]=Soleil;
    CI[1]=Mercure;
    CI[2]=Venus;
    CI[3]=Terre;
    CI[4]=Mars;
    CI[5]=Jupiter;
    CI[6]=Saturne;
    CI[7]=Uranus;
    CI[8]=Neptune;
    CI[9]=Pluton;
    return CI;
}