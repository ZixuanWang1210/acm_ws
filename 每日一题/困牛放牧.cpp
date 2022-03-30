#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int a[5];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=1;i<=3;i++) cin>>a[i];
    sort(a+1,a+4);

    int in_sort;
    if(a[2]==a[1]+1&&a[3]==a[2]+1) in_sort=3;
    else if(a[2]==a[1]+1||a[3]==a[2]+1) in_sort=2;
    else in_sort=1;

    if(in_sort==3) cout<<0<<endl<<0<<endl;
    else if(in_sort==2) cout<<1<<endl<<2<<endl;
    else cout<<3<<endl<<3<<endl;

    return 0;
}
