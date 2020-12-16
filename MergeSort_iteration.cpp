/* 合并排序的递归实现算法。

输入：先输入进行合并排序元素的个数，然后依次随机输入（或随机生成）每个数字。

输出：元素排序后的结果，数字之间不加任何标识符。

示 */

//合并排序 递归
#include<iostream>
using namespace std;
 
template<class Type>
void Merge(Type c[], Type d[], int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
	while ((i <= m) && (j <= r))
	{
		if (c[i] <= c[j])
		{
			d[k++] = c[i++];
		}
		else
		{
			d[k++] = c[j++];
		}
	}
	if (i>m)
	{
		for (int q = j; q <= r; q++)
		{
			d[k++] = c[q];
		}
	}
	else
	{
		for (int q = i; q <= m; q++)
		{
			d[k++] = c[q];
		}
	}
}
 
template<class Type>
void MergeSort(Type a[], Type b[], int left, int right)
{
	if (left<right)
	{
		int i = (left + right) / 2;
		MergeSort(a, b, left, i);
		MergeSort(a, b, i + 1, right);
		Merge(a, b, left, i, right);
		for (int i = left; i <= right; i++)
		{
			a[i] = b[i];
		}
	}
}
 
int main()
{
	int n, data[100], result[100];
	cout << "请输入数组的长度" << endl;
	cin >> n;
	cout << "请输入数组" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		result[i] = data[i];
	}
	MergeSort(data, result, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << data[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}