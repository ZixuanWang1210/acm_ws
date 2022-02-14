#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2e5+10;
int n,t;
string s;
int r[maxn],b[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    cin>>s;
    for(int i=0;i<s.length();i++){
        int st; cin>>st;
        if(s[i]=='B'){
            b[st]++;
            b[st+t]--;
        }
        else{
            r[st]++;
            r[st+t]--;
        }
    }
    int ans=0;
    for(int i=1;i<=maxn;i++){
        b[i]=b[i-1]+b[i];
        r[i]=r[i-1]+r[i];
        if(b[i]!=0&&r[i]==0){
            // cout<<i<<endl;
            ans++;
        }
    }
    
    cout<<ans;
    return 0;
}
