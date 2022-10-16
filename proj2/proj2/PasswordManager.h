#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <string>

using namespace std;

class PasswordManager{
    
    private:
        string username;
        string password;

        string encrypt(string unCrypt); //{return string encrypt};
        bool meetsCriteria(string password);

    public: 
        PasswordManager();
        PasswordManager(string, string);
        bool checkPassword(string);
        void setUsername(string);
        void setEncryptedPassword(string);
        string getUsername();
        string getEncryptedPassword();
        bool setNewPassword(string);
        bool authenticate(string);
       
};
#endif