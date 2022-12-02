#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    int score = 0;
    while(getline(input_stream, str)){
        int oppo = str[0] - 'A', result = str[2] - 'X';

        // The score of the outcome = result * 3
        int sum = result * 3;

        // Plus the score of your hand shape
        if(result == 0)//Lose
            sum += (oppo - 1 + 3) % 3 + 1;
        else if(result == 1)//Draw
            sum += oppo + 1;
        else//Win
            sum += (oppo + 1) % 3 + 1;
        
        score += sum;
    }
    cout << score << endl;
    return 0;
}