#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dvector.h"

dvector f(double t,dvector Y,double G,double r);
dvector runge_kutta(dvector y,double h,double t,double r,double G);

int main(){
    dvector rho(2),phi(2);
    double x0,y0,vx0,vy0;
    x0=6.8900355e-1;
    y0=7.0799513e-1;
    vx0=-1.2606830e-2;
    vy0=1.1932472e-2;
    rho[0]=sqrt(x0*x0+y0*y0);
    phi[0]=atan2(y0,x0);
    rho[1]=cos(phi[0])*vx0+sin(phi[0])*vy0;
    phi[1]=(-sin(phi[0])*vx0+cos(phi[0])*vy0);
    double t=0;
    double r,G;
    G=2.959122e-4;
    FILE *fich;
    fich = fopen("positions.txt","w");
    for (t=0;t<400;t+=0.01){
        dvector y0=y;
        dvector x0=x;
        r=sqrt(x0[0]*x0[0]+y0[0]*y0[0]);
        y=runge_kutta(y0,0.01,t,r,G);
        x=runge_kutta(x0,0.01,t,r,G);
    fprintf(fich, "%lf %lf\n", x[0],y[0]);
    fclose(fich);
}
}

dvector f(double t,dvector Y,double G,double r){
    int n = Y.size();
    dvector Y2(n);
    for(int i=0;i<n-1;i++){
        Y2[i]=Y[i+1];
    }
    Y2[n-1]=-G*Y[0]/(r*r*r);
    return Y2;
}

dvector runge_kutta(dvector y,double h,double t,double r,double G){
    dvector k1(y),k2(y),k3(y),k4(y);
    k1=h*f(t,y,G,r);
    k2=h*f(t+h/2,y+k1/2,G,r);
    k3=h*f(t+h/2,y+k2/2,G,r);
    k4=h*f(t+h,y+k3,G,r);
    return y+(k1+2*k2+2*k3+k4)/6;
}