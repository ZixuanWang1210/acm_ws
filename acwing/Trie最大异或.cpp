#include<bits/stdc++.h>
using namespace std;
const int maxn = (1e5 + 10) * 31;

int son[maxn][2], a[maxn];
int indx = 0;

void insert(int x){
    int p = 0;
    for(int i = 31; i >= 0; i--){
        int u = (x >> i) & 1;
        if(!son[p][u]) son[p][u] = ++indx;
        p = son[p][u];
    }
}

int query(int x){
    int p = 0, num = 0;
    for(int i = 31; i >=0; i--){
        int u = (x >> i) & 1;
        if(!son[p][!u]){
            p = son[p][u];
            num = num * 2 + u;
        }
        else{
            p = son[p][!u];
            num = num * 2 + !u;
        }
    }
    num = num ^ x;
    return num;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        insert(a[i]);
    }


    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(query(a[i]), ans);
    }

    cout << ans;

    return 0;
}