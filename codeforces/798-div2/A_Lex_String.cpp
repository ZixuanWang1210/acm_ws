#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int n,m,k; cin>>n>>m>>k;
    string s1,s2; cin>>s1>>s2;
    sort(_all(s1));sort(_all(s2));
    // cout<<s1<<endl<<s2<<endl;
    int cnt1=0,cnt2=0;
    string s3;

    while(s1.size()&&s2.size()){
        char x=s1[0],y=s2[0];
        if(x<y){
            if(cnt1>=k){
                s3+=y;
                s2=s2.substr(1);
                cnt1=0;
                cnt2=1;
            }
            else{
                s3+=x;
                s1=s1.substr(1);
                cnt1++;
                cnt2=0;
            }
        }
        else if(x>y){
            if(cnt2>=k){
                s3+=x;
                s1=s1.substr(1);
                cnt2=0;
                cnt1=1;
            }
            else{
                s3+=y;
                s2=s2.substr(1);
                cnt2++;
                cnt1=0;
            }
        }
        
    }
    cout<<s3<<endl;

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
