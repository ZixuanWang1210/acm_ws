#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=3e4+10;
int t;
int f[N],s[N],d[N];

int find(int x){
    if(x!=f[x]){
        int root=find(f[x]);
        d[x]+=d[f[x]];
        f[x]=root;
    }
    return f[x];
}



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    for(int i=0;i<N;i++){
        f[i]=i;
        s[i]=1;
        d[i]=0;
    }

    while(t--){
        char op; cin>>op;
        int a,b; cin>>a>>b;
        if(op=='M'){
            a=find(a),b=find(b);
            d[a]+=s[b];
            s[b]+=s[a];
            f[a]=b;
        }
        else{
            int pa=find(a),pb=find(b);
            if(pa!=pb) cout<<"-1"<<endl;
            else cout<<max(0,abs(d[a]-d[b])-1)<<endl;
        }
    }
    

    return 0;
}
