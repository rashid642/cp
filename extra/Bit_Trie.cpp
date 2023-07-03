#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* next[2];
    int count[2];
    Node(int c){
        count[0] = c;
        count[1] = c;
        next[0] = NULL;
        next[1] = NULL;
    }
};
class Trie{
    public:
    Node* head;
    Trie(){
        head = new Node(0);
    }
    void addNumber(long long num){
        Node* t = head;
        for(long long i=40; i>=0; i--){
            int bit = (num >> i) & 1LL;
            if(t->next[bit] == NULL){
                Node* newnode = new Node(0);
                t->next[bit] = newnode;
            }
            t->count[bit]++;
            t = t->next[bit];
        }
    }
    long long getMax(long long num){
        Node* t = head;
        long long ans = 0;
        for(long long i=40; i>=0; i--){
            int bit = (num >> i) & 1LL;
            if(bit == 0 && t->next[1] != NULL){
                t = t->next[1];
                ans += (1 << i);
            }else if(bit == 1 && t->next[0] != NULL){
                t = t->next[0];
                ans += (1 << i);
            } else if(t->next[1] != NULL){
                t = t->next[1];
            } else if(t->next[0] != NULL){
                t = t->next[0];
            } else{
                return ans;
            }
        }
        return ans;
    }
    void removeNum(long long num){
        Node* t = head;
        for(long long i=40; i>=0; i--){
            int bit = (num >> i) & 1LL;
            t->count[bit]--;
            if(t->count[bit] == 0){
                t->next[bit] = NULL;
                return;
            }else{
                t = t->next[bit];
            }
        }
    }
};
int main(){
    
    return 0;
}