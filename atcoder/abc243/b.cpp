#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
int a[1100],b[1100];
set<int> sa,sb;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sa.insert(a[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(a[i]==b[i]) ans1++;
        // sb.insert(b[i]);
        if(sa.count(b[i])!=0) ans2++;
    }
    
    cout<<ans1<<endl<<ans2-ans1;


    return 0;
}
