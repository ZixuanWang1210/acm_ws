#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int ans=0;
void build(int id,int l,int r){
    if(l==r){
        ans=max(ans,id);
        return;
    }
    int mid=l+r>>1;
    int len1=mid-l+1,len2=r-mid;
    if(len1==len2){
        build(id*2+1,mid+1,r);
    }
    else if(len1>len2){
        build(id*2,l,mid);
    }
    else if(len1<len2){
        build(id*2+1,mid+1,r);
    }
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        ans=0;
        int x; cin>>x;
        build(1,1,x);
        cout<<ans<<endl;
    }
    

    return 0;
}
