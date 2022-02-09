#pragma once
#include <vector>
#include <string>
#include <iostream>

/*
works best recursively

1. Sort array if not already sorted
2. calculate median of array
3. compare to desired value
	a. if desired value is greater
		A. Call function again, providing the second half of the array to the function
	b. else if equal
		A. index of value been found, return index
	c. else if less
		A. call func again, providing first half of array to function

*/

class BinSearch
{
public:
	BinSearch(std::string k, std::vector<std::string> arr);
	int searchForKey(int start, int end);

private:
	std::string key;
	void sortByVectorType(std::vector<std::string> arr);
	std::vector<std::string> arrToSearch;
	std::vector<int> intArrToSearch;
	std::vector<std::string> strArrToSearch;
	int strVersion(int start, int end);
	int intVersion(int start, int end);

	auto returnRightArr();
};