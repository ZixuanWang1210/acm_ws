#include <bits/stdc++.h>
#define maxn 1000010
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, tot;
char s[maxn], a[maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    cin >> n;
    while(n--){
        cin >> s;
        int le = strlen(s);
        for(int i = 0; i < le; i++){
            if(s[i] == '(' || s[i] == '['){
                tot++;a[tot] = s[i];
            }
        }

    }
    

    return 0;
}
