/*
 * Aim:     A C Program to perform addition on two polynomials using singly linked list.
 * Author:  Rohith
 * Date:    02-09-2017
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef, exp;
    struct node *next;
} Node;

Node* get_node()
{
    return (Node*) malloc(sizeof(Node));
}

Node* attach_node(int coef, int exp, Node* poly){
    Node *new_node, *temp = poly;

    new_node = get_node();
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;

    if( poly == NULL )
    {
        poly = new_node;
    }
    else
    {
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = new_node;
    }

    return poly;
}

Node* read_poly(int n){
    Node *exp = NULL;
    int i, c, e;

    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &c, &e);
        exp = attach_node(c, e, exp);
    }

    return exp;
}

Node* add_poly(Node *poly1, Node *poly2)
{
    Node *exp3 = NULL, *tpoly1, *tpoly2;

    tpoly1 = poly1;
    tpoly2 = poly2;

    while ( tpoly1 != NULL && tpoly2 != NULL )
    {
         if( tpoly1->exp == tpoly2->exp )
         {
             exp3 = attach_node(tpoly1->coef + tpoly2->coef, tpoly1->exp, exp3);
             tpoly1 = tpoly1->next;
             tpoly2 = tpoly2->next;
         }
         else if(tpoly1->exp > tpoly2->exp)
         {
             exp3 = attach_node(tpoly1->coef, tpoly1->exp, exp3);
             tpoly1 = tpoly1->next;
         }
         else
         {
             exp3 = attach_node(tpoly2->coef, tpoly2->exp, exp3);
             tpoly2 = tpoly2->next;
         }
    }

    return exp3;
}

void display(Node *e) {
    Node *temp = e;

    while(temp != NULL) {
        printf("%dx^%d  ", temp->coef, temp->exp);
        temp = temp->next;
    }

    printf("\n");
}

void main() {
    int n1, n2;
    Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

    printf("Enter the no. of terms in first expression: ");
    scanf("%d", &n1);

    printf("Enter the no. of terms in second expression: ");
    scanf("%d", &n2);

    printf("Enter the first expression terms:");
    poly1 = read_poly(n1);

    printf("First expression in memory: ");
    display(poly1);

    printf("Enter the second expression terms: ");
    poly2 = read_poly(n2);

    printf("Second expression in memory: ");
    display(poly2);

    poly3 = add_poly(poly1, poly2);

    printf("Resultant expression: ");
    display(poly3);
}

/*
Sample Run:
-----------
Enter the no. of terms in first expression:3
Enter the no. of terms in second expression:4
Enter the first expression terms:6 3 4 2 2 1
First expression in memory: 6x^3  4x^2  2x^1
Enter the second expression terms:5 4 4 3 2 2 1 1
Second expression in memory: 5x^4  4x^3  2x^2  1x^1
Resultant expression: 5x^4  10x^3  6x^2  3x^1
 */