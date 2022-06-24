#include<bits/stdc++.h>

typedef long long LL;
using namespace std;

const int N = 1e6+10;
int n, m;
int k;
int a[N],b[N],s[N];

vector<int> has;
int w[N];
struct Node
{
    int l, r;
    LL sum, add;
}tr[N * 4];

int get(int x){
	return lower_bound(has.begin(),has.end(),x)-has.begin()+1;
}

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum ^ tr[u << 1 | 1].sum;
}
void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.add ^= root.add, left.sum ^= (LL) root.add;
        right.add ^= root.add, right.sum ^= (LL) root.add;
        root.add = 0;
    }
}
void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, 0, 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int l, int r, int v)
{
    if (l <= tr[u].l && tr[u].r <= r)
    {
        tr[u].sum ^=  v;
        tr[u].add ^= v;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, v);
        if (r > mid) modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}
LL query(int u, int l, int r)
{
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL v = 0;
    if (l <= mid) v = query(u << 1, l, r);
    if (r > mid) v ^= query(u << 1 | 1, l, r);
    return v;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>w[i];
		has.push_back(a[i]),has.push_back(b[i]);
        has.push_back(b[i]+1);
	}
	has.erase(unique(has.begin(),has.end()),has.end());
	sort(has.begin(),has.end());

	int siz=has.size();
	build(1,1,siz);
	for(int i=1;i<=n;i++){
		int l=a[i],r=b[i];
        int rr=b[i]+1;
		l=get(l),r=get(r);
        rr=get(rr);
		modify(1,l,r,w[i]);

		s[l]++,s[rr]--;
	}
	for(int i=1;i<=siz;i++){
		s[i]=s[i-1]+s[i];
	}

	int ans=-1;

	for(int i=1;i<=siz;i++){
		if(s[i]>=k) ans=max(ans*1ll,query(1,i,i));
	}
	cout<<ans<<endl;

    return 0;
}
