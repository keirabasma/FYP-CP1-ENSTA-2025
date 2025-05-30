#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H

#include "doctor.h"

// typedef struct departments_node {
//     char department_name[50];
//     struct departments_node *next;
// } departments_node;
// typedef struct departments{
// } departments;
// // Department arrays
// extern char *pediatric_departments[];
// extern int pediatric_departments_count;
// extern char *clinical_depts[];
// extern int clinical_depts_count;
// extern char *diagnostic_depts[];
// extern int diagnostic_depts_count;
// extern char *admin_depts[];
// extern int admin_depts_count;
// // Linked list functions
// departments_node *create_dep_node(const char *name);
// departments_node *add_department(departments_node *dep_head, const char *name);
// departments_node *delete_department(departments_node *dep_head, const char *name);
// departments_node *search(departments_node *dep_head, const char *name);
// void display_departments(departments_node *dep_head);
// // // Initialization helpers
// // departments_node* create_department_list(const char* names[], int count);

// specific department doctors list
typedef struct doctor_department_list_node {
    doctor *dc;
    struct doctor_department_list_node* prev;
    struct doctor_department_list_node* next;
} doctor_department_list_node;

typedef struct department_tree_node {
    char name[100];
    doctor_department_list_node *doctor_department_list_head;
    struct department_tree_node *child;   // First child (sub-department)
    struct department_tree_node *sibling; // Next department in the same category
} department_tree_node;

department_tree_node* create_department_tree_node(const char* name);
void add_department_child(department_tree_node* parent, department_tree_node* child);
void add_department_sibling(department_tree_node* node, department_tree_node* sibling);
void display_department_tree(department_tree_node* root, int level);

extern department_tree_node* department_root;
extern department_tree_node* pediatric;
extern department_tree_node* clinical;
extern department_tree_node* geriatric;
extern department_tree_node* femiatric;
extern department_tree_node* diagnostic;
extern department_tree_node* admin;

int department_child_exists(department_tree_node* parent, const char* name);

void add_doctor_to_department(doctor_department_list_node **head, doctor *dc);
void remove_doctor_from_department(doctor_department_list_node **head, doctor *dc);
doctor_department_list_node* find_doctor_in_department(doctor_department_list_node *head, doctor *dc);
void display_department_doctors(doctor_department_list_node *head);

#endif