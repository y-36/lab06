#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool izq_ord(abb_elem e, abb tree){ 
    bool izq = true;
    if(tree != NULL){
        izq = elem_less(tree->elem, e) && izq_ord(e, tree->left) 
        && izq_ord(e, tree->right);
    }
    return izq;
}

static bool der_ord(abb_elem e, abb tree){ 
    bool der = true;
    if(tree != NULL){
        der = elem_less(e, tree->elem) && der_ord(e, tree->left) 
        && der_ord(e, tree->right); 
    }
return der;
}

static bool invrep(abb tree) {
    /* ¬(Need implementation) */
    bool res = true;
    if(tree != NULL){
        res = izq_ord(tree->elem, tree->left) && der_ord(tree->elem, tree->right)
        && invrep(tree->left) && invrep(tree->right);
    }

    return res;
}

abb abb_empty(void) {
    abb tree= NULL;
    /* ¬(Need implementation) */
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    /* ¬(Need implementation) */
    return is_empty = (tree == NULL);
}

bool abb_exists(abb tree, abb_elem e) {
bool exists=false;
    /* ¬(Need implementation) */
    assert(invrep(tree));
    if (tree == NULL)
    {
        return false;
    }else if (elem_less(e, tree->elem))
    {
        exists = abb_exists(tree->left, e);
    }else if (elem_less(tree->elem, e))
    {
        exists = abb_exists(tree->right, e);
    }else if (elem_eq(e, tree->elem))
    {
        return true;
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    /* ¬(Need implementation) */
    if (tree != NULL)
    {
        length = 1+ abb_length(tree->left);
        length += abb_length(tree->right);
    }
    
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
     /* ¬(Need implementation) */
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    /* ¬(Need implementation) */
    abb pointer = tree;
    while (pointer->right != NULL)
    {
        pointer = pointer->right;
    }
    max_e = pointer->elem;
    
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
     /* ¬(Need implementation) */

    abb pointer = tree;
    while (pointer->left != NULL)
    {
        pointer = pointer->left;
    }
    min_e = pointer->elem;

    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree, abb_ordtype ord) {
    assert(invrep(tree) && (ord==ABB_IN_ORDER  || 
                            ord==ABB_PRE_ORDER ||
                            ord==ABB_POST_ORDER));
    /*
     * c) Needs implementation: use the dump order indicated by `ord`
     *
     */

    // Implementing in-order as default
    if (tree != NULL) {
        abb_dump(tree->left, ord);
        printf("%d ", tree->elem);
        abb_dump(tree->right, ord);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    /* ¬(Need implementation) */
    if (tree == NULL) {
        return NULL;
    }
    tree->left=abb_destroy(tree->left);
    tree->right= abb_destroy(tree->right);
    free(tree);
    tree=NULL;
    assert(tree == NULL);
    return tree;
}

