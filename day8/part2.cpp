#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// Class to store the number of visible tree from 4 directions
class direction{
public:
    int left;
    int right;
    int top;
    int bottom;

    direction(){
        left = right = top = bottom = 0;
    }
    int get_score(){
        return left * right * top * bottom;
    }
};

int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    vector<vector<direction>> visible;
    vector<string> height;

    // Read data
    while(getline(input_stream, str))
        height.push_back(str);
    
    // Resize according to the data size
    visible.resize(height.size(), vector<direction>(height[0].length()));

    // From left to right
    for(int i = 0; i < height.size(); i++){
        // The key is height, the value is the index of last position
        unordered_map<char, int> hashMap;
        for(int j = 0; j < height[0].length(); j++){
            // The farthest visible tree is on the edge
            int min_distance = j;
            // If there's any tree higher than current tree, our view will be blocked
            // Find the minimum viewing distance
            for(int k = '9'; k >= height[i][j]; k--){
                if(hashMap.find(k) != hashMap.end())
                    if(abs(j - hashMap[k]) < min_distance)
                        min_distance = abs(j - hashMap[k]);
            }
            visible[i][j].left = min_distance;
            // Store current height and index to hash map
            hashMap[height[i][j]] = j;
        }
    }

    // Do the same thing for the other three directions
    
    // From right to left
    for(int i = 0; i < height.size(); i++){
        unordered_map<char, int> hashMap;
        for(int j = height[0].length() - 1; j >= 0; j--){
            int min_distance = height[0].length() - 1 - j;
            for(int k = '9'; k >= height[i][j]; k--){
                if(hashMap.find(k) != hashMap.end())
                    if(abs(j - hashMap[k]) < min_distance)
                        min_distance = abs(j - hashMap[k]);
            }
            visible[i][j].right = min_distance;
            hashMap[height[i][j]] = j;
        }
    }

    // From top to bottom
    for(int i = 0; i < height[0].length(); i++){
        unordered_map<char, int> hashMap;
        for(int j = 0; j < height.size(); j++){
            int min_distance = j;
            for(int k = '9'; k >= height[j][i]; k--){
                if(hashMap.find(k) != hashMap.end())
                    if(abs(j - hashMap[k]) < min_distance)
                        min_distance = abs(j - hashMap[k]);
            }
            visible[j][i].top = min_distance;
            hashMap[height[j][i]] = j;
        }
    }

    // From bottom to top
    for(int i = 0; i < height[0].length(); i++){
        unordered_map<char, int> hashMap;
        for(int j = height.size() - 1; j >= 0; j--){
            int min_distance = height.size() - 1 - j;
            for(int k = '9'; k >= height[j][i]; k--){
                if(hashMap.find(k) != hashMap.end())
                    if(abs(j - hashMap[k]) < min_distance)
                        min_distance = abs(j - hashMap[k]);
            }
            visible[j][i].bottom = min_distance;
            hashMap[height[j][i]] = j;
        }
    }

    // Find the highest score
    int ans = 0;
    for(int i = 0; i < visible.size(); i++)
        for(int j = 0; j < visible[0].size(); j++)
            if(visible[i][j].get_score() > ans)
                ans = visible[i][j].get_score();
    
    cout << ans << endl;
    return 0;
}