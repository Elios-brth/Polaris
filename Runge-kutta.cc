#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dvector.h"

dvector f(double t,dvector s,double G);
dvector runge_kutta(dvector s,double h,double t,double G);

int main(){
    dvector s(4);
    s[0]=6.8900355e-1;
    s[2]=7.0799513e-1;
    s[1]=-1.2606830e-2;
    s[3]=1.1932472e-2;
    double t=0;
    double G=2.959122e-4;

    FILE *fich;
    fich = fopen("positions.txt","w");
    for (t=0;t<400;t+=0.01){
        s=runge_kutta(s,0.01,t,G);
        printf("%lf,%lf\n", s[0],s[1]);
        fprintf(fich, "%lf,%lf\n", s[0],s[1]);
    }
    fclose(fich);
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
