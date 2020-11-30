#include <iostream>
#include <string.h>
#define N 50

using namespace std;

class book{ // БАЗОВЫЙ класс book
protected:
	char name[40];
	char author[40];
public:
	book(char*, char*);
	book() {};
	~book() {};
	void see();
	//void setName(char* s1); void setAuthor(char* s2);
};

class section : public book{ // ПРОИЗВОДНЫЙ класс
protected:
	char sect[40];
public:
	section(char*, char*, char*);
	section() {};
	~section() {};
	void see();
};

class library :public section {
	char libr[10];
public:
	library(char*, char*, char*, char*);
	library() {};
	~library() {};
	void see();
};

book::book(char* s1, char* s2){
	strcpy_s(name, s1);
	strcpy_s(author, s2);
}

void book::see(){
	cout << "Name of the book: " << name << endl;
	cout << "Author of the book: " << author << endl;
}

section::section(char* s1, char* s2, char* s3) : book(s1, s2){
	strcpy_s(sect, s3);
}

void section::see(){
	cout << "Name of the book: " << name << endl;
	cout << "Author of the book: " << author << endl;
	cout << "Section: " << sect << endl;
}

library::library(char* s1, char* s2, char* s3, char* s4) :section(s1, s2, s3) {
	strcpy_s(libr, s4);
}

void library::see() {
	cout << "Name of the book: " << name << endl;
	cout << "Author of the book: " << author << endl;
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
			cout << "Input the name of the book: ";
			cin >> name;
			cout << "Input the author of the book: ";
			cin >> author;
			cout << "Input the section: ";
			cin >> sect;
			cout << "Input the library: ";
			cin >> libr;
			cout << endl;
			library s1(name, author, sect, libr); //создание объекта класса section 
			s[number_of_book] = s1;
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
		else if (choice < 0 || choice > 3) //обработка ввода не правельных значений
			cout << "Error! Incorrect input!" << endl;
	} while (choice != 0);
	return 0;
}