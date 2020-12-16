/* 输入：先输入物品的个数n，再输入背包的容量c，然后依次输入物品的重量wi，
最后依次输入物品的价值vi。注意：所有值都不能随机生成！！！

输出：物品的选择向量xi，0=<xi=<1。

示例：输入：320  18 15 10 25 24 15，输出：0.0   1.0    0.5 */

#include <iostream>
using namespace std;
 
void swp(double a[],int i,int j)
{
    double t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}
 
void Knapsack(int n,double c,double w[],double v[],double x[],int num[])
{
    int i,j,t;
    for(i = 0;i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(v[j]/w[j] > v[i]/w[i])
            {
                swp(w,i,j);
                swp(v,i,j);
 
                t = num[i];
                num[i] = num[j];
                num[j] =t;
            }
        }
    }
 
    for(i = 0; i < n; i++)
    {
        if(w[i] > c)
        {
            break;
        }
        x[num[i]] = 1;
        c -= w[i];
    }
    if(i < n)
    {
        x[num[i]] = c/w[i];
    }
}
 
int main()
{
    int n,i;
    int num[1000];
    double c,w[1000],v[1000],x[1000];
    cin >> n >> c;
    for(i = 0; i < n; i++)
    {
        cin >> w[i];
        num[i] = i;
        x[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Knapsack(n,c,w,v,x,num);
    for(i = 0; i < n; i++)
    {
        cout << double(x[i]) << " ";
    }
    cout << endl;
    return 0;
}