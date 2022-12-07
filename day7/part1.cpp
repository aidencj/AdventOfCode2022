#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// I use tree to construct the file structure system
// Basically, every file/directory is a node in our tree.
class Node{
public:
    Node *parent;
    bool isDir;
    unordered_map<string, Node *> children;
    int size;
    Node(){
        parent = NULL;
        isDir = false;
    }
    Node(Node *parent, bool isDir, int size){
        this->parent = parent;
        this->isDir = isDir;
        this->size = size;
    }
};

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

// Traverse the whole file strcture tree, calculate folders' size based on the size of their children
int CalculateSize(Node *root){
    if(!root->isDir)
        return root->size;
    
    int sum = 0;
    for(auto child: root->children){
        sum += CalculateSize(child.second);
    }
    root->size = sum;
    return sum;
}
// Traverse the whole file structrue tree, sum up all the folders with size not larger "max_size"
void SumSizeLessThan(Node *root, int max_size, int &ans){
    if(!root->isDir)
        return;
    
    if(root->size <= max_size)
        ans += root->size;
    
    for(auto child: root->children)
        SumSizeLessThan(child.second, max_size, ans);
}

int main(){
    fstream input_stream("input.txt", ios::in);
    string str;
    // The root of tree, which is our "/" directory
    Node *root = new Node(NULL, true, 0);
    // Use "cur" to store the current location in the tree
    Node *cur = root;

    while(getline(input_stream, str)){
        // Tokenize the input string
        vector<string> tokens = SplitToTokens(str);

        // If the first token is not "$", it means this line is the output of previous "ls"
        // Create a child node with the information, and insert it to the children hash map of current node
        if(tokens[0] != "$"){
            cur->children[tokens[1]] = (tokens[0] == "dir"? new Node(cur, true, 0): new Node(cur, false, stoi(tokens[0])));
            continue;
        }

        // If it is "ls", simply do nothing
        if(tokens[1] == "ls")
            continue;

        // Now, the only possible command is "cd"
        // Change the directory according to the input
        if(tokens[2] == "/")
            cur = root;
        else if(tokens[2] == "..")
            cur = cur->parent;
        else
            cur = cur->children[tokens[2]];
    }

    // Calculate each folder's size
    CalculateSize(root);

    int ans = 0;
    // Sum up all the folders with size larger at most 100000
    SumSizeLessThan(root, 100000, ans);
    cout << ans << endl;
    return 0;
}