#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int cnt[10];
int n;
string s;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    // cnt[5]=1;
    if(s=="5"){
        cnt[5]=1;
        for(int i = 1; i <= 9; i++){
            cout<< cnt[i] << " ";
        }
        return 0;
    }
    for(int i=0;i<s.length();i++){
        
        int t=s[i]-'0';
        if(t==5) continue;
        cnt[t]++;
        cnt[5]++;
    }
    for(int i = 1; i <= 9; i++){
        cout<< cnt[i] << " ";
    }

    return 0;
}
