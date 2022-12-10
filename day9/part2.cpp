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
    pair<int, int> start_pos = make_pair(500, 500), rope[10];
    for(int i = 0; i < 10; i++)
        rope[i] = start_pos;
    visited[rope[9].first][rope[9].second] = true;

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
            rope[0].first += step.first;
            rope[0].second += step.second;

            // For the following nine knots
            for(int j = 1; j < 10; j++){
                // If the current knot is in the closest 9 block of its previous knot, it is just fine
                if(abs(rope[j - 1].first - rope[j].first) < 2 && abs(rope[j - 1].second - rope[j].second) < 2)
                    continue;

                // Otherwise, move the knot to the appropriate position
                if(rope[j - 1].first != rope[j].first)
                    rope[j].first += (rope[j - 1].first - rope[j].first > 0? 1: -1);
                if(rope[j - 1].second != rope[j].second)
                    rope[j].second += (rope[j - 1].second - rope[j].second > 0? 1: -1);
            }

            // Set the last knot's new location to visited
            visited[rope[9].first][rope[9].second] = true;
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