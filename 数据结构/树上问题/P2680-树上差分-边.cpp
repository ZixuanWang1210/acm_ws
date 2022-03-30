#include<bits/stdc++.h> 
//#define int long long 
using namespace std;

const int maxn=5e6+10;
int e[maxn],ne[maxn],w[maxn],h[maxn],idx;
int n,m;

void add(int a,int b,int c){
	e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

struct LCA {
    /*
    $st[cnt][0]$：树的$dfs$序，第$cnt$个遍历的点是$st[cnt][0]$
    $dfn[x]$：节点编号为x的节点，第一次出现在dfs序中的位置
    $dep[x]$：节点x在树中的深度
    */

    int dfn[maxn], dep[maxn], st[maxn][30], dis[maxn], fath[maxn], cnt;
    void dfs(int x, int fa) {
        dfn[x] = ++cnt, dep[x] = dep[fa] + 1, st[cnt][0] = x, fath[x]=fa;
        for (int i = h[x]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            dis[j]=dis[x]+w[i];
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
    
    int get_dis(int l,int r){
    	int lca=get(l,r);
    	return dis[l]+dis[r]-dis[lca]*2;
	}

} plt;

struct node{
	int u,v;
	int lca,dist;
} plan[maxn];

int res[maxn];
void get_dif(int u,int fa){
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fa) continue;
		get_dif(j,u);
		res[u]+=res[j];
	}
}

bool check(int x){
	memset(res,0,sizeof res);
	int num=0,ans=0;
	for(int i=1;i<=m;i++){
		if(plan[i].dist>x){
			num++;
			int u=plan[i].u,v=plan[i].v,lca=plan[i].lca;
			ans=max(ans,plan[i].dist-x);
			res[u]++,res[v]++,res[lca]-=2;
		}
	}
	if(num==0) return true;
	get_dif(1,-1);
	for(int i=2;i<=n;i++){
		if(res[i]==num&&plt.dis[i]-plt.dis[plt.fath[i]]>=ans) return true;
	}
	return false;
	
}

signed main(){
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	memset(h,-1,sizeof h);
	for(int i=1;i<=n-1;i++){
		int a,b,t; cin>>a>>b>>t;
		add(a,b,t),add(b,a,t);
	}
	
	plt.dfs(1,-1);
	plt.RMQ();
	
	for(int i=1;i<=m;i++){
		cin>>plan[i].u>>plan[i].v;
		plan[i].lca=plt.get(plan[i].u,plan[i].v);
		plan[i].dist=plt.get_dis(plan[i].u,plan[i].v);
	}
	long long l=0,r=1e15,ans;
	while(l<=r){
//		cout<<1<<endl;
		int mid=(l+r)>>1;
		if(check(mid)){
//			cout<<mid<<endl;
			ans=mid;
			r=mid-1;
//			r=mid;
		}
		else l=mid+1;
	}
	
	cout<<ans<<endl;
	return 0;
}
