#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define mod 1000000007
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=2e5+10;
int l[maxn],r[maxn]; // l[i]以i为最大值区间左端点 r[i]以i为最大值的区间右端点
int n;
int a[maxn],s[maxn];

int d1[maxn][20];   //最大
int d2[maxn][20];   //最小
void RMQ_init(int n) {
    for (int i = 0; i <= n; i++) {
        d1[i][0] = d2[i][0] = s[i];
    }
    for (int j = 1; 1 << j <= n + 1; j++) {
        for (int i = 0; i + (1 << j) - 1 <= n; i++) {
            int x = d1[i][j - 1], y = d1[i + (1 << j - 1)][j - 1];
            d1[i][j] = max(x,y);
            x = d2[i][j - 1], y = d2[i + (1 << j - 1)][j - 1];
            d2[i][j] = min(x,y);
        }
    }
}
int RMQ1(int L, int R) {
    int k = log2(R - L + 1);
    int x = d1[L][k], y = d1[R - (1 << k) + 1][k];
    return x >= y ? x : y;
}
int RMQ2(int L, int R) {
    int k = log2(R - L + 1);
    int x = d2[L][k], y = d2[R - (1 << k) + 1][k];
    return x <= y ? x : y;
}

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    a[0]=a[n+1]=inf;
    for(int i=1;i<=n;i++){
        l[i]=i;
        while(a[i]>=a[l[i]-1]) l[i]=l[l[i]-1];
    }
    for(int i=n;i>=1;i--){
        r[i]=i;
        while(a[i]>=a[r[i]+1]) r[i]=r[r[i]+1];
    }

    RMQ_init(n);

    int ok = 1;
    for (int i = 1; i <= n; i++) {
        int t = RMQ1(i, r[i]) - RMQ2(l[i] - 1, i - 1);
        // printf("%d %d\n", RMQ1(i, r[i]), RMQ2(l[i] - 1, i - 1));
        if (a[i] < t) ok = 0;
    }
    puts(ok ? "YES" : "NO");

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
