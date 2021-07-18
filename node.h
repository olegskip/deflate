#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>
#include <iostream>

class Node
{
public:
	explicit Node(char value_, int freq) noexcept;
	explicit Node(std::shared_ptr<Node> leftChild_, std::shared_ptr<Node> rightChild_);

	std::string getValue() const noexcept;
	int getFrequency() const noexcept;
	bool isLeaf() const noexcept;

	const std::shared_ptr<Node> &getRightChild() const noexcept;
	const std::shared_ptr<Node> &getLeftChild() const noexcept;

private:
	int frequency;
	std::string value;

	std::shared_ptr<Node> leftChild, rightChild;
};


class NodeComparator
{
public:
	bool operator()(const std::shared_ptr<Node> &first, const std::shared_ptr<Node> &second) noexcept
	{
		return first->getFrequency() > second->getFrequency();
	}
};
#endif // NODE_H