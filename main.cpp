#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Based on tutorial from: https://www.youtube.com/watch?v=I_aWPGCaaFA

bool IsLoggedIn()
{
    // login function
    string username, password;
    string un, pw;      // username, password

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    // if username and password are correct return true, otherwise return false
    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;     // user's choice
    menu:           // where to jump

    cout << "1: Register\n2: Login\nYour choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string username, password;

        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ofstream file;
        file.open(username + ".txt");
        file << username << "\n" << password;
        file.close();

        goto menu;
    }
    else if (choice == 2)
    {
        bool status = IsLoggedIn();

        if (!status)
        {
            cout << "Incorrect login and/or password!\n";
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Succesfully logged in!\n";
            system("PAUSE");
            return 1;
        }
    }
    else
    {
        cout << "\nPlease enter valid number (1 or 2)\n";
        goto menu;
    }
}
