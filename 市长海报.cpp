#include<bits/stdc++.h>
#define ls tr[u>>1]
#define rs tr[u>>1|1]
#define rt tr[u]
using namespace std;
    

int n;
const int maxn=4e4+10;
int tr[maxn];
vector<int> hs;

struct node{
    int l,r,v;
    int cnt;
    int len;
} tr[maxn<<2];

struct edge{
    int l,r;
} seg[maxn<<1];

int get(int x){
    return lower_bound(hs.begin(),hs.end(),x)-hs.begin();
}

void build(int u,int l,int r){
    if(l==r){
        rt={l,r,0,0};
    }
}

void sol(){
    cin>>n;
    memset(tr,0,sizeof tr);
    memset(seg,0,sizeof seg);
    hs.clear();

    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        r++;
        seg[i]={l,r};
        hs.push_back(l),hs.push_back(r);
    }

    sort(hs.begin(),hs.end());
    hs.erase(unique(hs.begin(),hs.end()),hs.end());

    build(1,0,hs.size()-2);




}

int main(){
    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}