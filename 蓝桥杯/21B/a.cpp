#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int w[110];
int n;
set<int> s;

void dfs(int i,int sum,int st){
    if(i==n+1){
        return;
    }
    if(s.find(abs(sum))==s.end()) s.insert(sum);
    dfs(i+1,sum+w[i+1],1);
    dfs(i+1,sum-w[i+1],1);
    dfs(i+1,sum,0);
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];

    dfs(0,0,0);
    
    int cnt=0;
    for(std::set<int>::iterator x=s.begin();x!=s.end();x++){
        if(*x>0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
