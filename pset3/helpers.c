/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include <math.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
        int min = 0;
        int max = n;
        int i = 0;
        int avg;
        
        
        while(max >= min){
            avg = floor((min + max)/2);
            if(values[avg] == value) { return true;}
            else if(values[avg] > value) {max = avg -1;}
            else {min = avg + 1;}
            i++;
            
        }
  
  
    
    return false;
    
}
    
    


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int k = 0; k < n - 1; k++){
        int swap;
        
            for(int i = 0; i < n - k - 1; i++ ){
                if (values[i] > values[i + 1]){
                    swap = values[i];
                    values[i] = values[i + 1];
                    values[i + 1] = swap;
                }
            }
        
        
    
    }
    /*for (int i = 0; i < n; i++){
        printf("\nElem:%i\n", values[i]);
    }*/
    
    return;
}