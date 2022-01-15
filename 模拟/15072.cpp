#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout);
    unordered_map<ull,ull> mp;
    mp[1]=1,mp[2]=2;
    ull ak_1,ak_2,x,temp;
    ak_1=2,ak_2=1;
    for(ull i=3;i<100000;i++){
        mp[ak_1+ak_2]=i;
        temp=ak_2;
        ak_2=ak_1;
        ak_1+=temp;
    }

    string s;
    while(cin>>s){
    ull n=0;
    for(ull i=0;i<s.length();i++)
    n=n*10+(s[i]-'0');
    printf("%llu\n",mp[n]);
    }
    return 0;
}