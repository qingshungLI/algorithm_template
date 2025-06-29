/*给定一个长度为 n 的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 i个和第 j个元素，如果满足 i<j 且 a[i]>a[j]，则其为一个逆序对；否则不是。

输入格式

第一行包含整数 n，表示数列的长度。

第二行包含 n 个整数，表示整个数列。

输出格式

输出一个整数，表示逆序对的个数。

数据范围

1≤n≤100000，

数列中的元素的取值范围 [1,109]。

输入样例：

6

2 3 4 5 6 1

输出样例：

5*/
#include <iostream>
using namespace std;
const int N=100010;
int a[N],tmp[N];
int rev_pair(int a[],int l,int r){
    //双指针,相信递归能够做到
    if(l>=r) return 0;
    int mid=(l+r)>>1;
    int res=rev_pair(a,l,mid)+rev_pair(a,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) tmp[k++]=a[i++];
        else
        {
            tmp[k++]=a[j++];
            res+=mid-i+1;
        }
    }
    while(i<=mid) tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];
    for(int i=l,j=0;i<=r;i++,j++) a[i]=tmp[j];
    return res;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<rev_pair(a,0,n-1);
}