#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;
const int N = 2e5 + 5;
int sq = 500;
//  sum 每个整快 
int sum[500],cot[N], ans[N],a[N],n, m;
struct query {
    int l, r, id;
} Q[N];
bool cmp(query& a, query& b) {
    if (a.l / sq != b.l / sq)
        return a.l < b.l;
    if ((a.l / sq) & 1)
        return a.r < b.r;
    return a.r > b.r;
}
inline void add(int p){
    cot[p]++;
    if (cot[p] == 1)sum[p / sq]++;
}
inline void del(int p){
    cot[p]--;
    if (cot[p] == 0)sum[p / sq]--;
}
inline int que() {
    for (int i = 1; i <= sq; i++) {
        if (sum[i - 1] != sq) {
            for (int j = (i - 1) * sq; j < i * sq; j++) {
                if (!cot[j])return j;
            }
        }
    }
}
void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] > 2e5)a[i] = 2e5 + 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }
    sort(Q + 1, Q + 1 + m, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
        while (l > Q[i].l)
            add(a[--l]);
        while (r < Q[i].r)
            add(a[++r]);
        while (l < Q[i].l)
            del(a[l++]);
        while (r > Q[i].r)
            del(a[r--]);
        ans[Q[i].id] = que();
    }
    for (int i = 1; i <= m; i++)cout << ans[i] << endl;
}
// const int maxn=2e5+10;
// int a[maxn];
// int kuai[maxn];
// int num[maxn],cnt[maxn];
// int K=500;
// int ans[maxn];
// struct node{
//     int l,r,id;
//     bool operator<(const node & t) const{
//         // if(kuai[l]==kuai[t.l]) return r<t.r;
//         // return kuai[l]<kuai[t.l]; 
//         if(l/K!=t.l/K) return l<t.l;
//         if((l/K)&1) return r>t.r;
//         return r>t.r;
//     }
// } ask[maxn];

// void add(int x){
//     if(!cnt[x]) num[x/K] ++;
//     cnt[x]++;
// }

// void del(int x){
//     if(cnt[x]==1) num[x/K]--;
//     cnt[x]--;
// }

// void query(int x){
//     for(int i=1;i<=K;i++){
//         if(num[i-1]!=K){
//             for(int j=(i-1)*K;j<i*K;j++){
//                 if(!cnt[j])
//                     ans[ask[x].id]=j;
//                     return;
//             }
//         }
//     }
// }

// void sol(){
//     int n,m; cin>>n>>m;
//     int len=sqrt(n);
//     for(int i=1;i<=n;i++) cin>>a[i];
//     for(int i=1;i<=n;i++) if(a[i]>2e5) a[i]=2e5+1;
//     for(int i=1;i<=n;i++) kuai[i]=(i-1)/len+1;
//     for(int i=1;i<=m;i++){
//         cin>>ask[i].l>>ask[i].r;
//         ask[i].id=i;
//     }
//     sort(ask+1,ask+1+m);

//     int l=1,r=0;
//     for(int i=1;i<=m;i++){
//         while(l>ask[i].l) add(a[--l]);
//         while(r<ask[i].r) add(a[++r]);
//         while(l<ask[i].l) del(a[l++]);
//         while(r>ask[i].r) del(a[r--]);
//         query(i);
//     }
//     for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
// }

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
