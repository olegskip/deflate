#include "huffman_encoder.h"


int main()
{
	std::string input;
	std::cin >> input;
	std::cout << HuffmanEncoder(input).getEncodedText() << std::endl;

	return 1;
}