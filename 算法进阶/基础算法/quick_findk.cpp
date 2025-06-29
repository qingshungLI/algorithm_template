/*给定一个长度为 n 的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k 个数。

输入格式

第一行包含两个整数 n和 k。

第二行包含 n个整数（所有整数均在 1∼1e9 范围内），表示整数数列。

输出格式

输出一个整数，表示数列的第 k小数。

数据范围

1≤n≤100000,
1≤k≤n

输入样例：

5 3
2 4 1 5 3
输出样例：

3 */
#include <iostream>
using namespace std;
const int N=100010;
int a[N];
int quick_findk(int a[],int l,int r,int k){
    if(l==r) return a[l];
    int i=l,j=r+1,q=a[l];
    while(i<j){
        do i++;while(a[i]<q && i<=r);
        do j--; while (a[j]>q && j>=l);
        if(i<j)swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    int cnt=j-l+1;
    if(k>cnt) return quick_findk(a,j+1,r,k-cnt);
    if(k==cnt) return a[j];
    else return quick_findk(a,l,j-1,k);

}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    cout<<quick_findk(a,0,n-1,k);
}