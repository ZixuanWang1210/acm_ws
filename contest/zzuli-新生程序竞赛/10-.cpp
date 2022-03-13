#include<bits/stdc++.h>
// #define int long long
using namespace std;

const int P=1000000007;
const int maxn=11000;
#define pii pair<int,int>
#define int long long
int mp[maxn][maxn];
vector<vector<int>> v(maxn);
vector<vector<int>> v2(maxn);
int sum[3*maxn];
int ans=1e15;
int n;


void sol1(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t; cin>>t;
            mp[i][j]=t;
            v[i+j].push_back(t);
        }
    }

    for(int i=1;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            sum[i]+=v[i][j];
        }
        sum[i]+=sum[i-1];
    }
    sum[1]=0;
    for(int i=2;i<=2*n;i++){
        int sum11=sum[i-1];
        int sum22=sum[2*n]-sum[i];
        // cout<<sum11<<' '<<sum22<<endl;
        ans=min(ans,abs(sum11-sum22));
    }
    // cout<<ans;
}
void sol2(){
    // int n; cin>>n;
    // v.clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // int t; cin>>t;
            int t=mp[i][j];
            v2[i-j+n].push_back(t);
        }
    }
    memset(sum,0,sizeof sum);
    for(int i=1;i<v2.size();i++){
        for(int j=0;j<v2[i].size();j++){
            sum[i]+=v2[i][j];
        }
        sum[i]+=sum[i-1];
    }
    for(int i=1;i<=2*n-1;i++){
        int sum11=sum[i-1];
        int sum22=sum[2*n-1]-sum[i];
        // cout<<sum11<<' '<<sum22<<endl;
        ans=min(ans,abs(sum11-sum22));
    }
    // cout<<ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int _; _=1;
    while(_--){
        sol1();
        sol2();
        cout<<ans;
    }

    return 0;
}