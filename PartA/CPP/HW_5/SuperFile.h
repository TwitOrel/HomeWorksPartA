//
// Created by Orel on 19/06/2023.
//

#ifndef EX5_SUPERFILE_H
#define EX5_SUPERFILE_H
#include <fstream>

using namespace std;

class SuperFile {
private:
    mutable fstream file;
    const string nameFile;
public:
    class CharProxy{
    private:
        fstream& file;
        fstream ::pos_type pos;
    public:
        //  Ctor
        CharProxy(fstream &file, fstream::pos_type pos):file(file),pos(pos){}

        //  operator= to return CharProxy: to change the val
        CharProxy& operator=(char c){
            file.seekg(pos);
            file.put(c);
            file.close();
            return *this;
        }

        //  operator= to return CharProxy: to change the val
        CharProxy& operator=(string c){
            file.seekg(pos);
            file.put(c[0]);
            file.close();
            return *this;
        }

        //  change the val in the file
        operator char(){
            file.seekg(pos);
            return char(file.get());
        }
    };

    // Ctor
    explicit SuperFile(const string& file);

    //Dtor
    ~SuperFile() = default;

    //  return the char from the file by the index:only to read
    char operator[](int index)const;

    //  return the char from the file by the index (mutable)
    CharProxy operator[](int index);

    //  return string same as the file
    string readText()const;

    //  write the txt to the file
    void writeText(const string& txt);

    //  check if the file is open
    bool is_open();

    //  close the file
    void close();

};

//  this functions same as requested
void touch(const string& name);
void copy(const string& from, const string& to);
void remove(const string& name);
void move(const string& from, const string& to);
void cat(const string& name);
void head(const string& name, int lines = 10);
void tail(const string& name, int lines = 10);


#endif //EX5_SUPERFILE_H
