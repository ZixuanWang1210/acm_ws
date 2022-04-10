#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,int>
using namespace std;
const int maxnum=5e5+10;

struct node
{
	int v, id;
};
vector<node>g[maxnum];
int n;
int ans[maxnum];
int d[maxnum];
 
void dfs(int u, int fa, int col) {
	for (node nd : g[u]) {
		if (nd.v == fa)continue;
		ans[nd.id] = col;
		dfs(nd.v, u, 5 - col);
		col = 5 - col;
	}
}
 
void slove() {
	cin >> n;
	for (int i = 1; i <= n; i++)d[i] = 0, g[i].clear();
	for (int i = 1; i <= n - 1; i++) {
		int u, v ; cin >> u >> v;
		g[u].push_back({ v,i });
		g[v].push_back({ u,i });
		d[u]++;d[v]++;
	}
	for (int i = 1; i <= n; i++)if (d[i] > 2) { cout << "-1" << endl; return; }
	dfs(1, 0, 2);
	for (int i = 1; i <= n - 1; i++)cout << ans[i] << " ";
	cout << endl;
}

// void sol(){
//     int n; cin>>n;
//     for(int i=1;i<=n-1;i++){
//         int u,v; cin>>u>>v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//         d[u]++;
//         d[v]++;
//     }
//     for(int i=1;i<=n;i++){
//         if(d[i]>2){
//             cout<<-1<<endl;
//             return;
//         }
//     }
//     bfs();
// }

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) slove();

    return 0;
}
