/*
	Nuon, Molita

	CS A250
	April 29, 2018

	Lab 12
*/

#include <iostream>
#include <set>
#include <map>
#include <iterator>

using namespace std;

int countClumps(const multiset<int>& multiSet);
void clumps(const int a[], int numOfElem);

bool linearIn(const multimap<int, int>& multiMap);
void linear(int a[][2], int rows);

void multiples(set < int>& aSet, int num);
void printMultiples(int num);

const int MULTIPLES = 10;

int main()
{
	int arr1[] = { 1,2,2,3,4,4 };
	int arr2[] = { 1,1,2,2,2 };
	int arr3[] = { 3,3,3,3,3 };
	int arr4[] = { 1,2,3 };
	int arr5[] = { 2,2,6,6,6,7,8,8,9,9 };
	int arr6[] = { 1,2,3,4,5,6,7,8,9,9 };
	int arr7[] = { 1,3,5,7,7,8,9 };

	cout << "TEST: clumpCount -------------------\n";
	clumps(arr1, 6);
	clumps(arr2, 5);
	clumps(arr3, 5);
	clumps(arr4, 3);
	clumps(arr5, 10);
	clumps(arr6, 10);
	clumps(arr7, 7);
	clumps(arr1, 0);

	int arr8[6][2] = { {3,3}, {4,4}, {5,1}, {6,2}, {7,3}, {7,5} };
	int arr9[5][2] = { {1,2}, {2,6}, {4,2}, {4,6}, {6,4} };
	int arr10[6][2] = { {2,4}, {2,3}, {4,6}, {4,7}, {6,5}, {6,2} };
	int arr11[4][2] = { {3,6}, {4,6}, {5,6}, {6,6},};
	int arr12[5][2] = { {3,3}, {3,3}, {3,3}, {3,3}, {3,4} };
	int arr13[5][2] = { {3,3}, {3,3}, {3,3}, {3,4}, {4,3} };

	cout << "\n\nTEST: linearIn -------------------\n";
	linear(arr8, 6);
	linear(arr9, 5);
	linear(arr10, 6);
	linear(arr11, 4);
	linear(arr12, 5);
	linear(arr13, 5);

	cout << "\n\nTEST:  multiples-------------------\n";

	printMultiples(2);
	printMultiples(3);
	printMultiples(5);

	cout << endl;
	system("Pause");
	return 0;
}

int countClumps(const multiset<int>& multiSet)
{
	if (multiSet.size() == 0)
		return 0;
	else
	{
		int count = 0;

		multiset<int>::const_iterator iterMultiSet 
			= multiSet.cbegin();
		multiset<int>::const_iterator iterMultiSetEnd
			= multiSet.cend();
		
		int leftValue = *iterMultiSet;
		++iterMultiSet;
		
		bool done = false;
		
		while (iterMultiSet != iterMultiSetEnd)
		{
			if (*iterMultiSet == leftValue)
			{
				if (!done)
					count++;
				done = true;
			}
			else
				done = false;

			leftValue = *iterMultiSet;
			iterMultiSet++;
		}

		return count;
	}
}

void clumps(const int a[], int numOfElem)
{
	multiset<int> multiSet(a, a + numOfElem);
	int clumpCount = countClumps(multiSet);
	cout << clumpCount << endl;
}

bool linearIn(const multimap<int, int>& multiMap)
{
	multimap<int, int>::const_iterator iterMultiMap 
		= multiMap.cbegin();
	multimap<int, int>::const_iterator iterMultiMapEnd
		= multiMap.cend();

	while (iterMultiMap != iterMultiMapEnd)
	{
		if (multiMap.find(iterMultiMap->second) == iterMultiMapEnd)
			return false;
		iterMultiMap++;
	}
	return true;
}
void linear(int a[][2], int rows)
{
	multimap<int, int> multiMap;

	for (int i = 0; i < rows; i++)
		multiMap.emplace(a[i][0], a[i][1]);

	cout << ((linearIn(multiMap)) ? "true" : "false") << endl;
}

void multiples(set <int>& aSet, int num)
{
	int count = 0;
	int multiple = num * 2;

	set<int>::const_iterator iter = aSet.cbegin();

	while (count < MULTIPLES)
	{
		iter = aSet.insert(iter, multiple);
		multiple += num;
		if (multiple % 10 == num)
			multiple += num;
		count++;
	}
}
void printMultiples(int num)
{
	set<int> aSet;
	multiples(aSet, num);

	ostream_iterator<int> screen(cout, " ");
	copy(aSet.begin(), aSet.end(), screen);
	cout << endl;
}