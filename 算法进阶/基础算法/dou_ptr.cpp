/*给定一行句子，输出其中的单词

样例输入

i am student

样例输出

i

am

student  */
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char str[1000];
    gets(str);
    int n=strlen(str);
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j<n&&str[j]!=' ') j++; //指针j扫描到空格
        for(int k=i;k<j;k++) cout<<str[k];
        cout<<endl;
        i=j; //指针i等于空格后的第一个字符
    }
    return 0;

}