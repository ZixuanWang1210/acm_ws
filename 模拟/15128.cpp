#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    do{
        for(int i=0; i<8; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    while(next_permutation(a, a + 8));

    return 0;
}