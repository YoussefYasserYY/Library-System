#ifndef BookList_H
#define BookList_H
#include"users.h"
#include"books.h"

class BookList
{
 private:
    Book* books;
    int capacity;
    int booksCount = 0;
    double temprating = 0;          // used in the gettheHighestRatedBook function
public:
    BookList();
	BookList(const BookList& anotherList);  // a Copy Constractor 
    BookList(int);                 
    void setcapacity(int);                 // To limit the number of books
    Book& searchBook(string);             // To search for a Book using the Name
    Book& searchBook(int);               // To search for a Book using the ID
    void addBook(Book);                 // To add Book to the List
    void deleteBook(int);              // Takes a Book ID and deletes this book
    Book getTheHighestRatedBook();    // Get the highest rated book from the list
    Book* getBooksForUser(User);     // Takes an author and print all the Books he wrote
    Book & operator [ ] (int);      // Overloading the [ ] operator
    friend ostream &operator<<( ostream &output, BookList &booklist );  //To Easily output a BookList object
    ~BookList(); // a destractor to free up space
};

#endif//BookList_h