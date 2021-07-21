#ifndef HUFFMAN_TABLE
#define HUFFMAN_TABLE

#include <memory>
#include <set>

#include "bits_container.h"


typedef std::pair<char, BitsContainer> CharWithBit;

/* 
 * The Huffman codes uses two rules:
 * 1) Shorter codes lexicographically precede longer codes.
 * 2) All codes of a given bit length have lexicographically consecutive values, in the same order as the symbols they represent;
 */
class CodesComparator
{
public:
	bool operator()(const CharWithBit &firstPair, const CharWithBit &secondPair) const noexcept;
};


class HuffmanTable
{
public:
	HuffmanTable() noexcept;

	void append(char ch, BitsContainer codeInBits) noexcept;

private:
	std::set<CharWithBit, CodesComparator> charAndBitsContainer;
};


#endif // HUFFMAN_TABLE
