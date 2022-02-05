#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=100;
int n,k,ans;
int f[N*3];

int find(int x){
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}

void merge(int a,int b){
    f[find(a)]=find(b);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=3*n;i++) f[i]=i;

    while(k--){
        int d,x,y;cin>>d>>x>>y;
        if(x>n||y>n){
            ans++;
            continue;
        }

        if(d==1){
            if(find(x)==find(y+n)||find(x)==find(y+n+n)){
                ans++;
                continue;
            }
            merge(x,y);
            merge(x+n,y+n);
            merge(x+n+n,y+n+n);
        }
        else{
            if(find(x)==find(y)||find(x)==find(y+n)||x==y){
                ans++;
                continue;
            }
            merge(x,y+n+n);//y的捕食域加入x
            merge(x+n,y);//x的天敌域加入y
            merge(x+n+n,y+n);//x的捕食域是y的同类域.
        }

    }
        cout<<ans;

    return 0;
}
