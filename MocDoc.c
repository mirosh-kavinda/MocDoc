#include <stdio.h>
#include <stdlib.h>
#define MAX 15

//this structure for store patient information
struct patientInfo
{
    char name[100];
    int age;
    int id; 
    char phoneNo[12];
};

//Create struct Array 
struct patientInfo patientStruct[MAX];
int priorityVal ,priorityNormal=15;

void addPatient(int);
void deleteAppoinment(int);
void create();
void checkPriority(int,int);
void displayPatientList();
int checkIfCritical(int,int);

//Assign new arrays and variables to arrange patient acording to priority
int patientIdQueue[MAX],priority[MAX];
int front, rear;
int p=-1;


//main method
void main()
{
    int ch,n;
 
    do
    {   
        printf("\n\nMOC DOC Patient Management system\n..............................................");
        printf("\n1.Make an Appoinment \t   (Press 1)");
        printf("\n2.Cancel Appointment\t   (Press 2) ");
        printf("\n3.Display the patient list (Press 3) ");
        printf("\n4.Exit from the system\t   (Press 4) ");
        printf("\n..............................................\nOnly have fifteen appoinment for the day\n ");
        printf("\nENTER Your Choice NO : ");
        scanf("%d", &ch);
        
        switch (ch)
        {
        case 1:
            printf("\nIs this Patient a Critical Patient ?\n.............................................");
            printf("\n1.Critical Patient\t(Press 1)");
            printf("\n2.Normal Patient\t(Press 2)\n");
            printf("\nENTER Your Choice NO : ");
            scanf("%d", &n);
            addPatient(n);
            break;
        case 2:
            displayPatientList();
            printf("\nEnter Patient No in Patients Detaile table to delete the Appoinment  : ");
            scanf("%d", &n);
            deleteAppoinment(n);
            break;
        case 3:
            printf("\n---------------------------------\n");
            printf ("Patients Detaile table \n");   
            displayPatientList();
            break;
        case 4:
            exit(0);
        default:
            printf("\n! Choice is incorrect, Enter a correct choice");
        }
    } while (1);
}


//Add patient to the system
void addPatient(int critical)
{
    int i;
    char ch2;
    p++;
    if (rear >= MAX - 1)
        printf("\nAll the channelings are Booked! \n");
    else
    {
        printf("\nEnter patient name : ");
        scanf("%s", patientStruct[p].name);

        printf("\nEnter patient age : ");
        scanf("%d", &patientStruct[p].age);

        printf("\nEnter patient phone No (Ex:  077-xxxxxxx): ");
        scanf("%s", &patientStruct[p].phoneNo);

        printf("\n Appoinment has successfully completed..!");
        checkIfCritical(critical,p);   
    
        if ((front == -1) && (rear == -1))
        {
            front++;
            rear++;
            patientIdQueue[rear] =patientStruct[rear].id = p;
            priority[rear] =priorityVal;
            return;
        }
        else
            checkPriority(priorityVal,patientIdQueue[rear]);
        rear++;
        patientIdQueue[rear] =patientStruct[rear].id = rear;
    }

};

//function Check whether the patient critical or not
int checkIfCritical(int i,int j)
{
    if (i==1)
        {
            priorityVal=priorityNormal+5-j;
            return priorityVal;
        }
    else if(i==2)
        {
             priorityVal=priorityNormal-j;
             return priorityVal;
        }
    else
        {
            printf("Enter Valid input ,Thank you!");
        }   
}


//Compare priority values of each person
void checkPriority(int prt,int prtId)

{
    int i, j;
    for (i = 0; i <= rear; i++)
    {

        if (prt >= priority[i])
        {
            for (j = rear + 1; j > i; j--)

            {

                priority[j] = priority[j - 1];
                patientIdQueue[j]=patientIdQueue[j-1] ;
            }

            priority[i] = prt;
            patientIdQueue[i]=prtId;

            return;
        }
    }

    priority[i] = prt;
    patientIdQueue[i]=prtId;
}


//Displays the whole patient details

void displayPatientList(int prt)
{
    int j=0;
    if((front == -1) && (rear == -1))
    {
        printf("\n---------------------------------\nNO any patient to display\n");
        return;
    }
    
     
    for(front=0 ; front < rear; front++)
    {
         j=patientIdQueue[front];
        printf("\n%d Patient Name --> \t%s ", front+1,patientStruct[j].name);
        printf("\n  Reservation No--> \t%d ",patientStruct[j].id+1);
        printf("\n  Patient Age--> \t%d ",patientStruct[j].age);
        printf("\n  Patient phone no--> \t%s ",patientStruct[j].phoneNo);
        printf("\n  Priority given by system: %d",priority[front]);
        printf("\n---------------------------------");
    } 
      

};


//this patient delete the Appoinment from system

void deleteAppoinment(int pid)
{
    int i=0;
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }

    for (i = 0; i <= rear; i++)

    {
        if (pid ==patientIdQueue[i])
        {
            for (; i < rear; i++)

            {
               patientIdQueue[i]=patientIdQueue[i+1];
            }

       
            patientIdQueue[i]=-99;
            rear--;

            if (rear == -1)

                front = -1;

            return;
        }
        
    }
    printf("\n.......Reservation canceled successfully!......");
}
