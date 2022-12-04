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
        unordered_set<char> char_set, char_set2;
        char common;

        // Add the first string to the set1
        for(auto c: str)
            char_set.insert(c);
        
        // Read the second string, put the common items between itself and first string to the set2
        getline(input_stream, str);
        for(auto c: str)
            if(char_set.find(c) != char_set.end()){
                char_set2.insert(c);
            }
        
        // Read the third string, find the common items between itself and the other two strings
        getline(input_stream, str);
        for(auto c: str)
            if(char_set2.find(c) != char_set2.end()){
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