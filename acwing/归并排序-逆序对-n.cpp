#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn], b[maxn], n;
ll ans;

void merge_sort(int l, int r){
	if(l >= r) return;

	int mid = l + r >> 1;
	merge_sort(l, mid), merge_sort(mid + 1, r);

	int i = l, j = mid + 1, k = 0;
	while(i <= mid && j <= r){
		if(a[i] <= a[j]) b[k++] = a[i++];
		else{
			b[k++] = a[j++];
			ans = ans + mid - i + 1;
		}
	}
	while(i <= mid) b[k++] = a[i++];
	while(j <= r) b[k++] = a[j++];

	for(int k = 0, i = l; i <= r; i++){
		a[i] = b[k++];
	}
}

int main(){
	cin >> n; 
	for(int i = 0; i < n; i++) cin >> a[i];

	merge_sort(0, n - 1);

	cout << ans;
}