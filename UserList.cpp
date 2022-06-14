#include"users.h"
#include"books.h"
#include"UserList.h"
#include<cstring>
#include<iostream>
using namespace std;


UserList::UserList()
{
}

UserList::UserList(int Capacity)
{
	capacity = Capacity;
	users = new User[capacity];
	User::count = User::count - capacity;
}

void UserList:: setcapacity(int i)
{
    capacity = i;
	users = new User[capacity];
	User::count = User::count - capacity;
}
void UserList::addUser(User user)
{
	if (usersCount < capacity)
	{
		users[usersCount] = user;
		usersCount++;
	}
}
User& UserList:: searchUser(string name)
{
    for (int i = 0; i < usersCount; i++)
	{	
		if (users[i].getName() == name)
		{
			return users[i];
			break;
		};
	}
}	

User& UserList::searchUser(int id)
{
	if (id <= usersCount && id>0)
	{
		for (int i = 0; i < usersCount; i++)
		{
			if (users[i].getId() == id)
			{
				return users[i];
				break;
			};
		}
	}
	else
	{
		cout << "User not found\n";
	}
}

void UserList::deleteUser(int id)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i].getId() == searchUser(id).getId())
		{
			for (int j = i; j < usersCount - 1; j++)
			{
				users[j] = users[j + 1];
			}
		    usersCount = usersCount - 1;
			break;
		}
	}
}
ostream& operator<<(ostream& output, UserList& userList)
{
	for (int i = 0; i < userList.usersCount; i++)
	{
		 output << userList.users[i];
	}
	return output;
}
UserList::~UserList()
{
	delete[] users;
}
