#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int bottlespm = 12;
    printf("minutes:");
    
    int sminutes = GetInt();
    int bottle = sminutes * bottlespm;
    printf("bottles:%i\n", bottle);
}    
