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
int cost;
set<char> now;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int c; string s;
        cin>>c>>s;
        v.push_back({c,s});
    }    
    sort(v.begin(),v.end());

    for(auto x:v){
        string ss=x.second;
        int cost=x.first;
        set<char> nex;
        set<char> tmp;
        nex=now;

        for(int i=0;i<ss.length();i++){
            nex.insert(ss[i]);
            tmp.insert(ss[i]);
        }
        if(nex==now){
            if(tmp.size()==3){
                cost=min(cost,x.first);
            }
            continue;
        }
        else{
            bool hanyu=1;
            for(auto xx:now){
                if(tmp.find(xx)==tmp.end()) hanyu=false;
            }
            if(hanyu){
                cost=x.first;
                now=tmp;
            }
            else{
                cost+=x.first;
                now=nex;
            }
        }
    }


    cout<<cost;

    return 0;
}
