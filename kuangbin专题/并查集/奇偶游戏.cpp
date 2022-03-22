#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


const int maxn=5100;
int p[maxn],d[maxn];
int n,m;

int find(int x){
    if(x!=p[x]){
        int pa=find(x);
        d[x]^=d[p[x]];
        p[x]=pa;
    }
    return p[x];
}

int merge(int a,int b,int c){
    a=find(a),b=find(b);

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;

    while(m--){
        int l,r; cin>>l>>r;
        string op; cin>>op;
        l--;

        l=find(l),r=find(r);
        int tt=0;
        if(op=="even") tt=1;
        else tt=0; 

        if(l==r){

        }


    }
    

    return 0;
}
