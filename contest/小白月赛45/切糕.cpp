#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;

using namespace std;

const int maxn=1e6+10;
int a[maxn],s[maxn];

int qmi(int a,int b,int p){
    long long res=1;
    while(b){
        if(b&1) res=a*res%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string str; 
    cin>>str;
    int n=str.length();
    for(int i=0;i<str.length();i++){
        if(str[i]=='(') a[i+1]=1;
        else a[i+1]=-1;
    }
    int cnt=0;
    for(int i=1;i<=str.length();i++){
        s[i]=s[i-1]+a[i];
        if(s[i]<0){
            cout<<-1<<endl;
            return 0;
        }
        if(s[i]==0&&i!=n) cnt++;
    }
    if(s[n]){
        cout<<-1<<endl;
        return 0;
    }
    // cnt--;
    cout<<qmi(2,cnt,1e9+7)<<endl;
    
    return 0;
}
// stack<char> s;
// int ans=0;
// int main(){
//     string str; cin>>str;
//     for(int i=0;i<str.length();i++){
//         if(str[i]=='(') s.push(str[i]);
//         else{
//             if(!s.empty()&&s.top()=='('){
//                 s.pop();
//                 if(s.empty()) ans++;
//             }
//             else s.push(str[i]);
//         }
//     }
//     if(ans==0||s.empty()){
//         cout<<-1<<endl;
//         return 0;
//     } 
//     ans--;
//     cout<<qmi(2,ans)
// }
