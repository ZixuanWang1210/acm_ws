#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1100;
int p[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void merge(int a,int b){
    a=find(a),b=find(b);
    p[b]=a;
    return;
}

void sol(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        merge(a,b);
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(p[i]==i) ans++;
    }

    cout<<ans<<endl;

    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
