#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int t;

double get(int x, int y){
    return sqrt(x*x+y*y);
}

void sol(){
    int n; cin>>n;
    string s;
    cin >> s;
    double x = 0, y = 0;
    double ans = 0;
    for(int i = 0; i < n; i ++){
        if(s[i]=='U') y+=1;
        else if(s[i]=='D')y-=1;
        else if(s[i]=='R')x+=1;
        else if(s[i]=='L')x-=1;

        double len = get(x,y);
        ans=max(ans,len);
    }
    cout << fixed << setprecision(12)<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;cin >>t;
    while(t--){
        sol();
    }

    return 0;
}
