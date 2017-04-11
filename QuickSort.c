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
	//출력부(현재 pivot은 high 인덱스와 자리바꿈한 상태입니다.) 
	for (temp = 0; temp <= right; temp++)
	{
		if (temp<left)//left보다 작으면 
		{
			printf("%6s", "");//공백을 폭6으로 출력 
		}
		else if (temp == high)//temp가 high와 같을 때(pivot이 있는 위치) 
		{
			printf(" [%02d] ", list[temp]);//공백 [폭2로 정수] 공백  출력 
		}
		else//pivot이 아닌 수들일 때 
		{
			printf("  %02d  ", list[temp]);//공백 공백 폭2로정수 공백 공백 출력 
		}
	}
	printf("\n");//다음 출력과 구분하기 위해 개행 출력 
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
	printf("---------------------출력 --------------------------\n");
	quick_sort(list, 0, n - 1);
	return 0;
}