#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    string s,p;
    cin>>s>>p;
    int idx[100000];
    memset(idx,-1,sizeof idx);
    set<int> st;
    int j=s.length()-1;
    for(int i=p.length()-1;i>=0;i--){
        for(;j>=0;j--){
            if(p[i]==s[j]){
                idx[i]=j;
                j--;
                break;
            }
        }
        if(idx[i]==-1){
            cout<<"NO"<<endl;
            return;
        }
        st.insert(idx[i]);
    }
    for(int i=0;i<p.length();i++){
        for(int j=idx[i]+1;j<s.length();j++){
            if(s[j]==p[i]){
                if(st.count(j)) continue;
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) sol();
    

    return 0;
}








