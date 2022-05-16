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

// 6 ==> Merges another file to the existing file
void mergeFile(char filename[]);

// 7 ==> Counts number of words in the file
void wordCount(char filename[]);

// 8 ==> Counts number of characters in the file
void charCount(char filename[]);

// 9 ==> Counts number of lines in the file
void lineCount(char filename[]);

// 10 ==> Search for a word in the file
void wordSearch(char filename[]);

// 11 ==> count number of existence a specific word in the file
void wordFrequency(char file[]);

// 12 ==> Convert every character in the file to upper case
void toUpper(char file[]);

// 13 ==> Convert every character in the file to lower case
void toLower(char file[]);

// 14 ==> Convert first character of each word to upper case
void firstCaps(char file[]);

// 15 ==> Save file contents to a new or current file
void save();

#endif