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
            
            printf("Enter message, all in caps: ");
            scanf("%s", &string[0]);
            char roatationEncoder(char *string);
            printf("%s\n", &string[0]);
            
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

char rotationEncoder(char string[])
{
    int rotation = 10;
    int index = 0;

    while(string[index] != 0)
    {
        string[index] += rotation; //This moves all letters up by the designated rotation amount.

        if(string[index] > 90) //if string number greater than 90 it will minus 26 ie. send the letters at the end of the alphabet to the start.
        {
            string[index] -= 26;
        }
       
        if(string[index] == 32 + rotation) //if statement says: if string number equal to 32 it undoes the rotation ie. so spaces stay as spaces.
        {
            string[index] -= rotation;
        }  
        index++; //increments value to perform loop for string
     }
     //printf("%s\n", string);
     return;
}