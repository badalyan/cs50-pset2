#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]) {


    // Make sure the user gave us a key
    if (argc == 2) {

        // Convert the number (key) from String to Int
        int salt = atoi(argv[1]);

        // Set base points for when new characters overflow
        int upperCaseAsciiForA = 65;
        int lowerCaseAsciiForA = 97;


        // Ask user what message they'd like to encrypt
        printf("Enter a message to encrypt: ");
        string text = GetString();
        printf("Here it is encrypted:       ");


        // Iterate through each character and encrypt by specified parameter
        for (int i = 0, lengthOfString = strlen(text); i < lengthOfString; i++) {

            // For lowercase letters
            if ( islower(text[i]) ) {
                printf("%c", (((text[i] - lowerCaseAsciiForA) + salt) % 26) + lowerCaseAsciiForA );

            // For uppercase letters
            } else if ( isupper(text[i]) ) {
               printf("%c", (((text[i] - upperCaseAsciiForA) + salt) % 26) + upperCaseAsciiForA );

            // For everything else that isn't a character (e.g., spaces, #, !, etc.)
            } else {
                printf("%c", text[i]);
            }
        }

        printf("\n");
        return 0;

    // If they didn't give us any parameters, notify them
    } else if (argc == 1) {
        printf("You forgot to enter a secret number!\n");
        printf("Please re-run the program, but this type add a number. E.g., ./program 420 \n");
        return 1;

    // If they entered too many parameters, just quit program
    } else {
        printf("You entered too many parameters!\n");
        printf("Please re-run the program, but this type add a number. E.g., ./program 420 \n");
        return 1;
    }
}
