// this was created after .h

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "book.h"
#include <string.h>
#include <stdlib.h>

P_BOOK createBook(double ISBN, char bookAuthor[], char bookTitle[], int volumeNumber) {

	P_BOOK newBook = (P_BOOK)malloc(sizeof(BOOK)); // holding this in the heap
	//(pointer of books) (variable newbook) = (struct of Pointerbooks)(malloc-returns void pointer)(size of books array)
	newBook->ISBN = ISBN;
	strcpy(newBook->bookAuthor, bookAuthor);
	strcpy(newBook->bookTitle, bookTitle);
	newBook->volumeNumber = volumeNumber;

	newBook->next = NULL;
	newBook->prev = NULL;

	return newBook;

}

P_BOOK removeBook(P_BOOK bookList, char bookTitle[]) {

	P_BOOK bookToRemove = searchTitle(bookList, bookTitle);

	if (bookToRemove == NULL) {
		return bookList;
	}

	if (bookToRemove->prev == NULL) {
		bookList = bookList->next;
		bookList->prev = NULL;
	}
	else {
		bookToRemove->prev->next = bookToRemove->next;
		bookToRemove->next->prev = bookToRemove->prev;
	}
	free(bookToRemove);

	return bookList;
}

P_BOOK updateList(P_BOOK bookList, P_BOOK nextBook) { // pointing to an empty list

	if (bookList == NULL) { // have one book?
		bookList = nextBook;
	}
	else {
		P_BOOK currentBook = bookList;
		P_BOOK prevBook = bookList->prev;
		while (currentBook->next != NULL) {
			currentBook = currentBook->next;
		}
		prevBook = currentBook;
		currentBook->next = nextBook;
		nextBook->prev = prevBook;
	}

	return bookList;
}

P_BOOK searchTitle(P_BOOK listOfBooks, char bookTitle[])
{
	if (listOfBooks == NULL) { // have one book?
		return NULL;
	}
	if (listOfBooks->next == NULL) { // have only one book? ( next book is not there- so cant search for name)
		if (strcmp(listOfBooks->bookTitle, bookTitle) == 1) { // is the one book the one we want

			return listOfBooks;
		}
		else {
			return NULL;

		}
	}

	P_BOOK currentBook = listOfBooks;
	while (currentBook->next != NULL) {
		if (!strcmp(currentBook->bookTitle, bookTitle)) {

			return currentBook;
		}
		else {
			currentBook = currentBook->next;
			// list of books = list of book->next;
		}

	}

	return NULL;

}

void saveFile(P_BOOK listofBooks) {
	FILE* fp;

	fp = fopen("BookList_File-TN.txt", "w+");
	P_BOOK currentBook = listofBooks;

	while (currentBook->next != NULL) {

		fprintf(fp, "%d\n", currentBook->ISBN);
		fprintf(fp, "%s\n", currentBook->bookAuthor);
		fprintf(fp, "%s\n", currentBook->bookTitle);
		fprintf(fp, "%d\n", currentBook->volumeNumber);

		currentBook = currentBook->next;
	}

	fclose(fp);
}

void readFile(P_BOOK listofBooks) {
	FILE* fp;

	fp = fopen("BookList_File-TN.txt", "w+");
	char tempISBN[MAXLEN];
	char tempBookAuthor[MAXLEN];
	char tempBookTitle[MAXLEN];
	char tempVolume[MAXLEN];
	P_BOOK tempBook;

	P_BOOK currentBook = listofBooks;

	for (int i = 0; i < 3; i++) {

		fgets(tempISBN, MAXLEN, fp);
		fgets(tempBookAuthor, MAXLEN, fp);
		fgets(tempBookTitle, MAXLEN, fp);
		fgets(tempVolume, MAXLEN, fp);

		tempBook = createBook((double)tempISBN, tempBookAuthor, tempBookTitle, (int)tempVolume);
		listofBooks = updateList(listofBooks, tempBook);
	}

	fclose(fp);

}