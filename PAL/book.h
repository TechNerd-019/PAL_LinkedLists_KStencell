#pragma once
// started at books

#define MAXLEN 25

typedef struct book {
	int ISBN;
	char bookAuthor[MAXLEN];
	char bookTitle[MAXLEN];
	int volumeNumber;

	struct book* next; // linked list to struct of book
	struct book* prev;

} BOOK, * P_BOOK; // type def the pointer to books into *P_BOOKS

P_BOOK createBook(double, char[], char[], int);
P_BOOK removeBook(P_BOOK, char[]);
P_BOOK updateList(P_BOOK, P_BOOK);
P_BOOK searchTitle(P_BOOK lisitOfBooks, char bookTitle[]);
void saveFile(P_BOOK listofBooks);
void readFile(P_BOOK listofBooks);
