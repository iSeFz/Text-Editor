#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Here we will put function prototypes

// The main file name to use across the whole program
char fileName[101];

// Takes the initial file from the user to work on
void getFile();

// Displays the menu to the user to choose what to do with the file
void start();

// 1 ==> Add more text to the file as input through console
void addText(char filename[]);

// 2 ==> Display contents of the file in the console
void displayContent(char filename[]);

// 3 ==> Remove/Truncate contents of the file
void emptyFile(char filename[]);

// 4-5 ==> Encrypt Or Decrypt contents of the file
void encryptORdecrypt(char filename[], int decision);

// 11 ==> count number of existence specific char in the file
void wordCount(char filename[],char word[]);

// 12 ==> Convert every char in the file to upper case
void toUpper(char filename[]);

// 13 ==> Convert every char in the file to lower case
void toLower(char filename[]);

// 14 ==> Convert first char char of each word to upper case
void caps(char filename[]);

#endif