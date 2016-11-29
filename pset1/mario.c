#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int n;
   
   do
   {
    printf("height:");
     n = GetInt();
   }
        while(n < 0 || n > 23);
        
        if(n > 0 && n < 24){
        for(int i = 0; i < n; i++){
            for(int k = n - 1 ; k > i; k--){
                printf(" ");
            }
            for(int j = 0 ; j < i + 2; j++){
                printf("#");
            }
            printf("\n");}
        }
}