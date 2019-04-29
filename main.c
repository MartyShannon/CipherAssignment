/*______________________________________________________________________________________________________________________________________________________________
This is a program aimed at the encryption and decryption of rotation and substitution ciphers. The program opens to a menu where number inputs into the terminal
is used to select a function. once the function is complete is brings up the option to return to the menu or to exit the program, except for cse 6 which must
restart due to the mass of datat printed to the screen. 
All inputs and outputs can be found in files, the text you wish to encode or decode must go in the phrase.txt file and the output will be in the code.txt file
the key for substition evidently goes in the key.txt file. With the exetion of, the common letter in decrypting a rotation cipher (case 5) must be hard 
coded to the value of comChar on line 281.

__________________________________________________________________________________________________________________________________________________*/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char rotationEncoder(char x, int r);
char rotationDecoder(char x, int r);
int letterFrequency(void);
void menu2(int g);

int main()
{
    int f = 0;
    
    printf("Type number for desired function:\n   1 -- Rotation Cipher Encryption\n   2 -- Rotation Cipher Decrytion\n   3 -- Substitution Cipher Enryption\n   4 -- Substitution Cipher Decyption\n   5 -- Decryption of Rotation Cipher (Most common letter)\n   6 -- Decryption of Rotation Cipher (Brute Force)\n   7 -- Exit Program\n");
    scanf("%d", &f);
    
    switch(f) 
    {
        case 1:
/*______________________________________________________________________________________________________________________________________________________________
Case 1 -- Encypting Phrase with Roatation Cipher, In this case a while loop has been created that reads a single character at a time from file phrase.txt and using function,
rotationEncoder, prints the text file to stdout and file code.txt.
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input, *output;   
            int rotation = 0;
            
            input = fopen("phrase.txt", "r");   //Opening file phrase.txt to read, this has the text to be coded inside
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
Case 2 -- Decypting Phrase with Rotation Cipher, In this case a while loop has been created that reads a single character at a time from file phrase.txt and using function,
rotationDecoder, prints the text file to stdout and code.txt file decrypted.
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
                c = fgetc(input); // reading the file        //scans file for single character the file pointer is on
                
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
Case 3 -- Encyrpting Phrase with Substitution Cipher, within this case the alphabet has been declared as an array, the files opened then a while loop which reads
the input file, it will pull the first character from the file and store it in c. Next, the code sequentially finds the placement (i) of the letter along
the alphabet and uses that to locate the corresponding letter in the key.txt file. Once this is complete it assigns the corresponduing letter and prints it to both
stdout and code.txt. Repeating the loop until the end of file.
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input, *output;
            FILE *key;
            char c, s;      //initilizing characters for reading from the input file and the key file
            char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; //initialize an array as the alphabet, to be used as a place holder in correspondance with the given key
            
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
                c = fgetc(input);   // reading the file
                for(int i=0; i < 26; i++)   //loop runs until i reaches 25, increasing by 1 each loop 
                {
                    fseek(key, i, SEEK_SET);    //fseekmis used to move the cursor reading the file a certain distance from the start of the file(SEEK_SET), the offset amount is i int the key.txt file
                    s = fgetc(key);     //stores the corressponding letter from key.txt as a char in s
                    
                    if(c == alpha[i])       //if the first letter is equal to the current value of the i section of the array it will assign the corresponing key value to c
                    {
                        c = s;
                        break; //once the if statement is fullfilled the loop is broken
                    }

                }    
                if(c == EOF) //once the end of the file is reached the while statement is broken
                    break;
                    
                printf("%c", c); //and the coded value of c printed to terminal and code.txt below
                putc(c, output);
            }       //the while statement will now start these loops again for the second letter of phrase.txt
            
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
Case 4 -- Decyrpting Phrase with Substitution Cipher, within this case the alphabet has been declared as an array, the files opened then a while loop which reads
the input file, it will pull the first character from the file and store it in c. Next, the code sequentially finds the placement (i) of the letter along
the key in file key.txt and uses that to locate the corresponding letter in the alphabet stored in the array "alpha". Once this is complete it assigns the 
corresponduing letter and prints it to both stdout and code.txt. Repeating the loop until the end of file.
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
                    
                    if(c == s)      //all of this is similar to the encoding functiont the only changes occur in this if statement which says if the letter in phrase.txt is equal to the the i'th letter in key.txt it will assign the i'th letter of the alphabet
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
Case 5 -- Decripting Phrase Rotation Cipher, hardcoded in this decryption is a common letter, to do this the letterfrequency function is used which returns the
most common letter in the input file. This is then turned into the rotation amount by subtracting the suspected most common letter, hardcoded into the code and
the most common letter, an if...else... statement is used to keep the roation between 0-25 and depending on which is used the rotation needs to move clockwise or
anticlockwise ie. use the encode or decoder function. To produce the correct decipher. The results are then printed to stdout and code.txt
________________________________________________________________________________________________________________________________________________________________*/
        {
            FILE *input, *output;
            int rotation = 0;
            
            input = fopen("phrase.txt", "r");
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

            char comChar = 'I';     //this is the hardcoded letter which may be common in the phrase, noting the most common letter in the english language is E followed by T and A
            
            int maxChar = letterFrequency();        //this is assigning the most used letter in phrase.txt to the integer maxChar, still a number 0-25
            if(comChar - (maxChar + 'A') >= 0)      //this if..else statement keeps the rotation amount within 0-25, by ensuring the solution of a common character subtracted by the most used character(ASCII) in the file is positive.
            {
                rotation = comChar - (maxChar + 'A'); // assigns the solution to the common char
                printf("%d", rotation);
                printf("Assuming the most common letter in the phrase is %c, the recommended solution is:\n", comChar);
                
                while(feof(input) == 0)     //Loop runs, until the file pointer has reached the end of the file
                    {
                        char c = fgetc(input); // reading the file           
                        c = rotationEncoder(c, rotation);     //calls function rotationEncoder, passing values of c and rotation
                        printf("%c", c);      //prints singular encoded character
                        putc(c, output);
                    }
            }

            else
            {
                rotation = (maxChar + 'A') - comChar;
                printf("Assuming the most common letter in the phrase is %c, the recommended solution is:\n", comChar);
                
                while(feof(input) == 0)     //Loop runs, until the file pointer has reached the end of the file
                    {
                        char c = fgetc(input); // reading the file           
                        c = rotationDecoder(c, rotation);     //calls function rotationEncoder, passing values of c and rotation
                        printf("%c", c);      //prints singular encoded character
                        putc(c, output);
                    }
            }
            fclose(input);
            fclose(output);
            
            int g = 0;
            printf("\n\n____________________________________\nWhat would you like to do now?\n     1 -- back to menu\n     2 -- Exit Program\n");
            scanf("%d", &g);
            menu2(g);
        }

/*______________________________________________________________________________________________________________________________________________________________
Case 6 -- Brute force Deciphering a rotation cipher, this closely follows the standard deciphering used in the 2nd case, but the contents of case 2 have been put
in a for... statement which runs the code for rotations 0 - 25 rather then giving th eperson the option to choose the rotation. The results are printed to the 
code.txt file and stdout.
________________________________________________________________________________________________________________________________________________________________*/
        case 6:
        {
            FILE *input, *output;
            input = fopen("phrase.txt", "r");
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
            for(int rotation = 0; rotation < 26; rotation++)
            {
                rewind(input); //this moves the cursor back to the start of the file so that the phrase can be read again with a different rotation
                printf("rotatio of %d: ", rotation);
                while(feof(input) == 0) //Loop runs, until the file pointer has reached the end of the file
                {
                    char c;
                    c = fgetc(input); // reading the file 
                    c = rotationDecoder(c, rotation); //calls function rotationEncoder, passing values of c and rotation
                        
                    printf("%c", c); //prints singular encoded character
                    putc(c, output);
                }
                printf("\n");
                fputs("\n", output);
            }
            fclose(input);
            fclose(output);
            break;      
            /*int g = 0;
            printf("\n\n");
            printf("____________________________________\nWhat would you like to do now?\n     1 -- back to menu\n     2 -- Exit Program\n");
            scanf("%d", &g);
            menu2(g);*/
        
        }


        
        case 7:
        {
            exit(0); //simply exits the program
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

/*______________________________________________________________________________________________________________________________________________________________
Function letterCounter, counts the letters in a file to find the most frequent letter, it does this by reading each character in the input file and taking the ascii
number of the character and subtracting 65 from it to put the capital letters in a range of 0-25. Once this has been done an array is used to keep count of each letters
use in the file, by incrementing the array[0-25] depending on the corresponding letter. Once complete a for statement is used to go through the array and find the 
highest stored number the "i" value of this becomes the most common letter represented as a number of 0-25. This number is returned to the main funtion. No inputs are
required as it is taken from file phrase.txt.
________________________________________________________________________________________________________________________________________________________________*/
int letterFrequency(void)
{
    FILE *input;
    input = fopen("phrase.txt", "r");     //Opening file code.txt to read, this has the text to be decoded inside
    if (input == NULL)
    {
        printf("Error opening file!");    //Program prints error message and closes if file is not found            
        exit(0);
    }

    int frequency[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // initializing all counters to 0 for each lette in the alphabet
    while(1)
        {
            int ch = fgetc(input); //gets the character from input file
                
            if (ch == EOF) 
                break;
            else if (ch >= 'A' && ch <= 'Z')   //if the file character is bettween A-Z on the ASCII table
                frequency[ch - 'A']++;  //it will add 1 to the part of the array corresponding to its spot 0-25 in the alphabet
        }
        
    int maxCount = 0;
    int maxChar = 0;
    
    for (int i = 0; i < 26; ++i)
    {
        if (frequency[i] > maxCount)    //occurs only if the value stored in frequency[i] is greater then the max count intitially 0
        {
            maxCount = frequency[i];    //if it is it reassigns the value of threquency[i] to the max count
            maxChar = i;        //and assigns the placement of the letter in the alphabet as an int in maxChar
        }
    }
    fclose(input);
    return maxChar;     //returns the 0-25 of the most used letter to the main function to be used to calculate the roation
}
/*____________________________________________________________________________________________________________________________________________________________
menu function is just a way for the user to get back to the main menu rather then restarting the program each time, it involves a switch statment that clears
the terminal and either exits or runs the program again. taking integer input selected by the user.
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