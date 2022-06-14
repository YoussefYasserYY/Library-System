#include"users.h"
#include"books.h"
#include"UserList.h"
#include"BookList.h"
#include<cstring>
#include<iostream>

using namespace std;

BookList::BookList()
{
}

BookList::BookList(int Capacity)
{
	capacity = Capacity;
	books = new Book[capacity];
	Book::count = Book::count - capacity;
}


Book& BookList::searchBook(string name)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getTitle() == name)
		{
			return books[i];
			break;
		};
	}
}
Book& BookList::searchBook(int id)
{
	if (id <= booksCount && id>0)
	{
		for (int i = 0; i < booksCount; i++)
		{
			if (books[i].getId() == id)
			{
				return books[i];
				break;
			};
		}
	}
	else
	{
		cout << "Book not found\n";
	};
}


void BookList::addBook(Book book)
{
	if (booksCount < capacity)
	{
		books[booksCount] = book;
		booksCount++;
	}
}
void BookList:: deleteBook(int id)
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i] == searchBook(id))
		{
			for (int j = i; j < booksCount - 1; j++)
			{
				books[j] = books[j + 1];
			}
			booksCount = booksCount - 1;
			break;
		}
	}
}

void BookList ::setcapacity(int i)
{
	capacity = i;
	books = new Book[capacity];
	Book::count = Book::count - capacity;
}

Book BookList::getTheHighestRatedBook()
{
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getRating() > temprating)
		{
			temprating = books[i].getRating();
		}
	}
	for (int i = 0; i < booksCount; i++)
	{
		if (temprating == books[i].getRating())
		{
			return books[i];
			break;
		}
	}
}

Book& BookList:: operator[ ] (int position)
{
	if (position<0 || position>capacity)
	{
		cout << "error";
	}
	return books[position];
}

Book* BookList:: getBooksForUser(User user)
{
	int b = 0;
	for (int i = 0; i < booksCount; i++)
	{
		if (books[i].getAuthor() == user)
		{
			cout << books[i];
			cout <<"\nAuthor name:" <<books[i].getAuthor().getName()<<"\n";
			cout << "=============================\n";
			b ++ ;
		}
		if ( b == 0 )
		{
			cout << "No Books for this user\n ";
		}
	}
	return books;
}

BookList:: ~BookList()
{
	delete[] books;
}

BookList::BookList(const BookList& anotherList)
{
	capacity = anotherList.capacity;
	books = new Book[capacity];
	booksCount = anotherList.booksCount;
}

ostream& operator<<(ostream& output, BookList& booklist)
{
	for (int i = 0; i < booklist.booksCount; i++)
	{
		output << "========== Book " << booklist.books[i].getId() << " info ===========\n";
		output << "Title: " << booklist.books[i].getTitle() << "\nISBN: " << booklist.books[i].getISBN() << "\nID: " << booklist.books[i].getId() 
			   << "\nCategory: " << booklist.books[i].getCategory() << "\nAvg Rating: " << booklist.books[i].getRating()<<endl;

		if (booklist.books[i].getAuthor().getName() != " ")
		{
			output << "===== Author info ======= " << endl;
			output << "Name: " << booklist.books[i].getAuthor().getName() << "\nAge: " << booklist.books[i].getAuthor().getAge() << "\nID: " << booklist.books[i].getAuthor().getId() 
				   << "\nEmail: " << booklist.books[i].getAuthor().getEmail() <<"\n";
		    output << "=========================================="<<endl<<"\n";
			
		}

	}
	return output;
}