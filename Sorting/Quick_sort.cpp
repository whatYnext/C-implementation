#include<iostream>
#include<vector>
using namespace std;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(vector <int> &arr, int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(vector<int> &arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(vector<int> arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout<<arr[i]<<" ";
}
int main()
{
	vector <int> arr = { 10, 7, 8, 9, 1, 5 };
	int n = arr.size();
	quickSort(arr, 0, n - 1);
	cout<<"Sorted array: ";
	printArray(arr, n);
	return 0;
}
