#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    int sum = 0;

    while(getline(input_stream, str)){
        unordered_set<char> char_set;
        char common;
        // Split the string into halves
        string s1, s2;
        s1 = str.substr(0, str.length()/2);
        s2 = str.substr(str.length()/2, string::npos);
        
        // Add the first substring to set
        for(auto c: s1)
            char_set.insert(c);

        // For each character in second substring, check whether it is in the set
        for(auto c: s2)
            if(char_set.find(c) != char_set.end()){
                common = c;
                break;
            }
        
        // Calculate score based on the common item
        int score;
        if('a' <= common && common <= 'z')
            score = common - 'a' + 1;
        else if('A' <= common && common <= 'Z')
            score = common - 'A' + 1 + 26;
        
        sum += score;
    }
    cout << sum << endl;
    return 0;
}