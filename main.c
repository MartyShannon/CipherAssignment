#include <stdio.h>
#include <string.h>

char rotationEncoder(char x, int r);
char rotationDecoder(char x, int r);

int main()
{
    int f = 0;
    
    printf("Type number for desired function:\n   1 -- Rotation Cypher Encryption\n   2 -- Rotation Cypher Decrytion\n   3 -- Substitution Cypher Enryption\n   4 -- Substitution Cypher Decyption\n   5 -- Decryption of Rotation Cypher (Rotation unknown)\n   6 -- Decrytion of a Substitution Cypher (substitution unkown)\n");
    scanf("%d", &f);
    
    switch(f) 
    {
        case 1:
/*______________________________________________________________________________________________________________________________________________________________
Case 1 -- Encypting Phrase with Roatation Cyper, In this case a while loop has been created that reads a single character at a time from file code.txt and using function,
rotationEncoder, prints the text file to stdout encrypted.
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input;
            int rotation = 0;
            
            input = fopen("code.txt", "r");     //Opening file code.txt to read, this has the text to be coded inside
            
            printf("Enter Rotation Amount:");
            scanf("%d", &rotation);     //Amount in which the alphabet is rotated by
            
            while(feof(input) == 0)     //Loop runs, until the file pointer has reached the end of the file
            {
                char c;
                fscanf(input, "%c", &c);        //scans file for single character the file pointer is on
                
                c = rotationEncoder(c, rotation);       //calls function rotationEncoder, passing values of c and rotation
                
                printf("%c", c);      //prints singular encoded character
            }
            break;
        }

        case 2:
/*______________________________________________________________________________________________________________________________________________________________
Case 1 -- Decypting Phrase with Rotation Cypher, In this case a while loop has been created that reads a single character at a time from file code.txt and using function,
rotationDecoder, prints the text file to stdout decrypted.
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input;
            int rotation = 0;
            
            input = fopen("code.txt", "r");     //Opening file code.txt to read, this has the text to be decoded inside
            
            printf("Enter Rotation Amount:");
            scanf("%d", &rotation);     //Amount in which the alphabet is rotated by
            
            while(feof(input) == 0)     //Loop runs, until the file pointer has reached the end of the file
            {
                char c;
                fscanf(input, "%c", &c);        //scans file for single character the file pointer is on
                
                c = rotationDecoder(c, rotation);     //calls function rotationEncoder, passing values of c and rotation
                
                printf("%c", c);      //prints singular encoded character
            }

            break;
        }

        case 3:
            break;
        default:
            printf("You only have options 1 to 6\n");

    }
    
    return 0;
}
/*______________________________________________________________________________________________________________________________________________________________
Function rotationEncoder adds the rotation amount to the single character currently being read by the while loop in main c:26.
It keeps spaces, fullstops, commas and the like the same as before being encypted.

The inputs is the character being encoded (c) and the rotation amount (rotation); The return value is char x, which is what c has bevome after rotation.
________________________________________________________________________________________________________________________________________________________________*/
char rotationEncoder(char x, int r)
{
    
        if(x > 31 && x < 65)     //keeps characters before capital alphabet the same, by subtracting the rotation prior to adding it
    {
        x -= r;
    }  
    
    x += r;     //This moves all letters up by the designated rotation amount (kind of funny that i could do this for letters greater than 26 and it would do the same as the for statement above c:87)

    if(x > 90)  //if string number greater than 90 it will subtract 26 ie. send the letters at the end of the alphabet to the start.
    {
        x -= 26;
    }
     return x;
}


/*____________________________________________________________________________________________________________________________________________________________
Function rotationDecoder subtracts the rotation amount to the single character currently being read by the while loop in main c:26.
It keeps spaces, fullstops, commas and the like the same as before being encypted.

The inputs is the character being encoded (c) and the rotation amount (rotation); The return value is char x, which is what c has bevome after rotation.
______________________________________________________________________________________________________________________________________________________________*/
char rotationDecoder(char x, int r)
{
    
        if(x > 31 && x < 65)    //keeps characters before capital alphabet the same, by subtracting the rotation and 26 to account for if statement below c:118
    {
        x = x + r - 26;
    }  
    
    x -= r; //This moves all letters down by the designated rotation amount.

    if(x < 65) //if string number less than 65 it will add 26 ie. send the letters at the start of the alphabet to the end.
    {
        x += 26;
    }
     return x;
}
/*______________________________________________________________________________________________________________________________________________________________

________________________________________________________________________________________________________________________________________________________________*/