#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    vector<bool> b(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]<0) b[i]=true;
    }
    bool bz=(n%2==0);
    if(bz){
        for(int i=1;i<=n;i+=2){
            if(b[i]==b[i+1]){
                v[i]*=-1;
                cout<<v[i+1]<<' '<<v[i]<<' ';
            }
            else cout<<abs(v[i+1])<<' '<<abs(v[i])<<' ';
        }
        cout<<endl;
    }
    else{
        n-=3;
        for(int i=1;i<=n;i+=2){
            if(b[i]==b[i+1]){
                v[i]*=-1;
                cout<<v[i+1]<<' '<<v[i]<<' ';
            }
            else cout<<abs(v[i+1])<<' '<<abs(v[i])<<' ';
        }
        if(v[n+1]+v[n+2]!=0){
            cout<<-v[n+3]<<' '<<-v[n+3]<<' '<<v[n+1]+v[n+2]<<endl;
        }
        else if(v[n+2]+v[n+3]!=0){
            cout<<v[n+3]+v[n+2]<<' '<<-v[n+1]<<" "<<-v[n+1]<<endl;
        }
        else cout<<-v[n+2]<<' '<<v[n+1]+v[n+3]<<' '<<-v[n+2]<<endl;
        // int aa=abs(v[n+2]*v[n+3]);
        // int bb=abs(v[n+1]*v[n+3]);
        // int cc=abs(v[n+1]*v[n+2]*(-2));

        // if(b[n+1]) cout<<-aa<<' ';
        // else cout<<aa<<' ';
        // if(b[n+2]) cout<<-bb<<' ';
        // else cout<<bb<<' ';
        // if(b[n+3]) cout<<cc<<' ';
        // else cout<<-cc<<' ';
        // cout<<endl;

        // cout<<abs(v[n+2]*v[n+3])<<' '<<abs(v[n+1]*v[n+3])<<' '<<-abs(v[n+1]*v[n+2]*(-2))<<endl;
    }

}   

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
