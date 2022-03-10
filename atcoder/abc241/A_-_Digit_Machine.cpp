#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=100;
int a[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0;i<=9;i++){
        cin>>a[i];
        // cout<<a[i]<<' ';
    }
    int fi=a[0];
    int se=a[fi];
    int th=a[se];
    
    cout<<th<<endl;

    return 0;
}
