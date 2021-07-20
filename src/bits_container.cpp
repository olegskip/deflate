#include "bits_container.h"

BitsContainer BitsContainer::operator+(bool newValue) noexcept
{
	BitsContainer newBitsContainer;
	newBitsContainer.reserve(size() + 1);
	std::copy(begin(), end(), std::back_inserter(newBitsContainer));

	return newBitsContainer;
}