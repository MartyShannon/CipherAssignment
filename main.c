#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char rotationEncoder(char x, int r);
char rotationDecoder(char x, int r);
void menu2(int g);

int main()
{
    int f = 0;
    
    printf("Type number for desired function:\n   1 -- Rotation Cipher Encryption\n   2 -- Rotation Cipher Decrytion\n   3 -- Substitution Cipher Enryption\n   4 -- Substitution Cipher Decyption\n   5 -- Decryption of Rotation Cipher (Rotation unknown)\n   6 -- Exit Program\n");
    scanf("%d", &f);
    
    switch(f) 
    {
        case 1:
/*______________________________________________________________________________________________________________________________________________________________
Case 1 -- Encypting Phrase with Roatation Cipher, In this case a while loop has been created that reads a single character at a time from file code.txt and using function,
rotationEncoder, prints the text file to stdout encrypted.
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input, *output;
            int rotation = 0;
            
            input = fopen("phrase.txt", "r");     //Opening file code.txt to read, this has the text to be coded inside
            if (input == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            output = fopen("code.txt", "w");
            if (output == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            printf("Enter Rotation Amount:");
            scanf("%d", &rotation);     //Amount in which the alphabet is rotated by
            printf("\nEncryption: ");
            
            while(feof(input) == 0)     //Loop runs, until the file pointer has reached the end of the file
            {
                char c;
                c = fgetc(input); // reading the file        //scans file for single character the file pointer is on
                    
                c = rotationEncoder(c, rotation);       //calls function rotationEncoder, passing values of c and rotation
                
                printf("%c", c);
                putc(c, output);
            }
            
            fclose(input);
            fclose(output);
            
            int g = 0;
            printf("\n\n____________________________________\nWhat would you like to do now?\n     1 -- back to menu\n     2 -- Exit Program\n");
            scanf("%d", &g);
            menu2(g);

        }

        case 2:
/*______________________________________________________________________________________________________________________________________________________________
Case 2 -- Decypting Phrase with Rotation Cipher, In this case a while loop has been created that reads a single character at a time from file code.txt and using function,
rotationDecoder, prints the text file to stdout decrypted.
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input;
            FILE *output;
            int rotation = 0;
            
            input = fopen("phrase.txt", "r");     //Opening file code.txt to read, this has the text to be coded inside
            if (input == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            output = fopen("code.txt", "w");
            if (output == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            printf("Enter Rotation Amount:");
            scanf("%d", &rotation);     //Amount in which the alphabet is rotated by
            
            while(feof(input) == 0)     //Loop runs, until the file pointer has reached the end of the file
            {
                char c;
                fscanf(input, "%c", &c);        //scans file for single character the file pointer is on
                
                c = rotationDecoder(c, rotation);     //calls function rotationEncoder, passing values of c and rotation
                
                printf("%c", c);      //prints singular encoded character
                putc(c, output);
            }
            
            fclose(input);
            fclose(output);
            
            int g = 0;
            printf("\n\n____________________________________\nWhat would you like to do now?\n     1 -- back to menu\n     2 -- Exit Program\n");
            scanf("%d", &g);
            menu2(g);
        }

        case 3:
/*______________________________________________________________________________________________________________________________________________________________
Case 3 -- Encyrpting Phrase with Substitution Cipher, 
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input, *output;
            FILE *key;
            char c, s;
            char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
            
            key = fopen("key.txt", "r");
            if (key == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }

            input = fopen("phrase.txt", "r");     //Opening file code.txt to read, this has the text to be decoded inside
            if (input == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            output = fopen("code.txt", "w");
            if (output == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            while (1)
            {
                c = fgetc(input); // reading the file
                for(int i=0; i < 26; i++)
                {
                    fseek(key, i, SEEK_SET);
                    s = fgetc(key);
                    
                    if(c == alpha[i])
                    {
                        c = s;
                        break;
                    }

                }    
                if(c == EOF)
                    break;
                    
                printf("%c", c);
                putc(c, output);
            }
            
            fclose(input);
            fclose(key);
            fclose(output);
            
            int g = 0;
            printf("\n\n____________________________________\nWhat would you like to do now?\n     1 -- back to menu\n     2 -- Exit Program\n");
            scanf("%d", &g);
            menu2(g);
        }


        case 4:
/*______________________________________________________________________________________________________________________________________________________________
Case 4 -- Encyrpting Phrase with Substitution Cipher, cmmc
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input, *output;
            FILE *key;
            char c, s;
            char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
            
            key = fopen("key.txt", "r");
            if (key == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            input = fopen("phrase.txt", "r");     //Opening file code.txt to read, this has the text to be decoded inside
            if (input == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            output = fopen("code.txt", "w");
            if (output == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            while (1)
            {
                c = fgetc(input); // reading the file
                for(int i=0; i < 26; i++)
                {
                    fseek(key, i, SEEK_SET);
                    s = fgetc(key);
                    
                    if(c == s)
                    {
                        c = alpha[i];
                        break;
                    }

                }
                
                if(c == EOF)
                break;
                
                printf("%c", c);
                putc(c, output);
            }
            printf("\n\n");
            fclose(key);
            fclose(input);
            fclose(output);
        
            int g = 0;
            printf("\n\n____________________________________\nWhat would you like to do now?\n     1 -- back to menu\n     2 -- Exit Program\n");
            scanf("%d", &g);
            menu2(g);
        }

        case 5:
/*______________________________________________________________________________________________________________________________________________________________
Case 5 -- Decripting Phrase with Substitution Cipher
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input, *output;
            int rotation = 0;
            
            input = fopen("phrase.txt", "r");     //Opening file code.txt to read, this has the text to be decoded inside
            if (input == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            output = fopen("code.txt", "w");
            if (output == NULL)
            {
                printf("Error opening file!");    //Program prints error message and closes if file is not found            
                exit(0);
            }
            
            for(rotation = 0; rotation < 26; rotation++)
            {
                printf("%d:  ", rotation);
                while(feof(input) == 0)     //Loop runs, until the file pointer has reached the end of the file
                {
                    char c;
                    fscanf(input, "%c", &c);        //scans file for single character the file pointer is on
                    
                    c = rotationDecoder(c, rotation);     //calls function rotationEncoder, passing values of c and rotation

                    printf("%c", c);      //prints singular encoded character
                }
                printf("\n");
                rewind(input);
            }

            fclose(input);
            
            int g = 0;
            printf("\n\n____________________________________\nWhat would you like to do now?\n     1 -- back to menu\n     2 -- Exit Program\n");
            scanf("%d", &g);
            menu2(g);
        }


        
        case 6:
        {
            exit(0);
        }


        default:
        {
            printf("You only have options 1 to 6\n");
            system("./a.out");

        }
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


/*____________________________________________________________________________________________________________________________________________________________
Function 
______________________________________________________________________________________________________________________________________________________________*/
void menu2(int g)
{
    switch(g)
            {
                case 1:
                    system("clear");
                    system("./a.out");
                case 2:
                {
                    system("clear");
                    exit(0);
                }

            }

} 

/*______________________________________________________________________________________________________________________________________________________________

________________________________________________________________________________________________________________________________________________________________*/
/*char substitutionEncoder(FILE *sub1, char c, char *alpha[])
{
    for(int i=0; i < 26; i++)
    {
        fseek(sub1, i, SEEK_SET);
        char s1 = fgetc(sub1);
                    
        if(c == alpha[i])
        {
            c = s1;
            break;
        }
    }
    return c;
}*/


/*______________________________________________________________________________________________________________________________________________________________

__________________________________________________________________________________________________________________________________________________*/