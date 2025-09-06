//
// Created by Erasmo on 6/09/25.
//

#include "AuxiliaryFunctions.hpp"

//'A' … 'Z' → rango de 65 a 90.
//'a' … 'z' → rango de 97 a 122.
// 'a' - 'A' -> 97 - 65 :> 32

void to_uppercase(char &c) {
    if (c >= 'a' and c <= 'z') {
        c = c - ('a' - 'A'); // o simplemente c -= 32;
    }
}

void to_lowercase(char &c) {
    if (c >= 'A' and c <= 'Z') {
        c = c + ('a' - 'A'); // o simplemente c += 32;
    }
}

void read_print_str() {
    char c;
    bool startWord = true;
    cin>>ws;
    cout<<" ";
    while (true) {
        c = cin.get();              // read one character

        if (c == '\n') {            // stop at ENTER or end of line
            break;
        }

        if (c == '.') {
            cout.put(' ');       // print space directly
            startWord = true;       // next char starts a new word
        }
        else {
            if (startWord) {
                to_uppercase(c);
                startWord = false;
            } else {
                to_lowercase(c);
            }
            cout.put(c);
        }
    }
    cout << endl;
}

