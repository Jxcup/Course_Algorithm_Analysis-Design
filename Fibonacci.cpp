/* 1.写出菲波拉契数列自底向上的非递归动态规划算法或自顶向下的递归动态规划算法（备忘录方法）。

输入：输入一个数字。                  

输出：输出为Fibonacci数列的值。

示例：输入：5  ，输出：8

 

Fibonacci数列可以递归地定义为： */

#include<iostream>
#include<algorithm>
using namespace std;
 
int memo[100];
int Fib(int n)
{
    if(n<=1) return 1;
    else if(memo[n]) return memo[n];
    else return memo[n]=Fib(n-1)+Fib(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<Fib(n)<<endl;
    return 0;
}