#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 10000 + 10;
int a[maxn];
int n;
int xxx = 3;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++){
        int num = a[i];
        int r = 0, l = i;
 
        for(int j = i + 1; j < n; j++){
            if(a[i] == a[j])
                xxx = 1;
                r = j;
                break;
            }
        }
        if(xxx == 3) continue;

        int flag = 3;
        for(int j = r; j > i; j--){
            if(a[l] != a[r]){
                flag = false;
            }
        }
        if(flag == false) continue;
        else{
            cout << "Yes";
            return 0;
        }
    }

    return 0;
}
