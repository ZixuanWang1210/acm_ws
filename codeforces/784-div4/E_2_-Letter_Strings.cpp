#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
#define pii pair<char,char> 
using namespace std;

// void sol(){
//     int n; cin>>n;
//     set<pii> st;
//     for(int i=1;i<=n;i++){
//         char a,b; cin>>a>>b;
//         st.insert({a,b});
//     }
//     int cnt1[30]={0},cnt2[30]={0};
//     for(auto x:st){
//         int idx1=x.first-'a',idx2=x.second-'a';
//         cnt1[idx1]++,cnt2[idx2]++;
//     }
//     long long ans=0;
//     for(int i=0;i<26;i++){
//         if(cnt1[i]>=2){
//             ans+=(cnt1[i]*(cnt1[i]-1)/2);
//         }
//         if(cnt2[i]>=2){
//             ans+=(cnt2[i]*(cnt2[i]-1)/2);
//         }
//     }
//     cout<<ans<<endl;

// }
void sol(){
    int n; cin>>n;
    int ans=0;
    int mp[100][100]={0};
    
    for(int i=0;i<n;i++){
        string s; cin>>s;
        for(int j=0;j<2;j++){
            for(int c='a';c<='k';c++){
                if(c==s[j]) continue;
                string a=s; a[j]=c;     
                ans+=mp[a[0]-'a'][a[1]-'a'];
            }
        }
        ++mp[s[0]-'a'][s[1]-'a'];

    }
    cout<<ans<<endl;
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
