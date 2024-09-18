#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node *next;
};

struct node *addnode(struct node *c, int s, int e);
struct node *poly_multiply(struct node *a, struct node *b);
void remove_duplicates(struct node *c);
void display_poly(struct node *c);

int main() {

    struct node *a = NULL, *b = NULL;

    
    a = addnode(a, 2, 3); // Example term: 2x^3
    a = addnode(a, 5, 2); // Example term: 5x^2
    
    b = addnode(b, 4, 1); 
    b = addnode(b, 1, 0); 
   

 
    struct node *result = poly_multiply(a, b);

  
    remove_duplicates(result);

   
    display_poly(result);

    
    return 0;
}

struct node *addnode(struct node *c, int s, int e) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->coef = s;
    new_node->exp = e;
    new_node->next = NULL;

    if (c == NULL) {
        c = new_node;
    } else {
        struct node *ptr3 = c;
        while (ptr3->next != NULL) {
            ptr3 = ptr3->next;
        }
        ptr3->next = new_node;
    }

    return c;
}

struct node *poly_multiply(struct node *a, struct node *b) {
    struct node *result = NULL;

    struct node *ptr1 = a;
    while (ptr1 != NULL) {
        struct node *ptr2 = b;
        while (ptr2 != NULL) {
            int m = ptr1->coef * ptr2->coef;
            int e = ptr1->exp + ptr2->exp;
            result = addnode(result, m, e);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return result;
}

void remove_duplicates(struct node *c) {
    struct node *ptr1 = c;
    while (ptr1 != NULL && ptr1->next != NULL) {
        struct node *ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->exp == ptr2->next->exp) {
                ptr1->coef += ptr2->next->coef;
                struct node *duplicate = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(duplicate);
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void display_poly(struct node *c) {
    while (c != NULL) {
        printf("%dx^%d", c->coef, c->exp);
        if (c->next != NULL) {
            printf(" + ");
        }
        c = c->next;
    }
    printf("\n");
}

