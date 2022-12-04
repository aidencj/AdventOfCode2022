#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;

int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    int ans = 0;

    while(getline(input_stream, str)){
        string s1, s2;
        size_t mid = str.find(",");
        // Split the input string by ","
        s1 = str.substr(0, mid);
        s2 = str.substr(mid+1, string::npos);

        pair<int, int> e1, e2;
        // Split two substrings by "-", cast them to integer and store the ranges in pair
        mid = s1.find("-");
        e1 = make_pair(stoi(s1.substr(0, mid)), stoi(s1.substr(mid+1, string::npos)));
        mid = s2.find("-");
        e2 = make_pair(stoi(s2.substr(0, mid)), stoi(s2.substr(mid+1, string::npos)));

        // Make sure the range of e2 is always after e1's range
        if(e1.second > e2.second)
            swap(e1, e2);
        
        // If e2's first section is in e1's range, increase ans by 1
        if(e2.first <= e1.second)
            ans++;
    }
    cout << ans << endl;
    return 0;
}