#include<vector>
using namespace std;

//�鲢�����㷨����������
template<typename Comparable>
void mergeSort(vector<Comparable>& a)
{
	//����һ����ʱ���� ��С������������ͬ
	vector<Comparable>tempArray(a.size());
	//����mergeSort�����غ��� ��ʼ����
	mergeSort(a, tempArray, 0, a.size() - 1);
}

//���еݹ���õ��ڲ�����
template<typename Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tempArray, int left, int right)
{
	//���������С�������� ��ʾ����������������Ԫ��
	if (left<right)
	{
		//�����м�����
		int center = (left + right) / 2;
		//����벿����������й鲢����
		mergeSort(a, tempArray, left, center);
		//���Ұ벿����������й鲢����
		mergeSort(a, tempArray, center + 1, right);
		//�ϲ������������������
		merge(a, tempArray, left, center + 1, right);
	}
}

//�ϲ������������������ֵ��ڲ�����
template<typename Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tempArray, int leftPos, int rightPos, int rightEnd)
{
	//������벿������������һ��Ԫ�ص�����
	int leftEnd = rightPos - 1;
	//������ʱ�������ʼ����
	int tempPos = leftPos;
	//����ϲ���Ԫ������
	int numElements = rightEnd - leftPos + 1;

	//��ѭ�����ϲ�����������
	while (leftPos<=leftEnd&&rightPos<=rightEnd)
	{
		//�����������ĵ�ǰԪ��С�ڵ�����������ĵ�ǰԪ��
		if (a[leftPos] <= a[rightPos])
			//����������ĵ�ǰԪ�ظ��Ƶ���ʱ����
			tempArray[tempPos++] = move(a[leftPos++]);
		else
			//����������ĵ�ǰԪ�ظ��Ƶ���ʱ����
			tempArray[tempPos++] = move(a[rightPos++]);
	}

	//����ǰ�벿�ֵ�ʣ��Ԫ��
	while (leftPos<=leftEnd)
		tempArray[tempPos++] = move(a[leftPos++]);

	//���ƺ�벿�ֵ�ʣ��Ԫ��
	while (rightPos <= rightEnd)
		tempArray[tempPos++] = move(a[rightPos++]);

	//����ʱ���鸴�ƻ�ԭ����a
	for (int i = 0; i < numElements; ++i,--rightEnd)
	{
		a[rightEnd] = move(tempArray[rightEnd]);
	}
}