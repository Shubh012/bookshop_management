#include<iostream> 
#include<conio.h>
#include<string>
#include"book_class.h"
using namespace std;

void addBook(int count);
void deleteBook(int count);
void editBook(int count);
void searchBook(int count);
void viewAllBooks(int count);
void quit();


int count=0;

void increment(int a){
	a++;
	count=a;
}

void decrement(int a){
	a--;
	count=a;
}

Book books[10];//Array of objects for Book class

int main(){
string choice;
int no_books;
system("CLS");
cout<<"BOOKSHOP MANAGEMENT SYSTEM\n\n";
cout<<"[1]ADD BOOK\n";	
cout<<"[2]DELETE BOOK\n";	
cout<<"[3]EDIT BOOK\n";	
cout<<"[4]SEARCH BOOK\n";	
cout<<"[5]VIEW ALL BOOKS\n";	
cout<<"[6]QUIT\n\n";

cout<<"ENTER CHOICE: ";
getline(cin,choice);
system("CLS");

if(choice=="1"){
	addBook(count); 
}		
else if(choice=="2"){	
	deleteBook(count); 
}
else if(choice=="3"){
	editBook(count); 	
}
else if(choice=="4"){
	searchBook(count); 	
}
else if(choice=="5"){
	viewAllBooks(count); 	
}
else if(choice=="6"){
	quit();	 
}
else{
	main();  
}
_getch();
return 0;
}

//addBook function
void addBook(int count){
	string isbn,title,author,edition,publication;
	cout<<"ADD BOOK\n\n";
	if(count<10){
		cout<<"Enter ISBN: ";
		getline(cin,isbn); 
		cout<<"Enter Title: ";
		getline(cin,title);
		cout<<"Enter Author: ";
		getline(cin,author);
		cout<<"Enter Edition: ";
		getline(cin,edition);
		cout<<"Enter Publication: ";
		getline(cin,publication);
		books[count].setIsbn(isbn); 
		books[count].setTitle(title);
		books[count].setAuthor(author);
		books[count].setEdition(edition);
		books[count].setPublication(publication);	
		increment(count);
		cout<<"\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	else{
		cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
}

//deleteBook function
void deleteBook(int count){
	string isbn;
	int choice;
	cout<<"DELETE BOOK\n\n";
	if(count==0){
		cout<<"THERE IS NO BOOK TO DELETE!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter ISBN: ";
	getline(cin,isbn);

	for(int i=0;i<count;i++){
		if(books[i].getIsbn()==isbn){
			cout<<"\nBOOK FOUND\n\n";
			cout<<"Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
			cin>>choice;
			if(choice==1){
				books[i].setIsbn(""); 
				books[i].setTitle("");
				books[i].setAuthor("");
				books[i].setEdition("");
				books[i].setPublication("");
				for(int a=i;a<count;a++){
					books[a] = books[a+1];
				}
				books[9].setIsbn(""); 
				books[9].setTitle("");
				books[9].setAuthor("");
				books[9].setEdition("");
				books[9].setPublication("");
				decrement(count); 
				cout<<"\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
				_getch();
				main();
			}
			else{
				main();
			}
		}
	}
	cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
	
}
void editBook(int count){
	system("CLS");
	string editIsbn,choice;
	string isbn,title,author,edition,publication;
	cout<<"\nEDIT BOOK\n\n";
	if(count==0){
		cout<<"THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter ISBN: ";
	getline(cin,editIsbn);
	for(int i=0;i<count;i++){
		if(books[i].getIsbn()==editIsbn){
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"ISBN: "<<books[i].getIsbn()<<endl;
			cout<<"TITLE: "<<books[i].getTitle()<<endl;
			cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
			cout<<"EDITION: "<<books[i].getEdition()<<endl;
			cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
			cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
			getline(cin,choice);
			if(choice=="1"){
				cout<<"Enter ISBN: ";
				getline(cin,isbn);
				cout<<"Enter Title: ";
				getline(cin,title);
				cout<<"Enter Author: ";
				getline(cin,author);
				cout<<"Enter Edition: ";
				getline(cin,edition);
				cout<<"Enter Publication: ";
				getline(cin,publication);
				books[i].setIsbn(isbn);
				books[i].setTitle(title);
				books[i].setAuthor(author);
				books[i].setEdition(edition);
				books[i].setPublication(publication);	
				cout<<"\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
				_getch();
				editBook(count);
			}
			else{
				main();
			}			
		}
}
	cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
}
void searchBook(int count){
	string isbn;
	int choice;
	bool print = false; 
	cout<<"SEARCH BOOK\n\n";
	if(count==0){
		cout<<"THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter ISBN: ";
	getline(cin,isbn);
	for(int i=0;i<count;i++){
		if(books[i].getIsbn()==isbn){ 
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"ISBN: "<<books[i].getIsbn()<<endl;
			cout<<"TITLE: "<<books[i].getTitle()<<endl;
			cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
			cout<<"EDITION: "<<books[i].getEdition()<<endl;
			cout<<"PUBLICATION: "<<books[i].getPublication()<<endl;
			print = true;
		}
	}
	if(print){
		cout<<"\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	else{
		cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
		_getch();
		main();		
	}
}
void viewAllBooks(int count){
	cout<<"VIEW ALL BOOKS\n\n";
	if(count==0){
		cout<<"THERE IS NO BOOK TO DISPLAY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	for(int i=0;i<count;i++){
		cout<<"BOOK DETAILS\n\n";
		cout<<"ISBN: "<<books[i].getIsbn()<<endl;
		cout<<"TITLE: "<<books[i].getTitle()<<endl;
		cout<<"AUTHOR: "<<books[i].getAuthor()<<endl;
		cout<<"EDITION: "<<books[i].getEdition()<<endl;
		cout<<"PUBLICATION: "<<books[i].getPublication()<<endl<<endl;
	}
	cout<<"Press any key to continue . . .";
	_getch();
	main();
}
void quit(){
	_exit(1);
}
