#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int h[maxn], ne[2 * maxn], e[2 * maxn], indx;
bool vis[maxn];
int n, ans = maxn;

void add(int a, int b){
    e[indx] = b, ne[indx] = h[a], h[a] = indx++;
}

int dfs(int a){ //以a为根的子树大小
    vis[a] = true;
    int sum = 1, res = 0;
    for(int i = h[a]; i != -1; i = ne[i]){
        int j = e[i];
        if(!vis[j]){
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main(){
    memset(h, -1, sizeof h);
    cin >> n;
    int a, b;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1);
    cout << ans << endl;

    return 0;
}