/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{
    
    int counter = 0;
    BYTE block[512];
    FILE* cardin = fopen("card.raw", "r");
    FILE* jpgout = NULL;
    char jpgnev[7];
    
    do {
            
            if((block[0] == 0xff) && (block[1] == 0xd8) && (block[2] == 0xff) && (0xe0 <= block[3]||block[3] <= 0xef)){
                if(jpgout != NULL){
                    
                    fclose(jpgout);
                }
                
                   sprintf(jpgnev, "%03d.jpg", counter);
                   
                   jpgout = fopen(jpgnev, "w");
                   
                   counter++;
                   
                   fwrite(block, sizeof(block), 1, jpgout);
            }
                   
             else if (counter > 0){
        
            
             fwrite(block, sizeof(block), 1, jpgout); 
             }
            
        
      
        fread(block, sizeof(block), 1, cardin);
        
         
    
    } while (! (feof(cardin)));
    fclose(cardin);
    return 0;
    
}