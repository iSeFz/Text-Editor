// These are all the functions of the program from which
// the user chooses one or more to apply to the file

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <regex>
#include "functions.h"

using namespace std;

// Takes the initial file from the user to work on
void getFile(){
    cout << "\n------------------------------ Input File -------------------------------\n";
    // Get the file to work on as input from the user
    while(true){
        cout << "Please enter the name of text file to work on: ";
        cin.clear();
        cin.getline(fileName, 101, '\n');
        // Check for the correct format of the input file
        regex validFormat("[\\w-]+(.txt)");
        if(!regex_match(fileName, validFormat)){
            cerr << "########## File format NOT supported! Enter only \".txt\" files ##########\n";
            continue;
        }
        else
            break;
    }
    // Open the file to check if it exists or not
    // and if not create a new file with the new name
    ifstream file(fileName, ios::in);
    if(file.fail()){
        ofstream newFile(fileName, ios::out);
        cout << "$$$$$$$$$$ \"" << fileName << "\" is a new file. I created it for you! $$$$$$$$$$\n";
        newFile.close();
    }
    else
        cout << "$$$$$$$$$$ \"" << fileName << "\" already exists! $$$$$$$$$$\n";
    file.close();
}

// Displays the menu to the user to choose what to do with the file
void start(){
    cout << "\n------------------------------ Text Editor ------------------------------\n";
    string choice;
    while(choice != "16"){
        cout << "\nThe program can do the following actions:\n"
                "1- Add new text to the end of the file.\n"
                "2- Display the content of the file.\n"
                "3- Empty the file.\n4- Encrypt the file content.\n"
                "5- Decrypt the file content\n6- Merge another file.\n"
                "7- Count the number of words in the file.\n"
                "8- Count the number of characters in the file.\n"
                "9- Count the number of lines in the file.\n"
                "10- Search for a word in the file.\n"
                "11- Count the number of times a word exists in the file.\n"
                "12- Turn the file content to upper case.\n"
                "13- Turn the file content to lower case.\n"
                "14- Turn file content into first caps.\n"
                "15- Save the file.\n16- Exit.\n";
        cout << "Choose one of the above options: ";
        cin.clear();
        getline(cin, choice);
        if(choice == "1")
            addText(fileName);
        else if(choice == "2")
            displayContent(fileName);
        else if(choice == "3")
            emptyFile(fileName);
        else if(choice == "4")
            encryptORdecrypt(fileName, 1); // encrypt
        else if(choice == "5")
            encryptORdecrypt(fileName, -1); // decrypt
        else if(choice == "6")
            mergeFile(fileName);
        else if(choice == "7")
            wordCount(fileName);
        else if(choice == "8")
            charCount(fileName);
        else if(choice == "9")
            lineCount(fileName);
        else if(choice == "10")
            wordSearch(fileName);
        else if(choice == "11")
            wordFrequency(fileName);
        else if(choice == "12")
            toUpper(fileName);
        else if(choice == "13")
            toLower(fileName);
        else if(choice == "14")
            firstCaps(fileName);
        else if(choice == "15"){
            save();
            break;
        }
        else if(choice == "16")
            break;
        else{
            cerr << "\n########## INVALID INPUT! Enter only numbers from 1 to 16 ##########\n";
            continue;
        }
    }
    cout << "\t\t\tThank You for using the Text Editor program!\n";
    return;
}

// Add more text to the file as input through console
void addText(char filename[]){
    cout << "\n-------------------- Add Text to " << filename << " --------------------\n";
    ofstream addToFile(filename, ios::app);
    string input;
    cout << "Enter text to add and finish by (Ctrl + Z) \"in its own line\":\n";
    // Take text from user and add it to the file
    // and stop when the user enters ctrl + z (^Z)
    while(getline(cin, input)){
        addToFile << input << endl;
    }
    addToFile.close();
    cout << "$$$$$$$$$$ Text added to the file successfully! $$$$$$$$$$\n";
}

// Display contents of the file in the console
void displayContent(char filename[]){
    cout << "\n\t\t    ---------- " << filename << " ----------\n";
    ifstream displayFile(filename, ios::in);
    if(displayFile.peek() == EOF)
        cout << "\t\t\t  " << filename << " is EMPTY!\n";
    string line;
    // Output the contents of the file line by line
    while(getline(displayFile, line)){
        cout << line << endl;
    }
    displayFile.close();
    cout << "-------------------------------------------------------------------------\n";
}

// Remove/Truncate contents of the file
void emptyFile(char filename[]){
    cout << "\n-------------------------- Empty file -------------------------\n";
    ofstream emptyFile(filename, ios::trunc);
    emptyFile.close();
    cout << "$$$$$$$$$$ " << filename << " contents removed and is now EMPTY! $$$$$$$$$$\n";
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
    // Closing files
    inFile.close();
    outFile.close();
    // According to the action print the suitable confirmation message
    if(decision == 1){
        cout << "\n--------------- Encrypt file contents ---------------\n";
        cout << "$$$$$$$$$$ File is encrypted and secured! $$$$$$$$$$\n";
    }
    else{
        cout << "\n------------- Decrypt file contents -------------\n";
        cout << "$$$$$$$$$$ File is decrypted! $$$$$$$$$$\n";
    }
}

// Merges another file to the main file
void mergeFile(char filename[]){
    cout << "\n-------------------- Merge file with " << filename << " --------------------\n";
    char fileName2[101];
    int valid = 0;
    // Get the file to merge as input from the user
    while(!valid){
        cout << "Please enter the name of text file to merge: ";
        cin.clear();
        cin.getline(fileName2, 101, '\n');
        // Check for the correct format of the input file
        regex validFormat("[\\w-]+(.txt)");
        // If expression is not valid it loops again for input
        if(!regex_match(fileName2, validFormat)){
            cerr << "########## File format NOT supported! Enter only \".txt\" files ##########\n";
            continue;
        }
        // Create objects for the original file and the file to merge
        fstream file1, file2;
        file1.open(filename, ios::app);
        file2.open(fileName2, ios::in);
        // Checks if file2 is working then adds the second file to the main
        if(!strcmp(fileName2, filename)){
            cerr << "########## Choose another DIFFERENT file from the current file!! ##########\n";
            continue;
        }
        else if(file2.fail()){
            cerr << "########## File does NOT exist! ##########\n";
            continue;
        }
        else{
            string line;
            while(getline(file2, line)){
                file1 << line << endl;
            }
            cout << "$$$$$$$$$$ " << filename << " & " << fileName2 << " were merged successfully! $$$$$$$$$$\n";
            break;
        }
        // Closing the two files
        file1.close();
        file2.close();
    }
}

// Counts how many words in the file
void wordCount(char filename[]){
    cout << "\n------------- Count number of words in " << filename << " -------------\n";
    fstream file(filename, ios::in);
    // Initiating variables needed for counting words
    int nWords = 0;
    char ch;
    string text = "";
    // Looping on each character in the file and copies it to string (text)
    file.get(ch);
    while(!file.eof()){
        text += ch;
        file.get(ch);
    }
    // Loop for counting words in text
    for(int i = 0; i < text.length() - 1; i++){
        // Checking if first character is a letter then increments nWords
        if(i == 0 && !isspace(text[0]))
            nWords++;
        // Checking if current letter is a space and the next is a letter to increment nWords
        if(isspace(text[i]) && !isspace(text[i + 1]))
            nWords++;
    }
    cout << "\n$$$$$$$$$$ " << filename << " contains " << nWords << " words $$$$$$$$$$\n";
    file.close(); // Closing file
}

// Counts how many characters in the file
void charCount(char filename[]){
    cout << "\n------------- Count number of characters in " << filename << " -------------\n";
    fstream file(filename, ios::in);
    // Initiating variables needed to count characters
    int nChars = 0;
    char ch;
    file.get(ch);
    // Loop that iterates on each letter in file and increments nChars by 1 if it is a character
    while(!file.eof()){
        if(!isspace(ch))
            nChars++;
        file.get(ch);
    }
    cout << "\n$$$$$$$$$$ " << filename << " contains " << nChars << " characters $$$$$$$$$$\n";
    file.close(); // Closing file
}

// Counts how many lines in the file
void lineCount(char filename[]){
    cout << "\n------------- Count number of lines in " << filename << " -------------\n";
    fstream file(filename, ios::in);
    // Checking if file is empty then initiates nLines with 0
    int nLines;
    if(file.peek() == EOF){
        cout << "########## " << filename << " is EMPTY! Contains 0 lines! ##########\n";
        return;
    }
    else
        nLines = 1;
    char ch;
    file.get(ch);
    // Loop that iterates on each letter
    while(!file.eof()){
        // If new line character was found then increment nLines
        if(ch == '\n')
            nLines++;
        file.get(ch);
    }
    cout << "\n$$$$$$$$$$ " << filename << " contains " << nLines << " lines $$$$$$$$$$\n";
    file.close(); // Closing the file
}

// Searches for a word in the file
void wordSearch(char filename[]){
    cout << "\n----------------- Word search in " << filename << " -----------------\n";
    // Taking the word needed to search for from user
    string word;
    cout << "Enter the word to search for: ";
    cin.clear();
    getline(cin, word);
    // Loop to convert the word to lowercase
    for(int i = 0; i < word.length(); i++){
        word[i] = tolower(word[i]);
    }
    // Initiating file and text string
    fstream file(filename, ios::in);
    char ch;
    string text = "";
    file.get(ch);
    // Loop to add a lowercase version of the file to text string
    while(!file.eof()){
        text += (char)tolower(ch);
        file.get(ch);
    }
    // Loop to that compares each word from text to the word taken from user
    string temp = "";
    for(int i = 0; i <= text.length(); i++){
        // Adding new character to temp
        temp += text[i];
        // Checking if temp string is same as word and that temp is a whole word
        if(temp == word && isspace(text[i + 1])){
            cout << "$$$$$$$$$$ \"" << word << "\" was found in the file :) $$$$$$$$$$\n";
            return;
        }
        // Checking if current character is a space character and empties temp if true
        else if(isspace(text[i])){
            temp = "";
        }
    }
    cout << "########## \"" << word << "\" was NOT found in the file :( ##########\n";
    file.close(); // Closing the file
}

// Counts how many times the word input from user was repeated in the file
void wordFrequency(char file[]){
    cout << "\n---------------- Count frequency of a certain word in " << file << " ----------------\n";
    string word;
    // Taking the word from user
    cout << "Enter the word you want to know how many repetitions of it: ";
    cin.clear();
    getline(cin, word);
    // Converting word to lower case
    for(int i = 0; i < word.length(); i++)
        word[i] = tolower(word[i]);
    // Opening file
    fstream myFile;
    myFile.open(file, ios::in);
    char ch;
    string text = "";
    // Copying a lower case version of the file to a string called text
    myFile.get(ch);
    while(!myFile.eof()){
        text += (char)tolower(ch);
        myFile.get(ch);
    }
    // Initiating variables needed for counting
    string temp = "";
    int count = 0;
    // Iterate on each char in string
    for(int i = 0; i <= text.length(); i++){
        temp += text[i];
        // Checking if temp is a whole word and is the same as the input word
        if(temp == word && isspace(text[i + 1])){
            count += 1;
            temp = "";
        }
        // Checking if coming character is a space character and empties temp if true
        else if (isspace(text[i])){
            temp = "";
        }
    }
    cout << "$$$$$$$$$$ \"" << word << "\" was repeated "
         << count << " time(s) in " << file << " $$$$$$$$$$\n";
    myFile.close(); // Closing file
}

// Convert every character in the file to upper case
void toUpper(char file[]){
    cout << "\n---------- Convert " << file << " content into Upper case ----------\n";
    fstream fileData;
    fileData.open(file, ios::in);
    char ch;
    string upperChars;
    fileData.get(ch);
    while(!fileData.eof()){
        // Collect content of file in the string after converting it to upper case
        upperChars.push_back(char(toupper(ch)));
        fileData.get(ch);
    }
    fileData.close(); // Closing file
    // Create a new object with the same file but with different open mode
    fileData.open(file, ios::out);
    for(auto el: upperChars){
        // write chars after converting it to upper case in file
        fileData << el;
    }
    fileData.close(); // Closing file
    cout << "$$$$$$$$$$ Upper case applied successfully! $$$$$$$$$$\n";
}

// Convert every character in the file to lower case
void toLower(char file[]){
    cout << "\n---------- Convert " << file << " content into Lower case ----------\n";
    fstream fileData;
    fileData.open(file, ios::in);
    char ch;
    string lowerChars;
    fileData.get(ch);
    while(!fileData.eof()){
        // Collect content of file in the string after converting it to lower case
        lowerChars.push_back(char(tolower(ch)));
        fileData.get(ch);
    }
    fileData.close();
    // Create a new object with the same file but with different open mode
    fileData.open(file, ios::out);
    for(auto el: lowerChars){
        // write chars after converting it to lower case in file
        fileData << el;
    }
    fileData.close(); // Closing file
    cout << "$$$$$$$$$$ Lower case applied successfully! $$$$$$$$$$\n";
}

 // Convert first character of each word to upper case
void firstCaps(char file[]){
    cout << "\n---------- Convert " << file << " content into first caps ----------\n";
    fstream myFile;
    myFile.open(file, ios::in);
    char ch;
    string text = "";
    myFile.get(ch);
    while(!myFile.eof()){
        // collect content of file in the string
        text.push_back(ch);
        myFile.get(ch);
    }
    myFile.close();
    // Create a new object with the same file but with different open mode
    myFile.open(file, ios::out);
    for(int i = 0; i < text.size(); i++){
        // Convert first char in first word to upper case
        if(i == 0 && !isspace(text[i])){
           myFile << (char)toupper(text[i]);
        }
        else if(isspace(text[i])){
            myFile << text[i];
            // Convert char after space character
            if(!isspace(text[i + 1]) && text[i + 1] != '\0'){
                myFile << (char)toupper(text[i + 1]);
                i++;
            }
        }
        else{
            myFile << text[i];
        }
    }
    myFile.close(); // Closing file
    cout << "$$$$$$$$$$ First Caps applied successfully! $$$$$$$$$$\n";
}

// Save file contents to a new or same file
void save(){
    cout << "\n------------------------------ Save contents of the file ------------------------------\n";
    char newFilename[101];
    // Check the input of the user if its empty that means
    // ENTER is pressed so save to the current file
    while(true){
        cout << "Enter a NEW file name OR press ENTER to save to the current same file: ";
        cin.clear();
        cin.getline(newFilename, 101, '\n');
        // Check for the correct format of the input file
        regex validFormat("[\\w-]+(.txt)");
        // Checking if user typed enter to save contents to current file
        if(newFilename[0] == '\0' | !strcmp(newFilename, fileName)){
            cout << "$$$$$$$$$$ \"" << fileName << "\" is saved successfully! $$$$$$$$$$\n";
            break;
        }
        // Checking if file format is invalid to return back to user and take input
        else if(!regex_match(newFilename, validFormat)){
            cerr << "########## File format NOT supported! Enter only \".txt\" files ##########\n";
            continue;
        }
        // Creates a new file with the given name from user and saves contents in it    
        else{
            ifstream oldFile(fileName, ios::in);
            ofstream newFile(newFilename, ios::out);
            string line;
            while(getline(oldFile, line)){
                newFile << line << endl;
            }
            cout << "$$$$$$$$$$ Contents saved in the new file ==> \"" << newFilename << "\" successfully! $$$$$$$$$$\n";
            oldFile.close();
            newFile.close();
            break;
        }
    }
    cout << "---------------------------------------------------------------------------------------\n";
}