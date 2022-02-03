#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

const int N=1e5+10,M=1e4+10;
int n,m;
int a[N];
struct node{
    int l,r;
    int cnt;
} tr[N*4+N*17];

vector<int> nums;
int root[N],idx;

int find(int x){
    return lower_bound(nums.begin(),nums.end(),x)-nums.begin();
}

// int build(int l,int r){
//     int u=++idx;
//     if(l==r) return u;
//     int mid=l+r>>1;
//     tr[u].l=build(l,mid), tr[u].r=build(mid+1,r);
//     return u;
// }
// int insert(int p, int l, int r, int x)
// {
//     int q = ++ idx;
//     tr[q] = tr[p];
//     if (l == r)
//     {
//         tr[q].cnt ++ ;
//         return q;
//     }
//     int mid = l + r >> 1;
//     if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
//     else tr[q].r = insert(tr[p].r, mid + 1, r, x);
//     tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
//     return q;
// }

int insert(int p,int l,int r,int x){
    int q=++idx;
    tr[q]=tr[p];
    if(l==r){
        tr[q].cnt++;
        return q;
    }
    int mid=l+r>>1;
    if(x<=mid) tr[q].l=insert(tr[p].l,l,mid,x);
    else tr[q].r=insert(tr[p].r,mid+1,r,x);
    tr[q].cnt=tr[tr[q].l].cnt+tr[tr[q].r].cnt;
    return q;
}

int query(int L,int R,int l,int r,int k){
    if(l==r) return r;
    int cnt=tr[tr[L].l].cnt-tr[tr[R].l].cnt;
    int mid=l+r>>1;
    if(k<=cnt) return query(tr[L].l,tr[R].l,l,mid,k);
    else return query(tr[L].r,tr[R].r,mid+1,r,k-cnt);
}

// int query(int q, int p, int l, int r, int k)
// {
//     if (l == r) return r;
//     int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
//     int mid = l + r >> 1;
//     if (k <= cnt) return query(tr[q].l, tr[p].l, l, mid, k);
//     else return query(tr[q].r, tr[p].r, mid + 1, r, k - cnt);
// }

// int main(){
//     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         nums.push_back(a[i]);
//     }

//     sort(nums.begin(),nums.end());
//     nums.erase(unique(nums.begin(),nums.end()),nums.end());

//     // root[0]=build(0,nums.size()-1); 

//     for(int i=1;i<=n;i++){
//         root[i]=insert(root[i-1],0,nums.size(),find(a[i]));
//     }

//     while(m--){
//         int l,r,k;cin>>l>>r>>k;
//         cout<<nums[query(root[r], root[l - 1], 0, nums.size() - 1, k)]<<endl;
//     }

//     return 0;
// }
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        nums.push_back(a[i]);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    // root[0] = build(0, nums.size() - 1);

    for (int i = 1; i <= n; i ++ )
        root[i] = insert(root[i - 1], 0, nums.size() - 1, find(a[i]));

    while (m -- )
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", nums[query(root[r], root[l - 1], 0, nums.size() - 1, k)]);
    }

    return 0;
}