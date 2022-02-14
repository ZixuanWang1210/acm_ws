#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

int n,k;
string s;
string op;

ll query(){
    int cnt=0,ans=0,st=0x3f3f3f3f,ed=-1;
    if(k==1){
        int ccnt=0, totl=0;
        for(int i=0;i<op.length();i++){
            if(op[i]=='R'){
                ccnt++;
            }
        }
        for(int i=0;i<op.length();i++){
            if(op[i]=='R'){
                ans=ans+op.size()-i;
                ccnt--;
            }
            else{
                ans+=ccnt;
            }
        }
        return ans;
    }
    bool fir=false;
    for(int i=0;i<op.length();i++){
        if(op[i]=='R'){
            st=min(st,i+1);
            ed=max(ed,i+1);
            cnt++;
            if(cnt>=k){
                if(fir==false){
                    ans=ans+(st*(op.length()-ed+1));
                    // st --;
                    // if(st<=0) st=0;

                    fir=true;
                }
                else{
                    ans+=cnt-k;
                }
            }
        }
    }
    return ans;
}

signed main(){
        // freopen("out.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>s;
    long long ans1=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='P'){
            if(op.size()) ans1+=query();
            op.clear();
        }
        else{
            op+=s[i];
        }
    }
    ans1+=query();
    cout<<ans1;

    return 0;
}
