#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n, num;

int lowbit(int x){
    return x & -x;
}

int main(){
    cin >> n;
    while (n--){
        cin >> num;
        int res = 0;
        while(num){
            num -= lowbit(num);
            res++;
        }
        cout << res;
    }
    
}