#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    
    // Ask user for their name
    printf("What is your name? ");
    string name = GetString();
    
    // Iterate through ASCII characters and display the initials of their name
    for (int i = 0, n = strlen(name); i < n; i++) {
        if (name[i - 1] == 0 || name[i - 1] == 32) {
          
            if (name[i] >= 97) {
                printf("%c", name[i] - 32);
            }
            else {
                printf("%c", name[i]);  
            }
          
        }
    }
   
   // Line break to make it pretty :)
   printf("\n");
    
}