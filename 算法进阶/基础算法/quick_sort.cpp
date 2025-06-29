/*给定你一个长度为 n 的整数数列。

请你使用快速排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

输入格式

输入共两行，第一行包含整数 n。

第二行包含 n 个整数（所有整数均在 1∼1e9），表示整个数列。

输出格式

输出共一行，包含 n 个整数，表示排好序的数列。

数据范围

1≤n≤100000

输入样例：

5

3 1 2 4 5

输出样例：

1 2 3 4 5*/
#include <iostream>
using namespace std;
const int N=100010;
int a[N];
void quick_sort(int a[],int l,int r){
    if(l>=r) return;
    int i=l,j=r+1;
    int q=a[l];
    while(i<j){
        do i++;while(a[i]<q&& i<r);
        do j--;while(a[j]>q &&j>l);
        if(i<j)swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    quick_sort(a,l,j-1);
    quick_sort(a,j+1,r);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}