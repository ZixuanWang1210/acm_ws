#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

int a,b,c,aa,bb,cc;

void sol(){
    cin>>a>>b>>c>>aa>>bb>>cc;
    int ans=0;

    for(int i=1;i<=30;i++){
        for(int j=1;j<=30;j++){
            for(int k=1;k<=30;k++){
                for(int l=1;l<=30;l++){
                    int a1=a-(i+j);
                    int b1=b-(k+l);
                    int aa1=aa-(i+k);
                    int bb1=bb-(j+l);
                    int c1=c-(aa1+bb1);
                    int cc1=cc-(a1+b1);
                    if(a1>=1&&b1>=1&&aa1>=1&&bb1>=1&&c1==cc1&&c1>=1){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
