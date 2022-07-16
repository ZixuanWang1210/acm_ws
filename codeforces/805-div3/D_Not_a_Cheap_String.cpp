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

void sol(){
    // int n; cin>>n;
    string s; cin>>s;
    // map<int,int> mp;
    vector<int> cnt(27);
    for(int i=0;i<s.length();i++){
        cnt[s[i]-'a']++;
    }

    int p; cin>>p;
    int cost=0;
    for(int i=0;i<26;i++){
        cost+=(i+1)*cnt[i];
        if(cost<=p) continue; 
        else{
            cost-=(i+1)*cnt[i];
            int res=p-cost;
            cnt[i]=res/(i+1);
            i++;
            while(i<26){
                cnt[i]=0;
                i++;
            }
            break;
        }
    }
    for(int i=0;i<s.length();i++){
        char x=s[i];
        if(cnt[x-'a']){
            cout<<x;
            cnt[x-'a']--;
        }
    }
    cout<<endl;
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
