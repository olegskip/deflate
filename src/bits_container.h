#ifndef BITS_CONTAINER
#define BITS_CONTAINER

#include <vector>
#include <algorithm>

class BitsContainer: public std::vector<bool>
{
public:
	BitsContainer operator+(bool newValue) noexcept;
};


#endif // BITS_CONTAINER