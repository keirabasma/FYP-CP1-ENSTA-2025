#ifndef SEARCH_BST_H
#define SEARCH_BST_H
#include "patient/patient.h"
//Declare a BST
typedef struct tree_node
{
    patient data;
    struct tree_node *right;
    struct tree_node *left;
}tree_node;

tree_node *create(patient patient_data);
tree_node *insert(tree_node *root, patient patient_data);
tree_node *search(tree_node *root, int patient_id, char patient_name[]);
void free_BST(tree_node *root);

#endif