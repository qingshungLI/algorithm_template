/*问题描述

　　输入一个正整数n，输出n!的值。

　　其中n!=1*2*3*…*n。

算法描述

　　n!可能很大，而计算机能表示的整数范围有限，需要使用高精度计算的方法。使用一个数组A来表示一个大整数a，A[0]表示a的个位，A[1]表示a的十位，依次类推。

　　将a乘以一个整数k变为将数组A的每一个元素都乘以k，请注意处理相应的进位。

　　首先将a设为1，然后乘2，乘3，当乘到n时，即得到了n!的值。

输入格式

　　输入包含一个正整数n，n<=1000。

输出格式

　　输出n!的准确值。

样例输入

10

样例输出

3628800*/

#include<iostream>
#include<algorithm>
#include<cstring>
 
using namespace std;
const int N=1e5+10;
int n;
int a[N];
 
int main()
{
   int t=0;
   cin>>n;
   a[1]=1;
   for(int i=2;i<=n;i++){
    for(int j=1;j<=10000;j++){
        int p=a[j]*i+t;
        a[j]=p%10;
        t=p/10;
    }
   }
   n=10000;
   while(a[n]==0)n--;
   for(int i=n;i>0;i--)cout<<a[i];
}
