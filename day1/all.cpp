#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    vector<int> calories;

    int sum = 0;
    while(getline(input_stream, str)){
        // Empty line mean the end of current elf
        if(str == ""){
            calories.push_back(sum);
            sum = 0;
            continue;
        }
        // Otherwise, keep counting the total calories of current elf
        sum += stoi(str);
    }

    // Sort in descending order
    sort(calories.begin(), calories.end(), greater<int>());

    
    int ans = 0;
    for(int i = 0; i < 3; i++)
        ans += calories[i];

    // For part 1, find the max number of calories
    cout << "Part 1: " << calories[0] << endl;
    // For part 2, sum up the largest 3 calories
    cout << "Part 2: " << ans << endl;
    return 0;
}