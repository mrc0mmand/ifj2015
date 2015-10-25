#ifndef __BST_H_INCLUDED
#define __BST_H_INCLUDED

#include "lex.h"

// TODO
typedef struct bst_data {
    lex_token_type_t type;
    union {
        char *s;
        int i;
        double d;
    } value;
} bst_data_t;

/**
  * @brief Structure for BST node
*/
typedef struct bst_node {
    struct bst_node *left;   /**< Pointer to left BST child */
    struct bst_node *right;  /**< Pointer to right BST child */
    bst_data_t data;         /**< Node data */
    char *key;               /**< Node key */
} bst_node_t;

/**
  * @brief Create new BST node with specified key
  * @details Given key is 'strduped' into node
  *          and later deallocated by bst_destroy
  *          function
  *
  * @param key Key for BST node
  * @return Allocated BST node
*/
bst_node_t *bst_new_node(char *key);

/**
  * @brief Recursively deallocates all nodes
  *        and their keys from given node
  *
  * @param node Node to deallocate
*/
void bst_destroy(bst_node_t *node);

/**
  * @brief Inserts node into BST with specicfied key
  *
  * @param node Pointer to BST
  * @param key Node key
*/
bst_node_t *bst_insert_node(bst_node_t *node, char *key);

/**
  * @brief Searches for node with given key in BST
  *
  * @param node Pointer to BST
  * @param key Search key
  * @return Pointer to node which matches key on success,
            NULL otherwise
*/
bst_node_t *bst_lookup_node(bst_node_t *node, char *key);

#endif
