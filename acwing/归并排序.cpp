#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int n, a[maxn], temp[maxn];

void merge_sort(int a[], int l, int r){
    if(l >= r) return;//易忘

    int mid = l + r >> 1;
    merge_sort(a, l, mid), merge_sort(a, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    for(int i = l, k = 0; i <= r; i++, k++){
        a[i] = temp[k];
    }
}


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

    merge_sort(a, 0, n - 1);

    for(int  i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}
