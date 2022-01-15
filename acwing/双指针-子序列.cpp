#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n, m;
int a[maxn], b[maxn];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    for(int i = 0; i < n; i++){
        while(a[i] != b[j]){
            j++;
            if(j > m - 1){
                cout << "No";
                return 0;
            }
        }
        j++;
    }
    cout << "Yes";
    return 0;
}