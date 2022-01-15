#include <bits/stdc++.h>
using namespace std;

int n, q, num, ans;
int a[100100];


bool check_upper(int x){
    return (a[x] >= num) ? true : false;//注意边界条件
}

bool check_lower(int x){
    return (a[x] <= num) ? true : false;
}

int upper_bound_search(int a[], int l, int r){
    while(l < r){
        int mid = l + r >> 1;
        if(check_upper(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int lower_bound_search(int a[], int l, int r){
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check_lower(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    while(q--){
        cin >> num;
        ans = upper_bound_search(a, 0, n - 1);
        if(a[ans] != num) cout << "-1 -1" << endl;
        else{
            cout << ans << " ";
            
            ans = lower_bound_search(a, 0, n - 1);
            cout << ans << endl;
        }
    }

    return 0;
}
