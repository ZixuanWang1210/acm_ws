#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    int cnt1=0,cnt11=0,cnt111=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]>0) cnt1++;
        else if(v[i]<0) cnt11++;
        else cnt111++;
    }
    set<int> st;
    if(cnt11>=3||cnt1>=3){
        cout<<"NO"<<endl;
        return;
    }
    else{
        vector<int> vvv;
        vvv.push_back(0);
        for(int i=1;i<=n;i++){
            if(v[i])   vvv.push_back(v[i]),st.insert(v[i]);
        }
        for(int i=1;i<=min(cnt111,3ll);i++){
            vvv.push_back(0);
            st.insert(0);
        }

        int n=vvv.size()-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    int sum=vvv[i]+vvv[j]+vvv[k];
                    if(!st.count(sum)){
                        cout<<"NO"<<endl;
                        return;
                    }
                }
            }

        }
        cout<<"YES"<<endl;
    }

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
