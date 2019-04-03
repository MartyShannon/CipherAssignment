#include <stdio.h>
#include <string.h>

void encoder(char str[], int i, int r);

int main()
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
   
   
   // THIS CODE WORKS, trying to make into a function
   while(string[index] != 0)
   {
       string[index] += rotation;   //This moves all letters up by the designated rotation amount.

       //if statement says: if string number greater than 90 it will minus 26 ie. send the letters at the end of the alphabet to the start.
       if(string[index] > 90)
       {
           string[index] -= 26;
       }
       
       //for(string[index] == 35; string[index] -= rotation;)      Causes segmentation error, but would be a neater way of laying out then a if statement.
       
       
       //if statement says: if string number equal to 32 it undoes the rotation ie. so spaces stay as spaces.
       if(string[index] == 32 + rotation)
       {
           string[index] -= rotation;
       }  
       index++; //increments value to perform loop for string
    }

   //encoder(char string[], int index, int rotation);  
   printf("%s\n", string);
  
  
   return 0;
}

/* Attempt at turning working code into a function
void encoder(char str[], int i, int r)   
{
    while(str[i] != 0)
   {
       str[i] += r;

       if(str[i] > 90)
       {
           str[i] -= 26;
       }
       
       //for(string[index] == 35; string[index] -= rotation;)      Causes segmentation error, but would be a neater way of laying out then a if statement.
       
       if(str[i] == 32 + r)
       {
           str[i] -= r;
       }
    }

    return char str[];
}*/