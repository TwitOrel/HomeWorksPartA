//
// Created by Orel on 19/06/2023.
//

#include "SuperFile.h"
#include <iostream>
#include <sstream>

SuperFile::SuperFile(const string& file):file(fstream(file)),nameFile(file){}

char SuperFile::operator[](int index) const{
    this->file.seekg(0,ios_base::end);

    // size = size of the text
    int size = (int)this->file.tellg();
    if ((index > size) || index < 0){
        throw "error: USAGE operator[] ";
    }

    this->file.seekg(index);
    char ret;
    file.get(ret);
    return ret;
}

SuperFile::CharProxy SuperFile::operator[](int index) {
    this->file.seekg(0,ios_base::end);
    int size = (int)this->file.tellg();
    if (index > size){
        this->file.close();
        throw "problem with size";
    }
    return {this->file,index};
}

string SuperFile::readText()const {
    stringstream ret ;
    ret << this->file.rdbuf();
    this->file.close();
    return ret.str();
}

void SuperFile::writeText(const string& txt) {
    this->file << txt;
    this->file.flush();
}

bool  SuperFile::is_open(){
    return this->file.is_open();
}

void SuperFile::close() {
    file.close();
}


void touch(const string& name){
    SuperFile tmpFile(name);
    if (!tmpFile.is_open()){
        ofstream planB(name);
        if (!planB.is_open()){
            throw "problem with copy function";
        }
    } else {
        string txt = tmpFile.readText();
        tmpFile.close();
        SuperFile thisFile(name);
        thisFile.writeText(txt);
    }
}

void copy(const string& from, const string& to){
    SuperFile source(from);
    SuperFile destination(to);
    if (!source.is_open()){
        throw  "problem with copy function" ;
    }  if (!destination.is_open()){
        ofstream planB(to);
        if (!planB.is_open()){
            throw "problem with copy function";
        }
        planB << source.readText();
    }
    destination.writeText(source.readText());
}

void remove(const string& name){
    if (remove(name.c_str()) != 0) {
        throw "error: USAGE remove FILENAME." ;
    }
}

void move(const string& from, const string& to){
    copy(from,to);
    remove(from);
}


void cat(const string& name) {
    SuperFile txt(name);
    if (!txt.is_open()){
        throw "problem with cat";
    }
    char a = 0;
    int index = 0;
    a = txt[index];
    while (a != EOF){
        cout << a ;
        a = txt[++index];
    }
    cout << endl;
}

void head(const string& name, int lines){
    SuperFile myFile(name);
    if (!myFile.is_open()){
        throw  "problem with head function " ;
    }
    int count = 0;
    int index = 0;
    while (index++, count <= lines){
        char x = myFile[index-1];
        if (x == EOF){
            break;
        }
        if (x == '\n'){
            count++;
        }
        cout << x;
    }
}

void tail(const string& name, int lines){
    SuperFile myFile(name);
    if (!myFile.is_open()) {
        throw  "problem with tail";
    }
    string txt = myFile.readText();
    int count = 0;
    size_t index = txt.length();
    while (count < lines) {
        char tav = txt[--index];
        if (tav == '\n') {
            ++count;
        }
        if (index == 0) break;
    }
    string toPrint = txt.substr((index == 0) ? 0 : index + 1, txt.length());
    cout << toPrint << endl;

}
