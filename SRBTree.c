/* Alex Phillips and Nicholas Deleuze
   March 10th, 2017
   COP 4520 Spring 2017
   Description: Main file for 
   Sequential Red-Black Tree implementation
*/
//*********************************************************//

#include "SRBTree.h"

int main(void)
{
	srand(time(NULL));
	int r = rand() % 100, i;
	Node* RBTree = createNode(r);
	for(i = 0; i < 20; i++)
	{
		r = rand() % 100;
		InsertTree(r, RBTree);
	}
	
	printTree(RBTree);
}

// Super function that make the new node 
// Pushes the node to insert function    
Node* InsertTree(int data, Node* root)
{
	Node* newNode;
    newNode = createNode(data);
	//setColor(newNode, red);
	
	// Node is already in tree
	if(Insert(newNode, root) == NULL) 
	{
		deleteNode(newNode);
		return NULL;
	}
	
	// Rebalance tree and colors
	root = balanceTree(root);
	
	return root;
}

// Inserts the new node into the tree
Node* Insert(Node* newNode, Node* root)
{
	//We found a place for this newNode
	if(root == NULL)
	{
		root = newNode;
		return newNode;
	}
	
	// MIGHT HAVE TO PLACE SAME NODES TO THE RIGHT IN THE TREE //

	// if it is already in the tree return null
	if((root->data) == (newNode->data)) return NULL;
	//else go right
	else if(root->data > newNode->data) return Insert(newNode, root->left);
	//else go left
	else return Insert(newNode, root->right);
	
}

// Remove the data from the tree
Node* Remove(int data, Node* root)
{
	return NULL;
}

// Find data in the tree
Node* Search(int data, Node* root) 
{
	// return null if data isnt in the tree
	if(root == NULL) return NULL;
	
	// traverse the tree until you do or don't find data
	if(root->data == data) return root;
	else if(root->data > data) Search(data, root->left);
	else return Search(data, root->right);

	return NULL;
}

Node* balanceTree(Node* root)
{
	return root;
}

//Debugging tool for whole printing tree (INORDER)
void printTree(Node* root)
{
	if(root == NULL)
		return;

	printTree(root->left);
	printf("%d\n", root->data);
	printTree(root->right);
}

//*********************************************************//
