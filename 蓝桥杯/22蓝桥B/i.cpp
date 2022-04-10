#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int n,m,ans;

int lowbit(int x){
    return x&-x;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<(1<<(m+n));i++){
        int temp=i;
        int cnt=0;
        while(temp){
            cnt++;
            temp-=lowbit(temp);
        }
        if(cnt!=n||i&1==1) continue;
        
        temp=i;
        string s;
        while(temp){
            if(temp&1){
                s+='1';
            }
            else s+='0';
            temp>>=1;
        }
        cout<<s<<endl;
        int sum=2;
        for(int j=0;j<s.length();j++){
            if(s[i]=='1') sum<<=1;
            else{
                if(sum==0) break;
                sum-=1;
            }
            if(j==s.length()-1&&sum==0) ans++;
        }
        
    }
    
    cout<<ans<<endl;
    return 0;
}