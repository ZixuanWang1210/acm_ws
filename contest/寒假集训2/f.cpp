#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=10;
int n,q;
vector<int> v;
vector<char> c;
int f[N];
int a[N];
int mp[N];
ll sum;
const unsigned long long P=10000000071000000007;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    int idx=1;
    for(int i=0;i<n-1;i++){
        char t; cin>>t;
        if(t=='*'){
            f[i]=idx;
            f[i+1]=idx;
        }
        else{
            if(f[i]!=0)idx++;
        }
        c.push_back(t);
    }

    for(int i=0;i<n;i++)cin>>a[i];

    idx=1;
    for(int i=0;i<n;i++){
        // int t; cin>>t;
        if(f[i]==0) sum=(a[i]%P+sum)%P;
        else{
            int tt=1;
            while(f[i]){
                tt=tt*a[i];
                i++;
            }
            mp[idx++]=tt;
            i--;
        }
    }

    while(q--){
        int x,y;cin>>x>>y;x--;
        if(f[x]==0){
            sum=((sum-a[x])%P+y%P)%P;
            a[x]=y;
        }
        else{
            int idx=f[x];
            mp[idx]=(((mp[idx]/a[x])%P)*(y%P))%P;
            a[x]=y;
        }
        ll sum_ji = 0;
        for(int i=1;i<idx;i++){
            sum_ji=(mp[i]%P+sum_ji)%P;
        }

        ll ans = (sum%P+sum_ji%P)%P;
        cout<<ans<<endl;
    }
    // cout << sum;

    return 0;
}
