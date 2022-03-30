#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,int>

using namespace std;

int get(int a,int b,int c,int d){
    return max(0,min(b,d)-max(a,c));
}

int area(int a[]){
    return (a[2]-a[0])*(a[3]-a[1]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a[3][4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>a[i][j];
        }
    }

    int res=0;
    for(int i=0;i<2;i++){
        res+=get(a[i][0],a[i][2],a[2][0],a[2][2])*get(a[i][1],a[i][3],a[2][1],a[2][3]);
    }
    cout<<area(a[0])+area(a[1])-res<<endl;

    return 0;
}
