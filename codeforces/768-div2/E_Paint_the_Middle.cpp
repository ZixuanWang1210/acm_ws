#include<bits/stdc++.h>
using namespace std;

const int maxn=20;
int n;
int op[maxn],v[maxn];

int main(){
    // vector<int> v(2*n);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        op[v[i]]=max(op[v[i]],i);
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        if(i==op[v[i]]) continue;
        int now=i,ed=op[v[i]];
        int bz=false;
        while(now<=ed){
            now++;now++;
            // ed=max(ed,op[v[now]]);
            if(ed<op[v[now]]){
                ed=op[v[now]];
                // now++;
                bz=true;
            }
            now++;
        }
        if(bz) ans+=(now-i-3);
        else ans+=(now-i-2) ;
        i=now;
        i--;
    }
    cout<<ans;

    return 0;
}