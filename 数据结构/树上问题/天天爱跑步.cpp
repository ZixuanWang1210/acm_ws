#include<bits/stdc++.h> 
using namespace std;

const int maxn=3e6+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int t[maxn];

void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int n,m;


struct LCA {
    int dfn[maxn], dep[maxn], st[maxn][30], fath[maxn], cnt;
    void dfs(int x, int fa) {
        dfn[x] = ++cnt, dep[x] = dep[fa] + 1, st[cnt][0] = x, fath[x] = fa;
        for (int i = h[x]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            dfs(j, x);
            st[++cnt][0] = x;
        }
    }

    void RMQ() {
        for (int j = 1; j <= 20; j++) {
            for (int i = 1; (i + (1 << j) - 1) <= cnt; i++) {
                int r = i + (1 << (j - 1));
                st[i][j] = dep[st[i][j - 1]] < dep[st[r][j - 1]] ? st[i][j - 1] : st[r][j - 1];
            }
        }
    }

    int get(int l, int r) {
        l = dfn[l], r = dfn[r];
        if (l > r) swap(l, r);
        int k = log2(r - l + 1);
        int res = dep[st[l][k]] < dep[st[r - (1 << k) + 1][k]] ? st[l][k] : st[r - (1 << k) + 1][k];
        return res;
    }

} plt;

int c1[maxn],c2[maxn];
int ans[maxn];
vector<int> a1[maxn],b1[maxn],a2[maxn],b2[maxn];
int dfs(int u,int fa){
	int val1=c1[plt.dep[u]+t[u]],val2=c2[n+t[u]-plt.dep[u]];
//	cout<<val1<<val2<<endl;
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fa) continue;
		dfs(j,u);
	}
	for(int i=0;i<a1[u].size();i++) c1[a1[u][i]]++;
	for(int i=0;i<b1[u].size();i++) c1[b1[u][i]]--;
	for(int i=0;i<a2[u].size();i++) c2[a2[u][i]+n]++;
	for(int i=0;i<b2[u].size();i++) c2[b2[u][i]+n]--;
	ans[u]+=c1[plt.dep[u]+t[u]]-val1+c2[t[u]-plt.dep[u]+n]-val2;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n-1;i++){
		int u,v; cin>>u>>v; 
		add(u,v),add(v,u);
	}
	
	plt.dfs(1,-1);
	plt.RMQ();
//	cout<<plt.get(1,5)<<endl;
//	return 0;
	
	for(int i=1;i<=n;i++){
		cin>>t[i];
	} 
	
	for(int i=1;i<=m;i++){
		int s,t; cin>>s>>t;
		int lca=plt.get(s,t);
		int dep=plt.dep[s];
		a1[s].push_back(dep);
		b1[plt.fath[lca]].push_back(dep);
		a2[t].push_back(plt.dep[s]-2*plt.dep[lca]);
		b2[lca].push_back(plt.dep[s]-2*plt.dep[lca]);
//		cout<<lca<<' '<<2*plt.dep[lca]<<endl;
	}
	
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}

