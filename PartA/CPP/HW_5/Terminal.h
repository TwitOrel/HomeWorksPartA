//
// Created by Orel on 20/06/2023.
//

#ifndef EX5_TERMINAL_H
#define EX5_TERMINAL_H
#include <iomanip>
#include <iostream>
#include <vector>
#include <sstream>
#include "SuperFile.h"

using namespace std;
void options(){

    // Display available options to the user.
    cout << left << "[1]" << setw(5) << " " << "read FILENAME POSITION" << endl;
    cout << left << "[2]" << setw(5) << " " << "write FILENAME POSITION CHARACTER" << endl;
    cout << left << "[3]" << setw(5) << " " << "touch FILENAME" << endl;
    cout << left << "[4]" << setw(5) << " " << "copy SOURCE_FILENAME TARGET_FILENAME" << endl;
    cout << left << "[5]" << setw(5) << " " << "remove FILENAME" << endl;
    cout << left << "[6]" << setw(5) << " " << "move SOURCE_FILENAME TARGET_FILENAME" << endl;
    cout << left << "[7]" << setw(5) << " " << "cat FILENAME" << endl;
    cout << left << "[8]" << setw(5) << " " << "head FILENAME [n]" << endl;
    cout << left << "[9]" << setw(5) << " " << "tail FILENAME [n]" << endl;
    cout << left << "[10]" << setw(4) << " " << "exit" << endl;
}


void run(){
    string line;
    while (true) {
        //  write the options for the user
        //options();

        //  get the line from the user
        getline(cin, line);

        //  split the line by ' ' to vector
        vector<string> words;
        stringstream ss(line);
        string word;
        while (std::getline(ss, word, ' ')) {
            words.push_back(word);
        }

        // deal by the case
        string command = words[0];
        if (command == "read"){
            string fileName = words[1];
            int index = stoi(words[2]);
            const SuperFile file(fileName);
            if (file[index] != '\0'){
                cout << file[index] << endl;
            }
        }

        else if (command == "write"){
            try {
                string fileName = words[1];
                int index = stoi(words[2]);
                SuperFile file(fileName);
                file[index] = words[3];
            }
            catch (char const*){
                cout << "error: "<< words[1] <<" does not exist or cannot be processed."<<endl;
            }
        }

        else if (command == "touch"){
            string fileName = words[1];
            touch(fileName);
        }

        else if (command == "copy"){
            if (words.size() >= 3) {
                try {
                    string from = words[1];
                    string to = words[2];
                    copy(from, to);
                }
                catch (char const*){
                    cout << "error: USAGE copy SOURCE_FILENAME TARGET_FILENAME." << endl;
                }
            }
            else{
                cout << "error: USAGE copy SOURCE_FILENAME TARGET_FILENAME." << endl;
            }

        }

        else if (command == "remove"){
            if (words.size() >= 2) {
                string fileName("tmp");
                fileName = words[1];
                remove(fileName);
            }
            else{
                cout << "error: USAGE remove FILENAME." << endl;
            }
        }

        else if (command == "move") {
            if (words.size() >= 3) {
                try {
                    string from = words[1];
                    string to = words[2];
                    move(from, to);
                }
                    catch (char const*) {
                         cout << "error: USAGE move " << words[1] << " " << words[2] << endl;
                }
            }
            else{
                cout << "error: USAGE move SOURCE_FILENAME TARGET_FILENAME." << endl;
            }
        }

        else if (command == "cat"){
            try {
                string fileName = words[1];
                cat(fileName);
            }
            catch (char const*){
                cout << "error: " << words[1] << " does not exist or cannot be processed." << endl;
            }
        }

        else if (command == "head"){
            try {
                string fileName = words[1];
                int n = stoi(words[2]);
                head(fileName,n);
            }
            catch (char const*){
                cout << "error: USAGE head " << words[1] << endl;
            }
        }

        else if (command == "tail"){
            try {
                string fileName = words[1];
                int n = stoi(words[2]);
                tail(fileName,n);
            }
            catch (char const*){
                cout << "error: USAGE tail " << words[1] << endl;
            }
        }

        else if (command == "exit"){
            return;
        }
        else{
            cout << "error: command is not supported." << endl;
        }
    }
}

#endif //EX5_TERMINAL_H
