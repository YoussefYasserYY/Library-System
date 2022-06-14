#ifndef books_H
#define books_H
#include"users.h"
#include<cstring>
#include<iostream>

using namespace std;

class Book {
private:
	string title;
	string isbn;
	double sum = 0;                          // To help the average rating function
	int counter = 0;                        //  To help the average rating function
	int id = 0;
	string category;
	User author;
	double averageRating = 0;
public:
	static  int count;
	Book();                                // A defult constractor 
	Book(string, string, string);         //  A constractor with parameters to take title, ISBN, category
	Book(const Book& book);              //  Copy constractor 
	static void Cout();                 // To have control on what to print and when 
	int getCount()                     // To access the static integer
	{
		return count;
	};

	void setTitle(string Title)      
	{
		title = Title;
	}

	string getTitle()
	{
		return title;
	};

	void setISBN(string Isbn)
	{
		isbn = Isbn;
	};

	string getISBN()
	{
		return isbn;
	};

	void setId()          // To store the count
	{
		id = getCount();
	};

	int getId()
	{
		return id;
	};

	void setCategory(string Category)
	{
		category = Category;
	};

	double getRating()
	{
		return averageRating;
	};

	string getCategory()
	{
		return category;
	};

	void setAuthor(User);    // Take an object that is already created as a parameters and copy the data to author variable
	User getAuthor()
	{
		return author;
	};
	void rateBook(int);  // A function to calculate the average rating 
						// Whenever this function is called a counter is incremented
					   // The sum of the previous rating is divided by the counter

	bool operator==(const Book& book);                                 // Overloading the == operator 
	                                                                  // The function compares the Title, ISBN, Category, and Author
	friend ostream& operator<<(ostream& output, const Book& book);   // Easily output an object (book)
	friend istream& operator >>(istream& input, Book& book);        // Easily input values to an object (book)
};
#endif//books_h
