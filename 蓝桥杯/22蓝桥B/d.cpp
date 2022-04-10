#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;

int h[maxn];
int res[maxn];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1;i<=n;i++){
        h[i]=0;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            h[j]+=1;
            res[j]=max(res[j],h[j]);
        }
    }
    for(int i=n-1;i>=1;i--){
        h[i]=0;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            h[j]+=1;
            res[j]=max(res[j],h[j]);
        }
    }
    for(int i=2;i<=n;i++){
        h[i]=0;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            h[j]+=1;
            res[j]=max(res[j],h[j]);
        }
    }
    for(int i=n-1;i>=1;i--){
        h[i]=0;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            h[j]+=1;
            res[j]=max(res[j],h[j]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]+1<<endl;
    }

    return 0;
}