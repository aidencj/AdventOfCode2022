#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// I use two pointer technique to solved this problem
int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    vector<vector<bool>> visible;
    vector<string> height;

    // Read data
    while(getline(input_stream, str))
        height.push_back(str);
    
    // Resize according to the data size
    visible.resize(height.size(), vector<bool>(height[0].length(), false));

    // Horizontal direction
    for(int row = 0; row < height.size(); row++){
        int start = 0, end = height[0].length() - 1;
        int start_max = INT_MIN, end_max = INT_MIN;
        while(start <= end){
            if(end_max == '9' && start_max == '9')
                break;
            if(height[row][start] > start_max){
                visible[row][start] = true;
                start_max = height[row][start];
            }
            if(height[row][end] > end_max){
                visible[row][end] = true;
                end_max = height[row][end];
            }
            if(start_max < end_max)
                start++;
            else
                end--;
        }
    }

    // Vertical direction
    for(int col = 0; col < height[0].length(); col++){
        int start = 0, end = height.size() - 1;
        int start_max = INT_MIN, end_max = INT_MIN;
        while(start <= end){
            if(start_max == '9' && end_max == '9')
                break;
            if(height[start][col] > start_max){
                visible[start][col] = true;
                start_max = height[start][col];
            }
            if(height[end][col] > end_max){
                visible[end][col] = true;
                end_max = height[end][col];
            }
            if(start_max < end_max)
                start++;
            else
                end--;
        }
    }
    
    // Count how many trees are visible from at least one direction
    int ans = 0;
    for(int i = 0; i < visible.size(); i++){
        for(int j = 0; j < visible[i].size(); j++)
            if(visible[i][j])
                ans++;
    }
    cout << ans << endl;

    return 0;
}