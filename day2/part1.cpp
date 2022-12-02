#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    int score = 0;

    while(getline(input_stream, str)){
        int oppo = str[0] - 'A', you = str[2] - 'X';

        // The score of your hand shape = you + 1
        int sum = you + 1;
        
        // Plus the score of the outcome
        if(oppo == you)// Draw
            sum += 3;
        else if(you == (oppo + 1) % 3)// Win
            sum += 6;
        // else if(you == (oppo - 1 + 3) % 3)// Lose
        //     sum += 0;

        score += sum;
    }
    cout << score << endl;
    return 0;
}