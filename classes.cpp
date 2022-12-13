#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <regex>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

//helper function that only outputs non helper words
void strStop(map<string, int> &mp) {
    string text;
    vector<string> vectorstr;
    string word;
    string in;

    ifstream file("stop.txt");

    //adds stop words to a vector
    while (file >> in) {
        vectorstr.push_back(in);
    }

    file.close();

    //loops through vector and removes stop words
    for (const auto& stop : vectorstr) {

        //erases stop words from map of words
        mp.erase(stop);
    }
}

//member function to convert a string to lowercase
string strLower(string str) {

    //use transform to implement tolower
    transform(str.begin(), str.end(), str.begin(), ::tolower);

return str;
}

//removes all punctuation (except the - used for n-words)
string strNoPunct(string str) {
    
    regex r("[^a-zA-Z- ]"); //only display letters, -, and spaces

    //replace all characters that aren't regex characters empty spaces
    string newstr = regex_replace(str, r, "");

return newstr;
}

//returns the total amount of words
void allCount(const string& filename) {
    int count = 0;
    string word;
    //takes in file name to count
    ifstream file(filename);

    //while the file is adding up words, increment
    while (file >> word) {

        count++;
    }
cout << "There are a total of: " << count << " words";
}

//this class will create n-grams
class nGrams {
    public:
    string word;

    //takes in the document and N
    nGrams(string doc) {

        //reading in the file
        ifstream file(doc);

        //will store the values in a vector, then output them
        vector<string> words;

        while (file >> word) {
            
            //removes caps and punct
            word = strNoPunct(word);
            word = strLower(word);

            //adding text file contents to a vector
            words.push_back(word);
        }

        // Create the 3-grams
        vector<vector<string>> grams;
        for (size_t i = 0; i < words.size() - 2; ++i) {

            //groups three words together, adds to vector
            vector<string> gram = { words[i], words[i+1], words[i+2] };
            grams.push_back(gram);
        }

        // Print the 3-grams to the console
        for (auto gram : grams) {

            //this one actually prints each word
            for (auto word : gram) {
                cout << word << " ";
            }
            cout << "\n";
        }
    }
};

//class that takes in a map, and then outputs everything 
class wordCount {
    public:

    wordCount(map<string, int> &wc) {

        ifstream file("book.txt");

        //sorts them alphabetically, outputs number of times said
        for (const auto& p : wc) {
		    cout << p.first << ": " << p.second << "\n"; 
        }
    }
};

class document {
    public:

    string text;    //used to loop through each indivudual line
    string word;    //used to add each individual word to map

    //reads in a book and adds it to a map
    document() {

        map<string, int> words;	//creating a map to store all words and values

        ifstream file("book.txt");

        while (getline (file, text)) {  //while there is another line to parse...
            
            text = strNoPunct(text);
            text = strLower(text);

            stringstream sstream(text);
        
            while (sstream >> word) {
                strStop(words);

                ++words[word];			//words is subscripted by string
                //  for testing: 
                //  cout << word <<"\n"
            } 
        }
        cout << "\nN-gram will now run: \n";
        nGrams("book.txt");

        //alphabatizes and counts each occurance
        cout << "\nNow is the organized words: \n";
        wordCount w(words);
        allCount("book.txt");
    }
};