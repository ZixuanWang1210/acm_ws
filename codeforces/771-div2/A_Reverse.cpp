#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1000;
int t,n;
int a[maxn],b[maxn];

void sol(){
    cin>>n;
    int _min=0x3f3f3f3f;
    string s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        s+='0'+a[i];
    }
    
    sort(b+1,b+1+n);
    int idx=0,ed=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]&&!idx){
            idx=i;
        }
        if(a[i]==idx) ed=i;
    }

    // cout<<idx<<' '<<ed;
    // cout<<s<<endl;;

    // reverse(s.begin()+idx,s.begin()+ed);
    // cout<<s;
    if(idx==0){
        for(int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
    }
    else{
        for(int i=1;i<idx;i++){
            cout<<a[i]<<' ';
        }
        for(int i=ed;i>=idx;i--){
            cout<<a[i]<<' ';
        }
        for(int i=ed+1;i<=n;i++){
            cout<<a[i]<<' ';
        }
    }

    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
