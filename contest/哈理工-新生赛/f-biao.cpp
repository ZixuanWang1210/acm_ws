#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
string s;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n >> s;
    int a = 0, b = n - 1;
    while (a <= b)
    {
        bool left = false;
        for(int i = 0; i + a <= b; i++){
            if(s[i + a] < s[b - i]){
                left = true;
                break;
            }
            else if(s[a + i] > s[b - i]){
                left = false;
                break;
            }
        }
        if(left) putchar(s[a++]);
        else putchar(s[b--]);
    }
    
    

    return 0;
}
