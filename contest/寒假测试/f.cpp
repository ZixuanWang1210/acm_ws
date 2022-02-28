#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int t;
int n;
int a[10],s[10];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        int n; cin>>n;
        int ans1=0,_min=0x3f3f3f3f,ans2=0;
        bool falg=false;
        for(int i=1;i<=n;i++){
            string ss; cin>>ss;
            int x; cin>>x;
            if(ss=="LOST") a[i]=-x;
            else a[i]=x;
            s[i]=s[i-1]+a[i];
            if(s[i]<=0)
                s[i]=0;
            
        }
        for(int i=1;i<=n;i++){
            if(s[i]<=0&&falg==false){
                ans1=s[n]-s[i]+s[i-1];
                falg=true;
            }
            else{
                if(s[i]>0&&a[i]<=0)
                    _min=min(_min,a[i]);
            }
        }
        ans2=s[n]-_min;
        cout<<max(ans1,ans2)<<endl;

    }
    

    return 0;
}
