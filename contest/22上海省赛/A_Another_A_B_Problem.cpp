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

const int maxn=100;
int cnt_p[maxn],cnt_b[maxn];
string s(10,' ');
string s1,s2; 
vector<string> res;

int get(int x){
    return (s[x]-'0')*10+(s[x+1]-'0');
}

void dfs(int x){
    if(x==8){
        int c1=get(0),c2=get(3),c3=get(6);
        if(c1+c2!=c3) return;
        for(int i=0;i<=7;i++){
            if(s2[i]!='G'&&s1[i]==s[i]) return;
        }
        int cnt_now[100]={0};
        for(int i=0;i<=7;i++){
            if(s2[i]!='G') cnt_now[s[i]-'0']++;
        }
        for(int i=0;i<=9;i++){
            if((cnt_now[i]<cnt_p[i])||(cnt_b[i]&&cnt_now[i]>cnt_p[i])) return;
        }
        res.push_back(s);
    }
    else{
        if(s2[x]=='G') s[x]=s1[x],dfs(x+1);
        else{
            for(int i=0;i<=9;i++){
                s[x]='0'+i;
                dfs(x+1);
            }
        }
    }
}

void sol(){
    cin>>s1>>s2;
    for(int i=0;i<=7;i++){
        if(s2[i]=='P') cnt_p[s1[i]-'0']++;
        if(s2[i]=='B') cnt_b[s1[i]-'0']++;
    }

    dfs(0);
    cout<<res.size()<<endl;
    for(auto x:res) cout<<x<<endl;
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
