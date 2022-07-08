#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define int long long
#define pii pair<pair<int,int>,pair<int,int>>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long

using namespace std;

struct node{
    int x1,y1,x2,y2;
    bool operator=(const node &t) const {
        return x1==t.x1&&y1==t.y1&&x2==t.x2&&y2==t.y2;
    }
};

void sol(){
    string s; cin>>s;
    set<pii> st;
    int x=0,y=0;
    for(int i=0;i<(int)s.length();i++){
        node tmp,tmp1;
        int xx=x,yy=y;
        if(s[i]=='N') y++;
        else if(s[i]=='S') y--;
        else if(s[i]=='W') x--;
        else if(s[i]=='E') x++;
        st.insert({{xx,yy},{x,y}});
        st.insert({{x,y},{xx,yy}});
        // st.insert{xx,yy,x,y},st.insert({x,y,xx,yy});
        // cout<<st.size()<<endl;
    }  
    int ccc=st.size()/2;
    cout<<5*ccc+(int)s.length()-ccc<<endl;

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
