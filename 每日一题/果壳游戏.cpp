#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


int n;
bool st[5][5];
int cnt[5];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    st[1][1]=1;
    st[2][2]=1;
    st[3][3]=1;
    for(int i=1;i<=n;i++){
        int a,b,g; cin>>a>>b>>g;
        for(int j=1;j<=3;j++){
            swap(st[j][a],st[j][b]);
            if(st[j][g]) cnt[j]++;
        }
    }
    cout<<*max_element(cnt+1,cnt+4);
    

    return 0;
}
