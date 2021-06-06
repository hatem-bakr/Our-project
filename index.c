#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"


struct sub{
 char name[15];
 int mark;
 };

 typedef struct infostudent{
 char name [50];
 char currentyear[15];
 int section;
 int code;
 long long int national_id;
 char email[30];
 char Birthday[30];
 struct sub *subjects[4];
 }stud;


 typedef struct list_infostudent{

    char name [50];
    long long int national_id;
    char currentyear[15];
    int section;
    int code;
    char email[30];
    char Birthday[30];
    struct sub *subjects[4];

    struct list_infostudent *nextPtr;

 }stud1;

 typedef stud1 *infostptr;

    stud1 *head = NULL;
    stud1 *curr = NULL;





void insert ();
int isEmpty(infostptr  sPtr);
void printList();
void display_all(infostptr currentPtr);





int main()
{


    printf("enter choice ( 1 ->insert , 2->display , 3->stop ) : ");
    unsigned int choice;
    scanf("%u", &choice);

    while (choice != 3) {


     switch (choice) {
     case 1:
     insert();
     printList(head);
     break;

     case 2:
        display_all(head);
        break;

     default :
        printf("invalid input");
        break;
     }
        printf("enter choice ( 1->insert , 2->display , 3->stop ) : ");
        scanf("%u", &choice);
     }



    FILE *fptrW;

   fptrW = fopen("data.txt","wb");

    infostptr tempW = head;
    while(tempW != NULL){

        fwrite(&tempW->name,sizeof(tempW->name),1,fptrW);
        fwrite(&tempW->code,sizeof(tempW->code),1,fptrW);
        fwrite(&tempW->national_id,sizeof(tempW->national_id),1,fptrW);
        fwrite(&tempW->Birthday,sizeof(tempW->Birthday),1,fptrW);
        fwrite(&tempW->email,sizeof(tempW->email),1,fptrW);
        fwrite(&tempW->currentyear,sizeof(tempW->currentyear),1,fptrW);
        fwrite(&tempW->section,sizeof(tempW->section),1,fptrW);

        fwrite(&tempW->subjects[0]->name,sizeof(tempW->subjects[0]->name),1,fptrW);
        fwrite(&tempW->subjects[0]->mark,sizeof(tempW->subjects[0]->mark),1,fptrW);
        fwrite(&tempW->subjects[1]->name,sizeof(tempW->subjects[1]->name),1,fptrW);
        fwrite(&tempW->subjects[1]->mark,sizeof(tempW->subjects[1]->mark),1,fptrW);
        fwrite(&tempW->subjects[2]->name,sizeof(tempW->subjects[2]->name),1,fptrW);
        fwrite(&tempW->subjects[2]->mark,sizeof(tempW->subjects[2]->mark),1,fptrW);
        fwrite(&tempW->subjects[3]->name,sizeof(tempW->subjects[3]->name),1,fptrW);
        fwrite(&tempW->subjects[3]->mark,sizeof(tempW->subjects[3]->mark),1,fptrW);

        tempW=tempW->nextPtr;
    }

    fclose(fptrW);


    return 0;
}

//-----------------
int isEmpty(infostptr sPtr)
 {
    return sPtr == NULL;
 }


//-----------
void printList(stud1 *currentPtr)
 {

 puts("The list is:");

 // while not the end of the list
 while (currentPtr != NULL) {
 printf("%s --> ", currentPtr->name);
 currentPtr = currentPtr->nextPtr;
 }

 puts("NULL\n");
 }



 //--------------------
 void insert()
 {

    infostptr newPtr = malloc(sizeof(stud1));

    newPtr->subjects[0] =  malloc(sizeof(struct sub));
    newPtr->subjects[1] =  malloc(sizeof(struct sub));
    newPtr->subjects[2] =  malloc(sizeof(struct sub));
    newPtr->subjects[3] =  malloc(sizeof(struct sub));


    if (newPtr != NULL) {

    FILE *pfile1 ;
    pfile1= fopen("data.txt","rb");
    if(pfile1==NULL)
    {
        printf("couldn't find the file\n");
        exit(1);
    }

//adding all data for a new student

    printf("Enter the student's name : ");
    fflush(stdin);
    gets(newPtr->name);
    printf("Enter the student's code : ");
    fflush(stdin);
    scanf("%d",&newPtr->code);

    printf("Enter the student's ID :");
    fflush(stdin);
    scanf("%lli",&newPtr->national_id);
    printf("Enter the student's date of birth :");
    fflush(stdin);
    gets(newPtr->Birthday);

    printf("Enter the student's E-mail :");
    fflush(stdin);
    gets(newPtr->email);

    printf("Enter the student's current year :");
    fflush(stdin);
    gets(newPtr->currentyear);
    printf("Enter the student's section :");
    fflush(stdin);
    scanf("%d",&newPtr->section);

    printf("Enter [name] of the subject No.1 :");
    fflush(stdin);
    gets(newPtr->subjects[0]->name);
    printf("Enter [degree] of the subject No.1 :");
    fflush(stdin);
    scanf("%d",&newPtr->subjects[0]->mark);

    printf("Enter [name] of the subject No.2 :");
    fflush(stdin);
    gets(newPtr->subjects[1]->name);
    printf("Enter [degree] of the subject No.2 :");
    fflush(stdin);
    scanf("%d",&newPtr->subjects[1]->mark);

    printf("Enter [name] of the subject No.3 :");
    fflush(stdin);
    gets(newPtr->subjects[2]->name);
    printf("Enter [degree] of the subject No.3 :");
    fflush(stdin);
    scanf("%d",&newPtr->subjects[2]->mark);

    printf("Enter [name] of the subject No.4 :");
    fflush(stdin);
    gets(newPtr->subjects[3]->name);
    printf("Enter [degree] of the subject No.4 :");
    fflush(stdin);
    scanf("%d",&newPtr->subjects[3]->mark);

    newPtr->nextPtr = NULL;




//read all data from the file
if(head == NULL){

    stud1 *cur = malloc(sizeof(stud1));

    while( 1 ){

        stud1 *temp = malloc(sizeof(stud1));
        if( fread(&temp->name,sizeof(temp->name),1,pfile1)  == 0 ) {  break;}

        temp->subjects[3] =  malloc(sizeof(struct sub));
        temp->subjects[0] =  malloc(sizeof(struct sub));
        temp->subjects[1] =  malloc(sizeof(struct sub));
        temp->subjects[2] =  malloc(sizeof(struct sub));

        fread(&temp->code,sizeof(temp->code),1,pfile1);
        fread(&temp->national_id,sizeof(temp->national_id),1,pfile1);
        fread(&temp->Birthday,sizeof(temp->Birthday),1,pfile1);
        fread(&temp->email,sizeof(temp->email),1,pfile1);
        fread(&temp->currentyear,sizeof(temp->currentyear),1,pfile1);
        fread(&temp->section,sizeof(temp->section),1,pfile1);

        fread(&temp->subjects[0]->name,sizeof(temp->subjects[0]->name),1,pfile1);
        fread(&temp->subjects[0]->mark,sizeof(temp->subjects[0]->mark),1,pfile1);
        fread(&temp->subjects[1]->name,sizeof(temp->subjects[1]->name),1,pfile1);
        fread(&temp->subjects[1]->mark,sizeof(temp->subjects[1]->mark),1,pfile1);
        fread(&temp->subjects[2]->name,sizeof(temp->subjects[2]->name),1,pfile1);
        fread(&temp->subjects[2]->mark,sizeof(temp->subjects[2]->mark),1,pfile1);
        fread(&temp->subjects[3]->name,sizeof(temp->subjects[3]->name),1,pfile1);
        fread(&temp->subjects[3]->mark,sizeof(temp->subjects[3]->mark),1,pfile1);

        if(head == NULL){head = temp; cur=temp;}

        cur->nextPtr=temp;
        cur=cur->nextPtr;

        }
    cur->nextPtr = NULL ;
    fclose(pfile1);

    }

    stud1 *previousPtr = NULL;
    stud1 *currentPtr = head;


    int record ,fname ,lname,space1 ,space2;
    bool bigger ,lower;


    for(record=0; currentPtr != NULL ;record++){
            bigger=false ,lower=false;
        for(fname=0; fname<3; fname++){
            if(newPtr->name[fname] < currentPtr->name[fname]){
                    lower=true; break;  }
            else if(newPtr->name[fname] == currentPtr->name[fname]) {continue;}
            else{ bigger=true ; break;}
        }

                if(lower){ break;}
                if(bigger){
                previousPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
                    continue;}

        for(space1=1; newPtr->name[space1]!=' ' ; space1++){}
        for(space2=1; currentPtr->name[space2]!=' ' ; space2++){}

        for(lname=0; lname<3; lname++, space1++,space2++){
            if(newPtr->name[space1] < currentPtr->name[space2]){ lower=true; break;}
            else if(newPtr->name[space1] == currentPtr->name[space2]) {continue;}
            else{  break;}
        }
                if(lower){break;}

                previousPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
    }

 if (previousPtr == NULL) {
 newPtr->nextPtr = head;
 head = newPtr;
 }
 else {
 previousPtr->nextPtr = newPtr;
 newPtr->nextPtr = currentPtr;
 }
 }
 else {
 printf(" No memory available.\n" );
 }
 }



 void display_all(stud1 *currentPtr){

 puts("The list is:");


 while (currentPtr != NULL) {
    printf("\n name : %s \n", currentPtr->name);
    printf(" code : %d  \n", currentPtr->code);
    printf(" ID : %lli \n", currentPtr->national_id);
    printf(" birth_day : %s \n", currentPtr->Birthday);
    printf(" E-mail : %s  \n", currentPtr->email);
    printf(" current_year : %s  \n", currentPtr->currentyear);
    printf(" section : %d  \n", currentPtr->section);

    printf(" name 1 : %s \n", currentPtr->subjects[0]->name);
    printf(" mark 1 : %d \n", currentPtr->subjects[0]->mark);
    printf(" name 2 : %s \n", currentPtr->subjects[1]->name);
    printf(" mark 2 : %d \n", currentPtr->subjects[1]->mark);
    printf(" name 3 : %s \n", currentPtr->subjects[2]->name);
    printf(" mark 3 : %d \n", currentPtr->subjects[2]->mark);
    printf(" name 4 : %s \n", currentPtr->subjects[3]->name);
    printf(" mark 4 : %d \n", currentPtr->subjects[3]->mark);


    puts("-----------");

    currentPtr = currentPtr->nextPtr;
 }


 }



