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
    
   
   
    string key = argv[1];
    for(int i = 0; key[i]; i++){
      key[i] = tolower(key[i]);
}
    
    string poz = "abcdefghijklmnopqrstuvwxyz";
    string POZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string text = GetString();

        for(int i = 0, bad = 0; i < strlen(text); i++){
            
            if(isalpha(text[i]) && islower(text[i])){
                 for(int j = 0; j < strlen(poz); j++){
                      if (key[((bad + i) % strlen(key))] == poz[j]){
                          
                          for (int k = 0; k < strlen(poz); k++){
                              if (text[i] == poz[k]){ printf("%c", poz[(j+k) % 26]);     }
                          }
                      }
                }
                        
            }            
            
           if(isalpha(text[i]) && isupper(text[i])){
                for(int j = 0; j < strlen(POZ); j++){
                      if (key[((bad + i) % strlen(key))] == poz[j]){
                          
                          for (int k = 0; k < strlen(POZ); k++){
                              if (text[i] == POZ[k]){ printf("%c", POZ[(j+k) % 26]);     }
                          }
                      }
                }
                        
            }            
           if(!(isalpha(text[i]))) 
            { printf("%c",text[i]); bad--; }
                 
}    
    printf("\n");   
    return 0;
}
