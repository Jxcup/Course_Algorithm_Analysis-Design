/* 3.整数划分的递归实现算法。

输入：输入整数划分的整数（只输入一次，即n==m）。

输出：输入整数的划分个数值。

示例：输入：7，输出：15

 

q(n,m)的如下递归关系定义如下：

正整数n的划分数p(n)=q(n,n)。 */

#include<iostream>
using namespace std;
 
int q(int n,int m)
{
	if((n<1)||(m<1))return 0;
	if((n==1)||(m==1))return 1;
	if(n<m)return q(n,n);
	if(n==m)return q(n,m-1)+1;
	return q(n,m-1)+q(n-m,m);
}
 
int main()
{
	int m,n;
	cin>>n;
	m=n;
	cout<<q(n,m);
	system("pause");
	return 0;
}