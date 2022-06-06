#include <iostream>
using namespace std;
void sort(char *b[4]) {
    char *arr[4];
    for (int i = 0; i < 4; i++) arr[i] = b[i];
    char *tmp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (*arr[j + 1] < *arr[j]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
}
int main() {
    char *name[4] = {"Follow", "Great", "FORTRAN", "Computer"};
    sort(name);
    return 0;
}
