#pragma once
#include <functional>

namespace HashFunction {

	typedef std::function< unsigned int(unsigned char*, unsigned int)> HashFunc;

	// implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length);
	unsigned int BKDRHash(unsigned char* data, unsigned int length);
	unsigned int ELFHash(unsigned char* data, unsigned int length);
	// ADD YOUR FUNCTIONS HERE

	// a helper to access a default hash function

	static HashFunc default = BKDRHash;
	//static HashFunc other = BKDRHash;
}