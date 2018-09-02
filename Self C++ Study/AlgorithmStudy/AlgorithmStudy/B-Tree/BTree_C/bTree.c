
#include <stdio.h>
#include <stdlib.h>	
#include <assert.h>	
#include <string.h>
#include "bTree.h"

#define MAX_KEYS (1024)

struct btNode {
	int isLeaf;
	int numKeys;
	int keys[MAX_KEYS];
	struct btNode *kids[MAX_KEYS + 1]; // it holds ndoes keys[i]

};

bTree btCreate(void)
{
	bTree b;
	b = malloc(sizeof(*b));
	assert(b);

	b->isLeaf = 1;
	b->numKeys = 0;

	return b;
}

void btDestroy(bTree b)
{
	int i;
	if (!b->isLeaf)
	{
		for (i = 0; i < b->numKeys + 1; i++)
		{
			btDestroy(b->keys[i]);
		}
	}

	free(b);
}

static int searchKey(int n, const int *a, int key)
{
	int low;
	int high;
	int middle;

	// invariant : a[low] < key <= a[high] 
	low = -1;
	high = n;

	while (low + 1 < high)
	{
		middle = (low + high) / 2;
		if (a[middle] == key)
		{
			return middle;
		}
		else if (a[middle] < key)
		{
			low = middle;
		}
		else
		{
			high = middle;
		}
	}
	return high;
}


static bTree btInsertInternal(bTree b, int key, int *median)
{
	int pos;
	int middle;
	bTree b2;

	pos = searchKey(b->numKeys, b->keys, key);
	if (pos < b->numKeys && b->keys[pos] == key)
	{
		return 0;
	}
	if (b->isLeaf)
	{
		//everybody aobe pos moves up one space
		memmove(&b->keys[pos + 1], &b->keys[pos], sizeof(*(b->keys)) * (b->numKeys - pos));
		b->keys[pos] = key;
		b->numKeys++;
	}
	else
	{
		// insert in child
		b2 = btInsertInternal(b->kids[pos], key, &middle);

		// maybe insert a new key in b
		if (b2)
		{
			memmove(&b->keys[pos + 1], &b->keys[pos], sizeof(*(b->keys)) * (b->numKeys - pos));
			memmove(&b->keys[pos + 2], &b->keys[pos+1], sizeof(*(b->keys)) * (b->numKeys - pos));
			b->keys[pos] = middle;
			b->kids[pos + 1] = b2;
			b->numKeys++;
		}
	}

	if (b->numKeys >= MAX_KEYS)
	{
		middle = b->numKeys / 2;
		*median = b->keys[middle];

		b2 = malloc(sizeof(*b2));
		b2->numKeys = b->numKeys - middle - 1;
		b2->isLeaf = b->isLeaf;

		memmove(b2->keys, &b->keys[middle + 1], sizeof(*(b->keys)) * b2->numKeys);
		if (!b->isLeaf)
		{
			memmove(b2->kids, &b->kids[middle + 1], sizeof(*(b->kids)) * (b2->numKeys + 1));

		}
		b->numKeys = middle;
		return b2;
	}
	else
	{
		return 0;
	}
}


int btSearch(bTree b, int key)
{
	int pos;

	// have to check for empty tree
	if (b->numKeys == 0)
	{
		return 0;
	}

	// look for smallest position that key fits below
	pos = searchKey(b->numKeys, b->keys, key);



}

void btInsert(bTree b, int key)
{
	bTree b1;
	bTree b2;
	int median;

	b2 = btInsertInternal(b, key, &median);
	if (b2)
	{
		b1 = malloc(sizeof(*b1));
		assert(b1);

		memmove(b1, b, sizeof(*b1));

		b->numKeys = 1;
		b->isLeaf = 0;
		b->keys[0] = median;
		b->keys[0] = b1;
		b->keys[1] = b2;
	}
}

void btPrintKeys(bTree t)
{
}
