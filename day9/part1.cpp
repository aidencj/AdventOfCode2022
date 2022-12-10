#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    // Assume the grid is 1000 x 100
    vector<vector<char> > grid(1000, vector<char>(1000, '.'));
    vector<vector<bool> > visited(1000, vector<bool>(1000, false));

    // Place the starting point at the center of the grid
    pair<int, int> start_pos = make_pair(500, 500), head, tail;
    head = tail = start_pos;
    visited[tail.first][tail.second] = true;

    while(getline(input_stream, str)){
        char dir = str[0];
        int step_num = stoi(str.substr(2, string::npos));

        // Get the offset of each step
        pair<int, int> step;
        switch(dir){
            case 'L':
                step = make_pair(0, -1);
                break;
            case 'R':
                step = make_pair(0, 1);
                break;
            case 'U':
                step = make_pair(-1, 0);
                break;
            case 'D':
                step = make_pair(1, 0);
                break;
        }
        
        // For each step
        for(int i = 0; i < step_num; i++){
            // Move the head
            head.first += step.first;
            head.second += step.second;

            // After moving, if the tail is in the closest 9 block, it is just fine
            if(abs(head.first - tail.first) < 2 && abs(head.second - tail.second) < 2)
                continue;
            
            // Otherwise, move the tail to the appropriate position
            if(head.first != tail.first)
                tail.first += (head.first - tail.first > 0? 1: -1);
            if(head.second != tail.second)
                tail.second += (head.second - tail.second > 0? 1: -1);
            
            // Set tail's new location to visited
            visited[tail.first][tail.second] = true;
        }
    }

    // Count the number of visited poisiton on the grid
    int ans = 0;
    for(int i = 0; i < visited.size(); i++){
        for(int j = 0; j < visited[0].size(); j++){
            if(visited[i][j])
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}