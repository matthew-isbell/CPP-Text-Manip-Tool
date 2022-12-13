#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include "classes.cpp"

using namespace std;

int main() {

	document();
}

/*
	word counting routine


	first i will have to create a "document" class which stores the words
	of the file that is input. this will also organize all operations
	that will be going on. 

	[DONE]
		the constructors of this class will read all of the words in,
		but it will also store the redundant words too.


	[DONE]
		helper function that will convert all the words to lowercase

	[DONE]
		helper function that removes all stop words. 
		some stop words are (a, the, not, etc)

	[DONE]
		helper function that removes punctuation and numbers
		look at chapter 23 for regex
		remove punct. and nums. of both regular and stop words

*/

/*	
	[DONE]
		in another class, store all words and the counts of words
		this can be done by using a wrapper for the map container (idk)
		i need other stuff though:

	[DONE]
		should display a list of words in alphabetical order, followed
		by the counts
		
	[DONE]
		sum total number of words in a document, and the number of stop 
		words removed too
*/

/*
	in a class titled n-gram, register what n-grams are i guess
*/

/*
	make a driver that tests everything
*/