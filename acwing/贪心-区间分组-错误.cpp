/*
比如，有n个人需要用教室，每个人占用教室的起始时间和终止时间是不一样的。
1、如果想知道只有一间教室，能安排下的最多不冲突人数（不是所有的人都有机会，有的会被舍掉）是多少（区间选点和最大不相交问题），那么当然是最先结束的人排在前面，这样后面的人才有更多机会。如果是按左端点排序，那么如过一个人0点开始用，那么肯定他排在最前面，但是如果他自己就占用了24小时，那么只能给他一个人用了，这样就达不到最大的效果。所以按右端点排序。
2、如果想知道这些人都必须安排，没有人被舍弃，至少需要多少个教室能安排下（区间分组问题）。那么肯定是按照开始时间排序，开始时间越早越优先。这样每间教室都能得到最充分的利用。
*/

/*
这里分组选择组数尽可能小，就表示大区间尽可能包含更多的小区间，有可能一个大区间包含无数个不相交的小区间
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, ans, cnt;
vector<pii> v;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end()); //按照右端点大小进行排序

    while(!v.empty()){	//还有剩余集合用来分组
        int ed = -maxn, st = -maxn;
        for(int i = 0; i < v.size(); i++){
            st = v[i].second;
            if(st > ed){		//上一个右端点与当前左端点没有交集
                ed = v[i].first;
				cnt ++;			//记录没有交集区间的个数,即一组中元素的个数
				v[i] = {-maxn, -maxn};	
            }
        }

		sort(v.begin(),v.end());
		v.erase(v.begin(), v.begin() + cnt); //删除这组中的元素
		cnt = 0;

        ans++; // 组数
    }

    cout << ans;
    return 0;
}