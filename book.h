#include<iostream>
#include<string>
using namespace std;
class Book {
	private:
		string isbn,title,author,edition,publication;
	public:
      void addBook(int no_books);
      void deleteBook(int count);
      void editBook(int count);
      void searchBook(int count);
      void viewAllBooks(int count);
      void quit();

};
