#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

const int N=1e5+10;
int f[2*N];
int t;
vector<int> v;
struct node{
    int i,j,k;
} ask[N]; 
int idx;

int find(int x){
    if(x!=f[x]) f[x]=find(f[x]);
    return f[x];
}

int mp(int x){
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

void merge(int x,int y){
    f[find(x)]=find(y);
}

void sol(){
    int n; cin>>n;
    memset(f,0,sizeof f);
    memset(ask,0,sizeof ask);
    v.clear();
    idx=0;
    for(int o=1;o<=n;o++){
        int i,j,k;cin>>i>>j>>k;
        if(i>j) swap(i,j);
        ask[++idx]={i,j,k};
        v.push_back(i),v.push_back(j);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int cnt=v.size();
    for(int i=1;i<=2*cnt;i++) f[i]=i;
    for(int o=1;o<=n;o++){
        int i=ask[o].i=mp(ask[o].i);
        int j=ask[o].j=mp(ask[o].j);
        // i=find(i),j=find(j);
        if(find(i+cnt)==find(j)||find(i)==find(j+cnt)){
            cout<<"NO"<<endl;
            return;
        }
        if(ask[o].k==1){
            merge(i,j),merge(i+cnt,j+cnt);
        }
        else{
            merge(i+cnt,j);merge(i,j+cnt);
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        sol();
    }
    
    return 0;
}
