#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define piii pair<int,pair<int,int>> 
#define pii pair<int,int> 

using namespace std;

const int maxn=1e6+10;
int x[maxn],v[maxn];
vector<piii> mp;
int n,ans;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
        mp.push_back({x[i],{v[i],i}});
    }
    // cout<<11111<<endl;

    sort(mp.begin(),mp.end());

    stack<pii> stk;
    vector<int> res;
    for(int i=0;i<mp.size();i++){
        int vel=mp[i].second.first;
        if(stk.size()==0){
            stk.push({mp[i].second.first,mp[i].second.second});
        }
        else{
            int t=stk.top().first;
            if(t<0&&vel<0){
                if(vel<t){
                    stk.pop();
                }
            }
            else if(t<0&&vel>0){
                stk.push({vel,mp[i].second.second});
            }
            else if(t>0&&vel>0){
                if(t>=vel) stk.push({vel,mp[i].second.second});
                else{
                    stk.pop();
                }
            }
            else if(t>0&&vel<0){
                stk.pop();
            }
        }
    }
    cout<<stk.size();

    return 0;
}
