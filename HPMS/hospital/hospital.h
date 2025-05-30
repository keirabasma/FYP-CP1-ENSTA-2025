#ifndef HOSPITAL_H
#define HOSPITAL_H

//Structure for a staff
typedef struct staff
{
    char staff_name[50];
    char pos[50];
}staff;

//Structure for a service
typedef struct service
{
    char serv_name[50];
    staff *staffs; //pointer to array of staffs
    int staff_numb;
}service;

//Structure for a department 
typedef struct department
{
    char depart_name[50];
    service *services; //pointer to array of services
    int serv_numb;
}department;

//Structure for the hospital
typedef struct hospital
{
    char hospital_name[50];
    department *departments; //pointer to array of department
    int depart_numb;
}hospital;

// Function prototypes
void init_hospital(hospital *Hospital, char *hospital_name);
void add_department(hospital *Hospital, char *depart_name);
void add_service(hospital *Hospital, int depart_indx, char *serv_name);
void add_staff(service *Service, char *staff_name, char *pos);
void view_tree(hospital *Hospital, int lvl);
void free_hospital(hospital *Hospital);

#endif