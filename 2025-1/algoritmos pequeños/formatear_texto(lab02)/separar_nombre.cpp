#include <iostream>
#include <fstream>
using namespace std;

void separar_nombre(ifstream &input, ofstream &output){
    char c;
    bool flag=true;
    while(true){
        c = input.get();
        if(c == ' ') break;
        if(c == '-' or c == '/'){
            output << ' ';
            flag = true;
        }
        else if(flag){
            output << c;
            flag = false;
        }
        else output << char(c + ('a' - 'A'));
    }
}

int main(){
    ifstream input("datos.txt", ios::in);
    if(not input.is_open()) exit(1);
    ofstream output("reporte.txt", ios::out);
    if(not output.is_open()) exit(1);
    separar_nombre(input, output);
}