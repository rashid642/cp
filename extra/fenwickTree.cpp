// get fenwick tree equals to size of the array + 1
// so for example if it has 5 elements
// 0   1       2       3       4        5
//   (1,1)   (1,2)   (3,3)   (1,4)     (5,5)

// to get range
// 1. left range: switch off right most bit and add 1
//     2 -> 10 -> 00 -> 0 + 1 = 1;
// 2. right range: is same as index

// first initialize fenwick tree with 0
// to update value
// so if you want to update value at index 3
// so first go at 3rd index of fenwick tree and add the value
// now to update next value which have 3 in range follow these steps:
// 1. take 2's compliment
// 2. and with orignal number
// 3. add to orignal number

// so for example
// index = 3 = 11
// two's compliment = 01
// and with orignal = 01
// add orignal 01 + 11 = 4
// so next we need to update 4th index in fenwick tree
// easy way => i = i + (i & (-i))

// to get sum of a range
// it's similar to update just subtract orignal from 
// so for example if you want to get sum of range 1 to 3
// index = 3 = 11
// two's compliment = 01
// and with orignal = 01
// add orignal 11 + 01 = 2

#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int fen[N];
void update(int i, int add){
    while(i < N){
        fen[i] += add;
        i = i + (i & (-i));
    }
}
int sum(int i){
    int sum = 0;
    while(i > 0){
        sum += fen[i];
        i = i - (i & (-i));
    }
    return sum;
}
int rangeSum(int l, int r){
    return sum(r) - sum(l-1);
}
int main(){
    return 0;
}

