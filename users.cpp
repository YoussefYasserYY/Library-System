#include"users.h"
#include"books.h"
#include<cstring>
#include<iostream>

using namespace std;

User::User()
{
    count++;
    id = count;
};

User::User(string Name, int Age, string Email, string Password)
{
    name = Name;
    age = Age;
    email = Email;
    password = Password;
    count++;
    id = count;
};

User::User(const User& user) 
{
    name = user.name;
    age = user.age;
    password = user.password;
    email = user.email;
    id = user.id;
};

bool User::operator==(const User& user) 
{
    return name == user.name && age == user.age && password == user.password && email == user.email;
};

void User::Cout() {
    if (count == 0)
    {
        cout << "Let's add a user" << endl;
    }
    else
    {
        cout << "Let's add another user" << endl;
    }
    cout << "Enter the user info in this order" << endl;
    cout << "Name Age Email Password (Space seperated)" << endl;
};

ostream& operator<<(ostream& output, const User& user)
{
    output << "======= User " << user.id << " info =========" << endl;
    output << " name: " << user.name << "\n age: " << user.age << "\n ID: " << user.id << "\n Email: " << user.email << "  " << endl;
    output << "=============================\n";
    return output;
};

istream& operator>>(istream& input, User& user)
{
    input >> user.name >> user.age >> user.email >> user.password;
    return input;

};

int User::count = 0;
