#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e5+10;
int a[maxn];
int n,m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=i;
    while(m--){
        int op,x; cin>>op>>x;
        if(op==0){
            sort(a+1,a+x+1,greater<int>());
        }
        else{
            sort(a+x,a+n+1);
        }
    }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    

    return 0;
}
