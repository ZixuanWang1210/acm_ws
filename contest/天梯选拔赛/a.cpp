#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

string s;
int len;

bool check(int x){
    for(int i=0;i<x;i++){
        if(s[i]!=s[len-x+i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    string s1;
    cin>>s;
    s1=s;
    int ans=0;
    reverse(s1.begin(),s1.end());
    len=s.length();
    // if(s[0]!=s[len-1]){
    //     cout<<"Just a legend";
    //     return 0;
    // }
    else{
        int l=1,r=len;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid)){
                ans=mid;
                l=mid+1;

            }
        }
    }

    return 0;
}
