#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int, int>

using namespace std;

int n, m;
const int maxn = 2e5 + 10;
int e[maxn], ne[maxn], h[maxn], idx;
int st[maxn];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool bfs(int x){
    queue<pii> q;
    q.push({x, 1}); //第一个是编号，第二个是颜色
    st[x] = 1;

    while(q.size()){
        int ver = q.front().first, color = q.front().second; q.pop();
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];

            if(!st[j]){ //未被染色，则染色
                st[j] = 3 - color;
                q.push({j, 3 - color});
            }
            else{ //已被染色则判断
                if(st[j] == color)  return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= m; i ++){
        int a, b; cin >> a >> b;
        add(a, b), add(b, a);
    }

    for(int i = 1; i <= m; i ++){
        if(!st[i])
            if(!bfs(i)){
                cout << "No" << endl;
                return 0;
            }
    }
    
    cout << "Yes" << endl;
    return 0;
}
