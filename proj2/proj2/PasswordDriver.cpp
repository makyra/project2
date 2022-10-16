#include <iostream>
#include <string>
#include <fstream>
#include <cstring> 

#include "PasswordManager.h"

int main(int argc, char const *argv[])
{
    PasswordManager *pm_array;
    pm_array = new PasswordManager[3];

    ifstream file;
    file.open("passwords.txt");

    if(!file.good()){
        cout << "Input file does not exist\n";
        return 1;
    }

    for(int i = 0; i < 3; i++){
        string s;
        getline(file, s);
        // cout << s << "\n";

        string s0;
        string s1;
        int count = 0;
        for(int j = 0; j < s.length(); j++){
            char c = s[j];
            if(c == 32){
                count = j;
                break;
            } 

            s0 += c;
        }

        for(int j = count + 1; j < s.length(); j++){
            char c = s[j];
            s1 += c;
        }

        //cout << "s0: " << s0 << "    s1: " << s1 << "\n";
        
        PasswordManager *pm = new PasswordManager(s0, s1);
        pm_array[i] = *pm;
    }


    for(int i = 0; i < 3; i++){
        cout << pm_array[i].getUsername() << "\n";
    }

    return 0;
}

