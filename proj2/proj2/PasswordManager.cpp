
#include "PasswordManager.h"

// ---------Private--------- 

string PasswordManager::encrypt(string password){
    string res = "";
    for(int i =0; i < password.length(); i++) {
        char finC;
        char c = password[i];
        finC = ((c - 33) + 25) % 94 + 33;
        res += finC;
    }

    return res;
}

bool PasswordManager::meetsCriteria(string password){
    if(password.length() < 8){
        return false;
    }

    bool yesU = false, yesL = false, yesD = false;
    for(int i = 0; i < password.length(); i++){
        if(isupper(password[i]) && yesU == false) {
            yesU = true;
        }

        if(islower(password[i]) && yesL == false) {
            yesL = true;
        }

        if(isdigit(password[i]) && yesD == false) {
            yesD = true;
        }
    }

    if(!yesU || !yesL || !yesD){
        return false;
    }
    
    return true;
}

// ---------Public--------- 

PasswordManager::PasswordManager(){
    username = "";
    password = "";
}

PasswordManager::PasswordManager(string uName, string pw){
    username = uName;
    password = pw;
}

bool PasswordManager::checkPassword(string pw){
    return meetsCriteria(pw);
    
}

void PasswordManager::setUsername(string uName) {
    username = uName;
}

void PasswordManager::setEncryptedPassword(string encPassword) {
    password = encPassword;
}

string PasswordManager::getUsername(){
    return username;
}

string PasswordManager::getEncryptedPassword(){
    return encrypt(password);
}

bool PasswordManager::setNewPassword(string newPassword){
    if(!meetsCriteria(newPassword)){
        return false;
    }

    password = newPassword;
    return true;
}

bool PasswordManager::authenticate(string newpassword){
    string checkPassword = encrypt(newpassword);

    return checkPassword == encrypt(password);
}



