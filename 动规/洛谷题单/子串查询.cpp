// https://ac.nowcoder.com/acm/contest/1083/B
// https://segmentfault.com/a/1190000021980858
// 
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
const int maxn=1e5+10;
int n,m;
int q;
string s,t;

struct seqam{
    int nxt[maxn][26];
    // 记录 s[i] 的下一个 a，b，c，d，e...z 在哪里 O(n)
    void build(){
        int len=s.length()-1;
        for(int i=len;i>0;i--){
            for(int j=0;j<26;j++) nxt[i-1][j]=nxt[i][j];
            nxt[i-1][s[i]-'a']=i;
        }
    }
    void get(string t){
        int idx=0;
        for(auto x:t){
            if(!nxt[idx][x-'a']){
                cout<<"NO"<<endl;
                return;
            }
            idx=nxt[idx][x-'a'];
        }
        cout<<"YES"<<endl;
    }
};

seqam plt;
void sol(){
    cin>>n>>q;
    cin>>s;
    s=" "+s;

    plt.build();
    while(q--){
        cin>>t;
        plt.get(t);
    }

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
