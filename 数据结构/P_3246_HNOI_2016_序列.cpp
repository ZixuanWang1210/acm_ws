// #include <bits/stdc++.h>
// #define endl "\n"
// #define debug(x) cout << #x << ": -----> " << x << endl;
// #define inf 0x3f3f3f3f
// #define pii pair<int,int>
// // typedef long long ll;
// // typedef unsigned long long ull;
// // #define int long long

// using namespace std;

// const int maxn=1e5+10;
// int n,q;
// int a[maxn],s[maxn];
// int L[maxn],R[maxn];
// int ans[maxn];

// struct ask{
//     int key,l,r,val,id;
//     bool operator<(const ask &t) const{
//         return key<t.key;
//     }
// } ask[maxn*2];

// struct node{
//     int key,l,r,val;
//     bool operator<(const node &t) const{
//         return key<t.key;
//     }
// } seg[maxn*4];

// void sol(){
//     cin>>n>>q;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         s[i]=s[i-1]+a[i];
//     }  
    
//     for(int i=1;i<=n;i++){
//         L[i]=i;
//         while(a[i]<=a[L[i]-1]) L[i]=L[L[i]-1];
//     }
//     for(int i=n;i>=1;i--){
//         R[i]=i;
//         while(a[i]<=a[R[i]+1]) R[i]=R[R[i]+1];
//     }

//     int cnt_a=0;
//     for(int i=1;i<=q;i++){
//         int l,r; cin>>l>>r;
//         ask[++cnt_a]={l-1,l,r,-1,i};
//         ask[++cnt_a]={r,l,r,1,i};
//     }

    


// }

// signed main(){
//     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//     int _=1;
//     // cin>>_;
//     while(_--){
//         sol();
//     }

//     return 0;
// }
#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
const int N = 2000010;
int n, m, a[N], M[22][N], stk[N], top;
int pre[N], suf[N], fl[N], fr[N], gl[N], gr[N];
int RMQ(int l, int r) { 
    int k = log2(r - l + 1);
    int x = M[k][l], y = M[k][r - (1 << k) + 1];
    return (a[x] < a[y] ? x : y);
}
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) M[0][i] = i;
    for (int i = 1; i <= 21; i++)
        for (int j = 1; j <= n; j++) {
            int x = M[i - 1][j], y = M[i - 1][j + (1 << i - 1)];
            M[i][j] = (a[x] < a[y]) ? x : y;
        }
    for (int i = 1; i <= n; i++) {
        while (top && a[stk[top]] >= a[i]) top--;
        pre[i] = stk[top], stk[++top] = i;
    }
    top = 0;
    for (int i = n; i >= 1; i--) {
        while (top && a[stk[top]] >= a[i]) top--;
        suf[i] = stk[top], stk[++top] = i;
    }
    for (int i = 1; i <= n; i++) 
        fr[i] = fr[pre[i]] + a[i] * (i - pre[i]), 
        gr[i] = gr[i - 1] + fr[i];
    for (int i = n; i >= 1; i--)
        fl[i] = fl[suf[i]] + a[i] * (suf[i] - i),
        gl[i] = gl[i + 1] + fl[i];
    for (int l, r; m--; ) {
        scanf("%lld%lld", &l, &r);
        int p = RMQ(l, r);
        printf("%lld\n", (p - l + 1) * (r - p + 1) * a[p] + 
                        gr[r] - gr[p] - fr[p] * (r - p) + 
                        gl[l] - gl[p] - fl[p] * (p - l));
    }
    return 0;
}