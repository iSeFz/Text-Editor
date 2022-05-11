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
    }
    else
        cout << "\"" << fileName << "\" already exists!\n";
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
        cin >> choice;
        if(choice == "1"){
            ; // some function
        }
        else if(choice == "2"){
            ; // some function
        }
        else if(choice == "3"){
            ; // some function
        }
        else if(choice == "4"){
            ; // some function
        }
        else if(choice == "5"){
            ; // some function
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
