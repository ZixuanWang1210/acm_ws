#include<bits/stdc++.h> 
using namespace std;

const int maxn=5e6+10;
int e[maxn],ne[maxn],h[maxn],idx;

void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int n;
int ord[maxn]; 
int res[maxn];

struct LCA {
    /*
    $st[cnt][0]$：树的$dfs$序，第$cnt$个遍历的点是$st[cnt][0]$
    $dfn[x]$：节点编号为x的节点，第一次出现在dfs序中的位置
    $dep[x]$：节点x在树中的深度
    */

    int dfn[maxn], dep[maxn], st[maxn][30], fath[maxn],cnt;
    void dfs(int x, int fa) {
        dfn[x] = ++cnt, dep[x] = dep[fa] + 1, st[cnt][0] = x,fath[x]=fa;
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
int ans=0;
void dfs(int u,int fa){
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fa) continue;
		dfs(j,u);
		res[u]+=res[j];
	}
}
int tt[maxn];
void get(int a,int b){
	res[a]++,res[b]++;
	int lca=plt.get(a,b);
	res[lca]--,res[plt.fath[lca]]--;
	tt[b]--;
//	cout<<tt[b]<<' ' ;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>ord[i];
	
	memset(h,-1,sizeof h);
	for(int i=1;i<=n-1;i++){
		int a,b; cin>>a>>b;
		add(a,b),add(b,a);
	}
	
	plt.dfs(1,-1);
	plt.RMQ();
	
	for(int i=2;i<=n;i++){
		get(ord[i-1],ord[i]);
	}
//	int ed=ord[n];
	dfs(1,-1);
	
	for(int i=1;i<=n;i++){
//		if(i!=ed) cout<<res[i]<<endl;
//		else cout<<max(res[i]-1,0)<<endl;
		cout<<max(res[i]+tt[i],0)<<endl;
	}
	
	
	
	return 0;
}
