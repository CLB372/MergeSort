// This program accepts user input to a vector of a length determined by the user, 
// sorts the numbers from least to greatest using the merge sort algorithm, then
// displays the results to the user.

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

// mergeSort function prototype
vector<int> mergeSort(vector<int> x, int low, int high);
vector<int> merge(vector<int> x, int low, int high);

int main()
{
	// vector declaration
	vector<int> x;
	int vectorLength;

	// get user input
	cout << "\n     Enter the number of integers your list: ";
	cin >> vectorLength;
	cout << "\n     *** NOTE: ONLY ENTER INTEGER VALUES -- NO DECIMALS ***\n";
	x.resize(vectorLength);
	for (int i = 0; i < vectorLength; i++)
	{
		cout << "\n     (" << i + 1 << ") Enter number: ";
		cin >> x[i];
	}

	if (vectorLength > 0)
	{
		// perform the merge sort on the vector x
		x = mergeSort(x, 0, x.size()-1);


		// display the newly sorted vector x, from element 0 to element vectorLength-1
		cout << "\n\n     MERGESORTED RESULT:\n\n";
		for (int i = 0; i < vectorLength; i++)
		{
			cout << "                 " << x[i] << "\n";
		}
	}
	else
	{
		cout << "\n\n     ERROR: There must be at least 1 number in your list. Program terminated.\n";
	}

	cin.ignore(); cin.ignore();

	return 0;
}


vector<int> mergeSort(vector<int> x, int low, int high)
// takes the vector x, performs a merge sort, and returns the sorted vector
{
	vector<int> localVector;

	// copy the vector x to the vector localVector
	localVector.resize(x.size());
	for (int i = 0; i < x.size(); i++) { localVector[i] = x[i]; }

	if (low != high)
	{
		localVector = mergeSort(localVector, low, (low + high) / 2);
		localVector = mergeSort(localVector, ((low + high) / 2) + 1, high);
	}
	
	return merge(localVector, low, high);
}


vector<int> merge(vector<int> x, int low, int high)
// This function takes 2 already-sorted halves and merges them
// into one single vector and returns the merged vector
{
	vector<int> localVector;
	vector<int> subVectorLeft;
	vector<int> subVectorRight;
	int i, j, k;

	localVector.resize(x.size());
	for (i = 0; i < x.size(); i++) { localVector[i] = x[i]; }

	for (i = 0; i < ((low + high) / 2) - low + 1; i++)
	{
		subVectorLeft.resize(subVectorLeft.size() + 1);
		subVectorLeft[i] = localVector[i + low];
	}
	for (i = 0; i < high - ((low + high) / 2); i++)
	{
		subVectorRight.resize(subVectorRight.size() + 1);
		subVectorRight[i] = localVector[((low + high) / 2) + i + 1];
	}

	i = 0;
	j = 0;
	k = low;
	while (i < ((low + high) / 2) - low + 1 && j < high - ((low + high) / 2))
	{
		if (subVectorLeft[i] <= subVectorRight[j])
		{
			localVector[k] = subVectorLeft[i];
			i++;
		}
		else
		{
			localVector[k] = subVectorRight[j];
			j++;
		}
		k++;
	}
	while (i < ((low + high) / 2) - low + 1)
	{
		localVector[k] = subVectorLeft[i];
		i++;
		k++;
	}
	while (j < high - ((low + high) / 2))
	{
		localVector[k] = subVectorRight[j];
		j++;
		k++;
	}

	return localVector;
}