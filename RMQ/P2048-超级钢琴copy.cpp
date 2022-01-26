#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=5e5+10;
int n,k,l,r;
int dp[N][24];
int a[N],sum[N];

void ST(){
    for(int j=0;j<=24;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            if(j==0) dp[i][j]=i;
            else{
                int x=dp[i][j-1],y=dp[i+(1<<j-1)][j-1];
                dp[i][j]=sum[x]>sum[y]?x:y;
            }
        }
    }
}

int query(int l, int r){
    int k=log2(r-l+1);
    // debug(l);debug(k);debug(r);
    int x=dp[l][k],y=dp[r-(1<<k)+1][k];
    return sum[x]>sum[y]?x:y;
}

struct node{
    int o,l,r,t;
    node(int o,int l,int r):o(o),l(l),r(r),t(query(l,r)){}
    friend bool operator < (const node& a, const node& b) {
        return sum[a.t] - sum[a.o - 1] < sum[b.t] - sum[b.o - 1];
    }
};

priority_queue<node> q;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>k>>l>>r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }

    ST();

    for(int i=1;i<=n;i++)
        if(i+l-1<=n)
            q.push(node{i,i+l-1,min(i+r-1,n)});
    
    long long ans=0;
    while(k--){
        int o=q.top().o, l=q.top().l, r=q.top().r, t=q.top().t;
        q.pop();
        ans+=sum[t]-sum[o-1];
        if(l!=t)q.push(node(o,l,t-1));
        if(t!=r)q.push(node(o,t+1,r));
    }
    cout<<ans<<endl;
    return 0;
}
