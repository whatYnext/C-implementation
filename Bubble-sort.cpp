// Inplementation of Bubble sort
#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>&data, int i, int j)
{
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
void bubble(vector<int> &data)
{
	int length = data.size();
	for (int i = 0; i < length; i++)
	{
		bool swapped = false;
		for (int j = 0; j < length - (i + 1); j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data, j, j + 1);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}
void main()
{
	vector<int> data = { 10,9,8,7,6,5,4,3,2,1 };
	bubble(data);
	for (int i = 0; i < data.size(); i++)
		cout << data[i]<<" ";
}