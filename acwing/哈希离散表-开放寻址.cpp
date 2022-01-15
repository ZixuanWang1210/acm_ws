#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;

int h[N];
int n, x;
char op;

int find(int x){
    int k = (x % N + N) % N;
    while(h[k] != 0x3f3f3f3f && h[k] != x){
        k++;
        if(k == N) k = 0;
    }
    return k;
}

int _find(int x){
    int k = (x % N + N) % N;
    int i;
    for(i = k; h[i] != 0x3f3f3f3f; i++){
        if(i == N) i = 0;
        if(h[i] == x) return i;
    }
    return i;
}

int main(){
    memset(h, 0x3f, sizeof(h));

    cin >> n;
    while(n--){
        cin >> op >> x;
        if(op == 'I') h[_find(x)] = x;
        else{
            if(h[_find(x)] == 0x3f3f3f3f) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    return 0;
}