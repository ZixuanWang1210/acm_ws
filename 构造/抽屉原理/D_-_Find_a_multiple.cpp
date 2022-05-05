#include <iostream>
#include <vector>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1),s(n+1);
    for(int i=1;i<=n;i++) cin>>v[i],s[i]=s[i-1]+v[i],s[i]%=n;

    int idx[15100]={0};
    for(int i=1;i<=n;i++){
        if(s[i]==0){ // 如果是 0 ，则从第二位输出到当前位置
            cout<<i<<endl;
            for(int j=1;j<=i;j++){
                if(j!=1) cout<<v[j]<<endl;
                else cout<<v[j]<<endl;
            }
            break;
        }
        if(!idx[s[i]]) idx[s[i]]=i;
        else{
            cout<<i-idx[s[i]]<<endl;
            for(int j=idx[s[i]]+1;j<=i;j++){
                cout<<v[j]<<endl;
            }
            cout<<endl;
            return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;/
    while(_--){
        sol();
    }

    return 0;
}
