#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 100 
int n = 9;
int list[MAX_SIZE] = { 15,65,29,20,3,73,48,8,31};
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low]<pivot);
		do
			high--;
		while (high >= left&&list[high]>pivot);
		if (low<high) SWAP(list[low], list[high], temp);
	} while (low<high);
	SWAP(list[left], list[high], temp);
	//��º�(���� pivot�� high �ε����� �ڸ��ٲ��� �����Դϴ�.) 
	for (temp = 0; temp <= right; temp++)
	{
		if (temp<left)//left���� ������ 
		{
			printf("%6s", "");//������ ��6���� ��� 
		}
		else if (temp == high)//temp�� high�� ���� ��(pivot�� �ִ� ��ġ) 
		{
			printf(" [%02d] ", list[temp]);//���� [��2�� ����] ����  ��� 
		}
		else//pivot�� �ƴ� ������ �� 
		{
			printf("  %02d  ", list[temp]);//���� ���� ��2������ ���� ���� ��� 
		}
	}
	printf("\n");//���� ��°� �����ϱ� ���� ���� ��� 
	return high;
}
void quick_sort(int list[], int left, int right)
{
	if (left<right)
	{
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}
int main(int argc, char *argv[]) {
	printf("---------------------��� --------------------------\n");
	quick_sort(list, 0, n - 1);
	return 0;
}