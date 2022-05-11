// These are all the functions of the program from which
// the user chooses one or more to apply to the file

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "functions.h"

using namespace std;

// Takes the initial file from the user to work on
void getFile(){
    // Get the file to work on as input from the user
    while(true){
        cout << "Please enter the name of text file to work on: ";
        cin.getline(fileName, 101, '\n');
        // Check for the correct format of the input file
        regex validFormat("[a-zA-Z]+(-|_|[0-9])*[a-zA-Z]+(-|_|[0-9])*(.txt)");
        if(!regex_match(fileName, validFormat)){
            cerr << "File format NOT supproted! Enter only \".txt\" files.\n";
            continue;
        }
        else
            break;
    }
    // Open the file to check if it exists or not
    // and if not create a new file with the new name
    ifstream file(fileName, ios::in);
    if(file.fail()){
        cout << "This is a new file. I created it for you!\n";
        ofstream newFile(fileName, ios::out);
        newFile.close();
    }
    else
        cout << "\"" << fileName << "\" already exists!\n";
    file.close();
}

// Displays the menu to the user to choose what to do with the file
void start(){
    cout << "The program can do the following actions:\n"
            "1- Add new text to the end of the file.\n"
            "2- Display the content of the file.\n"
            "3- Empty the file.\n4- Encrypt the file content.\n"
            "5- Decrypt the file content\n6- Merge another file.\n"
            "7- Count the number of words in the file.\n"
            "8- Count the number of charachters in the file.\n"
            "9- Count the number of lines in the file.\n"
            "10- Search for a word in the file.\n"
            "11- Count the number of times a word exists in the file.\n"
            "12- Turn the file content to upper case.\n"
            "13- Turn the file content to lower case.\n"
            "14- Turn file content into 1st caps.\n"
            "15- Save the file.\n16- Exit.\n";
    string choice;
    while(choice != "16"){
        cout << "Choose one of the above options: ";
        cin.clear();
        getline(cin, choice);
        if(choice == "1"){
            addText(fileName);
        }
        else if(choice == "2"){
            displayContent(fileName);
        }
        else if(choice == "3"){
            emptyFile(fileName);
        }
        else if(choice == "4"){
            encryptORdecrypt(fileName, 1); // encrypt
        }
        else if(choice == "5"){
            encryptORdecrypt(fileName, -1); // decrypt
        }
        else if(choice == "6"){
            ; // some function
        }
        else if(choice == "7"){
            ; // some function
        }
        else if(choice == "8"){
            ; // some function
        }
        else if(choice == "9"){
            ; // some function
        }
        else if(choice == "10"){
            ; // some function
        }
        else if(choice == "11"){
            ; // some function
        }
        else if(choice == "12"){
            ; // some function
        }
        else if(choice == "13"){
            ; // some function
        }
        else if(choice == "14"){
            ; // some function
        }
        else if(choice == "15"){
            ; // some function
        }
        else if(choice == "16"){
            cout << "Thank You for using the Text Editor program!\n";
            break;
        }
        else{
            cerr << "INVALID INPUT! Enter only numbers from 1 to 16.\n";
            continue;
        }
    }
}

// Add more text to the file as input through console
void addText(char filename[]){
    ofstream addToFile(filename, ios::app);
    char input;
    cout << "Enter text to add and finish by (Ctrl + Z): ";
    cin.get(input);
    // Take text from user and add it to the file
    // and stop when the user enters ctrl + z (^Z)
    while(!cin.eof()){
        addToFile.put(input);
        cin.get(input);
    }
    cout << "Text added to the file successfully!\n";
}

// Display contents of the file in the console
void displayContent(char filename[]){
    cout << "\t\t---------- " << filename << " ----------\n";
    ifstream displayFile(filename, ios::in);
    if(displayFile.peek() == EOF)
        cout << "\t\t\tFile is EMPTY!\n";
    string line;
    // Output the contents of the file line by line
    while(getline(displayFile, line)){
        cout << line << endl;
    }
}

// Remove/Truncate contents of the file
void emptyFile(char filename[]){
    ofstream emptyFile(filename, ios::trunc);
    cout << "File contents removed and it is now EMPTY!\n";
}

// Encrypt Or Decrypt contents of the file
void encryptORdecrypt(char filename[], int decision){
    // Create an object to take text from
    ifstream inFile(filename, ios::in);
    char ch;
    inFile.get(ch);
    // Create a new object with the same file but with different open mode
    ofstream outFile(filename, ios::out);
    // Increment/Decrement the ASCII of each character by one
    while(!inFile.eof()){
        outFile.put(char (ch + decision));
        inFile.get(ch);
    }
    // According to the action print the suitable confirmation message
    if(decision == 1)
        cout << "File is encrypted and secured!\n";
    else
        cout << "File is decrypted!\n";
}
