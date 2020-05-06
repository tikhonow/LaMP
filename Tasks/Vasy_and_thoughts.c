#include <stdio.h>
#include <stdlib.h>
double get_t(double v, double w, double D, double T)
{
    if(v - w == 0) {
        if (D - v * T < 0.00001) {
        return D;} }

    double t = (D - w * T) / (v - w);
    if (t < 0) {
        t = 0;}

    if ((t > T) || (t * v > D)){
        return -1;}

    return (t * v);
}
double MAX (double m1, double m2){
double max;
    if (m1 > m2){
       max = m1; }
    else max = m2;
return max;
}
int main(){
    FILE *fin  = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    double v1,v2,w1,w2,D,T;
    fscanf (fin,"%lf%lf%lf%lf%lf%lf",&D,&T,&v1,&v2,&w1,&w2);

    double t1, t2, t3,d, t4;
    t1 = get_t (v1,w1,D,T);
    t2 = get_t (v1,w2,D,T);
    t3 = get_t (v2,w1,D,T);
    t4 = get_t (v2,w2,D,T);

    d = MAX(MAX(t1, t2), MAX(t3, t4));

    fprintf(fout,"%lf",d);
}
