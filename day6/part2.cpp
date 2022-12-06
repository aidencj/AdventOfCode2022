#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    unordered_set<char> char_set;
    int ans;

    getline(input_stream, str);

    // Start from the first possible position
    for(ans = 14; ans < str.length(); ans++){
        // Clear the set
        char_set.clear();

        // Insert current character to set
        for(int i = 1; i <= 14; i++)
            char_set.insert(str[ans - i]);
        
        // If the set size equals to 14, it means no duplicate characters
        if(char_set.size() == 14)
            break;
    }
    
    cout << ans << endl;
    return 0;
}