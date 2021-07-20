#include "node.h"

Node::Node(char value_, int freq) noexcept
{
	value = std::string(1, value_);
	frequency = freq;
}

Node::Node(std::shared_ptr<Node> leftChild_, std::shared_ptr<Node> rightChild_)
{
	if(!leftChild_ || !rightChild_)
		throw std::invalid_argument("A node child is invalid");
	leftChild = leftChild_;
	rightChild = rightChild_;
	frequency += leftChild->frequency + rightChild->frequency;
	value += leftChild->value + rightChild->value;
}

std::string Node::getValue() const noexcept
{
	return value;
}

int Node::getFrequency() const noexcept
{
	return frequency;
}

const std::shared_ptr<Node> &Node::getLeftChild() const noexcept
{
	return leftChild;
}

const std::shared_ptr<Node> &Node::getRightChild() const noexcept
{
	return rightChild;
}

// A node is considered to be a leaf if it has no children, in other words it's a single char 
bool Node::isLeaf() const noexcept
{
	return !leftChild && !rightChild;
}

bool NodeComparator::operator()(const std::shared_ptr<Node> &first, const std::shared_ptr<Node> &second) const noexcept
{
	return first->getFrequency() > second->getFrequency();
}
