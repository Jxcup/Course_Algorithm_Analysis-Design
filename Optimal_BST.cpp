/* 写出最优二叉搜索树的自底向上非递归的动态规划算法。

输入：首先输入结点的个数n，再依次输入搜索成功的概率bi，最后依次输入搜索失败的概率aj。注意：所有值都不能随机生成，且只输入整数（概率×100）！！！

输出：最优二叉树的结构。

示例：输入：5  15 10  5  10 20  5  10 5  5  5  10，输出：

S2是根

S2的左孩子是S1

S2的右孩子是S5

S5是根

S5的左孩子是S4

S4是根

S4的左孩子是S3 */

//二叉搜索树
#include <iostream>
using namespace std;
 
int s[1000][1000];//最佳节点
int w[1000][1000];//子树概率总和
int m[1000][1000];
void best(int n, int b[], int a[])
{
	for (int i = 0; i <= n; i++)
	{
		w[i + 1][i] = a[i];
		m[i + 1][i] = 0;
	}
	for (int r = 0; r <n; r++)
	{
		for (int i = 1; i <= n - r; i++)
		{
			int j = i + r;
			w[i][j] = w[i][j - 1] + b[j] + a[j];
			m[i][j] = m[i + 1][j];
			s[i][j] = i;
			for (int k = i + 1; k <= j; k++)
			{
				int t = m[i][k - 1] + m[k + 1][j];
				if (t<m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
			m[i][j] += w[i][j];
		}
	}
}
void T(int i, int j)
{//构造最优解
	if (j>i)
	{
		int root = s[i][j];//根节点
		cout << "s" << root << "是根" << endl;
		if (s[i][root - 1]>0)
			cout << "s" << root << "的左孩子是s" << s[i][root - 1] << endl;
		if (s[root + 1][j]>0)
			cout << "s" << root << "的右孩子是s" << s[root + 1][j] << endl;
		T(i, root - 1);
		T(root + 1, j);
	}
}
int main()
{
	int n;
	int b[1000];//成功的几率
	int a[1000];//失败的几率
 
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 0; i <= n; i++)
		cin >> a[i];
	best(n, b, a);
	T(1, n);
 
	return 0;
}