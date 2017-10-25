#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lchild,*rchild;
};
typedef struct node bnode;

bnode *getnode(int ele) {
    bnode *temp = (bnode *) malloc(sizeof(bnode));
    if (temp) {
        temp->data = ele;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    else {
        printf("\n Unable to create the node");
        exit(0);
    }
}

void preorder(bnode *root) {
    if (root) {
        printf("%5d", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void inorder(bnode *root) {
    if (root) {
        inorder(root->lchild);
        printf("%5d", root->data);
        inorder(root->rchild);
    }
}

void postorder(bnode *root) {
    if (root) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%5d", root->data);
    }
}

int getHeight(bnode *root)
{
    int lh, rh;
    if(!root){
        return -1;
    } else {
        lh = getHeight(root->lchild);
        rh = getHeight(root->rchild);
        if( lh > rh )
            return lh + 1;
        else
            return rh + 1;
    }

}

void printLevel(bnode *root, int level) {
    if (root == NULL)
        return;

    if (level == 1) {
        printf("%5d", root->data);
    }
    else if (level > 1) {
        printLevel(root->lchild, level - 1);
        printLevel(root->rchild, level - 1);
    }
}

void levelorder(bnode* root) {
    int i, h = getHeight(root);

    for (i=1; i<=(h+1); i++)
        printLevel(root, i);

    printf("\n");
}

bnode *insert(bnode *root, int ele) {
    if (!root) {
        bnode *q = getnode(ele);
        root = q;
    }
    else if (ele > root->data) {
        root->rchild = insert(root->rchild, ele);
    }
    else if (ele < root->data) {
        root->lchild = insert(root->lchild, ele);
    }
    else {
        printf("\n Duplicate data ");
    }
    return root;
}


bnode* findMinNode(bnode *root) {
    bnode *temp = root;

    while (temp->lchild != NULL)
        temp = temp->lchild;

    return temp;
}

bnode* delete(bnode *root, int ele)
{
    if(!root){
        return root;
    }
    else if (ele > root->data) {
        root->rchild = delete(root->rchild, ele);
    }
    else if (ele < root->data) {
        root->lchild = delete(root->lchild, ele);
    }
    else {
        // Case 1: No children.
        if(root->lchild == NULL && root->rchild == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One child.
        else if(root->lchild == NULL){
            bnode *temp = root;
            root = root->rchild;
            free(temp);
        }
        else if(root->rchild == NULL){
            bnode *temp = root;
            root = root->lchild;
            free(temp);
        }
        // Case 3: Two children.
        else {
            bnode *temp = findMinNode(root->rchild);
            root->data = temp->data;
            root->rchild = delete(root->rchild, temp->data);
        }
    }

    return root;
}

bnode* copy(bnode* root) {
    if(!root) return NULL;

    bnode* temp = getnode(root->data);
    temp->lchild = copy(root->lchild);
    temp->rchild = copy(root->rchild);

    return temp;
}

void display(bnode *root, int l, int d, int rd, int gl)
{
    // TODO: implement proper horizontal links
    int i;

    if( l == 0 ) rd = 1;

    if( root->rchild != NULL )
    {
        if( l > 0 && rd == d ){
            gl = l;
        }
        display( root->rchild, l + 1, 1, rd, gl);
    }

    if(l > 0 && d != rd ){
        for(i = 0; i <= gl*4; i++) printf(" ");
        printf("|");
        for(i = 0; i < (l-gl)*4; i++) printf(" ");
    } else {
        for(i = 0; i <= l*4; i++) printf(" ");
    }

    if(d > 0) printf("/");
    if(d < 0) printf("\\");
    if(d == 0) printf("|");
    for(i = 0; i < 3; i++) printf("-");
    printf("%d\n", root->data);

    if( l == 0 ) rd = -1;

    if( root->lchild != NULL ) {
        if( l > 0 && rd == d ){
            gl = l;
        }
        display( root->lchild, l + 1, -1, rd, gl);
    }

}

int main()
{
    bnode *root = NULL, *temp;
    int f = 1, ele, choice;

    while (f)
    {
        printf("\nBinary Search Tree Operations:\n");
        printf("---------------------------------\n");
        printf(" 1. Insert\t");
        printf(" 2. Delete\n");
        printf(" 3. Inorder\t");
        printf(" 4. Preorder\n");
        printf(" 5. Postorder\t");
        printf(" 6. Levelorder\n");
        printf(" 7. Print Height");
        printf(" 8. Copy \n");
        printf(" 9. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n Enter an element :");
                scanf("%d",&ele);
                root = insert(root,ele);
                break;
            case 2:
                printf("\n Enter an element to remove :");
                scanf("%d",&ele);
                delete(root, ele);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                levelorder(root);
                break;
            case 7:
                printf("Tree Height: %d\n", getHeight(root));
                break;
            case 8:
                temp = copy(root);
                printf("Copied Tree.\n");
                printf("Preorder of copied tree: ");
                preorder(temp);
                break;
            case 9:
                f = 0;
                break;
            default : printf("\n Invalid choice.");
        }
    }

    return 0;
}