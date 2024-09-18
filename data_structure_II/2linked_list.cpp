#include <iostream>
#include <cstdlib>

struct node {
    int n;
    struct node* next;
};

int main() {
    int i;

    struct node* h1, * h2, * t, * t1;

    h1 = NULL;
    h2 = NULL;

    // Creating the first linked list
    for (i = 0; i < 5; i++) {
        std::cout << "Enter 5 numbers in descending order: ";
        t = new node;
        std::cin >> t->n;
        t->next = NULL;

        if (h1 == NULL)
            h1 = t;
        else {
            t->next = h1;
            h1 = t;
        }
    }

    t = h1;
    std::cout << "First linked list: ";
    while (t != NULL) {
        std::cout << t->n << " ";
        t = t->next;
    }
    std::cout << std::endl;

    // Creating the second linked list
    for (i = 0; i < 8; i++) {
        std::cout << "Enter 8 numbers in descending order: ";
        t = new node;
        std::cin >> t->n;
        t->next = NULL;

        if (h2 == NULL)
            h2 = t;
        else {
            t->next = h2;
            h2 = t;
        }
    }

    t = h2;
    std::cout << "Second linked list: ";
    while (t != NULL) {
        std::cout << t->n << " ";
        t = t->next;
    }

  return 0;
}