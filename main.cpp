/*
FCAI – Programming 1 – 2022 - Assignment 4
Group: S13
Author1 and ID: Seif Yahia - 20210172
Author2 and ID: Mohamed Amgad - 20210330
Author3 and ID: Omar Elgammal - 20210271
Program Name: Text Editor
Last Modification Date: 16 May 2022
Version: 3.0
*/

#include <iostream>
#include "txteditlib.cpp"

using namespace std;

int main(){
    cout << "Welcome to the Text Editor program!\n";
    getFile();      // Takes the file from the user
    start();        // Displays the menu of options
}