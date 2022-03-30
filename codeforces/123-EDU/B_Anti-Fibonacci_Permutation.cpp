#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



// void sol(){
//     int n; cin>>n;
//     // n++;
//     int zzz=n;
//     // n++;
//     vector<int> v(2*n);
//     for(int i=1;i<=n;i++) v[i]=i;
//     int cnt=0;
//     do{
//         bool bz=true;
//         for(int i=3;i<=zzz;i++){
//             if(v[i-2]+v[i-1]==v[i]) bz=false;
//         }
//         if(bz==false) continue;
//         for(int i=1;i<=zzz;i++){
//             int x=v[i];
//             cout<<x<<' ';
//         }
//         cnt++;
//         cout<<endl;
//         if(cnt==zzz) return;
//     }while(next_permutation(v.begin()+1,v.begin()+1+n));
//     return ;
// }

void sol(){
    int n;
    scanf("%d",&n);
    if(n==3){
        printf("3 2 1\n");
        printf("1 3 2\n");
        printf("3 1 2\n");
        return;
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--)
            printf("%d ",j);
        for(int j=n;j>=i+1;j--)
            printf("%d ",j);
        printf("\n");
    }

    return;
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
