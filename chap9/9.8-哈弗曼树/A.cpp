// http://codeup.cn/problem.php?cid=100000617&pid=0

/*

*/


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int maxn = 110;

struct HuffNode
{
	int w, parent, lchild, rchild;
}Node[maxn * 2]; // 结点数要包含新产生的结点

void SearchMin(int& a, int& b, int n)
{
	// 最小的元素下标
	int min = INT32_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (Node[i].parent == 0 && Node[i].w < min)
		{
			min = Node[i].w;
			a = i;
		}
	}
	// 第二小的元素下标
	min = INT32_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (Node[i].parent == 0 && Node[i].w < min && i != a)
		{
			min = Node[i].w;
			b = i;
		}
	}
	// 靠前的元素放左边（为什么？）
	if (a > b)
	{
		swap(a, b);
	}
}
void HuffmanCode(int n, int w[], vector<string>& ans)
{
	// 初始化所有根结点
	for (int i = 0; i < n; ++i)
	{
		Node[i].parent = Node[i].lchild = Node[i].rchild = 0;
		Node[i].w = w[i];
	}
	// 新建合并后的根结点Node[n]~Node[2n-2]
	for (int i = n; i < 2 * n - 1; ++i)
	{
		int a, b;
		SearchMin(a, b, i);
		Node[i].lchild = a;
		Node[i].rchild = b;
		Node[i].w = Node[a].w + Node[b].w;
		Node[a].parent = Node[b].parent = i;
	}
	int c, f, index;
	string temp;
	for (int i = 0; i < n; ++i)
	{
		temp = "";
		c = i;
		index = 0;
		while (Node[c].parent != 0)
		{
			f = Node[c].parent;
			if (Node[f].lchild == c)
				temp += '0';
			else
				temp += '1';
			index++;
			c = f;
		}
		reverse(temp.begin(), temp.begin() + index);
		ans.push_back(temp);
	}
}

int main() {
	int n, w[maxn];
	vector<string> ans;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &w[i]);
		}
		HuffmanCode(n, w, ans);
		for (int i = 0; i < n; ++i)
		{
			cout << ans[i] << endl;
		}
		ans.clear();
	}
	return 0;
}
