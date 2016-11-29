# include <stdio.h>
# include <cs50.h>
# include <math.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc != 2){
       printf("It looks like you forgot to add something!");
       return 1;
    }
    
    int k = atoi(argv[1]);
    string poz = "abcdefghijklmnopqrstuvwxyz";
    string POZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string text = GetString();

        for(int i = 0; i < strlen(text); i++){
            
            if(isalpha(text[i]) && islower(text[i])){
                 for(int j = 0; j < strlen(poz); j++){
                      if (text[i] == poz[j])
                        { printf ("%c",poz[(j + k) % 26]);}
                        
                    }
            }
            
           if(isalpha(text[i]) && isupper(text[i])){
                for(int j = 0; j < strlen(POZ); j++){
                     if (text[i] == POZ[j])
                       { printf ("%c",POZ[(j + k) % 26]);}
                         
                    }
             }
           if(!(isalpha(text[i]))) 
            { printf("%c",text[i]);}
                 
}    
    printf("\n");   
    return 0;
}
