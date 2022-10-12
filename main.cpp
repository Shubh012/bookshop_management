#include<iostream> 
#include<stdlib.h>
#include<conio.h>
#include<string>
#include"book.h"
using namespace std;

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
	for(int i=0;i<=count;i++){
		books[i].addBook(count);
	}
	 
}		
else if(choice=="2"){	
	for(int i=0;i<=count;i++){
	books[i].deleteBook(count); 
	}
}
else if(choice=="3"){
	for(int i=0;i<=count;i++){
	books[i].editBook(count); 
	}

}
else if(choice=="4"){
	for(int i=0;i<=count;i++){
		books[i].searchBook(count); 
	}	
}
else if(choice=="5"){
	for(int i=0;i<=count;i++){
		books[i].viewAllBooks(count); 
	}
		
}
else if(choice=="6"){
	exit(0);	 
}
else{
	main();  
}
_getch();
return 0;
}

//addBook function
void Book::addBook(int count){
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
		increment(count);
		cout<<"\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	else{
		cout<<"The maximum amount of books have reached"<<endl;
		_getch();
		main();
		}
	}


//deleteBook function
void Book::deleteBook(int count){
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
		if(books[i].isbn==isbn){
			cout<<"\nBOOK FOUND\n\n";
			cout<<"Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
			cin>>choice;
			if(choice==1){
				books[i].isbn; 
				books[i].title;
				books[i].author;
				books[i].edition;
				books[i].publication;
				for(int a=i;a<count;a++){
					books[a] = books[a+1];
				}
				books[9].isbn; 
				books[9].title;
				books[9].author;
				books[9].edition;
				books[9].publication;
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
void Book::editBook(int count){
	system("CLS");
	string editIsbn,choice;
	cout<<"\nEDIT BOOK\n\n";
	if(count==0){
		cout<<"THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter ISBN: ";
	getline(cin,editIsbn);
	for(int i=0;i<count;i++){
		if(books[i].isbn==editIsbn){
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"ISBN: "<<books[i].isbn<<endl;
			cout<<"TITLE: "<<books[i].title<<endl;
			cout<<"AUTHOR: "<<books[i].author<<endl;
			cout<<"EDITION: "<<books[i].edition<<endl;
			cout<<"PUBLICATION: "<<books[i].publication<<endl;
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
void Book::searchBook(int count){
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
		if(books[i].isbn==isbn){ 
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"ISBN: "<<books[i].isbn<<endl;
			cout<<"TITLE: "<<books[i].title<<endl;
			cout<<"AUTHOR: "<<books[i].author<<endl;
			cout<<"EDITION: "<<books[i].edition<<endl;
			cout<<"PUBLICATION: "<<books[i].publication<<endl;
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
void Book::viewAllBooks(int count){
	cout<<"VIEW ALL BOOKS\n\n";
	if(count==0){
		cout<<"THERE IS NO BOOK TO DISPLAY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	for(int i=0;i<count;i++){
		cout<<"BOOK DETAILS\n\n";
		cout<<"ISBN: "<<books[i].isbn<<endl;
		cout<<"TITLE: "<<books[i].title<<endl;
		cout<<"AUTHOR: "<<books[i].author<<endl;
		cout<<"EDITION: "<<books[i].edition<<endl;
		cout<<"PUBLICATION: "<<books[i].publication<<endl<<endl;
	}
	cout<<"Press any key to continue . . .";
	_getch();
	main();
}
void quit(){
	_exit(1);
}
