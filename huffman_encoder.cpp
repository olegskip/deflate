#include "huffman_encoder.h"

HuffmanEncoder::HuffmanEncoder(const std::string &textToEncode) noexcept
{
	encodedText = encode(textToEncode);
}

std::string HuffmanEncoder::getEncodedText()
{
	return encodedText;
}

std::string HuffmanEncoder::encode(const std::string &textToEncode) noexcept
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

	std::string output = "";
	if(!nodes.empty()) {
		HuffmanTable newHuffmanTable;
		generateHuffmanTable(nodes.top(), newHuffmanTable);
		while(!newHuffmanTable.empty()) {
			const std::pair<char, std::string> front = newHuffmanTable.front();
			output += std::string(1, front.first) + fromBinaryStringToDecimalString(front.second) + "\n";
			newHuffmanTable.pop();
		}
	}
	return output;
}

void HuffmanEncoder::generateHuffmanTable(const std::shared_ptr<Node> &node, HuffmanTable &huffmanTable, std::string parentPosition) noexcept
{
	const auto leftChild = node->getLeftChild();
	if(leftChild) {
		const std::string newLeftBinaryPos = parentPosition + "0";
		if(leftChild->isLeaf())
			huffmanTable.push({leftChild->getValue()[0], newLeftBinaryPos});
		else
			generateHuffmanTable(leftChild, huffmanTable, newLeftBinaryPos);
	}
	const auto rightChild = node->getRightChild();
	if(rightChild) {
		const std::string newRightBinaryPos = parentPosition + "1";
		if(rightChild->isLeaf())
			huffmanTable.push({rightChild->getValue()[0], newRightBinaryPos});
		else
			generateHuffmanTable(rightChild, huffmanTable, newRightBinaryPos);
	}
}

std::string HuffmanEncoder::fromBinaryStringToDecimalString(std::string binary) noexcept
{
	int decimal = 0;
	const std::size_t binaryLength = binary.length();
	for(std::size_t i = 0; i < binaryLength; ++i) {
		decimal += std::pow(2, binaryLength - i - 1) * binary[i];
	}

	return std::to_string(decimal);
}
