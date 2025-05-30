#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doctor.h"
#include "departments.h"

// // Department arrays
// char *pediatric_departments[] = {"General Pediatrics", "Neonatology / NICU", "Pediatric Growth & Nutrition", "Pediatric Vaccination"};
// int pediatric_departments_count = 4;
// char *clinical_depts[] = { "Cardiology", "Neurology", "Pediatrics", "Obstetrics & Gynecology", "Orthopedics" };
// int clinical_depts_count = 5;
// char *diagnostic_depts[] = { "Radiology", "Pathology", "Pharmacy" };
// int diagnostic_depts_count = 3;
// char *admin_depts[] = { "Hospital Administration", "Medical Records", "Security" };
// int admin_depts_count = 3;
// departments_node* pediatric_head = NULL;
// departments_node* clinical_head = NULL;
// departments_node* diagnostic_head = NULL;
// departments_node* admin_head = NULL;
// // Linked list functions
// departments_node *create_dep_node(const char *name) {
//     departments_node *new_node = (departments_node*)malloc(sizeof(departments_node));
//     if (!new_node) {
//         printf("there is no space\n");
//         return NULL;
//     }
//     strcpy(new_node->department_name, name);
//     new_node->next = NULL;
//     return new_node;
// }
// departments_node *add_department(departments_node *dep_head, const char *name) {
//     departments_node *new_node = create_dep_node(name);
//     if (!new_node) return dep_head;
//     new_node->next = dep_head;
//     return new_node;
// }
// departments_node *delete_department(departments_node *dep_head, const char *name) {
//     if (!dep_head) return dep_head;
//     departments_node *temp = dep_head;
//     departments_node *prev = NULL;
//     while (temp != NULL && strcmp(temp->department_name, name) != 0) {
//         prev = temp;
//         temp = temp->next;
//     }
//     if (temp == NULL) {
//         printf("Value %s not found in the list.\n", name);
//         return dep_head;
//     }
//     if (prev == NULL) {
//         dep_head = dep_head->next;
//     } else {
//         prev->next = temp->next;
//     }
//     free(temp);
//     return dep_head;
// }
// departments_node *search_department(departments_node *dep_head, const char *name) {
//     departments_node *current = dep_head;
//     while (current != NULL) {
//         if (strcmp(current->department_name, name) == 0) {
//             return current;
//         }
//         current = current->next;
//     }
//     return NULL;
// }
// void display_departments(departments_node *dep_head) {
//     departments_node *temp = dep_head;
//     int i = 0;
//     while (temp) {
//         printf("%d.> %s \n", i, temp->department_name);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }
// // // Helper to create a linked list from an array
// // departments_node* create_department_list(const char* names[], int count) {
// //     departments_node* head = NULL;
// //     for (int i = count - 1; i >= 0; --i) {
// //         head = add_department(head, names[i]);
// //     }
// //     return head;
// // }
// void save_department_list(const char* filename, departments_node* head) {
//     FILE* file = fopen(filename, "w");
//     if (!file) return;
//     departments_node* temp = head;
//     while (temp) {
//         fprintf(file, "%s\n", temp->department_name);
//         temp = temp->next;
//     }
//     fclose(file);
// }
// departments_node* load_department_list(const char* filename) {
//     FILE* file = fopen(filename, "r");
//     if (!file) return NULL;
//     departments_node* head = NULL;
//     char buffer[50];
//     while (fgets(buffer, sizeof(buffer), file)) {
//         buffer[strcspn(buffer, "\n")] = 0; // Remove newline
//         head = add_department(head, buffer);
//     }
//     fclose(file);
//     return head;
// }
// void load_all_department_lists() {
//     pediatric_head = load_department_list("pediatric_departments.txt");
//     clinical_head = load_department_list("clinical_depts.txt");
//     diagnostic_head = load_department_list("diagnostic_depts.txt");
//     admin_head = load_department_list("admin_depts.txt");
// }
// void save_all_department_lists() {
//     save_department_list("pediatric_departments.txt", pediatric_head);
//     save_department_list("clinical_depts.txt", clinical_head);
//     save_department_list("diagnostic_depts.txt", diagnostic_head);
//     save_department_list("admin_depts.txt", admin_head);
// }

department_tree_node* create_department_tree_node(const char* name) {
    department_tree_node* node = (department_tree_node*)malloc(sizeof(department_tree_node));
    if (!node) return NULL;
    strcpy(node->name, name);
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

department_tree_node* department_root = NULL;
department_tree_node* pediatric = NULL;
department_tree_node* clinical = NULL;
department_tree_node* geriatric = NULL;
department_tree_node* femiatric = NULL;
department_tree_node* diagnostic = NULL;
department_tree_node* admin = NULL;

void add_department_child(department_tree_node* parent, department_tree_node* child) {
    if (!parent || !child) {
        printf("Error: parent or child is NULL.\n");
        return;
    }
    if (!parent->child) {
        parent->child = child;
    } else {
        department_tree_node* temp = parent->child;
        while (temp->sibling) temp = temp->sibling;
        temp->sibling = child;
    }
}

void add_department_sibling(department_tree_node* node, department_tree_node* sibling) {
    while (node->sibling) node = node->sibling;
    node->sibling = sibling;
}

void print_line_with_indent(const char* content, int indent) {
    printf("|");
    for (int i = 0; i < indent * 2; ++i) printf(" ");
    printf("%s", content);
    int content_len = indent * 2 + (int)strlen(content);
    int remaining_spaces = 48 - content_len;
    for (int i = 0; i < remaining_spaces; ++i) printf(" ");
    printf("|\n");
}

void print_separator() {
    printf("+------------------------------------------------+\n");
}

void display_department_tree(department_tree_node* root, int level) {
    if (!root) return;

    char buffer[60];
    if (level == 1) {
        department_tree_node* child = root->child;
        int count = 1;
        while (child) {
            snprintf(buffer, sizeof(buffer), "%d. %s", count, child->name);
            print_line_with_indent(buffer, level);
            child = child->sibling;
            count++;
        }
        print_separator();
        return;
    }

    snprintf(buffer, sizeof(buffer), "- %s", root->name);
    print_line_with_indent(buffer, level - 1);

    display_department_tree(root->child, level + 1);
    display_department_tree(root->sibling, level);
}

department_tree_node* build_department_tree() {
    // Root node
    department_tree_node* department_root = create_department_tree_node("Departments");

    // Categories
    department_tree_node* pediatric = create_department_tree_node("Pediatric Departments");
    department_tree_node* clinical = create_department_tree_node("Clinical Departments");
    department_tree_node* geriatric = create_department_tree_node("Geriatric Departments");
    department_tree_node* femiatric = create_department_tree_node("Femiatric Departments");
    department_tree_node* diagnostic = create_department_tree_node("Diagnostic Departments");
    department_tree_node* admin = create_department_tree_node("Administrative Departments");

    // Add categories to root
    add_department_child(department_root, pediatric);
    add_department_child(department_root, clinical);
    add_department_child(department_root, geriatric);
    add_department_child(department_root, femiatric);
    add_department_child(department_root, diagnostic);
    add_department_child(department_root, admin);

    // Add departments to each category
    add_department_child(pediatric, create_department_tree_node("General Pediatrics"));
    add_department_child(pediatric, create_department_tree_node("Neonatology / NICU"));
    add_department_child(pediatric, create_department_tree_node("Pediatric Growth & Nutrition"));
    add_department_child(pediatric, create_department_tree_node("Pediatric Vaccination"));

    add_department_child(clinical, create_department_tree_node("Cardiology"));
    add_department_child(clinical, create_department_tree_node("Neurology"));
    add_department_child(clinical, create_department_tree_node("Obstetrics & Gynecology"));
    add_department_child(clinical, create_department_tree_node("Orthopedics"));

    add_department_child(geriatric, create_department_tree_node("Memory and Dementia Care"));
    add_department_child(geriatric, create_department_tree_node("Cardiovascular Health"));
    add_department_child(geriatric, create_department_tree_node("Physical Therapy and Rehabilitation"));
    add_department_child(geriatric, create_department_tree_node("Nutrition and Dietetics"));

    add_department_child(femiatric, create_department_tree_node("Obstetrics"));
    add_department_child(femiatric, create_department_tree_node("Female Oncology"));
    add_department_child(femiatric, create_department_tree_node("Prenatal Diagnostics & Ultrasound"));
    add_department_child(femiatric, create_department_tree_node("Maternal Nutrition & Lactation Support"));

    add_department_child(diagnostic, create_department_tree_node("Radiology"));
    add_department_child(diagnostic, create_department_tree_node("Pathology"));
    add_department_child(diagnostic, create_department_tree_node("Pharmacy"));

    add_department_child(admin, create_department_tree_node("Hospital Administration"));
    add_department_child(admin, create_department_tree_node("Medical Records"));
    add_department_child(admin, create_department_tree_node("Security"));

    return department_root;
}

void save_department_tree(FILE* file, department_tree_node* node, int level) {
    if (!node) return;
    for (int i = 0; i < level; ++i) fprintf(file, "\t");
    fprintf(file, "%s\n", node->name);
    save_department_tree(file, node->child, level + 1);
    save_department_tree(file, node->sibling, level);
}

void save_department_tree_to_file(const char* filename, department_tree_node* root) {
    FILE* file = fopen(filename, "w");
    if (!file) return;
    save_department_tree(file, root, 0);
    fclose(file);
}

department_tree_node* load_department_tree_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;
    department_tree_node** stack = NULL;
    int* stack_level = NULL;
    int stack_capacity = 0;
    int top = -1;
    int stack_level[100];
    int top = -1;
    char line[128];

    department_tree_node* root = NULL;

    while (fgets(line, sizeof(line), file)) {
        int level = 0;
        while (line[level] == '\t') level++;
        char* name = line + level;
        name[strcspn(name, "\r\n")] = 0; // Remove newline

        department_tree_node* node = create_department_tree_node(name);

        if (level == 0) {
            root = node;
        } else {
            add_department_child(stack[top], node);
        }

        while (top >= 0 && stack_level[top] >= level) top--;

        if (top + 1 >= stack_capacity) {
            stack_capacity = stack_capacity == 0 ? 10 : stack_capacity * 2;
            stack = realloc(stack, stack_capacity * sizeof(department_tree_node*));
            stack_level = realloc(stack_level, stack_capacity * sizeof(int));
            if (!stack || !stack_level) {
                printf("Memory allocation failed.\n");
                fclose(file);
                free(stack);
                free(stack_level);
                return NULL;
            }
        }

        top++;
        stack[top] = node;
        stack_level[top] = level;
        stack_level[top] = level;
    }

    free(stack);
    free(stack_level);
    return root;
    return root;
}

department_tree_node* find_department_by_name(department_tree_node* root, const char* name) {
    if (!root) return NULL;
    if (strcmp(root->name, name) == 0) return root;
    department_tree_node* found = find_department_by_name(root->child, name);
    if (found) return found;
    return find_department_by_name(root->sibling, name);
}

void update_department_globals(department_tree_node* root) {
    pediatric = find_department_by_name(root, "Pediatric Departments");
    clinical = find_department_by_name(root, "Clinical Departments");
    geriatric = find_department_by_name(root, "Geriatric Departments");
    femiatric = find_department_by_name(root, "Femiatric Departments");
    diagnostic = find_department_by_name(root, "Diagnostic Departments");
    admin = find_department_by_name(root, "Administrative Departments");
}

int department_child_exists(department_tree_node* parent, const char* name) {
    if (!parent) return 0;
    department_tree_node* child = parent->child;
    while (child) {
        if (strcmp(child->name, name) == 0) return 1;
        child = child->sibling;
    }
    return 0;
}

void add_doctor_to_department(doctor_department_list_node **head, doctor *dc) {
    doctor_department_list_node *new_node = malloc(sizeof(doctor_department_list_node));
    if (!new_node) return;
    new_node->dc = dc;
    new_node->prev = NULL;
    new_node->next = *head;
    if (*head) (*head)->prev = new_node;
    *head = new_node;
}

void remove_doctor_from_department(doctor_department_list_node **head, doctor *dc) {
    doctor_department_list_node *curr = *head;
    while (curr) {
        if (curr->dc == dc) {
            if (curr->prev) curr->prev->next = curr->next;
            else *head = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
            free(curr);
            return;
        }
        curr = curr->next;
    }
}

doctor_department_list_node* find_doctor_in_department(doctor_department_list_node *head, doctor *dc) {
    while (head) {
        if (head->dc == dc) return head;
        head = head->next;
    }
    return NULL;
}

void display_department_doctors(doctor_department_list_node *head) {
    int count = 1;
    while (head) {
        if (head->dc && head->dc->full_name) {
            printf("%d. %s (ID: %d)\n", count, head->dc->full_name, head->dc->id);
        } else {
            printf("%d. [Invalid doctor data]\n", count);
        }
        head = head->next;
        count++;
    }
}

