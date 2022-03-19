#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,string>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
vector<pii> v;
bool a[10];
int ans;

bool _get(string s,string now){

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int c; string s;
        cin>>c>>s;
        v.push_back({c,s});
    }    
    sort(v.begin(),v.end());

    
    for(auto x : v){
        int cost=x.first;
        string s=x.second;

        for(int i=0;i<s.length();i++){
            int bz=false;
            if(s[i]=='A'&&a[1]==false){
                a[1]=true;
                
                if(bz==false) ans+=cost,bz=true;
            }
            if(s[i]=='B'&&a[2]==false){
                a[3]=true;
                if(bz==false) ans+=cost,bz=true;
            }
            if(s[i]=='C'&&a[3]==false){
                a[3]=true;
                if(bz==false) ans+=cost,bz=true;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
