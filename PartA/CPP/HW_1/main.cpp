#include <iostream>
#include <cstring>
#include "LinkedList.h"
using namespace std;

using InvalidInputExcepcion = std::domain_error;
using InvalidArgumentException = std::invalid_argument;

// Function to read and return a complex number from the user.
Complex chooseComplex(){
    //////cout << "choose scalar: " << endl;
    string scalar;
    getline(cin,scalar);
    double a;
    double b;
    if (sscanf(scalar.c_str(), "(%lf,%lf)",&a ,&b) != 2){
        throw InvalidInputExcepcion("");
    }
    return {a,b};
}

// Function to check if a string represents a number.
bool is_number(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Function to handle the "Printing" command.
void Printing(LL ll){
    string name = chooseName();
    if (!isInLL(ll,name)){
        throw InvalidArgumentException("error: "+ name + " does not exist");
    }
    LLPrintMatrix(ll,name);
}

// Function to handle the "Determinant" command.
void Determinant(LL ll){
    string name = chooseName();
    if (!isInLL(ll,name)){
        throw InvalidArgumentException("error: "+ name + " does not exist");
    }
    cout << LLDeterminantMatrix(ll,name).toString() << endl;
}

// Function to handle the "Ordering" command.
void Ordering(LL ll){
    string name = chooseName();
    if (!isInLL(ll,name)){
        throw InvalidArgumentException("error: "+ name + " does not exist");
    }
    string num;
    int number;
    /////cout << "what order do you want? " << endl;
    getline(cin,num);
    if (is_number(num)){
        stringstream ss(num);
        ss >> number;
        if (number >= 0){
            string newName = chooseName();
            if (name == newName){
                LLOrdering(ll,name,number);

            } else {
                Matrix newMatrix = CreateMatrix((LLGetSizeMatrix(ll, name)), newName);
                LLAdd(ll, newMatrix);
                LLCopyMatrix(ll, newName, name);
                LLOrdering(ll, newName, number);
            }
        }
    } else {
        throw InvalidInputExcepcion("");
    }
}

// Function to handle the "MltByScalar" command.
void MltByScalar(LL ll){
    string name = chooseName();
    if (isInLL(ll,name)){
        Complex scalar = chooseComplex();
        string newName = chooseName();
            if (name == newName) {
                LLMltByScalar(ll, scalar, name);

            } else {
                Matrix newMatrix = CreateMatrix(LLGetSizeMatrix(ll, name), newName);
                LLAdd(ll, newMatrix);
                LLCopyMatrix(ll, newName, name);
                LLMltByScalar(ll, scalar, newName);
            }
        }

    else {
        throw InvalidArgumentException("error: " + name + " does not exist");
    }
}

// Function to handle the "Deleting" command.
void Deleting(LL ll){
    string name = chooseName();
        if (isInLL(ll,name)) {
            LLRemoveById(ll, name);
        } else{
            throw InvalidArgumentException("error: "+ name + " does not exist");
        }
}

// Function to handle the "Adding" command.
void Adding(LL ll) {
    string name = chooseName();
    ////cout << "what dimension would you like? " << endl;
    string size;
    getline(cin,size);
    if (is_number(size)){
        stringstream ss(size);
        int dimension;
        ss >> dimension;
        if (dimension > 256 || dimension <= 0) {
            throw InvalidInputExcepcion("");
        }
        Matrix matrix = CreateMatrix(dimension, name);
        for (int i = 0; i < dimension; i++) {
           //// cout << "Line number " << i + 1 << ": "<< endl;
            string tmpLine;
            getline(cin, tmpLine);
            const char *delimiter = tmpLine.c_str();
            int column = 0;
            while (*delimiter != '\0') {
                if (column >= dimension) throw InvalidArgumentException("error: " + name + " does not exist");
                double a = 0;
                double b = 0;
                if (sscanf(delimiter, "(%lf, %lf)", &a, &b) != 2) throw InvalidInputExcepcion("");
                SetIndexMatrix(matrix, i, column++, {a, b});
                delimiter = strchr(delimiter, ')');
                if (*(++delimiter) == ' ') {
                    delimiter++;
                }
            }
            if (column < dimension - 1) throw InvalidInputExcepcion("");
        }
        LLAdd(ll, matrix);
        /////cout << "done!" << endl;
    }
    else {
        throw InvalidInputExcepcion("");
    }
}


int main() {
    LL ll = LLCreate();
    while (true){
        try {
           //// cout << "please choose command!" << std::endl;
            string command;
            getline(cin,command);
            if (!is_number(command)) {
                cout << "error: invalid command; type 0 for exit" << std::endl;
            } else {
                int go;
                stringstream ss(command);
                ss >> go;
                switch (go) {
                    case 0:
                        LLDestroy(ll);
                        return 0;
                    case 1:
                        Adding(ll);
                        break;
                    case 2:
                        Deleting(ll);
                        break;
                    case 3:
                        MltByScalar(ll);
                        break;
                    case 4:
                        Ordering(ll);
                        break;
                    case 5:
                        Determinant(ll);
                        break;
                    case 6:
                        Printing(ll);
                        break;
                    default:
                        cout << "error: invalid command; type 0 for exit" << endl;
                        break;
                }
            }
        }
        catch (InvalidInputExcepcion& e){
            cout << "error: invalid input" << endl;
        }
        catch (InvalidArgumentException& e){
            cout << e.what() << endl;
        }
    }

}
