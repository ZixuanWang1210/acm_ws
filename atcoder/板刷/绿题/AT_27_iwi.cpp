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

bool check(string s){
    int len=s.length();
    if(len%2==0) return false;
    s=' '+s;

    map<char,int> st;
    st['{']=1,st['}']=2;
    st['[']=3,st[']']=4;
    st['(']=5,st[')']=6;
    st['w']= 7,st['i']=10;
    int ans=3;

    int mid=(len+1)/2;
    if(s[mid]=='w'&&s[mid-1]=='i'&&s[mid+1]=='i');
    else return false;
    int l=mid-2,r=mid+2;
    while(l>=1&&r<=len){
        int a=st[s[l]],b=st[s[r]];
        if((a&1&&(b==a+1))||(b&1&&(a==b+1))){
            ans+=2;
            l--,r++;
        }
        else if(a==7&&b==7){
            ans+=2;
            l--,r++;
        }
        else if(a==10&&b==10){
            ans+=2;
            l--,r++;
        }
        else return false;
    }
    return true;
}

void sol(){
    // check("iwi[");
    string s; cin>>s;
    int n=s.length();
    int ans=3;
    for(int i=0;i<(1<<n);i++){
        int x=i;
        int idx=0;
        string ss;
        while(x){
            if(x&1){
                ss+=s[idx];  
            }
            idx++;
            x>>=1;
        }
        // cout<<ss<<endl;
        int len=ss.length();
        if(check(ss)) ans=max(ans,len);
        // cout<<check(ss)<<' '<<ss<<endl;
    }
    cout<<ans<<endl;

}

// void sol(){
//     string s; cin>>s;
//     int len=s.length();
//     s=' '+s;

//     map<char,int> st;
//     st['{']=1,st['}']=2;
//     st['[']=3,st[']']=4;
//     st['(']=5,st[')']=6;
//     st['w']= 7,st['i']=10;
//     int ans=3;

//     int mid=(len+1)/2;
//     int l=mid-2,r=mid+2;
//     while(l>=1&&r<=len){
//         int a=st[s[l]],b=st[s[r]];
//         if((a&1&&(b==a+1))||(b&1&&(a==b+1))){
//             ans+=2;
//             l--,r++;
//         }
//         else if(a==7&&b==7){
//             ans+=2;
//             l--,r++;
//         }
//         else if(a==10&&b==10){
//             ans+=2;
//             l--,r++;
//         }
//         else r++;
//     }
//     cout<<ans<<endl;
// }

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;1
    while(_--){
        sol();
    }

    return 0;
}
