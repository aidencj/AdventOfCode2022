#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Function to tokenize the string
vector<string> SplitToTokens(string s){
    vector<string> tokenLists;
    size_t pos = 0;
    string token;
    while ((pos = s.find(" ")) != string::npos) {
        token = s.substr(0, pos);
        tokenLists.push_back(token);
        s.erase(0, pos + 1);
    }
    tokenLists.push_back(s);
    return tokenLists;
}

int main(){
    ifstream input_string("input.txt");
    string str;
    vector<int> x_val{1};

    // Store x value to the vector, the index is the cycle number
    while(getline(input_string, str)){
        vector<string> tokens = SplitToTokens(str);
        x_val.push_back(x_val.back());
        if(tokens[0] == "addx")
            x_val.push_back(x_val.back() + stoi(tokens[1]));
    }

    // Print the result to the console
    for(int pos = 0; pos < 240; pos++){
        cout << ((abs(x_val[pos] - (pos % 40)) <= 1)? '#': '.');
        
        if(pos % 40 == 39)
            cout << '\n';
    }
    
    return 0;
}