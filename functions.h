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
void addText(char []);

// 2 ==> Display contents of the file in the console
void displayContent(char []);

// 3 ==> Remove/Truncate contents of the file
void emptyFile(char []);

// 4-5 ==> Encrypt Or Decrypt contents of the file
void encryptORdecrypt(char [], int);

// 6 ==> Merges another file to the existing file
void mergeFile(char []);

// 7 ==> Counts number of words in the file
void wordCount(char []);

// 8 ==> Counts number of characters in the file
void charCount(char []);

// 9 ==> Counts number of lines in the file
void lineCount(char []);

// 10 ==> Search for a word in the file
void wordSearch(char []);

// 11 ==> count number of existence a specific word in the file
void wordFrequency(char []);

// 12 ==> Convert every character in the file to upper case
void toUpper(char []);

// 13 ==> Convert every character in the file to lower case
void toLower(char []);

// 14 ==> Convert first character of each word to upper case
void firstCaps(char []);

// 15 ==> Save file contents to a new or current file
void save();

#endif