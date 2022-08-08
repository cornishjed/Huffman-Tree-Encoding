#include "Compare.h"

bool Compare::operator() (node* x, node* y)
{
	if (x->freq > y->freq) {
			return x->freq > y->freq;
		}
	else
		return false;
};