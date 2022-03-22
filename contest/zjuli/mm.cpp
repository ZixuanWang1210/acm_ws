#include <bits/stdc++.h>
using namespace std;

const int N=1005,INF=0x3f3f3f3f;
int f[N][N];
char a[N],b[N];

int main()
{
    cin >> (a+1) >> (b+1);
    int lena=strlen(a+1), lenb=strlen(b+1);
    int t=lenb;

    for(int i=1; i<=lena; i++)
        for(int j=1; j<=lenb; j++)
            f[i][j] = INF;

    for(int i=1; i<lena; i++) f[i][0] = i;
    for(int j=1; j<lenb; j++) f[0][j] = j;
    // cout << "11" << endl;
    for(int i=1; i<=lena; i++)
        for(int j=1; j<=lenb; j++){
            
            f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
            if(a[i]==b[i]) f[i][j] = min(f[i][j], f[i-1][j-1]);
            else f[i][j] = min(f[i][j], f[i-1][j-1]+1);
            if(i==lena && j==lenb){
                if(f[i][j]==f[i-1][j-1]) continue;
                else if(f[i][j]==f[i][j-1]+1) lenb--;
                else if(f[i][j]==f[i-1][j-1]+1) lenb--;
            }
        }

    // cout << "11: " << endl;
    for(int i=1; i<=lenb; i++)
        cout << b[i];

    return 0;
}