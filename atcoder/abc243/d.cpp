#include <bits/stdc++.h>
#define endl "\n"
#define ull unsigned long long
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int unsigned long long


using namespace std;

int n,x;
string s;
long long sum,idx;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='L'||s[i]=='R'){
            sum++;
        }
        else{
            sum--;
            if(sum<0){
                sum=0;
                continue;
            }
        }
        if(sum==0){
            idx=i+1;
        }
    }
    // cout<<idx<<endl;
    for(int i=idx;i<s.length();i++){
        if(s[i]=='U'){
            x=x>>1;
        }
        else if(s[i]=='L'){
            x=x<<1;
        }
        else {
            x=x<<1|1;
        }
    }

    cout<<x;

    return 0;
}
