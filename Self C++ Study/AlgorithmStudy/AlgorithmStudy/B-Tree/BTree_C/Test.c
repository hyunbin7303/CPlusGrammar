#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bTree.h"


int main(int argc, char **argv)
{
	bTree b;
	int i;

	b = btCreate();
	assert(b);

	assert(btSearch(b, 12) == 0);
	btInsert(b, 12);
	assert(btSearch(b, 12) == 1);
	btDestroy(b);

	b = btCreate();
	for (i = 0; i < 100; i++) {
		assert(btSearch(b, i) == 0);
		btInsert(b, i);
		assert(btSearch(b, i) == 1);
	}

	for (i = 0; i < 100; i++) {
		assert(btSearch(b, i) == 1);
		btInsert(b, i);
		assert(btSearch(b, i) == 1);
	}

	btDestroy(b);

	b = btCreate();
	for (i = 0; i < 10000000; i += 2) {
		assert(btSearch(b, i) == 0);
		btInsert(b, i);
		assert(btSearch(b, i + 1) == 0);
		assert(btSearch(b, i) == 1);
	}

	btDestroy(b);

	return 0;
}