#ifndef DCTR_PAT_ASSIGN_H
#define DCTR_PAT_ASSIGN_H
#include "patient/patient.h" 
#include "doctor/doctor.h"

patient_node *find_patient(patient_node *head, int id);
doctor_node *find_doctor(doctor_node *head, int id);
void assign_doctor_patient(patient_node *p_head, doctor_node *dr_head);

#endif