/* Copyright (C) 2023 Amer Alhabsi - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 */

#include <stdio.h>
#include <math.h>

// area to the left of the standard Normal distribution
double area(double x)
{
    return 1-(erfc(x*M_SQRT1_2)/2);
}
int main()
{
    double z, delta, phi;
    int j=1;

    printf("\\begin{tabular}{l|lllllllllll}\n");
    printf("\\hline \n");
    printf(" {\\bfseries Z}& ");
    for(delta=0.00; delta<0.095; delta+=0.01){
        printf("\\bfseries%10.2f&", delta);
    }
    printf("\\\\ \\hline \n");



    for(z=0.0; z<3.99; z=z+0.1){
        printf("\\bfseries%6.2f&", z);
        for(delta=0.00; delta<0.095; delta+=0.01){
            phi = area(z+delta);
            printf("%10.5f&", phi);
        }
        if(++j == 6){
            printf("\\\\ \\hline \n");
            j=1;
        } else{
            printf("\\\\ \n");
        }

        
    }
    printf("\\end{tabular} \n");
}