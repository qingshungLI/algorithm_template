/*给定两个正整数（不含前导 0），计算它们的差，计算结果可能为负数。

输入格式

共两行，每行包含一个整数。

输出格式

共一行，包含所求的差。

数据范围

1≤整数长度≤105

输入样例：

32

11

输出样例：

21*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> minu(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int k = 0; // 借位
    int sizeA = A.size(), sizeB = B.size();
    
    for (int i = 0; i < sizeA; i++) {
        int a_digit = A[i]; // A的当前位
        int b_digit = (i < sizeB) ? B[i] : 0; // B的当前位，B短时用0填充

        // 计算当前位差值并考虑借位
        int diff = a_digit - b_digit - k;
        
        if (diff < 0) {
            diff += 10; // 如果差小于0，需要借位
            k = 1; // 借位
        } else {
            k = 0; // 没有借位
        }

        C.push_back(diff); // 存储当前位的差值
    }

    // 如果结果是负数，需要移除前导零
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    // 如果是负数，结果要反转，并加上负号
    if (k == 1) {
        C.push_back(-1);  // 表示负数
    }

    return C;
}


int main() {
    string a, b;
    cin >> a >> b;  // 获取输入

    vector<int> A, B;
    // 将字符串转为数字（逆序）
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    vector<int> C = minu(A, B);

    // 输出结果（逆序输出）
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl;

    return 0;
}
//看来是库中有相同的函数