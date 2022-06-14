#ifndef UserList_H
#define UserList_H
#include"users.h"
#include"books.h"

class UserList
{ 
private: 
   User* users;	
   int capacity = 0;
   int usersCount = 0;
public:
   UserList();
   UserList(int);
   void setcapacity(int);       // To limit the number of users
   void addUser(User);         // To add user to the List
   User& searchUser(string);  // To search for a user using the Name
   User& searchUser(int);    // To search for a user using the ID
   void deleteUser(int);    // This function takes a user ID to delete it from the list
   friend ostream& operator<<(ostream& output, UserList& userList); // To Easily output a UserList object
   ~UserList(); // a destractor to free up space
};
#endif//UserList_h