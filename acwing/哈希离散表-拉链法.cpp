#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;

int n, x;
char op;
int h[N], e[N], ne[N], idx;

void insert(int x){
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x){
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i]){
        if(e[i] == x) return true;
    }
    return false;
}

int main(){
    cin >> n;
    memset(h, -1, sizeof(h));
    while(n--){
        cin >> op >> x;
        if(op == 'I') insert(x);
        else{
            if(op == 'Q'){
                if(find(x)) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
    }
}