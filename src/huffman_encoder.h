#ifndef HUFFMAN_ENCODER
#define HUFFMAN_ENCODER

#include <functional>
#include <fstream>
#include <cmath>
#include <queue>

#include "node.h"
#include "huffman_table.h"
#include "bits_container.h"

class HuffmanEncoder
{
public:
	explicit HuffmanEncoder(const std::string &textToEncode) noexcept;

	// returns final encoded text written in binary
	std::string getEncodedText() const noexcept;

private:
	void encode(const std::string &textToEncode) noexcept;
	std::string encodedText = "";

	/*
	 * This function recursively iterates through the nodes and gives the leaf unique binary code
	 * (A leaf is a node without children, in other words a single char)
	 * If a leaf located on the left from the parent then unique number = 0 + the number of the parent leaf
	 * If a leaf located on the right from the parent then unique number = 1 + the number of the parent leaf
	 * Then we convert the binary result to decimal in order to save space
	 * Aa a result the function creates huffmanTable
	 * 
	 * parentPosition must be given as binary string e.g. "00010"
	 */
	void generateHuffmanTable(const std::shared_ptr<Node> &node, HuffmanTable &huffmanTable, BitsContainer parentPosition = {}) noexcept;

	/*
	 * This queue sorts the nodes in the decreasing order
	 * So the right(on the top) ones are always with the smallest frequency
	 */
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, NodeComparator> nodes;
};

#endif // HUFFMAN_ENCODER