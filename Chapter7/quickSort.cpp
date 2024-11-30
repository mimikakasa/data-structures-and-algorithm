#include<vector>
using namespace std;

//返回left center和right三项的中值 并将他们排序并隐藏枢纽元
template<typename Comparable>
const Comparable& median3(vector<Comparable>& a, int left, int right)
{
	//计算中间位置
	int center = (left + right) / 2;

	//确保a[left]<=a[center]
	if (a[center] < a[left])
		swap(a[left], a[center]);

	//确保a[left]<=a[right]
	if (a[right] < a[left])
		swap(a[left], a[right]);

	//确保a[center]<=a[right]
	if (a[right] < a[center])
		swap(a[center], a[right]);

	//将枢纽元（中值）放到a[right-1]的位置
	swap(a[center], a[right - 1]);

	return a[right - 1];
}

template<typename Comparable>
void quickSort(vector<Comparable>& a, int left, int right)
{
	//如果子数组大小大于10 则进行快速排序
	if (left+10<=right)
	{
		//获取枢纽元 
		const Comparable& pivot = median3(a, left, right);

		//初始化指针i和j
		int i = left, j = right - 1;

		//分割过程
		for (;;)
		{
			//从左向右找到第一个大于等于枢纽元的元素
			while(a[++i]<pivot){}
			//从右向左找到第一个小于等于枢纽元的元素
			while(pivot<a[--j]){}
			//如果i<j 则交换这两个元素
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}

		//将枢纽元放到正确的位置
		swap(a[i], a[right - 1]);

		//递归地对小于等于枢纽元的子数组进行排序
		quickSort(a, left, i - 1);
		//递归地对大于等于枢纽元的子数组进行排序
		quickSort(a, i + 1, right);
	}
	else
	{
		//insertionSort(a,left,right);
	}
}