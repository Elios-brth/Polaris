#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dvector.h"

dvector f(double t,dvector s,double G);
dvector euler(dvector s,double h,double t,double G);

int main(){
    dvector s(4);
    s[0]=6.8900355e-1;
    s[2]=7.0799513e-1;
    s[1]=-1.2606830e-2;
    s[3]=1.1932472e-2;
    double t=0;
    double G=2.959122e-4;
    double h =0.05;
    FILE *fich;
    fich = fopen("positions.txt","w");
    for (t=0;t<366;t+=h){
        s=euler(s,h,t,G);
        printf("%lf,%lf\n", s[0],s[2]);
        fprintf(fich, "%lf,%lf\n", s[0],s[2]);
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


dvector euler(dvector s,double h,double t,double G){
    dvector k(s);
    k=h*f(t,s,G);
    return s+k;
}
