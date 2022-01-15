#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int e[maxn], ne[maxn];
int head, idx;

void init(){
    head = -1;
    idx = 0;
}

void add(int k, int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void add_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void del(int k){
    ne[k] = ne[ne[k]];
}

int main(){
    init();
    char opt;
    int sum;
    cin >> sum;
    while(sum--){
        int a, b;
        cin >> opt;
        if(opt == 'H'){
            cin >> a;
            add_head(a);
        }
        else if(opt == 'I'){
            cin >> a >> b;
            add(a-1, b);
        }
        else if(opt == 'D'){
            cin >> a;
            if(a == 0) head = ne[head];
            else del(a-1);
        }   
    }

    for(int i = head; i != -1; i = ne[i]){
        cout << e[i] << " ";
    }


    return 0;
}