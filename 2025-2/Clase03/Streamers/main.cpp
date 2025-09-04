#include <iostream>
using namespace std;

int main() {
    int day, month, year;
    char separator, character;
    int viewers;
    double hours;

    while (true) {
        cin >> year;
        if(cin.eof())break;
        cin>> separator >> month >> separator >> day;
        cout << day << separator << month << separator << year << " | ";
        cin >> ws;
        while(true){
            cin.get(character);
            if(character == ' ') break;
            cout<<character;
        }
        cout << " | ";
        cin >> viewers >> hours;
        cout << viewers << " | " << hours << endl;
    }
    return 0;
}
