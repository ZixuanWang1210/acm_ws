#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1000010];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)  cin >> a[i];

    while(m--){
        int inq; cin >> inq;
        int pos = lower_bound(a, a + n, inq) - a;
        if(a[pos] != inq) cout << "-1 ";
        else cout << pos + 1 << " ";
    }
    

    return 0;
}