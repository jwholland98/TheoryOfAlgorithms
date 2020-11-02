/*******************************************************************************************
 Filename: ass3C.cpp                                  
 Assignment No: 3                                       
 File Description: Completes the 4th step for Assignment 3. Parses "Pride and Prejudice.txt"
 and puts the words into a hashtable. Contains functions that show the 150 most and least
 frequent words using heap sort, shows the numbers of sentences, and shows the count of
 any given word. Results and possible implementations were discussed with Matthew Behnke
 and Kimlong Seng. Code for heap sort was implemented from geeksforgeeks:
 https://www.geeksforgeeks.org/heap-sort/
                                                                  
 Date Last Modified: 10/30/2020

I declare that all material in this assessment task is my work except where there
is clear acknowledgement or reference to the work of others. I further declare that I
have complied and agreed to the CMU Academic Integrity Policy at the University
website.
http://www.coloradomesa.edu/student-services/documents
Submissions that do not include the above academic integrity statements will not be
considered.
Student Name: Jesse Holland UID: 700445452 Date: October 30, 2020
*******************************************************************************************/

/*******************************************************************************************
 a.) 81.6%  - Time taken in clock ticks: 46875
              Time taken in seconds: 0
     90.6%  - Time taken in clock ticks: 31250
              Time taken in seconds: 0
     70.2%  - Time taken in clock ticks: 31325
              Time taken in seconds: 0

     According to the value's seen, I should choose something around 85%-95% or 65%-75%.
     However, I question the validity of the answer, as with several runs of the program,
     I get different values. After several runs, I got 81.6% to print exactly 31250
     clock ticks. Regardless, the time difference is miniscule and as such, 70.2% will
     be chosen for no other reason than I feel like it.

 b.) You use an array of linked lists. Using this implementation, you can use any number
     of chains necessary but still use a fixed number of indices in the table. This also
     allows for the adjusting of the occupancy ratio or load factor.

 c.) My hash function mods each individual character by the size of the array after the
     character is converted to its ascii value and multiplied by the previous character's
     result and a constant prime number.

 d.) I implemented chaining into my hashtable. If a collision occurs, then it checks if
     the word is already in that location and increments the count if so. If the word is
     not found, a new link in the linked list is created at the back of the linked list
     for that word.

 e.) No, you do not need an interface file. While one could certainly be used, to say it
     is needed is not true. I can say this confidently, as I did not use one.
 
 f.) showCount() method in the hashtable class

 g.) showBottom150()

 h.) showTop150()

 i.) showNumSent()

*******************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <chrono>
#include <time.h>
#include "hashtable.cpp"

using namespace std;
using namespace std::chrono;

int numSent = 0; //number of sentences

//cleans each word; removes punctuation and increments the number of sentences accordingly
string clean(string word){
    while(ispunct(word[0]))
        word.erase(0, 1);
    while(ispunct(word.back())){
        if(word.back() == '.' || word.back() == '!' || word.back() == '?'){
            if(word == "mr." || word == "mrs.")
                break;
            else{
                numSent++;
                word.pop_back();
            }
        }
        else
            word.pop_back();
    }
    return word;
}

//parses "Pride and Prejudice.txt" and inserts the words into hashtable
void parseText(Hashtable &hashtable){
    ifstream text;
    text.open("Pride and Prejudice.txt");
    string word;
    getline(text, word);
    while(word != "By Jane Austen"){//discards everything before chapter 1
        getline(text, word);
        word.pop_back();
    }
    while(text >> ws >> word){
        if(word == "End")//check for end of actual text
            break;
        for(int i=0;i<word.length();i++){
            word[i] = tolower(word[i]);
            if(i != 0 && i != word.length()-1 && word[i] == '-' && word[i+1] == '-'){//check for "--"
                string subword = word.substr(0, i);
                subword = clean(subword);
                if(subword != "")//prevents empty strings that were all punctuation from being added
                    hashtable.newElement(subword);
                word.erase(0, i);
                i=-1;
            }
        }
        word = clean(word);
        if(word != "")//prevents empty strings that were all punctuation from being added
            hashtable.newElement(word);
    }
}

//takes in array of contents(words and their counts) and
//swaps the ith node with left or right index if either is larger
//modified from geeksfogeeks code found at: 
//https://www.geeksforgeeks.org/heap-sort/
void heapifyMin(content arr[], int n, int i){
    int largest = i;    //set largest to first element
    int l = 2*i + 1;    //index l = 2*i + 1
    int r = 2*i + 2;    //index r = 2*i + 2

    //if left is larger than current largest, set largest to l
    if(l<n && arr[l].count > arr[largest].count)
        largest = l;

    //if left is larger than current largest, set largest to l
    if(r<n && arr[r].count > arr[largest].count)
        largest = r;

    //if largest is no longer first element
    if(largest != i){
        swap(arr[i], arr[largest]);

        //recursively heapify the subtree
        heapifyMin(arr, n, largest);
    }
}

//takes in array of contents(words and their counts) and
//swaps the ith node with left or right index if either is smaller
//modified from geeksfogeeks code found at: 
//https://www.geeksforgeeks.org/heap-sort/
void heapifyMax(content arr[], int n, int i){
    int smallest = i;    //set smallest to first element
    int l = 2*i + 1;    //index l = 2*i + 1
    int r = 2*i + 2;    //index r = 2*i + 2

    //if left is smaller than current smallest, set smallest to l
    if(l<n && arr[l].count < arr[smallest].count)
        smallest = l;

    //if left is smaller than current smallest, set smallest to l
    if(r<n && arr[r].count < arr[smallest].count)
        smallest = r;

    //if smallest is no longer first element
    if(smallest != i){
        swap(arr[i], arr[smallest]);

        //recursively heapify the subtree
        heapifyMax(arr, n, smallest);
    }
}

//takes in array of contents(words and their counts) and sorts them in
//descending or ascending order based off of the max variable
//modified from geeksfogeeks code found at: 
//https://www.geeksforgeeks.org/heap-sort/
void heapSort(content arr[], int n, bool max=true){
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        if(max)
            heapifyMax(arr, n, i);
        else 
            heapifyMin(arr, n, i);
  
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--){ 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call heapify on the reduced heap 
        if(max)
            heapifyMax(arr, i, 0);
        else 
            heapifyMin(arr, i, 0);
    }
}

//returns the number of sentences
void showNumSent(){
    cout << "Number of sentences: " << numSent << endl << endl;
}

//displays the top 150 most used words in the hashtable
void showTop150(Hashtable &hashtable){
    content* words = hashtable.getAllContent();
    heapSort(words, hashtable.getWordCount());
    cout << "Top 150 most used words:" << endl;
    for(int i=0;i<150;i++){
        cout << i+1 << ".) " << words[i].word << " :: count = " << words[i].count << endl;
    }
    cout << endl;
}

//displays the top 150 least used words in the hashtable
void showBottom150(Hashtable &hashtable){
    content* words = hashtable.getAllContent();
    heapSort(words, hashtable.getWordCount(), false);
    cout << "Top 150 least used words:" << endl;
    for(int i=0;i<150;i++){
        cout << i+1 << ".) " << words[i].word << " :: count = " << words[i].count << endl;
    }
    cout << endl;
} 

int main(){
    clock_t start1, stop1;
    start1 = clock();
    auto start2 = high_resolution_clock::now();
    Hashtable hashtable(9300);
    parseText(hashtable);
    stop1 = clock();
    auto stop2 = high_resolution_clock::now();
    double durationTicks = (double) (stop1 - start1);
    auto durationSec = duration_cast<seconds>(stop2 - start2);
    
    cout << "Time taken in clock ticks: " << durationTicks << endl;
    cout << "Time taken in seconds: " << durationSec.count() << endl << endl;
    
    string input;
    while(input != "0"){
        cout << "What would you like to do" << endl <<
                "1.) Show number of sentences" << endl <<
                "2.) Show top 150 most used words" << endl <<
                "3.) Show top 150 least used words" << endl <<
                "4.) Show number of occurences of a word" << endl <<
                "0.) Exit" << endl << endl;
        cin >> input;
        if(input == "1")
            showNumSent();
        else if(input == "2")
            showTop150(hashtable);
        else if(input == "3")
            showBottom150(hashtable);
        else if(input == "4"){
            string word;
            cout << "What word would you like to search for?" << endl;
            cin >> word;
            hashtable.showCount(word);
        }
    }
    return 0;
}