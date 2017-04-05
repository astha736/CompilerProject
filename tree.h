/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#ifndef _TREE_H
#define  _TREE_H
#define MAX_NO_CHILDREN 20

typedef struct TNode
{
	int enumval;
	char value[25];	
	int type;
	struct TNode* children[MAX_NO_CHILDREN];
	struct TNode* parent;
	int no_of_children;
	int childID;
} TNode;

typedef struct TNode* TLink;

typedef struct 
{
	TLink root;
	int totalNodes;
	int totalLeafNodes;
} Tree;

Tree createTree();
void addNode(Tree *t, TLink linkParent, TLink linkChild);
TLink createNode(int enumval,char value[25]);

//Tree tree_remove(Tree, TLink, void* value);
void printNodes(TLink t, FILE *fp);
void printTree(Tree *t, FILE*fp);

#endif


