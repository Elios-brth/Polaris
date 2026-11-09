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
    double r = 0, v = 0, E = 0, p = 0, L = 0;
    double Mt=2.4476e-6;
    FILE *position;
    FILE *energie;
    FILE *distance;
    position = fopen("positions.txt","w");
    energie = fopen("energies.txt","w");
    distance = fopen("distance.txt","w");
    for (t=0;t<400;t+=0.01){
        s=runge_kutta(s,0.01,t,G);
        printf("%lf,%lf\n", s[0],s[2]);
        fprintf(position, "%lf,%lf\n", s[0],s[2]);
        r = sqrt(s[0]*s[0]+s[2]*s[2]);
        v = sqrt(s[1]*s[1]+s[3]*s[3]);
        E=0.5*Mt*v*v-G*Mt/(r);
        p = Mt*v;
        L = r * v;
        fprintf(energie, "%lf,%lf,%lf\n", E,p,L);
        fprintf(distance, "%lf,%lf\n", r,t);
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
