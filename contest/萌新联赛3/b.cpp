#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=6100;
int a[maxn],L[maxn],R[maxn],LL[maxn],RR[maxn];
int n,q;

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int l=1;l<=n;l++){
        int res=0;
        for(int r=l+1;r<=n;r++){
            if(a[r]<a[l]) res++;
        }
        L[l]=res;
    }

    for(int l=1;l<=n;l++){
        int res=0;
        for(int r=l+1;r<=n;r++){
            if(a[r]>a[l]) res++;
        }
        R[l]=res;
    }

    for(int i=1;i<=n;i++){
        LL[i]+=LL[i-1]+L[i];
        RR[i]+=RR[i-1]+R[i];
    }

    cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        int res=0;
        res=LL[l-1]+(LL[n]-LL[r]);
        
        // res+=R[l]-R[l-1];
        cout<<res<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
