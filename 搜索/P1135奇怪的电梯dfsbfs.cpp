#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans = 0x7ffffff;
int k[300] {}, vis[300] {};
typedef struct f{
    int num;
    int opt;
};

bool isTrue(int x){
    return (x>0&&x<=n&&vis[x]==0) ? true : false;  
}

void dfs(int floor, int step){
    if(floor == b) ans = min(ans, step);
    if(step>ans) return;//最优性剪枝，如果当前的sum大于答案，那么它不可能成为答案。
    vis[floor] = 1;
    int n_floor = floor + k[floor];
    if(isTrue(n_floor)) dfs(n_floor, step+1);
    n_floor = floor - k[floor];
    if(isTrue(n_floor)) dfs(n_floor, step+1);
    vis[floor] = 0;
}

void bfs(){
    queue<int>q;
    queue<int>s;
    int flo = a;
    q.push(flo); s.push(0);
    vis[a] = 1;
    while(!q.empty()){
        if(q.front() == b){
            cout << s.front();
            return;
        }
        int n_flo;
        n_flo = q.front() + k[q.front()];
        if(isTrue(n_flo)){
            vis[n_flo] = 1;
            q.push(n_flo);
            s.push(s.front()+1);
        }
        n_flo = q.front() - k[q.front()];
        if(isTrue(n_flo)){
            vis[n_flo] = 1;
            q.push(n_flo);
            s.push(s.front()+1);
        }
        q.pop();
        s.pop();
    }
    cout << -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> n>>a>>b;
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
    //bfs();
    dfs(a, 0);
    if(ans!=0x7ffffff) cout << ans;
    else cout << -1;

    return 0;
}
