#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float a;
    do
    {
        printf("How much change is owed?\n");
        a = GetFloat();
    }
    while (a < 0);
    float x  = 100 * a;
    int n = round(x);  
    
        int d1 = 0;
    while(n >= 25){
        n = n - 25;
        d1++;
    }
        int d2 = 0;
    while(n < 25 && n >= 10){
        n = n - 10;
        d2++;
    }
        
        int d3 = 0;
    while(n < 10 && n >= 5){
            n = n - 5;
            d3++;
        }
        
        int d4 = 0;
    while(n >= 1){
        n = n - 1;
        d4++;
    }    
        printf("%i\n", d1 + d2 + d3 + d4);
        
}