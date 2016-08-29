#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int getKey(int key);


int main(int argc, string argv[]) {

    // Check to see if user gave us correct number of parameters
    if (argc == 2) {

        // Check to see if user gave us correct characters for password
        string password = argv[1];
        for (int i = 0; i < strlen(password); i++) {
            if ( !isalpha(password[i]) ) {
                printf("Sorry! You must only include letters in the password. Try again\n");
                return 1;
            }
        }

        // Ask user what message they'd like to encrpt
        printf("Enter a message to encrypt: ");
        string message = GetString();
        printf("Here it is encrypted:       ");


        // Initialize variables
        int lengthOfPassword = strlen(password);
        int passwordCounter = 0;
        int lengthOfMessage = strlen(message);
        int lowerCaseAscii = 97;
        int upperCaseAscii = 65;


        // Iterate through letters
        for (int i = 0; i < lengthOfMessage; i++) {

                // Reset password counter if the index reaches the end
                if (passwordCounter == lengthOfPassword) {
                    passwordCounter = 0;
                }

                // Check if it's a lowercase letter
                if ( islower(message[i]) ) {

                    int x = message[i] - lowerCaseAscii;
                    int y = getKey(password[passwordCounter]);

                    printf("%c", (((x + y) % 26) + lowerCaseAscii));
                    passwordCounter++;


                // Check if it's an uppercase letter
                } else if ( isupper(message[i]) ) {

                    int x = message[i] - upperCaseAscii;
                    int y = getKey(password[passwordCounter]);

                    printf("%c", (((x + y) % 26) + upperCaseAscii));
                    passwordCounter++;


                // Otherwise it's a symbol; Just print it as-is
                } else {
                    printf("%c", message[i])  ;
                }

        }

        printf("\n");
        return 0;


    // If the user didn't give us correct parameters, notify them
    } else {
        printf("\nOops! You were supposed to give us a single secret key\n");
        printf("====================================\n");
        printf("EXAMPLE: ./program secretpassword\n");
        printf("====================================\n");
        printf("Try running the program again!\n\n");
        return 1;

    }
}


int getKey(int key) {
    if ( islower(key) ) {
        return  key - 97;
    } else {
        return key - 65;
    }

}
