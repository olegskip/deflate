#ifndef LZSS_ENCODER
#define LZSS_ENCODER

#include <string>

#include "bits_container.h"

// окно = 32 768 chars

class LzssEncoder
{
public:
	LzssEncoder(const std::string &textToEncode);
};

#endif // LZSS_ENCODER
