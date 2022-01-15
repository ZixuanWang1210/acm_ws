#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int l[maxn], r[maxn], e[maxn];
int indx;

void add(int a, int x){
    e[indx] = x;
    l[indx] = a, r[indx] = r[a];
    l[r[indx]] = indx, r[a] = indx;
    indx++;
}

void del(int a){
    r[l[a]] = r[a];
    l[r[a]] = l[a];
}

int main(){
    int m; cin >> m;

    r[0] = 1, l[1] = 0, indx = 2;
    
    while(m--){
        string opt;
        int x, k;
        cin >> opt;
        if(opt == "L"){
            cin >> x;
            add(0, x);
        }
        else if(opt == "R"){
            cin >> x;
            add(l[1], x);
        }
        else if(opt == "D"){
            cin >> x;
            del(x+1);
        }
        else if(opt == "IL"){
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else if(opt == "IR"){
            cin >> k >> x;
            add(k + 1, x);
        } 
    }

    for(int i = r[0]; i != 1; i = r[i]){
        cout << e[i] << " ";
    }

    return 0;
}