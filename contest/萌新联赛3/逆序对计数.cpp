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

const int maxn = 1e5 + 10;

int c[maxn], bb[maxn], n;
map<pii,int> mp;
int bk[maxn];
ll ans;

void merge_sort(int l, int r){
    if(l >= r) return;

    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(c[i] <= c[j]) bb[k++] = c[i++];
        else{
            bb[k++] = c[j++];
            ans += mid - i + 1; 
        }
    }
    while(i <= mid) bb[k++] = c[i++];
    while(j <= r) bb[k++] = c[j++];

    for(int k = 0, i = l; i <= r; i++){
        c[i] = bb[k++];
    }
}


int q;
void sol(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
        bk[i]=c[i];
    }
    // memcpy(bk,c,sizeof c);
    for(int l=0;l<n;l++){
        for(int r=l+1;r<n;r++){
            ans=0;
            memcpy(c,bk,sizeof bk);
            merge_sort(l,r);
            mp[{l,r}]=ans;
        }
    }
    int q; cin>>q;
    // cout<<mp[{0,n-1}]<<endl;
    while(q--){
        int l,r; cin>>l>>r;
        l--,r--;
    // cout<<mp[{l,r}]<<endl;
        int len=r-l+1;
        int cnt=len*(len-1)/2;
        // cout<<mp[{l,r}]<<endl;
        // cout<<cnt<<endl;
        cout<<mp[{0,n-1}]-mp[{l,r}]+(cnt-mp[{l,r}])<<endl;
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
