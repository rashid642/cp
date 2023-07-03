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

/*
class Node{
    public:
    Node* next[26];
    int count; // ending of string
    int scount; // ending of substring
    Node(){
        for(int i=0; i<26; i++) next[i] = NULL;
        count = 0;
        scount = 0;
    }
};
class Trie{
    public:
    Node* head;
    map<int, multiset<int>> mpp;
    Trie(){
        head = new Node();
    }
    void insert(string s){
        Node* t = head;
        for(int i=0; i<s.size(); i++){
            if(t->next[s[i] - 'a'] == NULL){
                t->next[s[i] - 'a'] = new Node();
            }
            t = t->next[s[i] - 'a'];
            t->scount++;
            if(mpp[i].find(t->scount - 1) != mpp[i].end()){
                mpp[i].erase(mpp[i].find(t->scount - 1));
            }
            mpp[i].insert(t->scount);
        }
        t->count++;
    }
    void remove(string s){
        Node* t = head;
        for(int i=0; i<s.size(); i++){
            t = t->next[s[i] - 'a'];
            if(mpp[i].find(t->scount) != mpp[i].end()){
                mpp[i].erase(mpp[i].find(t->scount));
            }
            t->scount--;
            mpp[i].insert(t->scount);
        }
        t->count--;
    }
    int findString(string s){
        Node* t = head;
        for(int i=0; i<s.size(); i++){
            if(t->next[s[i] - 'a'] == NULL) return 0;
            t = t->next[s[i] - 'a'];
        }
        return t->count;
    }
    int startsWith(string s){
        Node* t = head;
        for(int i=0; i<s.size(); i++){
            if(t->next[s[i] - 'a'] == NULL) return 0;
            t = t->next[s[i] - 'a'];
        }
        return t->scount;
    }
    int exist(int k, int l){
        // do k groups of string exist with same prefix of length equals to l
        l--;
        if(mpp[l].size() == 0) return 0;
        auto it = --mpp[l].end();
        return *it >= k;
    }

};
*/

int main(){
    
    return 0;
}