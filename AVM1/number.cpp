#include "Number.h"
#include <cmath>

Numbers::Numbers() : ui(0), f(0) {}

Numbers::~Numbers() {}

void Numbers::setUi(const unsigned int num)
{
	ui = num;
}

void Numbers::setF(const float num)
{
	f = num;
}

unsigned int Numbers::getUi() const
{
	return ui;
}

float Numbers::getF() const
{
	return f;
}

int Numbers::getOrder() const 
{
	return order;
}

std::string Numbers::getUiBits() const
{
	std::string res = "";
	unsigned int mask = 1 << order;
	for (int i = 0; i <= order; i++) {
		res += (ui & mask) ? '1' : '0';
		mask >>= 1;
		if ((!i || (i + 1) % 8 == 0) && i != order) {
			res += " ";
		}
	}

	return res;
}

std::string Numbers::getFBIts() const
{
	union {
		int tool;
		float f;
	};
	std::string res = "";
	unsigned int mask = 1 << order;
	for (int i = 0; i <= order; i++) {
		res += (tool & mask) ? '1' : '0';
		mask >>= 1;
		if (!i || i == 8) {
			res += " ";
		}
	}

	return res;
}

void Numbers::mirror(const int index, const int count, bool isFloat) 
{
	if (!isFloat) {
		unsigned int mask = 1 << index;
		for (int i = index; i < index + count / 2; i++) {
			unsigned int tmp = ((ui & (mask << (count - (i - index) * 2 - 1))) ? 1 : 0);
			if (((ui & mask) ? 1 : 0) != tmp) {             //1111   0 101001 1   00
				if (tmp) {								    //1111   1 101001 1   00
															// 11 11010 10
					ui -= (mask << (count - (i - index) * 2 - 1));
					ui += mask;
				}
				else {
					ui += (mask << (count - (i - index) * 2 - 1));
					ui -= mask;
				}
			}
			mask <<= 1;
		}
	}
	else {
		union {
			int tool;
			float f;
		};
		unsigned int mask = 1 << index;
		for (int i = index; i < index + count / 2; i++) {
			unsigned int tmp = ((tool & (mask << (count - (i - index) * 2 - 1))) ? 1 : 0);
			if (((tool & mask) ? 1 : 0) != tmp) {
				if (tmp) {
					tool -= (mask << (count - (i - index) * 2 - 1));
					tool += mask;
				}
				else {
					tool += (mask << (count - (i - index) * 2 - 1));
					tool -= mask;
				}
			}
			mask <<= 1;
		}
	}
}