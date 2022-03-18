// #include <bits/stdc++.h>
#include<iostream>

#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e8;
int p[maxn];
int n,m;

int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

void merge(int a,int b){
    a=find(a),b=find(b);
    if(a!=b) p[b]=a;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(cin>>n>>m,n||m){
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        for(int i=1;i<=m;i++){
            int num; cin>>num;
            int fi; cin>>fi;
            for(int j=1;j<=num-1;j++){
                int x; cin>>x;
                merge(fi,x);
            }
        }
        int pp=find(0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(find(i)==pp) ans++;
        }
        cout<<ans<<endl;
    }   


    return 0;
}
