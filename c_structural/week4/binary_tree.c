#include <stdio.h>
#include <stdlib.h>

/***************************************************************
 Given some elements of na array, place them inside
 a binary tree and then print out the values in an inorder
 transverse method.
 **************************************************************/

typedef int DATA;
struct node{
	DATA d;
	struct node *left;
	struct node *right;
};

typedef struct node NODE;
typedef NODE *BTREE;

void inorder(BTREE node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->d);
    inorder(node->right);
}

BTREE new_node(void)
{ return malloc(sizeof(NODE)); }

BTREE init_node(DATA d1, BTREE p1, BTREE p2)
{
	BTREE btree;
	btree = new_node();
	btree -> d = d1;
	btree -> left = p1;
	btree -> right = p2;
	return btree;
}

BTREE create_tree(DATA a[], int i, int size)
{
	if (i >= size)
		return NULL;
	else
		return (init_node(a[i], create_tree(a, 2*i + 1, size), create_tree(a, 2*i + 2, size)));
}

int main(void)
 {  
	FILE* ifp = fopen ("input_file", "r");
    int pos;
    int size;
    BTREE btree;

    if(fscanf(ifp, "%d", &size))
        printf ("%s\n","printing binary tree (inorder)...." );
    int* data = (int*)malloc(sizeof(int) * size);
    pos = -1;
    while (++pos < size)
    {  
        if(fscanf (ifp, "%d", &data[pos]))
            continue;
    }
	btree = create_tree(data, 0, size);
	inorder(btree);
    fclose (ifp); 
	return 0;
}