#include "binSearch.h"

int main()
{
	BinSearch numBin = BinSearch::BinSearch("69", { "3","6","19","33","1" });
	numBin.searchForKey(0,4);

	BinSearch strBin = BinSearch::BinSearch("jaffacake", { "hello","hi","penelope","jaffacake","jellyfish" });
	strBin.searchForKey(0, 4);
}