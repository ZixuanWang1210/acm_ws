#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 998244353
#define ll long long
// #define int long long

using namespace std;

int n;
const int maxn=2e6+10;
string s[maxn];

struct KMP{
    int nxt[maxn];int len;
    char t[maxn];
    void clear(){
        len =nxt[0] = nxt[1] =0;
    }
    /* 1-bas */
    /* 注意在ss结尾添加‘\0’ */
    void init(string s){
        s=' '+s;
        char *p=(char*)s.c_str();
        init(p);
    }
    void init(char* ss){
        len = strlen(ss+1);
        memcpy(t,ss,(len+2)*sizeof(char));
        for (int i=2;i<=len;i++){
            nxt[i] = nxt[i-1];
            while (nxt[i]&&ss[i]!=ss[nxt[i]+1]) nxt[i] = nxt[nxt[i]];
            nxt[i]+=(ss[i]==ss[nxt[i]+1]);
        }
    }
    /* 求所有在ss串中的start_pos. 如果first_only设置为true，则只返回第一个位置*/
    vector<int> match(string s,bool first_only = false){
        s=' '+s;
        char *ss=(char*)s.c_str();
        int len_s = strlen(ss+1);
        vector<int> start_pos(0);
        for (int i=1,j=1;i<=len_s;){
            while (j!=1 && ss[i] != t[j])j = nxt[j-1]+1;
            if (ss[i] == t[j]) j++,i++;
            else i++;
            if (j == len+1){
                start_pos.push_back(i-j+1);
                if (first_only)return start_pos;
                j = nxt[len]+1;
            }
        }
        return start_pos;
    }
    void _debug(){
        for (int i=0;i<=len;i++){
            printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
        }
    }
    /* 循环周期 形如 acaca 中 ac 是一个合法周期 */
    vector<int> periodic(){
        vector<int> ret;
        int now = len;
        while (now){
            now = nxt[now];
            ret.push_back(len-now);
        }
        return ret;
    }
    /* 循环节 形如 acac 中ac、acac是循环节，aca不是*/
    vector<int> periodic_loop(){
        vector<int>ret ;
        for (int x :periodic()){
            if (len%x==0)ret.push_back(x);
        }
        return ret;
    }
    int min_periodic_loop(){
        return periodic_loop()[0];
    }
} kmp;



void sol(){
    cin>>n;
    int idx=-1;
    int len=inf;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(len>s[i].length()){
            len=s[i].length();
            idx=i;
        }
        // else if(len==s[i].length()){
        //     if(s[idx]!=s[i]){
        //         cout<<0<<endl;
        //         return;
        //     }
        // }
    }   
    int res=1;
    kmp.init(s[idx]);
    for(int i=1;i<=n;i++){
        if(i==idx) continue;
        res=res*kmp.match(s[i]).size()%mod;
    }

    for(int i=1;i<=n;i++){
        if(s[i]!=s[idx]) cout<<0<<endl;
        else cout<<res<<endl;
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
