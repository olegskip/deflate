#include "huffman_table.h"

bool CodesComparator::operator()(const CharAndBitsPair &firstPair, const CharAndBitsPair &secondPair) const noexcept
{
	if(firstPair.second.size() == secondPair.second.size()) { 
		// if the codes are equal we should compare them lexicographically
		for(std::size_t i = 0; i < firstPair.second.size(); ++i) {
			if(firstPair.second[i] != secondPair.second[i]) {
				return firstPair.second[i] < secondPair.second[i];
			}
		}
	}
	return firstPair.second.size() < secondPair.second.size();
}

HuffmanTable::HuffmanTable() noexcept
{

}

void HuffmanTable::append(char ch, BitsContainer codeInBits) noexcept
{
	charAndBitsContainer.insert({ch, codeInBits});
}
