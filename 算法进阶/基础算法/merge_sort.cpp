/*给定你一个长度为 n 的整数数列。

请你使用归并排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

输入格式

输入共两行，第一行包含整数 nn。

第二行包含 n 个整数（所有整数均在 1∼109），表示整个数列。

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
int a[N],tmp[N];
void merge_sort(int a[],int l,int r){
   if(l>=r) return;
   int mid=(l+r)>>1;
   merge_sort(a,l,mid);
   merge_sort(a,mid+1,r);
   int k=0,i=l,j=mid+1;
   while(i<=mid &&j<=r){
    if(a[i]>=a[j]) tmp[k++]=a[j++];
    else tmp[k++]=a[i++];
   }
   while(i<=mid) tmp[k++]=a[i++];
   while(j<=r) tmp[k++]=a[j++];
   for(int i=l,j=0;i<=r;i++,j++) a[i]=tmp[j];
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}