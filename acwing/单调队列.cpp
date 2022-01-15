#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

deque<int> qmax, qmin;
int n, k;
int a[maxn];

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++){
        if(qmin.empty()) qmin.push_back(i); //不能空,没有元素时,均可放入
        else{
            while(!qmin.empty() && i - qmin.front() + 1 > k) qmin.pop_front(); //元素数量大于要求,从头部弹出
            while(!qmin.empty() && a[qmin.back()] > a[i]) qmin.pop_back(); //先弹出相对较大元素,为小元素的进入做准备
            qmin.push_back(i); //可能先弹出在进入,可也能直接进入
        }
        if(i + 2 > k) cout << a[qmin.front()] << " "; //题目未要求输出未形成完整滑动窗口时的答案
    }

    cout << endl;

    for(int i = 0; i < n; i++){
        if(qmax.empty()) qmax.push_back(i);
        else{
            while(!qmax.empty() && i - qmax.front() + 1 > k) qmax.pop_front();
            while(!qmax.empty() && a[qmax.back()] < a[i]) qmax.pop_back();
            qmax.push_back(i);
        }
        if(i + 2 > k) cout << a[qmax.front()] << " ";
    }
    return 0;
}