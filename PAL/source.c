///library needs  system to keep track of books
///search  for specific book and find info about book
/// add or remove book
/// 
/// 
/// linked list trial
/// 

#include <stdio.h>
#include "book.h"
#include <string.h>
#include <stdlib.h>

/// 
int main() {
	

	P_BOOK bookList = NULL; // list of books empty 
	readFile(bookList);

	/*P_BOOK book1 = createBook(1, "author 1", "random title one", 32);
	bookList = updateList(bookList, book1);
	P_BOOK book2 = createBook(2, "author 2", "random title two", 42);
	bookList = updateList(bookList, book2);
	P_BOOK book3 = createBook(3, "author 3", "random title three", 35);
	bookList = updateList(bookList, book3);*/

	saveFile(bookList);

	/*bookList = removeBook(bookList, "random title one");


	P_BOOK searchResult = searchTitle(bookList, "random title two");

	P_BOOK booklist = removeBook(bookList, "random title one");*/

	return 0;
}