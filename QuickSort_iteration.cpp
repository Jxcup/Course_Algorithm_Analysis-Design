/* 输入：先输入进行合并排序元素的个数，然后依次随机输入（或随机生成）每个数字。

输出：元素排序后的结果。

示例：输入：8  9  1  2  4  8  6  15  8，输出：1  2  4  6  8  8  9  15



代码中包含两种，一种是普通快排，一种是生成随机数的快排 */

//快速排序
#include<iostream>
#include <algorithm>
using namespace std;
template<class Type>
int Partition(Type a[],int p,int r)
{
	int i=p,j=r+1;
	Type x=a[p];
	while(i<j)
	{
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j)break;
		swap(a[i],a[j]);
	}
	a[p]=a[j];
	a[j]=x;
	return j;
 
}
template<class Type>
void QuickSort(Type a[],int p,int r)
{
	if(p<r)
	{
		int q=Partition(a,p,r);
		QuickSort(a,p,q-1);
		QuickSort(a,q+1,r);
	}
}
 
 
#include <algorithm>
template<class Type>
int Partition(Type a[],int p,int r)
{
	int i=p,j=r+1;
	Type x=a[p];
	while(i<j)
	{
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j)break;
		swap(a[i],a[j]);
	}
	a[p]=a[j];
	a[j]=x;
	return j;
 
}
template<class Type>
int RandomizedPartition(Type a[],int p,int r)
{
	int i=random()%（r-p)+p;
	swap(a[i],a[p]);
	return Partition(a,p,r);
}
template<class Type>
void RandomizedQuickSort(Type a[],int p,int r)
{
	if(p<r){
		int q=RandomizedPartition(a,p,r);
		RandomizedQuickSort(a,p,q-1);
		RandomizedQuickSort(a,q+1,r);
	}
}
 
int main()
{
	int n, data[100];
	cout << "请输入数组的长度" << endl;
	cin >> n;
	cout << "请输入数组" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	RandomizedQuickSort(data,0,n-1);
	for (int i = 0; i < n; i++)
	{
		cout << data[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}