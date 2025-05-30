#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospital.h"

//Function to initialize a hospital
void init_hospital(hospital *Hospital, char *hospital_name)
{
    strcpy(Hospital->hospital_name, hospital_name);
    Hospital->departments = NULL;
    Hospital->depart_numb = 0;
}

//Function to add a department
void add_department(hospital *Hospital, char *depart_name)
{
    department *temp = realloc(Hospital->departments, sizeof(department) * (Hospital->depart_numb + 1));
    if(temp == NULL)
    {
        printf("Memory allocation failed! \n");
        return;
    }
    Hospital->departments = temp;

    department *new_depart = &Hospital->departments[Hospital->depart_numb];
    strcpy(new_depart->depart_name, depart_name);
    new_depart->services = NULL;
    new_depart->serv_numb = 0;
    Hospital->depart_numb++;
}

//Function to add a service
void add_service(hospital *Hospital, int depart_indx, char *serv_name)
{
    if(depart_indx < 0 || depart_indx >= Hospital->depart_numb)
    {
        printf("Wrong department index! \n");
        return;
    }
    department *Department = &Hospital->departments[depart_indx];
    service *temp = realloc(Department->services, sizeof(service) * (Department->serv_numb + 1));
    if(temp == NULL)
    {
        printf("Memory allocation failed! \n");
        return;
    }
    Department->services = temp;
    service *new_serv = &Department->services[Department->serv_numb];
    strcpy(new_serv->serv_name, serv_name);
    new_serv->staffs = NULL;
    new_serv->staff_numb = 0;
    Department->serv_numb++;
}

//Function to add a staff
void add_staff(service *Service, char *staff_name, char *pos)
{
    staff *temp = realloc(Service->staffs, sizeof(staff) *(Service->staff_numb + 1));
    if(temp == NULL)
    {
        printf("Memory allocation failed! \n");
        return;
    }
    Service->staffs = temp;
    staff *new_staff = &Service->staffs[Service->staff_numb];
    strcpy(new_staff->staff_name, staff_name);
    strcpy(new_staff->pos, pos);
    Service->staff_numb++;
}

//Function to show the hospital structure
void view_tree(hospital *Hospital, int lvl)
{
    printf("%*sHospital: %s \n", lvl * 2, "", Hospital->hospital_name);
    for(int i = 0; i < Hospital->depart_numb; i++)
    {
        printf("%*sDepartment: %s \n", (lvl+1) * 2, "", Hospital->departments[i].depart_name);

        for(int j = 0; j < Hospital->departments[i].serv_numb; j++)
        {
            printf("%*sService: %s \n", (lvl+2) * 2, "", Hospital->departments[i].services[j].serv_name);

            for(int k = 0; k < Hospital->departments[i].services[j].staff_numb; k++)
            {
                printf("%*sStaff: %s , Position: %s \n", (lvl+3) * 2, "", Hospital->departments[i].services[j].staffs[k].staff_name, Hospital->departments[i].services[j].staffs[k].pos);
            }
        }
    }
}

//Function to free the hospital
void free_hospital(hospital *Hospital)
{
    for(int i = 0; i < Hospital->depart_numb; i++)
    {
        for(int j = 0; j < Hospital->departments[i].serv_numb; j++)
        {
            free(Hospital->departments[i].services[j].staffs);
        }
        free(Hospital->departments[i].services);
    }
    free(Hospital->departments);
    Hospital->departments = NULL;
    Hospital->depart_numb = 0;
}