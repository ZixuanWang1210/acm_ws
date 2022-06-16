#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    string s1,s2; cin>>s1>>s2;
    if(count(_all(s1),'a')!=count(_all(s2),'a')||count(_all(s1),'c')!=count(_all(s2),'c')||count(_all(s1),'b')!=count(_all(s2),'b')){
        cout<<"NO"<<endl;
        return;
    }
    string s,t;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        if(s1[i]!='b'){
            s+=s1[i];
            a.push_back(i);
        }
        if(s2[i]!='b'){
            t+=s2[i];
            b.push_back(i);
        }
    }
    if(s!=t){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<a.size();i++){
        if(s[i] == 'a' ? (a[i] > b[i]) : (a[i] < b[i])){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

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
