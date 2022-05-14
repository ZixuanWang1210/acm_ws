#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;
int lowbit(int x){
    return x&-x;
}

const int maxn=3e6+10;
int trr[maxn],trl[maxn];
int n;

void addl(int x,int k){
    for(;x<=n;x+=lowbit(x)) trl[x]+=k;
}
void addr(int x,int k){
    for(;x<=n;x+=lowbit(x)) trr[x]+=k;
}
int suml(int x){
    int res=0;
    for(;x;x-=lowbit(x)) res+=trl[x];
    return res;
}
int sumr(int x){
    int res=0;
    for(;x;x-=lowbit(x)) res+=trr[x];
    return res;
}
int askl(int a,int b){
    return suml(b)-suml(a-1);
}
int askr(int a,int b){
    return sumr(b)-sumr(a-1);
}

int cntl[maxn],cntr[maxn];
map<pair<int,int>,int> st;

void sol(){
    int q; cin>>n>>q;
    while(q--){
        int op; cin>>op;
        if(op==1){
            int x,y; cin>>x>>y;
            // st.insert({x,y});
            st[{x,y}]++;
            // if(cntl[x]==0) {
            //     addl(x,1),cntl[x]++;
            //     addr(y,1),cntr[y]++;
            // }
            // else{
            //     cntl[x]++,cntr[y]++;
            // }
            if(cntl[x]==0) addl(x,1);
            if(cntr[y]==0) addr(y,1);
            cntl[x]++,cntr[y]++;
        }
        else if(op==2){
            int x,y; cin>>x>>y;
            int q=st[{x,y}];
            st[{x,y}]=0;
            cntl[x]-=q,cntr[y]-=q;
            if(cntl[x]==0) addl(x,-1);
            if(cntr[y]==0) addr(y,-1);
        }
        else{
            int x,y,xx,yy; cin>>x>>y>>xx>>yy;
            if(askl(x,xx)==xx-x+1||askr(y,yy)==yy-y+1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
