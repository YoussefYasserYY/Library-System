#ifndef users_H
#define users_H
#include<cstring>
#include<iostream>

using namespace std;

class User {
private:
    string name = " ";
    int age = 0;
    int id = 0;
    string password;
    string email;
public:
    static int count;

    User();                                       // A default constructor
    User(string, int, string, string);           // A constructor that take Name, Age, Password, Email

    User(const User& user);                     // A copy constractor 
    static void Cout();                        // To have control on what to print and when

    bool operator==(const User& user);       // Overloading the == operator 
                                            // The function compares the Name, Age, Password, and Email

    int getCount()                         // To access the static integer
    {
        return count;
    };
    void setName(string Name)
    {
        name = Name;
    };
    string getName() const
    {
        return name;
    };
    void setPassword(string Password)
    {
        password = Password;
    };
    string getPassword()
    {
        return password;
    };
    void setEmail(string Email)
    {
        email = Email;
    };

    string getEmail()
    {
        return email;
    };
    void setAge(int Age)
    {
        age = Age;
    };

    int getAge()
    {
        return age;
    };
    void setId() //to store the count
    {
        id = getCount();
    };

    void setId(int Id)
    {
        id = Id;
    };

    int getId()
    {
        return id;
    };
    friend ostream& operator<<(ostream& output, const User& user);   // Easily output an object (user)
    friend istream& operator>>(istream& input, User& user);         // Easily input values to an object (user)
};
#endif//user_h


