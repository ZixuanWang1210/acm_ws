#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
const int maxn=2e5+10;
int a[maxn];
int st[maxn];


int dfs(int x){
    if(x==0) return 0;
    for(int i=1;i<x;i++){
        if(!st[i]) st[i]=dfs(i);
        long long temp=x-i;
        int res=st[i]+temp*temp*temp;
        
    }
    
}



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    

    return 0;
}
