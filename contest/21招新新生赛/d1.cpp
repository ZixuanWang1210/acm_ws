#include <bits/stdc++.h>
#define endl "\n"


using namespace std;

const int maxn = 10000000 + 10;
int a[maxn];
int n;
int xxx = 3;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++){
        int num = a[i];
        int r = 0, l = i;
 
        for(int j = i + 1; j < n; j++){

            if(a[i] == a[j]){
                xxx = 1;
                r = j;
                break;
            }
        }

        if(xxx == 3) continue;
        if(r - l < 2) continue;
        int flag = 3;
        for(int j = r; j > l; j--){
            if(a[l] != a[j]){
                flag = false;
            }
            l ++;
        }
        if(flag == false) continue;
        else{
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}
