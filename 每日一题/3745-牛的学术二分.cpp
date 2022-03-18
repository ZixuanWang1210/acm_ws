#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;
int n,L;
const int maxn=1e5+10;
vector<int> v(maxn);

bool check(int x){
    int xx=L;
    int cnt=0;
    for(int i=n;i>=1;i--){
        if(xx>0&&v[i]<x){
            xx--;
            if(v[i]+1>=x){
                cnt++;
            }
        }
        else if(v[i]>=x){
            cnt++;
        }
        // else if(xx&&v[i]<x){
        //     // int det=x-v[i];
        //     xx-=1;
        //     if(xx>=0) cnt++;
        // }
        if(cnt>=x) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>L;
    // int ans=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin()+1,v.begin()+1+n);
    int l=1,r=maxn;
    int ans=0;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;

    return 0;
}
