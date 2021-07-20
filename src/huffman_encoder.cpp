#include "huffman_encoder.h"

HuffmanEncoder::HuffmanEncoder(const std::string &textToEncode) noexcept
{
	encode(textToEncode);
}

std::string HuffmanEncoder::getEncodedText() const noexcept
{
	return encodedText;
}

void HuffmanEncoder::encode(const std::string &textToEncode) noexcept
{
	// counting the frequency of the input chars
	std::unordered_map<char, int> map;
	for(char ch: textToEncode) {
		map[ch]++;
	}
	
	for(auto pair: map) {
		nodes.push(std::make_shared<Node>(pair.first, pair.second));
	}

	// Combines until there is one parent node(root)
	while(nodes.size() > 1) {
		std::shared_ptr<Node> newRight = nodes.top();
		nodes.pop();
		std::shared_ptr<Node> newLeft = nodes.top();
		nodes.pop();
		nodes.push(std::make_shared<Node>(newLeft, newRight));
	}

	if(!nodes.empty()) {
		// generating huffman table
		HuffmanTable newHuffmanTable;
		generateHuffmanTable(nodes.top(), newHuffmanTable);

		// encode using the generated huffman table
		for(char ch: textToEncode) {
			// encodedText += newHuffmanTable[ch];
		}
	}
}

void HuffmanEncoder::generateHuffmanTable(const std::shared_ptr<Node> &node, HuffmanTable &huffmanTable, BitsContainer parentPosition) noexcept
{
	const auto leftChild = node->getLeftChild();
	if(leftChild) {
		const BitsContainer newLeftPos = parentPosition + 0;
		if(leftChild->isLeaf())
			huffmanTable.append(leftChild->getValue()[0], newLeftPos);
		else
			generateHuffmanTable(leftChild, huffmanTable, newLeftPos);
	}
	const auto rightChild = node->getRightChild();
	if(rightChild) {
		const BitsContainer newRightPos = parentPosition + 0;
		if(rightChild->isLeaf())
			huffmanTable.append(rightChild->getValue()[0], newRightPos);
		else
			generateHuffmanTable(rightChild, huffmanTable, newRightPos);
	}
}
