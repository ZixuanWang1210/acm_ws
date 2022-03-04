#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=100;
int f[maxn];
int m,a,b;


signed main(){
    f[1]=1,f[2]=1;
    for(int i=3;i<=80;i++) f[i]=f[i-1]+f[i-2];

    cin>>m;
    while(m--){
        cin>>a>>b;
        while(a!=b){
            if(a>b){
                a-=(*(lower_bound(f,f+60,a)-1));
            }
            else{
                b-=(*(lower_bound(f,f+60,b)-1));
            }
        }
        cout<<a<<endl;
    }


    return 0;
}