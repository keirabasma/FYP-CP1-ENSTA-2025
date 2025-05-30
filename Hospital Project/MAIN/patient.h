#ifndef PATIENT_H
#define PATIENT_H

typedef struct patient {

        int id;
        char full_name[50];
        int age;
        gender gen;
        char department[50];
        char illness[200];

    status status;
    priority priority;
    int room;
    int bed;
    int doctor_id;
    int nurse_id;
    bool date[7][24];

} patient;

typedef struct p_node
{
    patient *p;
    // doctor *p_dc;
    // nurse *p_nu;
    struct p_node *next;
    struct p_node *prev;
} patient_node;

#endif