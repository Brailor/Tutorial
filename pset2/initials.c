# include <stdio.h>
# include <cs50.h>
# include <math.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    
    string name = GetString();
    
    printf ("%c", toupper(name[0]) );
    for (int i = 0; i <= strlen(name); i++){
        if (name[i] ==  ' '){char myChar = toupper (name[i + 1]); printf("%c", myChar);  }
    
    }
    
    printf("\n");
    
}