#include <stdlib.h>
#include <stdio.h>
#include <math.h>



double equation_r(double, double, double, double);

double equation_phi(double, double, double);

int main(){
	
    double h = 0.1; // Pas d'itération
    double a = 0; // t_initial
    double b = 20; // t_intégration
    double n = (b-a)/h; // nbre de points
    
    double v_x0 = 3.65, v_y0 = 4, x0 = 0.003, y0 = 0.0052; // Conditions Initiales cartésiennes
    
    double r = sqrt(pow(x0,2)+pow(y0,2)), phi = 0;
    double v_r = v_x0*cos(phi) + v_y0*sin(phi), v_phi = -v_x0*sin(phi)+v_y0*cos(phi); // Conditions initiales cylindriques
    double G =1 , M = 1 ; // Constantes
    
    double k1r, k2r, k3r, k4r, l1r, l2r, l3r, l4r;
    double k1phi, k2phi, k3phi, k4phi, l1phi, l2phi, l3phi, l4phi;
    h = (b-a)/(n-1);

    for (int i=0;i<n; i=i+1){ // Boucle d'itération Runge Kutta
        k1r = h*v_r;
        l1r = h*equation_r(v_phi, r, G, M);
        
        k2r = h*(v_r+0.5*l1r);
        l2r = h*equation_r(v_phi, r+0.5*k1r, G, M);
        
        k3r = h*(v_r+0.5*l2r);
        l3r = h*equation_r(v_phi, r+0.5*k2r, G, M);
        
        k4r = h*(v_r+l3r);
        l4r = h*equation_r(v_phi, r+k3r, G, M);
        
        r = r + 1/6 *(k1r+2*k2r+2*k3r+k4r);
        v_r = v_r + 1/6 *(l1r+2*l2r+2*l3r+l4r);
        
        k1phi = h*v_phi/r;
        l1phi = h*equation_phi(v_phi, r, v_r);
        
        k2phi = h*(v_phi+0.5*l1phi)/r;
        l2phi = h*equation_phi(v_phi+0.5*l1phi, r, v_r);
        
        k3phi = h*(v_phi+0.5*l2phi)/r;
        l3phi = h*equation_phi(v_phi+0.5*l2phi, r, v_r);
        
        k4phi = h*(v_phi+l3phi)/r;
        l4phi = h*equation_phi(v_phi+l3phi, r, v_r);
        
        phi = phi + 1/6 *(k1phi+2*k2phi+2*k3phi+k4phi);
        v_phi = v_phi + 1/6 *(l1phi+2*l2phi+2*l3phi+l4phi);
        
    }
    
}

double equation_r(double v_phi, double r, double G, double M){
    return (pow(v_phi,2)/r)-G*M/pow(r,2);
}

double equation_phi(double v_phi, double r, double v_r){
    return -2*v_phi*v_r/r;
}




