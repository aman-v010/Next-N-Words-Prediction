#include<bits/stdc++.h>
using namespace std;


bool isPrefix(string inp1, string inp2) {
    // inp1 as a prefix available for inp2 or not
    if (inp1.length() > inp2.length()) {
        return false;
    }
    string word;
    for (int i=0; i<=(inp1.length()-1); i++) {
        word = word + inp2[i];
    }
    if (word == inp1) {
        return true; // inp1 as a prefix available hai
    }
    else {
        return false; // inp1 as a prefix is not available
    }
}


int main () {
    string s = "ram India, a land of rich diversity and ancient heritage, captivates rat the world with its vibrant tapestry of cultures, traditions, and landscapes. From the towering peaks of the rat Himalayas to the tranquil ram backwaters of Kerala, India's geography is as varied ram as its people. With a history dating back millennia, India has been a cradle of civilization, giving rat birth to religions, philosophies, and rat architectural marvels that continue rat to inspire. Its bustling cities, rat like Mumbai, Delhi, and Bangalore.";
    // Break this paragraph to Array of Strings (Words)
    // We will make list of array of words...
    vector <string> words;

    string word; // India is

    for (int i =0; i<=(s.length()-1); i++) {
        if (s[i]== ',' || s[i] == '.' || s[i] == ' '){
            words.push_back(word); // jo bhee Word me store tha usko hmne Words me Push Back kr diya --> India
            word = ""; // Then after Push Back Word ko empty kar diye
        }
        else {
            word = word + s[i]; // I --> In --> Ind --> Indi --> India
        }
    }
    vector<int> frequencies;
    for (int i =0; i<=(words.size()-1); i++) {
        int counter =0;
        for (int j =0; j<= (words.size()-1); j++) {
            if (words[i] ==  words[j]){
                counter ++;
            }
        } // i th word kitna baar aaya hai wo counter pe stored hai
        frequencies.push_back(counter);
    }



    string inp;
    cin>>inp; // user given input
    vector<int> distance;
    for (int i =0; i<=(words.size()-1); i++) {
        // we will check whether inp as a prefix available in words[i] or not
        bool val = isPrefix(inp, words[i]);
        if (val == true) {
            distance.push_back(words[i].length() - inp.length());
        }
        else {
            distance.push_back(INT_MAX);
        }
    }
    int mi = INT_MAX;
    int index;
    int frequency;
    for (int i =0; i<= (distance.size()-1); i++) {
        if (distance[i] < mi) {
            mi = distance[i];
            index =  i;
            frequency = frequencies[i];
        }
        else if(distance[i] == mi) {
            if (frequencies[i] > frequency) {
                mi = distance[i];
                index =  i;
                frequency = frequencies[i];
            }
        }
    }
    cout << words[index];
}


