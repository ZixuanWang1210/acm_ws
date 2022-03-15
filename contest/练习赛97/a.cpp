#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
priority_queue<int,vector<int>,greater<int>> odd,even;
bool st[200];
vector<int> v;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(x&1) even.push(x),st[i]=1;
        else odd.push(x);
    }
    for(int i=1;i<=n;i++){
        if(st[i]){
            v.push_back(even.top());
            even.pop();
        }
        else{
            v.push_back(odd.top());
            odd.pop();
        }
    }
    // cout<<is_sorted(v.begin(),v.end())?"Yes":"No"<<endl;
    if(is_sorted(v.begin(),v.end())) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
