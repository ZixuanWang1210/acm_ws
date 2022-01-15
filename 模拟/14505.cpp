#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt","r",stdin); //输入重定向，输入数据将从D盘根目录下的in.txt文件中读取
	freopen("out.txt","w",stdout); //输出重定向，输出数据将保存在D盘根目录下的out.txt文件中

    int n, m;
    vector<int>v;
    cin >> n >> m;

    while(m--){
        int opt, data;
        cin >> opt;
        if(opt == 1){
            cin >> data;
            v.insert(v.begin(), data);
        }
        else if(opt == 2){
            v.erase(v.begin());
        }
        else if(opt == 3){
            cin >> data;
            v.push_back(data);
        }
        else if(opt == 4){
            v.erase(v.end() - 1);
        }
        else if(opt == 5){
            reverse(v.begin(), v.end());
        }
        else if(opt == 6){
            cout << v.size() << endl;
            for(auto it=v.begin(); it!=v.end(); it++){
                if(it != v.begin()) cout<<" ";
                cout << *it;
            }
            if(m != 0) cout << endl;
        }
        else if(opt == 7){
            sort(v.begin(), v.end());
        }
        
    }

    return 0;
}