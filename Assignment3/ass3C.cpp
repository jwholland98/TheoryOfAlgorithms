#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "hashtable.cpp"

using namespace std;

int numSent = 0;

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

void showNumSent(){
    cout << "Number of sentences: " << numSent << endl << endl;
}

void showTop150(Hashtable &hashtable){
    content* words = hashtable.getAllContent();
    heapSort(words, hashtable.getWordCount());
    cout << "Top 150 most used words:" << endl;
    for(int i=0;i<150;i++){
        cout << words[i].word << " :: count = " << words[i].count << endl;
    }
    cout << endl;
}

void showBottom150(Hashtable &hashtable){
    content* words = hashtable.getAllContent();
    heapSort(words, hashtable.getWordCount(), false);
    cout << "Top 150 least used words:" << endl;
    for(int i=0;i<150;i++){
        cout << words[i].word << " :: count = " << words[i].count << endl;
    }
    cout << endl;
}

int main(){
    //Hashtable hashtable(33);

    Hashtable hashtable(8500);
    parseText(hashtable);
    string input;
    while(input != "0"){
        cout << "What would you like to do" << endl <<
                "1.) Show number of sentences" << endl <<
                "2.) Show top 150 most used words" << endl <<
                "3.) Show top 150 least used words" << endl <<
                "0.) Exit" << endl << endl;
        cin >> input;
        if(input == "1")
            showNumSent();
        else if(input == "2")
            showTop150(hashtable);
        else if(input == "3")
            showBottom150(hashtable);
    }
    return 0;
}