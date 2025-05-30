#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search_BST.h"
#include "patient/patient.h"

//Create a BST
tree_node *create(patient patient_data)
{
    tree_node *new_node = (tree_node*)malloc(sizeof(tree_node));
    if(new_node == NULL)
    {
        printf("Memory allocation failed! \n");
        exit(1);
    }
    new_node->data = patient_data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

//Insert in BST by ID
tree_node *insert(tree_node *root, patient patient_data)
{
    if(root == NULL)
    {
        return create(patient_data);
    }
    if(patient_data.id < root->data.id)
    {
        root->left = insert(root->left, patient_data);
    }
    else
    {
        root->right = insert(root->right, patient_data);
    }
    return root;
}

//Function to search for a patient by ID or name
tree_node *search(tree_node *root, int patient_id, char patient_name[])
{
    //Base case
    if(root == NULL)
        return NULL;
    //Check if current node match by ID or name
    if(root->data.id == patient_id || strcmp(root->data.name, patient_name) == 0)
    {
        return root;
    }
    //recursively left and right check
    if(patient_id < root->data.id)
    {
        return search(root->left, patient_id, patient_name);
    }
    else{
        return search(root->right, patient_id, patient_name);
    }
}

//Free the BST
void free_BST(tree_node *root)
{
    if(root == NULL)
        return;
    free_BST(root->left);
    free_BST(root->right);
    free(root);
}
