/* 2. 写出矩阵连乘的自底向上非递归的动态规划算法或自顶向下递归的动态规划算法（备忘录方法）。

输入：先输入矩阵连乘的个数n，然后依次手动输入（不能随机生成！）矩阵的维数pi（数字）。注意，6个矩阵，需输7个维数值。

输出：矩阵连乘的次序，如：((A1(A2A3))((A4A5A6))。

示例：输入：6  30  35  15  5  10  20  25，输出：((A1(A2A3))((A4A5)A6)) */

/**矩阵连乘*/
#include<iostream>
using namespace std;
int s[100][100];
int matrixchain(int i,int j,int p[])
{
    if(i==j)return 0;
    int u=matrixchain(i,i,p)+matrixchain(i+1,j,p)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++)
    {
        int t=matrixchain(i,k,p)+matrixchain(k+1,j,p)+p[i-1]*p[k]*p[j];
        if(t<u)
        {
            u=t;
            s[i][j]=k;
        }
    }
    return u;
}
 
void print(int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;
        //return;
    }
    else
    {
        cout<<"(";
        print(i,s[i][j]);
        print(s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    int n;
    int p[100];
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>p[i];
    matrixchain(1,n,p);
    print(1,n);
    cout<<endl;
    return 0;
}