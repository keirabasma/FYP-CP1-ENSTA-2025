#ifndef PATIENT_H
#define PATIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "details.h"

// Patinet details
typedef struct patient {
    int id;
    int doctor_id;
    int nurse_id;
        char full_name[50];
        int age;
        gender gen;
        char illness[200];
    appointment_date date;
    status status;
    priority priority;
    int room;
    int bed;
} patient;
// Patinet details ^

// Patient tree
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node *createnode(int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("no space left");
        return NULL;
    }
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node *insert(node *root, int value)
{
    if (root == NULL)
    {
        node *root = createnode(value);
    } else {
        if (root->data > value)
        {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

node *search(node *root, int value)
{
    if (root == NULL || root->data == value) {
        return root;
    } else { if (root->data > value) {
            return search(root->left, value);
        } else { if (root->data < value) {
            return search(root->right, value); }
        }
    }
}
// Patient tree ^

#endif