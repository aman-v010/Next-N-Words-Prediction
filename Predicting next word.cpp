#include<bits/stdc++.h>
using namespace std;


bool isPrefix(string inp1, string inp2) {
    if (inp1.length() > inp2.length()) {
        return false;
    }
    string word;
    for (int i=0; i<=(inp1.length()-1); i++) {
        word = word + inp2[i];
    }
    if (word == inp1) {
        return true; 
    }
    else {
        return false; 
    }
}


int main () {
    string s = "ram India, a land of rich diversity and ancient heritage, captivates rat the world with its vibrant tapestry of cultures, traditions, and landscapes. From the towering peaks of the rat Himalayas to the tranquil ram backwaters of Kerala, India's geography is as varied ram as its people. With a history dating back millennia, India has been a cradle of civilization, giving rat birth to religions, philosophies, and rat architectural marvels that continue rat to inspire. Its bustling cities, rat like Mumbai, Delhi, and Bangalore.";
    vector <string> words;

    string word; // India is

    for (int i =0; i<=(s.length()-1); i++) {
        if (s[i]== ',' || s[i] == '.' || s[i] == ' '){
            words.push_back(word); 
            word = ""; 
        }
        else {
            word = word + s[i]; 
        }
    }
    vector<int> frequencies;
    for (int i =0; i<=(words.size()-1); i++) {
        int counter =0;
        for (int j =0; j<= (words.size()-1); j++) {
            if (words[i] ==  words[j]){
                counter ++;
            }
        } 
        frequencies.push_back(counter);
    }



    string inp;
    cin>>inp;
    vector<int> distance;
    for (int i =0; i<=(words.size()-1); i++) {
        
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


