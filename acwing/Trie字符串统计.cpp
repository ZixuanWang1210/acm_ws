#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10;

int son[maxn][26], cnt[maxn];
int idx;

void insert(string a){
    int p = 0;
    for(int i = 0; i < a.size(); i++){
        int x = a[i] - 'a';
        if(!son[p][x]) son[p][x] = ++idx;
        p = son[p][x];
    }
    cnt[p]++;
}

int inquire(string a){
    int p = 0;
    for(int i = 0; i < a.size(); i++){
        int x = a[i] - 'a';
        if(!son[p][x]) return 0;
        p = son[p][x];
    }
    return cnt[p];
}

int main(){
    int n; cin >> n;
    while(n--){
        char op; cin >> op;
        if(op == 'I'){
            string a; cin >> a;
            insert(a);
        }
        else if(op == 'Q'){
            string a; cin >> a;
            int ans = inquire(a) ? inquire(a) : 0;
            cout << ans << endl;
        }
    }
}