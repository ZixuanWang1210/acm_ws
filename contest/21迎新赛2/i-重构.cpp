#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> v;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        cnt ++;
        int ans = 0x3f3f3f3f;
        for(int j = i - 1; j >= 0; j--){
            if(v[i] < v[j]){
                ans = min(ans, j);
            }
        }
        if(ans == 0x3f3f3f3f){
            continue;
        }
        i = ans - 1;
    }

    cout << cnt << "\n";
   

    return 0;
}
