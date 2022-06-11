#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
#define int long long

using namespace std;

const int maxn=2e5+10;
int p[maxn],siz[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

int lcm(int a,int b){
    return a*b/__gcd(a,b);
}

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    s=' '+s;
    vector<bool> st(n+1);
    vector<int> p(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        if(!st[i]){
            string now;
            int fa=p[i];
            now+=s[i];
            st[i]=1;
            while(fa!=i){
                now+=s[fa];
                st[fa]=1;
                fa=p[fa];
            }
            // cout<<now<<endl;
            int len=now.length();
            now=' '+now;
            vector<int> nex(len+1);
            for(int i=2,j=0;i<=len;i++){
                while(j&&now[j+1]!=now[i]) j=nex[j];
                if(now[j+1]==now[i]) j++;
                nex[i]=j;
            }
            if(len%(len-nex[len])==0){
                ans=lcm(ans,len-nex[len]);
            }
            else ans=lcm(ans,len);
        }
    }
    cout<<ans<<endl;
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
