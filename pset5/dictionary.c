/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "dictionary.h"

unsigned int dictSize = 0;
static const unsigned int tablesize = 65536;
     
     typedef struct node{
         
         char word[LENGTH + 1];
         struct node* next;
         
     }node;
node* HashTable [tablesize] = {NULL};

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    char temp[LENGTH + 1];
    int length = strlen(word);
    for(int i = 0; i < length; i++){
        temp[i] = tolower(word[i]);
        
    }
    
    temp[length] = '\0';
    
    int index = Hash(temp);
    
    
    
    if(HashTable[index] == NULL){
        return false;
    }
    
    node* head = HashTable[index];
    
    while(head != NULL){
        
        if((strcmp(temp, head->word)) == 0){
            
            return true;
            
            }
            
         head = head->next;   
         
        }
        
    return false;
}
    
    
    
    


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    FILE *inputfile = fopen(dictionary, "r");
        if(inputfile == NULL){
            printf("Couldn't open file!\n");
            return false;
        }
    char word[LENGTH + 1];
    
    while (fscanf(inputfile, "%s\n", word)!= EOF){
        dictSize++;
        
        node* new_node = malloc(sizeof(node));
        
        strcpy(new_node->word, word);
        
        int index = Hash(word);
        
        if(HashTable[index] == NULL){
            HashTable[index] = new_node;
            new_node->next = NULL;
      
        }
        else{
            new_node->next = HashTable[index];
            HashTable[index] = new_node;
            
        }
        
        
  
    }
    fclose(inputfile);
        
        return true;
    
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    if(dictSize > 0){
        return dictSize;
    }
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    
    int index = 0;
    
    while(index < tablesize){
        
        if (HashTable[index] == NULL){
            index++;
        }
        else{
            while(HashTable[index] != NULL){
                node* cursor = HashTable[index];
                HashTable[index] = cursor->next;
                free(cursor);
                
            }
            index++;
            
        }
        return true;
    }
    
    
    
    
    
    return false;
}

int Hash(const char* word){
    
     int hash = 0;
     int n;
    
    for (int i = 0; word[i] != '\0'; i++)
    {
       
        if(isalpha(word[i])){
            n = word [i] - 'a' + 1;
        }
        
        else{
            n = 27;
        }
        hash = ((hash << 3) + n) % tablesize;
    }
    return hash;    
}




