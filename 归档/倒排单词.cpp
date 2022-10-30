#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<string> word_list;
    string word;
    while (cin >> word) word_list.push_back(word);
    for (int i = word_list.size() - 1; i >= 0; i--) cout << word_list[i] << " ";
    return 0;
}