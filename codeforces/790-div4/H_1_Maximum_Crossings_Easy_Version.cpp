#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define ll long long
// #define int long long

using namespace std;

const int maxn=2e5+10;
int c[maxn], bb[maxn], n;
ll ans;
void merge_sort(int l, int r){
    if(l >= r) return;

    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(c[i] < c[j]) bb[k++] = c[i++];
        else{
            bb[k++] = c[j++];
            ans += mid - i + 1; //使用全局变量存储答案
        }
    }
    while(i <= mid) bb[k++] = c[i++];
    while(j <= r) bb[k++] = c[j++];

    for(int k = 0, i = l; i <= r; i++){
        c[i] = bb[k++];
    }
}

void sol(){
    int n; cin>>n;
    ans=0;
    for(int i=0;i<n;i++) cin>>c[i];

    merge_sort(0,n-1);
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
