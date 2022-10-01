#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n;
char s[N];
int ans;
int sum;
int cnt[N];

int main(){
    cin>>s+1;
    n=strlen(s+1);
    s[0]='@',s[n+1]='@';

    for(int i=1;i<=n;i++){
        if(s[i]!='B') continue;

        int l=i-1,r=i+1;
        while(s[l]=='A') l--;
        while(s[r]=='C') r++;
        cnt[i]=min(i-l-1,r-i-1);
    }
    

    for(int i=1;i<=n;i++){
        if(!cnt[i]) continue;

        if(i%2==0){
            ans+=min(cnt[i],2+sum);
            if((cnt[i]==1&&sum)||(min(cnt[i],2+sum)>=2)) sum++;
        }
        else{
            ans+=min(cnt[i],1+sum);
            if(min(cnt[i],1+sum)>=1) sum++;
        }
    }

    cout<<ans<<endl;
    return 0;
}