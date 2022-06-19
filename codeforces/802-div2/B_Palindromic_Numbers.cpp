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
    string s; cin>>s;
    int a[2*n],b[2*n];
    if(s[0]=='9'){
        for(int i=0;i<n;i++){
            a[i]=s[i]-'0';
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]<=1) b[i]=1-a[i];
            else{
                b[i]=11-a[i];
                if(i-1>=0) a[i-1]++;
                while(i-1>=0&&a[i-1]>=10) a[i-1]-=10,a[i-2]++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<b[i];
        }
        // for(int i=0;i<n;i++){
        //     if(i==n-1) cout<<11-(s[i]-'0');
        //     else cout<<10-(s[i]-'0');
        // }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        cout<<'9'-s[i];
    }
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
