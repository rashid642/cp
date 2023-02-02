#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag = false;
    bool containKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void putKey(char ch, Node* root){
        links[ch - 'a'] = root;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool getEnd(){
        return flag;
    }
};
class Trie {
public:
    Node * root;
    Trie() {
        root = new Node();
    }   
    void insert(string word) {
        Node* temp = root;
        for(auto it: word){
            if(temp->containKey(it) == NULL){
                temp->putKey(it, new Node());
            }
            temp = temp->get(it);
        }   
        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto it: word){
            if(temp->containKey(it) == NULL) return false;
            temp = temp->get(it);
        }
        return temp->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto it: prefix){
            if(temp->containKey(it) == NULL) return false;
            temp = temp->get(it);
        }
        return true;
    }
};
int main(){
    
    return 0;
}