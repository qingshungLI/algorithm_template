/*给定一个长度为 n 的整数序列 a1,a2,…,an 以及一个长度为 m 的整数序列 b1,b2,…,bm。

请你判断 a 序列是否为 b 序列的子序列。

子序列指序列的一部分项按原有次序排列而得的序列，例如序列 {a1,a3,a5}是序列 {a1,a2,a3,a4,a5} 的一个子序列。

输入格式

第一行包含两个整数 n,m。

第二行包含 n 个整数，表示 a1,a2,…,an。

第三行包含 m 个整数，表示 b1,b2,…,bm。

输出格式

如果 a 序列是 b 序列的子序列，输出一行 Yes。

否则，输出 No。

数据范围

1≤n≤m≤105,

−1e9≤ai,bi≤1e9

输入样例：

3 5

1 3 5

1 2 3 4 5

输出样例：

Yes*/
#include <iostream>
using namespace std;
const int N=1010;
int a[N],b[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(a[i]=b[j])i++;
        j++;
    }
    if(i==n) cout<<"Yes";
    else cout<<"No";
}