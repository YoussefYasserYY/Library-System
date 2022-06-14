#include<cstring>
#include<iostream>
#include"users.h"
#include"books.h"
#include"UserList.h"
#include"BookList.h"

using namespace std;
// This program uses the "users" , "books" , "UserList" and "BookList" files. 
// The program is written by Kareem Ayman and Sandra Nabil
// The main function of the program is to store data of people and books from a user and then match them together and/or rate them 
int main()
{
    int i = 0;
    int ucounter = 0;
    int bcounter = 0;
    int booksnumber = 0;
    int usernumber = 0;
   UserList UL;
   BookList BL;
    while ( i != 3)
    { 
        //This is The Main menu
        cout << "Select one of the following choices:\n" << "1- Books Menu \n" << "2- User menu\n" << "3- exit\n";
        cin >> i;
        if (bcounter == 0)
        {
            if (i == 1)
            {
                cout << "how many books will be added\n";
                cin >> booksnumber;
                BL.setcapacity(booksnumber);
            }
        }
        if (ucounter == 0)
        {
            if (i == 2)
            {
                cout << "How many users will be added\n";
                cin >> usernumber;
                UL.setcapacity(usernumber);
            }
        }
        
        switch (i)
        {
        case 1: //Books Menu
        {
            while (i != 7)
            {
                // This is the Books menu 
                cout << "Books menu\n" << "1- Create a BOOK and add it to the list\n" << "2- Search for a book\n" << "3- Display all books(with book rating)\n"
                    << "4- get the highest rating book\n" << "5- get all books of a user\n" << "6- copy the current book list to a new Book List and swtich to it\n"
                    << "7- Back to the menu\n";
                cin >> i;
                switch (i)
                {
                case 1:   // Create a Book
                {
                    if (bcounter < booksnumber)
                    {
                        Book::Cout();
                        Book b1;
                        cin >> b1;
                        BL.addBook(b1);
                        bcounter++;
                        while (i == 1)
                        {
                            cout << "1- Assign author\n" << "2- Continue\n";
                            cin >> i;
                            switch (i)
                            {
                            case 1: //assign author
                            {
                                int id;
                                cout << "enter user ID\n";
                                cin >> id;
                                if (id <= Book::count && id > 0)
                                {
                                    BL.searchBook(bcounter).setAuthor(UL.searchUser(id));
                                    i = 2;
                                    break;
                                }
                                else //if the ID is unavailable 
                                {
                                    cout << "error user with ID "<< id << " not found\n";
                                    break;
                                }
                            }
                            }
                        }

                    }
                    else { cout << "out of Books capacity\n"; };
                    break;
                }
                case 2:   // Search for a book
                {
                    while (i != 3)
                    {
                        cout << "SEARCH OF A Book\n" << "1- search by Name\n" << "2- search by ID\n" << "3- return to users menu\n";
                        cin >> i;
                        switch (i)
                        {
                        case 1: // by name
                        {
                            string name;
                            cout << "enter Name\n";
                            cin >> name;
                            cout << BL.searchBook(name);
                            if (BL.searchBook(name).getAuthor().getName() != " ")
                            {
                                cout << "Author name: " << BL.searchBook(name).getAuthor().getName() << endl << "\n"; 
                            }
                            while (i != 6)
                            {
                                cout << "1- Update author\n" << "2- Update name\n" << "3- Update category\n" << "4- delete Book\n" << "5- Rate book\n" << "6- Get back to Book menu\n";
                                cin >> i;
                                switch (i)
                                {
                                case 1: //update author
                                {
                                    int newauthorid;
                                    cout << "enter new author\n";
                                    cin >> newauthorid;
                                    if (newauthorid <= User::count && newauthorid>0)
                                    {
                                        BL.searchBook(name).setAuthor(UL.searchUser(newauthorid));
                                        break;
                                    }
                                    else
                                    {
                                        cout << "error user with ID " << newauthorid << " not found\n";
                                        break;
                                    }
                                }
                                case 2:// update name
                                {
                                    string newname;
                                    cout << "enter new name\n";
                                    cin >> newname;
                                    BL.searchBook(name).setTitle(newname);
                                    cout << "You have changed the name\n";
                                    name = newname;
                                    break;
                                }
                                case 3: //update category
                                {
                                    string newcategory;
                                    cout << "enter new category\n";
                                    cin >> newcategory;
                                    BL.searchBook(name).setCategory(newcategory);
                                    break;
                                }
                                case 4: //delete book
                                {
                                    BL.deleteBook(BL.searchBook(name).getId());
                                    cout << "done\n";
                                    bcounter--;
                                    i = 6;
                                    break;
                                }
                                case 5: // add rating
                                {
                                    int rating;
                                    cout << "enter your rating\n";
                                    cin >> rating;
                                    BL.searchBook(name).rateBook(rating);
                                    break;
                                }
                                }
                            }
                            break;
                        }
                        case 2: // using ID
                        {
                            int ID;
                            cout << "enter ID\n";
                            cin >> ID;
                            if (ID <= Book::count && ID>0)
                            {
                               cout << BL.searchBook(ID);
                               if (BL.searchBook(ID).getAuthor().getName() != " ")
                               {
                                   cout << "Author name: " << BL.searchBook(ID).getAuthor().getName() << endl << "\n";
                               }
                                while (i != 6)
                                {
                                    cout << "1- Update author\n" << "2- Update name\n" << "3- Update category\n" << "4- delete Book\n" << "5- Rate book\n" << "6- Get back to Book menu\n";
                                    cin >> i;
                                    switch (i)
                                    {
                                    case 1: // update author
                                    {
                                        int newauthorid;
                                        cout << "enter new author\n";
                                        cin >> newauthorid;
                                        if (newauthorid <= User::count && newauthorid>0)
                                        {
                                            BL.searchBook(ID).setAuthor(UL.searchUser(newauthorid));
                                            break;
                                        }
                                        else
                                        {
                                            cout << "error user with ID " << newauthorid << " not found\n";
                                            break;
                                        }
                                    }
                                    case 2: //update name
                                    {
                                        string newname;
                                        cout << "enter new name\n";
                                        cin >> newname;
                                        BL.searchBook(ID).setTitle(newname);
                                        break;
                                    }
                                    case 3: // update category
                                    {
                                        string newcategory;
                                        cout << "enter new category\n";
                                        cin >> newcategory;
                                        BL.searchBook(ID).setCategory(newcategory);
                                        break;
                                    }
                                    case 4: //delete book
                                    {
                                        BL.deleteBook(BL.searchBook(ID).getId());
                                        cout << "done\n";
                                        bcounter--;
                                        i = 6;
                                        break;
                                    }
                                    case 5: //add rating
                                    {
                                        int rating;
                                        cout << "enter your rating\n";
                                        cin >> rating;
                                        BL.searchBook(ID).rateBook(rating);
                                        break;
                                    }
                                    }
                                }
                            }
                            else
                            {
                                cout << "Book not found\n";
                            }
                        }
                        }
                        break;
                    }
                    break;
                }
                case 3:   // Display all books
                {
                    cout << BL;
                    break;
                }
                case 4:  // Get the highest rating book
                {
                    cout << BL.getTheHighestRatedBook();
                    if (BL.getTheHighestRatedBook().getAuthor().getName() != " ")
                    {
                        cout << "===== Author info ======= " << endl;
                        cout << "Name: " << BL.getTheHighestRatedBook().getAuthor().getName() << "\nAge: " << BL.getTheHighestRatedBook().getAuthor().getAge() << "\nID: "
                               << BL.getTheHighestRatedBook().getAuthor().getId()<< "\nEmail: " << BL.getTheHighestRatedBook().getAuthor().getEmail() << "\n";
                        cout << "=========================================="<<endl<<"\n";

                    }
                    break;
                }
                case 5:  // get all books of a user
                {
                    int i=0;
                    while (i==0)
                    {
                    int userid;
                    cout << "Enter user's ID\n";
                    cin >> userid;
                        if (userid <= User::count && userid > 0)
                        {
                            BL.getBooksForUser(UL.searchUser(userid));
                            i=1;
                        }
                        else // if the ID is unavailable
                        {
                            cout << "User not found \n";
                        }
                    }
                    break;
                }
                case 6: // Copy booklist list to a new Booklist
                {
                    BookList BL2(booksnumber);
                    for (int i = 0; i < booksnumber; i++)
                    {
                        BL2[i] = BL[i];
                    }
                    cout << "copied current list (" << bcounter << " users) to a new list and switched to it\n";
                    break;
                }
                case 7: // Exit
                {
                    cout << "==========================================\n";
                    break;
                }
                }
            }
           break;
        }
        case 2: //users Menu
        {
            while (i != 4)
            {
                // This is the users menu
                cout << "User menu\n" << "1- Create a USER and add it to the list\n" << "2- Search for a user\n" << "3- Display all users\n" << "4- Back to the menu\n";
                cin >> i;
                switch (i)
                {
                case 1:  // Create a USER
                { 
                    if (ucounter < usernumber)
                    {
                        User::Cout();
                        User s1;
                        cin >> s1;
                        UL.addUser(s1);
                        ucounter++;
                    }
                    else { cout << "out of users capacity\n"; };
                    break;
                }
                case 2:  // Search for a USER
                {   
                    
                    while (i != 3)
                    {
                        cout << "SEARCH OF A USER\n" << "1- search by Name\n" << "2- search by ID\n" << "3- return to users menu\n";
                        cin >> i;
                        switch (i)
                        {
                        case 1: // Search by Name
                        {
                            string name;
                            cout << "enter Name\n";
                            cin >> name;
                            cout << UL.searchUser(name);
                            cout << "1- delete user\n" << "2- return to Users menu\n";
                            cin >> i;
                            switch (i)
                        case 1: // Delete User
                            {
                                UL.deleteUser(UL.searchUser(name).getId());
                                cout << "User deleted\n";
                                ucounter--;
                                break;
                            }
                            break;
                        } 
                        case 2: // Search by ID 
                        {
                            int ID;
                            cout << "enter ID\n";
                            cin >> ID;
                            if (ID <= User::count && ID > 0)
                            {
                                cout << UL.searchUser(ID);
                                cout << "1- delete user\n" << "2- return to Users menu\n";
                                cin >> i;
                                switch (i)
                                {
                                case 1:
                                {
                                    UL.deleteUser(UL.searchUser(ID).getId());
                                    cout << "User deleted\n";
                                    ucounter--;
                                    break;
                                }
                                break;
                                }
                            }
                            else
                            {
                                cout << "User not found\n";
                            }
                        }
                        }
                    }
                    break;
                }
                case 3 : // Display all Users
                {
                    cout << UL;
                    break;
                }
                case 4:  // Back to main menu
                {
                    cout << "==========================================\n";
                    break;
                }
                }
            }
            break;
        }
        case 3: //EXIT  
        {
            // the BookList destractor and UserList destractor will be called here
            break;
            return 0;
        }
        }
    }
};
