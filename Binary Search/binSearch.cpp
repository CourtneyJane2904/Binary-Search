#include <stdio.h>
#include "binSearch.h"
#include <algorithm>

BinSearch::BinSearch(std::string k, std::vector<std::string> arr)
{
	// set value of key field
	key = k;
	sortByVectorType(arr);
}


/*
Determines if the vector passed consisted of words or numbers
If numeric, the elements are converted from data type string to integer via stoi

Very basically done here- in a real-world scenario I would work on this to make type checking more accurate!
*/
void BinSearch::sortByVectorType(std::vector<std::string> arr)
{
	// checks the data type of the first char of the first element
	bool alphaArr = isalpha(arr[0][0]);
	bool intArr = isdigit(arr[0][0]);
	// if alphabetic
	if (alphaArr)
	{
		std::cout << "strArr:" << std::endl;
		// if the array holds alphabetical chars, store in strArrToSearch
		strArrToSearch = arr;
		std::sort(strArrToSearch.begin(), strArrToSearch.end());
		for (std::string s : strArrToSearch) 
		{
			std::cout << s << ", ";
		}
		std::cout << std::endl;
	}
	// else if multiple elements are numeric (or atleast begin with a number)
	else if (intArr)
	{
		std::cout << "intArr:" << std::endl;
		// if numeric, convert to int and store in intArrToSearch
		for (std::string i : arr)
		{
			// more thorough type checking on vectors detected to hold integer values
			// catches errors produced by stoi when encountering a non-integer vslue and reports
			try
			{
				intArrToSearch.push_back(stoi(i));
			}
			catch(std::exception &err)
			{
				std::cout << "Error converting " << i << " to an integer after identifying the intended data type of the vector as integer.\nPlease check the provided vector and ensure each element is an integer." << std::endl;
				break;
			}
		}
		
		// sort array in ascending order
		std::sort(intArrToSearch.begin(), intArrToSearch.end());
		for (int i : intArrToSearch) 
		{
			std::cout << i << ", ";
		}
		std::cout << std::endl;
	}
	else
	{
		// if neither numeric or alphabetic, the array is invalid
		std::cout << "Invalid array provided." << std::endl;
	}
}

int BinSearch::strVersion(int start, int end)
{
	// recurse through strArrToSearch

	int medianIndex = (end + start) / 2;
	std::string medianElem = strArrToSearch[medianIndex];

	if (end - start == 1 && medianElem != key)
	{
		if (strArrToSearch[medianIndex + 1] != key)
		{
			std::cout << "not found!" << std::endl;
			return -1;
		}
		else
		{
			std::cout << key << " is at index " << medianIndex + 1 << std::endl;
			return medianIndex + 1;
		}
	}

	// if ascii val of medianelem is less than key
	if (medianElem.compare(key) > 0)
	{
		// recurse through first half of strArrToSearch
		std::cout << "median " << medianElem << " is greater" << std::endl;
		int s = 0;
		int e = medianIndex;
		searchForKey(s, e);
	}
	// if ascii val of medianelem is less than key
	else if (medianElem.compare(key) < 0)
	{
		std::cout << "median " << medianElem << " is less" << std::endl;
		// recurse through second half of strArrToSearch
		int s = medianIndex;
		int e = strArrToSearch.size() - 1;
		searchForKey(s, e);
	}
	else
	{
		// return median index if equal
		std::cout << key << " is at index " << medianIndex << std::endl;
		return medianIndex;
	}
}

int BinSearch::intVersion(int start, int end) 
{
	// recurse through strArrToSearch

	int medianIndex = (end + start) / 2;
	int medianElem = intArrToSearch[medianIndex];
	int keyAsInt = std::stoi(key);

	if (end - start == 1 && medianElem != keyAsInt)
	{
		if (intArrToSearch[medianIndex + 1] != keyAsInt)
		{
			std::cout << "not found!" << std::endl;
			return -1;
		}
		else
		{
			std::cout << key << " is at index " << medianIndex + 1 << std::endl;
			return medianIndex + 1;
		}
	}

	std::cout << "median index = " << medianIndex << std::endl;

	// if medianelem < key 
	if (medianElem > keyAsInt)
	{
		// recurse through first half of strArrToSearch
		int s = 0;
		int e = medianIndex;
		searchForKey(s, e);
	}
	// if ascii val of medianelem is less than key
	else if (medianElem < keyAsInt)
	{
		// recurse through second half of strArrToSearch
		int s = medianIndex;
		int e = intArrToSearch.size() - 1;
		std::cout << "medianelem is smaller, start: " << s << ", end: " << e << std::endl;
		searchForKey(s, e);
	}
	else
	{
		// return median index if equal
		std::cout << key << " is at index " << medianIndex << std::endl;
		return medianIndex;
	}
}


int BinSearch::searchForKey(int start, int end)
{
	/*
	This is a recursive function

	1. Sort array if not already sorted
	2. calculate median of array
	3. compare to desired value
	a. if desired value is greater
		A. Call function again, providing the second half of the array to the function
	b. else if equal
		A. index of value been found, return index
	c. else if less
		A. call func again, providing first half of array to function

	sorted in ascending order
	*/
	std::cout << key << " is the key" << std::endl;
	
	if (strArrToSearch.size() > 0)
	{
		return strVersion(start, end);
	}
	else if (intArrToSearch.size() > 0)
	{
		return intVersion(start, end);
	}
}

