#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <string>

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
    fstream input_stream("input.txt", ios::in);
    // I use deque to store the crates
    vector<deque<char> > stacks;
    string str;

    // Construct stacks
    while(getline(input_stream, str) && str[1] != '1'){
        // If the stacks is empty, resize it based on the length of input string
        if(stacks.empty()){
            stacks.resize(str.length() / 4 + 1);
        }
        // Loop through the string
        // If there's any crate, push it to the corresponding stacks
        for(int i = 1; i < str.length(); i += 4){
            if(str[i] != ' '){
                stacks[i/4].push_front(str[i]);
            }
        }
    }

    // Read the empty line
    getline(input_stream, str);

    // Start the rearrangement
    while(getline(input_stream, str)){
        vector<string> tokens = SplitToTokens(str);
        
        // Cast the token(string) to integer
        int num = stoi(tokens[1]), from = stoi(tokens[3]) - 1, to = stoi(tokens[5]) - 1;

        // Pop the crate from the original stack and push it to the destination stack
        for(int i = 0; i < num; i++){
            char crate = stacks[from].back();
            stacks[from].pop_back();
            stacks[to].push_back(crate);
        }
    }

    string ans;
    for(auto s: stacks)
        ans.push_back(s.back());
    cout << ans << endl;
    return 0;
}