#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node* initNode(int x);
void addNode(node *root, node *new);
void displayPre(node *root);
int have(node *root, int x);
void addToTree(node **root, int x);
int numberOfNodes(node *root);
int height(node *root);
node* findParent(node* root, int x);
node* findNode(node* root, int x);
node* findLargestNode(node* root);
void deleteNode(node **root, int x);
void deleteRoot(node **root);
int isLeaf(node *leaf);

int main(){
	int x,y;
	node *root =  initNode(10);
	addToTree(&root, 13);
	displayPre(root);
	printf("\n");
	printf("number of nodes is: %d\n",numberOfNodes(root));	
	printf("height of the tree is: %d\n",height(root));	
	addToTree(&root, 8);
	addToTree(&root, 12);
	displayPre(root);
	printf("\n");
	printf("number of nodes is: %d\n",numberOfNodes(root));	
	printf("height of the tree is: %d\n",height(root));	
	addToTree(&root, 11);
	addToTree(&root, 14);
	addToTree(&root, 9);
	addToTree(&root, 7);
	displayPre(root);
	printf("\n");
	printf("number of nodes is: %d\n",numberOfNodes(root));	
	printf("height of the tree is: %d\n",height(root));
	x = 12;
	printf("parent of %d is: %d\n",x,findParent(root,x)->data);
	printf("node of %d is: %d\n",x,findNode(root,x)->data);	
	y = 13;
	node *n = findNode(root,y);
	printf("largest node parent from %d is: %d\n",y,findLargestNode(n)->data);
	x = 12;
	deleteNode(&root, x);
	displayPre(root);
	printf("\n");
	
	
	return 0;

}

node* initNode(int x){

	node *new = (node *)malloc(sizeof(node));
	new->data = x;
	new->right = NULL;
	new->left = NULL;
	return new;

}

void addNode(node *root, node *new){
	node *cur = root;
	
	if(cur->data > new->data){
		if(cur->left == NULL){
			cur->left = new;
			return;
		}
		addNode(cur->left, new);
	
	}
	else{
		if(cur->right == NULL){
			cur->right = new;
			return;
		}
		addNode(cur->right, new);	
	
	}
}

void addToTree(node **root, int x){
	node *new = initNode(x);
	if( (*root) == NULL){
		*root = new; 
		return;
	}
	addNode(*root, new);
	return;

}


void displayPre(node *root){
	if(root == NULL){
		return;	
	}
	
	printf("%d ",root->data);
	displayPre(root->left);
	displayPre(root->right);
	return;
}

int numberOfNodes(node *root){
	
	if(root == NULL)
		return 0;
	return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);



}

int height(node *root){
	int left, right;
	if(root == NULL)
		return 0;
	left = 1 + height(root->left);
	right = 1 + height(root->right);
	if(left > right)
		return left;
	else
		return right;

}


node* findParent(node* root, int x){
	node *parent = NULL;
	if(root == NULL)
		return NULL;
	if(root->right != NULL){
		if(root->right->data == x)
			return root;
	}
	if(root->left != NULL){
		if(root->left->data == x)
			return root;
	}
	
	parent = findParent(root->left, x);
	if(parent)
		return parent;
	parent = findParent(root->right, x);
	return parent;
}


node* findNode(node* root, int x){
	node *found = NULL;
	if(root == NULL)
		return NULL;
	if(root->data == x)
		return root;
	found = findNode(root->left, x);
	if(found)
		return found;
	found = findNode(root->right, x);
	return found;
}

node* findLargestNode(node* root){
	if(root == NULL)
		return NULL;
	if(root->right == NULL)
		return root;
	return findLargestNode(root->right);




}

void deleteNode(node **root, int x){
	node *cur = *root;
	node *rep, *parent, *lnode, *del;
	rep = initNode(0);
	if((*root) -> data == x ){
		deleteRoot(root);
		return;
	}
	parent = findParent(*root, x);
	del = findNode(*root, x);
	if(parent == NULL){
		printf("%d is not in the tree\n",x);
		return;
	}
	if(isLeaf(del)){
		free(del);
		if(parent->data > x)
			parent->left = NULL;
		else
			parent->right = NULL;
		return;
	}
	
	if(del->right == NULL){
		if(parent->data > x)
			parent ->left = del->left;
		else
			parent->right = del->left;
		free(del);
		return;
	
	}	
	else if(del->left == NULL){
		if(parent->data > x)
			parent ->left = del->left;
		else
			parent->right = del->left;
		free(del);
		return;
	
	}	

	else{
		lnode = findLargestNode(del->left);
		rep->data = lnode->data;
		rep->left = del->left;
		rep->right = del->right;
		lnode = NULL;
		if(parent->data > x){
			parent->left = rep;
		}
		else
			parent->right = rep;
		free(del);
		return;
	}

}

void deleteRoot(node **root){
	node *cur = *root, *rep,*lnode,*parent;
	if(cur->right && cur->right){
		lnode = findLargestNode(cur->left);
		rep->data = lnode->data;
		lnode = NULL;
		rep->left = cur->left;
		rep->right = cur->right;
		free(cur);
		*root = rep;
		return;
	}
	if(cur->right == NULL && cur->left == NULL){
		*root = NULL;
		return;
	
	}

	if(cur->right == NULL){
		rep = cur->left;
		*root = rep;
		return;
	}
	if(cur->left == NULL){
		cur = cur->right;
		return;
	}
		

}
int isLeaf(node *leaf){
	if(leaf->left == NULL && leaf->right == NULL)
		return 1;
	else
		return 0;

}





