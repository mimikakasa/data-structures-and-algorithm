#include<vector>
using namespace std;

//归并排序算法（驱动程序）
template<typename Comparable>
void mergeSort(vector<Comparable>& a)
{
	//创建一个临时数组 大小与输入数组相同
	vector<Comparable>tempArray(a.size());
	//调用mergeSort的重载函数 开始排序
	mergeSort(a, tempArray, 0, a.size() - 1);
}

//进行递归调用的内部方法
template<typename Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tempArray, int left, int right)
{
	//如果左索引小于右索引 表示子数组至少有两个元素
	if (left<right)
	{
		//计算中间索引
		int center = (left + right) / 2;
		//对左半部分子数组进行归并排序
		mergeSort(a, tempArray, left, center);
		//对右半部分子数组进行归并排序
		mergeSort(a, tempArray, center + 1, right);
		//合并两个已排序的子数组
		merge(a, tempArray, left, center + 1, right);
	}
}

//合并子数组已排序两部分的内部方法
template<typename Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tempArray, int leftPos, int rightPos, int rightEnd)
{
	//计算左半部分子数组的最后一个元素的索引
	int leftEnd = rightPos - 1;
	//计算临时数组的起始索引
	int tempPos = leftPos;
	//计算合并的元素总数
	int numElements = rightEnd - leftPos + 1;

	//主循环：合并两个子数组
	while (leftPos<=leftEnd&&rightPos<=rightEnd)
	{
		//如果左子数组的当前元素小于等于右子数组的当前元素
		if (a[leftPos] <= a[rightPos])
			//将左子数组的当前元素复制到临时数组
			tempArray[tempPos++] = move(a[leftPos++]);
		else
			//将右子数组的当前元素复制到临时数组
			tempArray[tempPos++] = move(a[rightPos++]);
	}

	//复制前半部分的剩余元素
	while (leftPos<=leftEnd)
		tempArray[tempPos++] = move(a[leftPos++]);

	//复制后半部分的剩余元素
	while (rightPos <= rightEnd)
		tempArray[tempPos++] = move(a[rightPos++]);

	//将临时数组复制回原数组a
	for (int i = 0; i < numElements; ++i,--rightEnd)
	{
		a[rightEnd] = move(tempArray[rightEnd]);
	}
}