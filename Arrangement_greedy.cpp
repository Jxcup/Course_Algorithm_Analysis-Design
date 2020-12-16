/* 输入：先输入活动的个数n，然后依次输入每个活动的开始时间si及结束时间fi。
如：时间输入格式为：8：30输入为830。注意：所有值都不能随机生成！！！

输出：活动的选择向量，即0，1的集合。如： 1 0 1 0 1或（1，0，1，0，1）

示例：输入：9800 1030 900 1130 700 1100 1130 1400 1200 1330 1300 1530 1500 1600 1430 16001600 1800，
输出：1 0 0 0 1 0 1 0 1 */

//活动安排
#include <iostream>
using namespace std;
 
void swp(int a[],int i,int j)
{
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}
 
void GreedySelector(int n,int s[],int f[],int num[],int state[])
{
    int i,j;
    for(i = 0;i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(f[j] < f[i])
            {
                swp(f,i,j);
                swp(s,i,j);
                swp(num,i,j);
            }
        }
    }
    state[num[0]] = 1;
    for(j = 0,i=1;i < n;i++)
    {
        if(s[i] >= f[j])
        {
            state[num[i]] = 1;
            j = i;
        }
        else
        {
            state[num[i]] = 0;
        }
    }
}
int main()
{
    int s[1000];
    int f[1000];
    int num[1000];
    int state[1000];
    int i,n;
    cin >> n;
    for(i = 0; i < n;i++)
    {
        cin >> s[i] >> f[i];
        num[i] = i;
    }
    GreedySelector(n,s,f,num,state);
    for(i = 0; i < n; i++)
    {
        cout << state[i] << " ";
    }
    cout << endl;
    return 0;
}