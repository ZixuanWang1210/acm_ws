#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    string s;
    cin>>s;
    int mp[30]={0};
    for(int i=0;i<s.length();i++){
        int ver=s[i]-'a';
        mp[ver]++;
    }
    int cnt=0;
    int cnt1=0;
    for(int i=0;i<26;i++){
        // if(mp[i]>=2){
            cnt+=mp[i]/2;
            cnt1+=mp[i]%2;
        // }
    }
    int ans1=cnt/k;
    cnt1+=(cnt%k)*2;
    ans1*=2;
    if(cnt1&&cnt1>=k) ans1++;
    cout<<ans1<<endl;


}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) sol();
    

    return 0;
}
