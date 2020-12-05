#include <iostream>
#include <string.h>
#define N 50

using namespace std;

class book{ // БАЗОВЫЙ класс book
	char name[40];
	char author[40];
public:
	book(char*, char*);
	book() {};
	~book() {};
	void see();
	void setName(char*s1); 
	void setAuthor(char*s2);
	char* getName();
	char* getAuthor();
};

class section : public book{ // ПРОИЗВОДНЫЙ класс
	char sect[40];
public:
	section(char*, char*, char*);
	section() {};
	~section() {};
	void see();
	void setSect(char*s3);
	char* getSect();
};

class library :public section {
	char libr[10];
public:
	library(char*, char*, char*, char*);
	library() {};
	~library() {};
	void see();
	void setLibr(char*s3);
	char* getLibr();
};

book::book(char* s1, char* s2){
	strcpy_s(name, s1);
	strcpy_s(author, s2);
}

void book::setName(char*s1) {
	cout << "Input the name of the book: ";
	cin >> s1;
	strcpy_s(name, s1);
}

void book::setAuthor(char*s2) {
	cout << "Input the author of the book: ";
	cin >> s2;
	strcpy_s(author, s2);
}

char* book::getName() {
	return name;
}

char* book::getAuthor() {
	return author;
}

void section::setSect(char*s3) {
	cout << "Input section: ";
	cin >> s3;
	strcpy_s(sect, s3);
}

char* section::getSect() {
	return sect;
}

void library::setLibr(char*s4) {
	cout << "Input library: ";
	cin >> s4;
	strcpy_s(libr, s4);
}

char* library::getLibr() {
	return libr;
}

void book::see(){
	cout << "Name of the book: " << name << endl;
	cout << "Author of the book: " << author << endl;
}

section::section(char* s1, char* s2, char* s3) : book(s1, s2){
	strcpy_s(sect, s3);
}

void section::see(){
	char* name=getName();
	char* author = getAuthor();
	char* sect = getSect();
	cout << "Name of the book: " << name << endl;
	cout << "Author of the book: " << author << endl;
	cout << "Section: " << sect << endl;
}

library::library(char* s1, char* s2, char* s3, char* s4) :section(s1, s2, s3) {
	strcpy_s(libr, s4);
}

void library::see() {
	char* name = getName();
	char* author = getAuthor();
	char* sect = getSect();
	char* libr = getLibr();
	cout << "Name of the book: " << name << endl;
	cout << "Author of the book: " << author<< endl;
	cout << "Section: " << sect << endl;
	cout << "Library: " << libr << endl << endl;
}

int main(){
	int choice, number_of_book = 0, deleted_number;
	char name[20];
	char author[20];
	char sect[20];
	char libr[20];
	library s[N];
	do {
		cout << "1. Add a book" << endl;
		cout << "2. Delete a book" << endl;
		cout << "3. See" << endl;
		cout << "0. Exit" << endl;
		cin >> choice;
		if (choice == 1) {
			s[number_of_book].setName(name);
			s[number_of_book].setAuthor(author);
			s[number_of_book].setLibr(libr);
			s[number_of_book].setSect(sect);
			cout << endl;
			number_of_book++;
		}
		else if (choice == 2) {
			cout << "Input the deleted book: ";
				cin >> deleted_number;
				deleted_number--;
			if (deleted_number >= number_of_book)
				cout << "Error! Incorrect input!" << endl;
			else{
				for (int i = deleted_number; i < number_of_book-1; i++) { //удаление элемента массива 
					s[i] = s[i + 1];
				}
				number_of_book--;
			}
		}
		if (choice == 3) {
			for (int i = 0; i < number_of_book; i++) {
				s[i].see(); //вызов функци see для элемента массива s
			}
		}
		if (choice == 0)
			break;
		else if (choice < 0 || choice > 3) //обработка ввода не правuльных значений
			cout << "Error! Incorrect input!" << endl;
	} while (choice != 0);
	return 0;
}
