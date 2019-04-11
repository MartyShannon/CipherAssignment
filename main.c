#include <stdio.h>
#include <string.h>

char rotationEncoder(char string[]);

int main()
{
    int f = 0;
    
    printf("Type number for desired function:\n   1 -- Rotation Cypher Encryption\n   2 -- Rotation Cypher Decrytion\n   3 -- Substitution Cypher Enryption\n   4 -- Substitution Cypher Decyption\n   5 -- Decryption of Rotation Cypher (Rotation unknown)\n   6 -- Decrytion of a Substitution Cypher (substitution unkown)\n");
    scanf("%d", &f);
    
    switch(f) 
    {
        case 1:
        {
            char string[100];
            int rotation = 0;
            int index = 0;
            
            printf("Text you would like to encode, All in caps and no spaces:");
            gets(string);
            //scanf("%s", &string[0]);     //%s scans for a string variable, not sure about white space though and how to avoid
            //printf("%s\n", &string[0]);        prints original input for testing
            
            printf("Now enter a value you would like the cipher to rotate the alphabet by (Number 1-25):");
            scanf("%d", &rotation);
            
            
            while(string[index] != 0)
            {
                string[index] += rotation;   //This moves all letters up by the designated rotation amount.
            
                   if(string[index] > 90)   //if string number greater than 90 it will minus 26 ie. send the letters at the end of the alphabet to the start.
                   {
                       string[index] -= 26;
                   }
            
                   //for(string[index] == 35; string[index] -= rotation;)      Causes segmentation error, but would be a neater way of laying out then a if statement.
            

                   if(string[index] == 32 + rotation)   //if string number equal to 32 it undoes the rotation ie. so spaces stay as spaces.
                   {
                       string[index] -= rotation;
                   }  
                   
                   index++; //moves to the next letter in the array, to create loop.
                }
 
            printf("%s\n", string);                       
            break;
        }

        case 2: 
            break;
        case 3: 
            break;
        default:
            printf("You only have options 1 to 6\n");

    }
    
    return 0;
}