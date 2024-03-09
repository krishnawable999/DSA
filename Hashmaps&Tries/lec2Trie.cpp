#include<iostream>
using namespace std;

class TrieNode{
    public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val){
        this->value = val;
        for(int i=0 ; i<26 ; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};


void insertWord(TrieNode* root, string word){

    //cout<<"Received word :" <<word<<endl;
    // base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        // present
        child = root->children[index];
    }
    else{
        // absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // recurssion
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root -> children[index] != NULL){
        // Present
        child = root->children[index];
    }
    else{
        // not present
        return false;
    }

    // recurssion
    bool ans = searchWord(child, word.substr(1));
    return ans;
}

void deleteWord(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        root->isTerminal = false;
        cout<<"Deleted Successfully"<<endl;
        return;
    }

    // 1 case 
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return;
    }

    // Baki recursion Tera
    deleteWord(child , word.substr(1));
}

int main(){
    TrieNode* root = new TrieNode('-');
    //string s = "";
    insertWord(root,"krishna");
    insertWord(root,"care");
    insertWord(root,"com");
    insertWord(root,"lover");
    insertWord(root,"loved");
    insertWord(root,"load");
    insertWord(root,"lov");
    insertWord(root,"bat");
    insertWord(root,"cat");
    insertWord(root,"car");

    cout <<"Inseretion Done"<<endl;

    if(searchWord(root,"bat")){
        cout<<"Found";
    }
    else{
        cout <<"Not Found"<<endl;
    }

    deleteWord(root,"bat");
    if(searchWord(root,"bat")){
        cout<<"Found";
    }
    else{
        cout <<"Not Found"<<endl;
    }
}