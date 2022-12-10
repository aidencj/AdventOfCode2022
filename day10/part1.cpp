#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    vector<int> x_val{0, 1};

    // Store x value to the vector, the index is the cycle number
    while(getline(input_string, str)){
        vector<string> tokens = SplitToTokens(str);
        x_val.push_back(x_val.back());
        if(tokens[0] == "addx")
            x_val.push_back(x_val.back() + stoi(tokens[1]));
    }

    // Calculate answer
    int ans = 0;
    for(int i = 20; i <= 220; i += 40)
        ans += x_val[i] * i;
    cout << ans << endl;
    
    return 0;
}