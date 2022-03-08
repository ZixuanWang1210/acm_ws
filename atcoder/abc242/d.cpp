#include<bits/stdc++.h>
using namespace std;

string S;
int Q;

int main(){
	cin >> S >> Q;
	long long k, pos;
	while(Q--){
		cin >> k >> pos;
		int diff = 0;
		while(k != 0 && pos != 1){
			diff += (pos % 2 == 0 ? 2 : 1);
			pos = (pos + 1) / 2;
			-- k;
		}
		k += diff;
		putchar((char)((S[pos-1] - 'A' + k) % 3 + 'A'));
		puts("");
	}	
	return 0;
}