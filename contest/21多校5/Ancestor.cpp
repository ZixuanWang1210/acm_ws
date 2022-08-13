#include<bits/stdc++.h>
#include<random>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define bl setiosflags(ios::fixed) << setprecision
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
#define inf 0x3f3f3f3f
#define gg "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define db double
#define us unordered_set 
#define um unordered_map
#define pq priority_queue
mt19937_64 sj(2022);
//#define x first
//#define y second
#define int ll
typedef long long ll;
typedef pair<int, int> pii;
const int N=1e5+10,M=2e5+10;
int h[N], e[M], ne[M], idx,w[M];
int depth[N], fa[N][19];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
void bfs(int root)
{
    queue<int> q;
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    q.push(root);
    while (q.size())
    {
        int t = q.front();q.pop();
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                for (int k = 1; k <= 18; k ++ )
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 18; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
      if(a==b) return a;
    for (int k = 18; k >= 0; k -- )
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

int a[N],pp[N];
int F[N];
struct Node
{
    int l, r;
   	int LCA;
}tr[N * 4];

void pushup(int u)
{
    tr[u].LCA=lca(tr[u<<1].LCA,tr[u<<1|1].LCA);
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r,a[l]};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].LCA;  
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        int res=a[l];
        if (l <= mid ) res = lca(res,query(u << 1, l, r));
        if (r > mid) res =lca(res, query(u << 1 | 1, l, r));
        return res;
    }
}
int ans[N];
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(h, -1, sizeof h);
	int n,k;cin>>n>>k;
	for(int i=1;i<=k;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>pp[i];
	F[1]=-1;
	for(int i=2;i<=n;i++)
	{
		cin>>F[i];
		add(F[i],i,pp[i]),add(i,F[i],pp[F[i]]);
	}	
	bfs(1);
	build(1,1,k);
	for(int i=1;i<=k;i++)
	{
		int u;
		if(i>1 && i<k)
			u=lca(query(1,1,i-1),query(1,i+1,k));
		else if(i==1)
			u=query(1,i+1,k);
		else u=query(1,1,i-1);
		ans[i]=pp[u];
	}
	for(int i=1;i<=n;i++) cin>>pp[i];
	memset(h, -1, sizeof h);
    //memset(h, -1, sizeof h);
    idx=0;
	for(int i=2;i<=n;i++)
	{
		cin>>F[i];
		add(F[i],i,pp[i]),add(i,F[i],pp[F[i]]);
	}	
	bfs(1);
	build(1,1,k);
	int res=0;
	for(int i=1;i<=k;i++)
	{
		int u;
		if(i>1 && i<k)
			u=lca(query(1,1,i-1),query(1,i+1,k));
		else if(i==1)
			u=query(1,i+1,k);
		else u=query(1,1,i-1);
		if(pp[u]<ans[i]) res++;
	}
	cout<<res;
	//for(int i=1;i<=k;i++) cout<<ans[i]<<" ";
	return 0;
	
}
