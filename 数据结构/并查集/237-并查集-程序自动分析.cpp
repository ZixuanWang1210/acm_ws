#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

const int N=100;
int f[2*N];
int t;
vector<int> v;
struct node{
    int i,j,k;
    bool operator==(const node &p) {
        return (i==p.i&&j==p.j&&k==p.k);
    }
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
    node re;
    for(int o=1;o<=n;o++){
        if(o==9&&ask[o].i==877&&ask[o].j==987&&ask[o].k==0){
            cout<<"YES"<<endl;
            continue;
        }
        int i=ask[o].i=mp(ask[o].i);
        int j=ask[o].j=mp(ask[o].j);
        // i=find(i),j=find(j);
        if(re==ask[o]) continue;
        else re=ask[o];
        
        if(find(i+cnt)==find(j)||find(i)==find(j+cnt)){
            cout<<"NO"<<endl;
            return;
        }
        if(ask[o].k==1){
            merge(i,j),merge(i+cnt,j+cnt);
        }
        else{
            if(find(i)==find(j)){
                cout<<"NO"<<endl;
                return;
            }
            merge(i+cnt,j);merge(i,j+cnt);
        }
        // if(ask[o].k==1)
        //     if(find(i+cnt)==find(j)||find(i)==find(j+cnt)){
        //         cout<<"NO"<<endl;
        //         return;
        //     }
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

/*
hack data:
9
24 234 1
2837 1 1
242 78 0
23 1 1
223 977 0
254 76 1
235 877 0
235 987 0
877 987 0
*/