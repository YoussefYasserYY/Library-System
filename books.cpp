#include"users.h"
#include"books.h"
#include<cstring>
#include<iostream>

Book::Book()
{
    count++;
    id = count;
}

Book::Book(string Title, string Isbn, string Category)
{
    title = Title;
    isbn = Isbn;
    category = Category;
    count++;
    id = count;
};

Book::Book(const Book& book)  
{
    title = book.title;
    isbn = book.isbn;
    category = book.category;
    author = book.author;
    averageRating = book.averageRating;
    id = book.id;
};

void Book::Cout() {
    if (count == 0)
    {
        cout << "Let's add a book" << endl;
    }
    else
    {
        cout << "Let's add another book" << endl;
    }
    cout << "Enter the book's info in this order" << endl;
    cout << "Title ISBN Category (Space seperated)" << endl;
};
bool Book:: operator==(const Book& book) 
{
    return title == book.title && isbn == book.isbn && category == book.category && author == book.author;
};
void Book::setAuthor(User user)
{
    author = user;
};

void Book::rateBook(int rating)
{
    counter++;
    sum += rating;
    averageRating = sum / counter;
};

ostream& operator<<(ostream& output, const Book& book)
{
    output << "===== Book " << book.id << " info ======= " << endl;
    output << "Title: " << book.title << "\nISBN: " << book.isbn << "\nID: " << book.id << "\nCategory: " << book.category << "\nAvg Rating: " << book.averageRating << endl;

    return output;
}
istream& operator>>(istream& input, Book& book)
{
    input >> book.title >> book.isbn >> book.category;
    return input;
};

int Book::count = 0;