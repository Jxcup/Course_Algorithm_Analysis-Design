/* 1. Ackerman函数的递归实现算法。

输入：输入两个数字，先输入n，后输入m。

输出：Ackerman函数计算后的值。

示例：输入：4    2，输出：16

 

Ackerman函数A(n，m)定义如下：

有两个独立的整型变量m、n： */

#include<iostream>
using namespace std;
 
int ackerman(int n,int m)
{
    if(m==0 && n==1)
        return 2;
    if(m>=0 && n==0)
        return 1;
    if(m==0 && n>=2)
        return n+2;
    if(m>=1 && n>=1)
        return ackerman(ackerman(n-1,m),m-1);
}

int main()
{
    int m, n;
    cin >> n >> m;
    cout << ackerman(n,m) << endl;
    return 0;
}