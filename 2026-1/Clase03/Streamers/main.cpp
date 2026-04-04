#include <iostream>
using namespace std;

int main() {
    int day, month, year; //Fecha
    char separator, c;
    int viewers;
    double hours;

    while (true) {
        cin >> year;
        if(cin.eof())break;
        cin>> separator >> month >> separator >> day;
        cout << day << separator << month << separator << year << " | ";
        cin >> ws;
        while(true){
            cin.get(c);
            if(c == ' ') break;
            if(c == '_') c = ' ';
            cout.put(c);
            //cout<<character;
        }
        cout << " | ";
        cin >> viewers >> hours;
        cout << viewers << " | " << hours << endl;
    }
    return 0;
}
