#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;

int a[maxn], b[maxn];
int n, ans = 0x3f3f3f3f, cnt, t;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    for(int j = 0; j < n; j++){
        for(int i = j; ; i++){
            if(++t == n) break;
            if(i == n) i = 0;
            while(a[i] != b[i]){
                if(a[i] < b[i]) a[i]++, a[i+1]--, cnt++;
                if(a[i] > b[i]) a[i]--, a[i+1]++, cnt++;
            }
        }
        ans = cnt;
        ans = min(ans, cnt);
    }
    
    
    cout << ans;

    return 0;
}