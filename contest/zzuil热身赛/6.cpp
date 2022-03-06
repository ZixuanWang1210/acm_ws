#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int t;
int mm,yy,dd;
string s;
int mo[30]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int yy,mm,dd;
    scanf("%d/%d/%d",&yy,&mm,&dd);
    // cout<<yy<<mm<<dd;
    if((yy%4==0&&yy%100!=0)||yy%400==0) mo[2]=29;
    else mo[2]=28;

    int res=0;
    for(int i=1;i<mm;i++){
        res+=mo[i];
    }
    res+=dd;
    cout<<res;


    return 0;
}
