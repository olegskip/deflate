#ifndef HUFFMAN_TABLE
#define HUFFMAN_TABLE

#include <memory>
#include <set>

#include "bits_container.h"


typedef std::pair<char, std::vector<bool>> CharAndBitsPair;

/* 
 * The Huffman codes uses two rules:
 * 1) Shorter codes lexicographically precede longer codes.
 * 2) All codes of a given bit length have lexicographically consecutive values, in the same order as the symbols they represent;
 */
class CodesComparator
{
public:
	bool operator()(const CharAndBitsPair &firstPair, const CharAndBitsPair &secondPair) const noexcept;
};


class HuffmanTable
{
public:
	HuffmanTable() noexcept;

	void append(char ch, BitsContainer codeInBits) noexcept;

private:
	std::set<CharAndBitsPair, CodesComparator> charAndBitsContainer;
};


#endif // HUFFMAN_TABLE