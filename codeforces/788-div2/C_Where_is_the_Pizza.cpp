#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1e5+10;
int n,a[maxn],b[maxn],c[maxn];
int p[maxn];
const int P=1e9+7;

int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int qmi(int a,int k,int p){
    int res=1;
    while(k){
        if(k&1) res=1ll*res*a%P;
        a=1ll*a*a%P;
        k>>=1;
    }
    return res;
}

void sol(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];

    for(int i=0;i<n+1;i++) p[i]=i;

    for(int i=0;i<n;i++){
        if(a[i]==b[i]) p[a[i]]=0;
        int pa=find(a[i]),pb=find(b[i]);
        p[pa]=pb;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        p[find(c[i])]=0;
    }
    for(int i=1;i<n+1;i++){
        if(p[i]==i) cnt++;
    }
    cout<<qmi(2,cnt,P)<<endl;
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
