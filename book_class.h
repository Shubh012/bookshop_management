#include<iostream>
#include<string>
using namespace std;
class Book {
	private:
		string isbn,title,author,edition,publication; //private variables
	public:
		//setters - assigning user value to private variables
		void setIsbn(string a){
            isbn = a;
            }
		void setTitle(string b){
            title = b;
            }
		void setAuthor(string c){
            author = c;
            }
		void setEdition(string d){
            edition = d;
            }
		void setPublication(string e){
            publication = e;
            }
		//getters - getting the values from private variables
		string getIsbn(){
            return isbn;
            }
		string getTitle(){
            return title;
            }
		string getAuthor(){
            return author;
            }
		string getEdition(){
            return edition;
            }
		string getPublication(){
            return publication;
            }

};
