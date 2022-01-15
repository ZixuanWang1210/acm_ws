#include<bits/stdc++.h>
using namespace std;
const int maxn = 210 * 210;

int n, m;
int fa[maxn];


int find(int x){
    if(x != fa[x]) fa[x] = find(fa[x]);
    return x;
}

int mp(int x, int y){
    return (x - 1) * n + y;
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n * n; i++){
        fa[i] = i;
    }

    int cnt = 0;
    while(m--){
        cnt ++;
        int x, y; cin >> x >> y;
        char op; cin >> op;

        int a = mp(x, y), b;
        if(op == 'D'){
            b = mp(x + 1, y);
        }
        else if(op == 'R'){
            b = mp(x, y + 1);
        }

        int pa = find(a), pb = find(b);

        if(pa == pb){
            cout << cnt;
            return 0;
        }
        else{
            fa[find(a)] = pb;
        }

    }
    cout << "draw";

    return 0;
}