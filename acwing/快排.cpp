#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int a[maxn], n;

void q_sort_1(int a[], int l, int r){
    if(l >= r) return;
    int x = a[l], i = l - 1, j = r + 1;// do..while()留出空余
    while(i < j){//穿过
        do i++; while(a[i] < x);//等于也停下
        do j--; while(a[j] > x);
        if(i < j) swap(a[i], a[j]);
    }
    q_sort_1(a, l, j), q_sort_1(a, j + 1, r);
}

void q_sort_2(int a[], int l, int r){
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while(i < j){
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    q_sort_2(a, l, j), q_sort_2(a, j + 1, r);
}

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
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
    //quick_sort(a, 0, n - 1);
    q_sort_2(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}
