#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define index2(i, j) cout << "(" << i << "," << j << ") "
#define index3(i, j, k) cout << "(" << i << "," << j << "," << k << ") "
#define tv(v) for(auto it: v) cout << it << " "; cout << endl
const int mod = 1e9 + 7;

void precompute(){
}
struct Node{
    int count;
    Node* next[2];
    Node(){
        count = 1;
        next[0] = NULL;
        next[1] = NULL;
    }
};
class Trie{
    public:
    Node* head;
    Trie(){
        head = new Node();
    }
    void addNumber(int num){
        Node* temp = head;
        for(int i=30; i>=0; i--){
            int t = (num & (1 << i)) == 0 ? 0 : 1;
            if(head->next[t] == NULL){
                Node* newnode = new Node();
                head->next[t] = newnode;
                head = head->next[t];
            }else{
                head->count++;
                head = head->next[t];
            }
        }
        head = temp;
    }
    int findMax(int num){
        Node* temp = head;
        int ans = 0;
        for(int i=30; i>=0 && temp != NULL; i--){
            int t = (num & (1 << i)) == 0 ? 0 : 1;
            if(t == 0 && temp->next[1] != NULL){
                cout << i << " " << 1 << endl;
                ans = ans | (1 << i);
            }else if(t == 1 && temp->next[0] != NULL){
                cout << i << " " << 0 << endl;
                ans = ans | (1 << i);
            } else if(temp->next[0] != NULL){
                cout << i << " NULL " << endl;
                temp = temp->next[0];
            } else{
                temp = temp->next[1];
            }
        }
        return ans;
    }
};
void solve(int test){
    int n;
    cin >> n;
    Trie* tr = new Trie();
    while(n--){
        char ch;
        int num;
        cin >> ch >> num;
        if(ch == '+'){
            tr->addNumber(num);
        } else if(ch == '?'){
            int ans = tr->findMax(num);
            cout << ans << endl;
        }
    }
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t = 1;
    // cin >> t;
    precompute();
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}