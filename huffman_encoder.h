#ifndef HUFFMAN_ENCODER
#define HUFFMAN_ENCODER

#include <map>
#include <queue>
#include <cmath>
#include <functional>

#include "node.h"

typedef std::queue<std::pair<char, std::string>> HuffmanTable;

class HuffmanEncoder
{
public:
	explicit HuffmanEncoder(const std::string &textToEncode) noexcept;

	std::string getEncodedText();

private:
	std::string encode(const std::string &textToEncode) noexcept;
	std::string encodedText;

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
	void generateHuffmanTable(const std::shared_ptr<Node> &node, HuffmanTable &huffmanTable, std::string parentPosition = "") noexcept;
	// std::queue<std::pair<char, std::string>> codes;

	// std::unique_ptr<HuffmanTable> huffmanTable;

	/*
	 * This queue sorts the nodes in the decreasing order
	 * So the right(on the top) ones are always with the smallest frequency
	 */
	std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, NodeComparator> nodes;

	std::string fromBinaryStringToDecimalString(std::string binary) noexcept;
};

#endif // HUFFMAN_ENCODER