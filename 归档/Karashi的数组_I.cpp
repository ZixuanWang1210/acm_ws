#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=5e5+10;
int n,m,len,res;
set<int> s;
int a[maxn];
void sol(){
    cin>>n>>m>>len;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(i<n-len){
                res++;
            }
            if(i>len+1&&a[i-len-1]!=0) res++;
        }
    }
    while(m--){
        int x,y; cin>>x>>y;
        if(a[x]==0&&y!=0){
            if(x<n-len&&a[x+len+1]!=0) res--;
            if(x>len+1&&a[x-len-1]!=0) res--;
            a[x]=y;
        }
        else if(a[x]!=0&&y==0){
            if(x<n-len&&a[x+len+1]!=0) res++;
            if(x>len+1&&a[x-len-1]!=0) res++;
            a[x]=y;
        }
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
