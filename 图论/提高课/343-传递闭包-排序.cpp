#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int g[26][26];
int d[26][26];
bool st[26];
int n,m;

void floyd(){
    memcpy(d,g,sizeof d);

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]|=d[i][k]&&d[k][j];
            }
        }
    }
}

// int check(){
//     for(int i=0;i<n;i++){
//         if(d[i][i]) return 2;
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(!d[i][j]&&!d[j][i]) return 0;
//         }
//     }
//     return 1;
// }
int check()
{
    for (int i = 0; i < n; i ++ )
        if (d[i][i])
            return 2;

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < i; j ++ )
            if (!d[i][j] && !d[j][i])
                return 0;

    return 1;
}


char get_min(){
    for(int i=0;i<n;i++){
        if(!st[i]){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(!st[j]&&d[j][i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                st[i] = true;
                return 'A'+i;
            }
        }
    }
}

int main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(cin>>n>>m,n||m){
        memset(g,0,sizeof g);
        int type=0,t;
        for(int i=1;i<=m;i++){
            char op[5];
            cin>>op;
            int a=op[0]-'A',b=op[2]-'A';

            if(!type){
                g[a][b]=1;
                floyd();
                type=check();
                if(type) t=i;
            }
        }

        if (!type) puts("Sorted sequence cannot be determined.");
        else if (type == 2) printf("Inconsistency found after %d relations.\n", t);
        else
        {
            memset(st, 0, sizeof st);
            printf("Sorted sequence determined after %d relations: ", t);
            for (int i = 0; i < n; i ++ ) printf("%c", get_min());
            printf(".\n");
        }
    }
    

    return 0;
}
