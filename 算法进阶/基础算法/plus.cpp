/*给定两个正整数（不含前导 0），计算它们的和。

输入格式

共两行，每行包含一个整数。

输出格式

共一行，包含所求的和。

数据范围

1≤整数长度≤100000

输入样例：

12

23

输出样例：

35*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plu(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int k = 0; // 进位
    int sizeA = A.size(), sizeB = B.size();
    for (int i = 0; i < max(sizeA, sizeB); i++) {
        if (i < sizeA) k += A[i];  // 加上A的当前位
        if (i < sizeB) k += B[i];  // 加上B的当前位
        C.push_back(k % 10);       // 当前位结果
        k /= 10;                   // 计算进位
    }
    if (k) C.push_back(k); // 如果最后有进位，追加进位
    return C;
}

int main() {
    string a, b;
    cin >> a >> b;  // 获取输入

    vector<int> A, B;
    // 将字符串转为数字（逆序）
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    vector<int> C = plu(A, B);

    // 输出结果（逆序输出）
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl;

    return 0;
}
