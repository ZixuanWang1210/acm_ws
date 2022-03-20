#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
const int maxn=100;
int tr[maxn];

int lowbit(int x){
    return x&-x;
}

void add(int x,int k){
    for(;x<=n;x+=lowbit(x))
        tr[x]+=k;
}

int ask(int x){
    int res=0;
    for(;x;x-=lowbit(x)) res+=tr[x];
    return res;
}


void sol(){
    memset(tr,0,sizeof tr);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t; cin>>t;
        add(i,t);
    }
    string op;
    while(cin>>op,op!="End"){
        if(op=="Add"){
            int x,k; cin>>x>>k;
            add(x,k);
        }
        else if(op=="Sub"){
            int x,k; cin>>x>>k;
            add(x,-k);
        }
        else{
            int l,r; cin>>l>>r;
            int res=ask(r)-ask(l-1);
            cout<<res<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    for(int i=1;i<=_;i++){
        cout<<"Case "<<i<<':'<<endl;
        sol();
    }
  
    return 0;
}
