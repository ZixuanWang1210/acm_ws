#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;

using namespace std;

const int maxn=1e5+10;
int n;
int p[maxn],ans[maxn];
vector<int> mp;
vector<int> g[maxn];

int get(int x){
    return lower_bound(mp.begin(),mp.end(),x)-mp.begin()+1;
}


struct BIT{
    vector<int> tr;
    int n;
    BIT(int _n) : tr(_n), n(_n) {}
    int lowbit(int x){
        return x&-x;
    }
    void add(int x,int k){
        for(;x<=n;x+=lowbit(x)) tr[x]+=k;
    }
    int ask(int x){
        int ans=0;
        for(;x;x-=lowbit(x)) ans+=tr[x];
        return ans;
    }
};

BIT bit(maxn);

void dfs(int x){
    ans[x]=-(bit.ask(n)-bit.ask(p[x]));
    for(auto i:g[x]) dfs(i);
    ans[x]+=(bit.ask(n)-bit.ask(p[x]));
    bit.add(p[x],1);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        mp.push_back(p[i]);
    }
    sort(mp.begin(),mp.end());
    for(int i=1;i<=n;i++){
        p[i]=get(p[i]);
    }
    for(int i=2;i<=n;i++){
        int fa;
        cin>>fa;
        g[fa].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
