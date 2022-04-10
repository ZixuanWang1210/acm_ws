#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n,m,k,cnt;
const int maxn=1e5+10;
int a[maxn],s[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int l,r; cin>>l>>r;
        a[l]++,a[r+1]--;
    }
    for(int i=1;i<=k;i++){
        int t; cin>>t;
    }
    int st=0,ed=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        if(s[i-1]==0&&s[i]==1&&st==0){
            st=i;
            cout<<i<<endl;
        }
        if(s[i]==1&&s[i+1]==0){
            cnt+=(i-st);
            st=0;
        }
    }
    cout<<cnt<<endl;
    

    return 0;
}
