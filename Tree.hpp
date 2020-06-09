#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Tree {

public:
    struct node {
        int id;
        int weight;
        node* r;
        node* l;
    };
    node* tree;
    Tree();
    void show(node* subtree, int n);
    void add(int a, node** subtree);
    node* pop(int a, node* subtree);
    int anw(node* subtree);
};

Tree::Tree() {
    Tree::tree = NULL;
    srand(time(NULL));
};

void Tree::show(node* subtree, int n) {
    if (subtree != NULL) {
        show(subtree->r, n + 1);
        cout << setw(n * 4) << subtree->id << "(" << subtree->weight << ")" << endl;
        show(subtree->l, n + 1);
    }
}

void Tree::add(int a, node** subtree) {
    if ((*subtree) == NULL) {
        (*subtree) = new node;
        (*subtree)->l = NULL;
        (*subtree)->r = NULL;
        (*subtree)->id = a;
        (*subtree)->weight = rand() % 3 - 1;
    }
    else {
        if (a < (*subtree)->id) {
            Tree::add(a, &((*subtree)->l));
        }
        else {
            Tree::add(a, &((*subtree)->r));
        }
    }
}

Tree::node* Tree::pop(int a, node* subtree)
{
    if (subtree == NULL)
        return subtree;

    if (a == subtree->id) {
        if (subtree->l == NULL && subtree->r == NULL) {
            delete subtree;
            return NULL;
        }
        node* temp;

        if (subtree->r == NULL) {
            temp = subtree->l;
            delete subtree;
            return temp;
        }

        else if (subtree->l == NULL) {
            temp = subtree->r;
            delete subtree;
            return temp;
        }

        else {
            node* r_subtree = subtree->r;

            while (r_subtree != NULL && r_subtree->l != NULL) {
                r_subtree = r_subtree->l;
            }

            subtree->weight = r_subtree->weight;
            subtree->id = r_subtree->id;
            subtree->r = pop(r_subtree->id, subtree->r);
        }
        return subtree;
    }
    else if (a < subtree->id)
        subtree->l = pop(a, subtree->l);
    else
        subtree->r = pop(a, subtree->r);
    return subtree;
}

int Tree::anw(node* subtree) {
    if (subtree == NULL)
        return 0;
    int Temp = anw(subtree->l) + anw(subtree->r);
    if (subtree->weight == -1) Temp += subtree->id;
    return Temp;
}