#include<vector>
using namespace std;

//����left center��right�������ֵ ������������������ŦԪ
template<typename Comparable>
const Comparable& median3(vector<Comparable>& a, int left, int right)
{
	//�����м�λ��
	int center = (left + right) / 2;

	//ȷ��a[left]<=a[center]
	if (a[center] < a[left])
		swap(a[left], a[center]);

	//ȷ��a[left]<=a[right]
	if (a[right] < a[left])
		swap(a[left], a[right]);

	//ȷ��a[center]<=a[right]
	if (a[right] < a[center])
		swap(a[center], a[right]);

	//����ŦԪ����ֵ���ŵ�a[right-1]��λ��
	swap(a[center], a[right - 1]);

	return a[right - 1];
}

template<typename Comparable>
void quickSort(vector<Comparable>& a, int left, int right)
{
	//����������С����10 ����п�������
	if (left+10<=right)
	{
		//��ȡ��ŦԪ 
		const Comparable& pivot = median3(a, left, right);

		//��ʼ��ָ��i��j
		int i = left, j = right - 1;

		//�ָ����
		for (;;)
		{
			//���������ҵ���һ�����ڵ�����ŦԪ��Ԫ��
			while(a[++i]<pivot){}
			//���������ҵ���һ��С�ڵ�����ŦԪ��Ԫ��
			while(pivot<a[--j]){}
			//���i<j �򽻻�������Ԫ��
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}

		//����ŦԪ�ŵ���ȷ��λ��
		swap(a[i], a[right - 1]);

		//�ݹ�ض�С�ڵ�����ŦԪ���������������
		quickSort(a, left, i - 1);
		//�ݹ�ضԴ��ڵ�����ŦԪ���������������
		quickSort(a, i + 1, right);
	}
	else
	{
		//insertionSort(a,left,right);
	}
}