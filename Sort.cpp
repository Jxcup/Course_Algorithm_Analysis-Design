/* 2.全排列的递归实现算法。

输入：先输入要求输入的字符的个数，后依次输入（或随机生成）每个字符（不能仅仅是数字）。

输出：全排列的结果。

示例：输入：3  /  *  2，输出：/  * 2  /  2  *  *  /  2  *  2  /  2  *  /  2  /  * 

 

R的全排列可归纳递归定义如下： */

#include<iostream>
using namespace std;
void perm(int *a,int k,int m)
{
    if(k==m)
    {
        for(int i=0;i<=m;i++)
            cout<<a[i]<<"  ";
    }
    else
    {
        for(int j=k;j<=m;j++)
        {
            swap(a[j],a[k]);
            perm(a,k+1,m);
            swap(a[j],a[k]);
        }
    }
}
 
int main()
{
    int n;
    char a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    perm(a,0,n-1);
    cout<<endl;
    return 0;
}