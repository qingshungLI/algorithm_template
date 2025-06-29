/*给定 n 个区间 [li,ri]，要求合并所有有交集的区间。

注意如果在端点处相交，也算有交集。

输出合并完成后的区间个数。

例如：[1,3] 和 [2,6] 可以合并为一个区间 [1,6]。

输入格式

第一行包含整数 nn。

接下来 nn 行，每行包含两个整数 l 和 r。

输出格式

共一行，包含一个整数，表示合并区间完成后的区间个数。

数据范围

1≤n≤100000,

−109≤li≤ri≤109

输入样例：

5

1 2

2 4

5 6

7 8

7 9

输出样例：

3*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 300010;
int n;
vector<PII> interval;
void merge(vector<PII>&interval){
    sort(interval.begin(), interval.end()); //! pair排序 优先左端点， 再以右端点排序
    vector<PII> ans;
    int st = -1e9-10, ed = -1e9-10;  //! 只要比 -1e9 小就可以
    for(auto item:interval)
    {
        if(ed<item.first) //! 第一段区间一定是  ed< item.first
        {
            if(st!=-1e9-10) ans.push_back({st,ed}); //! 第一次在这里初始化
            st = item.first, ed = item.second;//! 第一段区间从这里开始
        }
        else ed = max(ed, item.second);
    }//todo 这个循环结束之后还会剩下一个区间
    if(st!=-1e9-10) ans.push_back({st,ed});  //! 如果不是空的  那我们就加上一段
    interval = ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        interval.push_back({l,r});
    }
    merge(interval);
    cout << interval.size() << endl;

}
