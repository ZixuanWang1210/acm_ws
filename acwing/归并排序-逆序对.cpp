#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int a[maxn], temp[maxn], n;

ll merge_sort(int a[], int l, int r){
    if(l >= r) return 0;
    int mid = l + r >> 1;
    ll num = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else{
            num += mid - i + 1;
            temp[k++] = a[j++];
        }
        while(i <= mid) temp[k++] = a[i++];
        while(j <= r) temp[k++] = a[j++];
        for(int i = l, k = 0; i <= r; i++, k++){
            a[i] = temp[k];
        }
    }
    return num;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << merge_sort(a, 0, n - 1);
}