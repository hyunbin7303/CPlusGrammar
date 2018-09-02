
// Implementation of a B-tree
typedef struct btNode *bTree;


// Function for Creating new node 
bTree btCreate(void); 

void btDestroy(bTree);

int btSearch(bTree, int key);

void btInsert(bTree, int key);

void btPrintKeys(bTree);
