/* 3. 写出0-1背包问题的自底向上非递归的动态规划算法。

输入：首先输入物品的个数n，然后输入背包的容量c，再依次输入每个物品的重量wi，最后依次输入每个物品的价值vi。注意：所有值都不能随机生成！！！

输出：物品的选择向量。如：(1,0,0,1,1)等。

示例：输入：4  5 2  1  3 2  12  10  20  15输出：11 0 1或（1,1,0,1） */

//0-1背包问题
#include<iostream>
using namespace std;
 
int dp[1000][1000],w[1000],v[1000], ans[1000];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main ()
{
    int n,C;
 
    cin>>n>>C;
    for(int i=1;i<=n;i++)
		cin>>w[i];
    for(int i=1;i<=n;i++)
		cin>>v[i];
 
    for(int i=1;i<=n;i++)
        for(int k=C;k>=w[i];k--)
            dp[i][k]=max(dp[i-1][k],dp[i-1][k-w[i]]+v[i]);
    for(int i=n,a=C;i;i--)
        if(dp[i][a]>dp[i-1][a])
            ans[i]=1,a-=w[i];
    for(int i=1;i<=n;i++)
	{
        cout<<ans[i];
        if(i==n);
        else cout<<' ';
	}
 
    return 0;
}