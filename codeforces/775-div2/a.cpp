#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; 
    vector<int> v(n*2);
    int cnt1=-1,cnt2=-1;
    int cnt=0;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(cnt1==-1&&v[i]==0){
            cnt1=i;
        }
        if(v[i]==0) cnt++;
    }
    for(int i=n;i>=1;i--){
        if(cnt2==-1&&v[i]==0){
            cnt2=i;
            break;
        }
    }
    if(cnt==0){
        cout<<0<<endl;
    }
    if(cnt==1){
        cout<<2<<endl;
        return;
    }
    else{
        cout<<cnt2-cnt1+2<<endl;
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    

    return 0;
}
