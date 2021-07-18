#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>

#define BR_FILE "brdata.txt"
#define EMP_FILE "empdata.txt"
#define TMP_FILE "tmpdata.txt"
#define BANK_FILE "bank.txt"
#define MNG_FILE "mng.txt"
#define MERGE_FILE "mrg.txt"

#define EPF_RATE 0.18
#define ETF_RATE 0.03
#define GEN_TIME (8*20)

#define ENTER 13
#define TAB 9
#define BKSP 8

#define USER khushbu pwd 12345


//All methods declaration//
void main_menu();
void pwd();
//Employee and branch methods

void emp_branch();//first call
void em_br_menu();//second call

void emp_List();
void branch_list();
void add_branch();
void add_employee();
void update_employee();
void del_employee();
void search_employee();

//Setup methods
void set_up();//first call
void set_up_menu();//second call

void add_bk_details();
void salary_setup();

//Payroll methods
void pay_manage();//first call
void pay_manage_menu();//second call

void manage_payroll();
void manage_attendance();
void search_em_report();



//Report method
void report();

//All structure for method call

struct branch{
 char name[15];
 char code[15];
 int id;
 char address[40];
};

struct employee{
// employee data
 char name[25];
 int id;
 char email[40];
 char mobile[20];
 char address[50];
 char designation[30];
 char join[20];
 char dob[20];
 char branch[20];

 //Payroll
int emp_id;
char emp_name[20];
int total_working_days;
int presend_day;
int absent;
int  leave;
float salary;
int total_days;
};


struct bank{
char name[20];
int emp_id;
char branch[20];
char email[40];
char bank_name[20];
char  acc_no[30];
char ifsc_code[30];

};


int  main()
{
      system("color b0");
      pwd();
      char option;
      int isExit=0;
      fflush(stdin);
      system("cls");
      sleep(1);
      printf("\n");
      printf("\t\t\t***************************** WELCOME TO THE ***********************************\n");
      sleep(1);
      printf("\n\t\t\t\t\t\t******************************\n");
      printf("\t\t\t\t\t\t* PAYROLL--MANAGEMENT--SYSTEM *\n");
      printf("\t\t\t\t\t\t******************************\n");
      do
      {
        main_menu();
       fflush(stdin);
       scanf("%c",&option);
        switch(option)
        {
        case'1':
            {
            system("cls");
            emp_branch();
            break;
            }
        case'2':
            {
            system("cls");
            set_up();
            break;
            }
        case'3':
           {
            system("cls");
            pay_manage();
            break;
           }
        case'4':
            {
            system("cls");
            report();
            break;
            }
        case'5':
            {
            system("cls");
            isExit=1;
            break;
           }
        default:
            {
                printf("Invalid option\n\n");
                fflush(stdin);
                getchar();
                break;
            }
        }
    }while(isExit==0);
    sleep(1);
    printf("\n\n\t\t\t**THANKS YOU**\n");
    printf("  ___________________________________________________________________");
    sleep(1);
    printf("\n\n  SUBMITED TO");
    printf("\n\n  RAM LOVEWANSHI SIR \n (TPN DEPARMENT) ");
    sleep(1);
    printf("\n\n\t\t\t\t\t\t SUBMITED BY");
    printf("\n\n\t\t\t\t\t\t KHUSHBU SURYAWANSHI\n");
    printf("  ____________________________________________________________________");
    fflush(stdin);
    getch();
    return 0;
}



void main_menu(){
    //system("cls");
 printf("\n\t--MAIN-MENU--\n\n");
printf("\t1. MANAGE EMPLOYEE AND BRANCH \n\n");
printf("\t2. MANAGE BANK SETUP\n \n");
printf("\t3. MANAGE PAYROLL\n\n");
printf("\t4. MANAGE REPORT\n\n");
printf("\t5. LOG OUT\n\n");
printf("  SELECT OPTION-->>>");
}

void em_br_menu(){
    printf("\n");
    printf("\t~~MANAGE BRANCH AND EMPLOYEE~~\n\n");
    printf("\t\t----EMPLOYEE----\n");
    printf("\t1:  EMPLOYEE LIST\n");
   // printf("\t3:  ADD BRANCH\n");
    printf("\t2:  ADD EMPLOYEE\n");
    printf("\t3:  DELETE EMPLOYEE\n");
    printf("\t4:  UPDATE EMPLOYEE\n");
    printf("\t5:  SEARCH EMPLOYEE\n");
    printf("\n\n\t\t----BRANCH---\t\n");
    printf("\t6: BRANCH LIST\n");
    printf("\t7: ADD BRANCH \n");
    printf("\t8:  GO BACK \n");
    printf("\n  SELECT OPETION-->>>");
}

void set_up_menu(){
printf("\n\t~~MANAGE BANK  SETUP~~\n");
printf("\n\t1: EMPLOYEE BANK DETAILS ");
printf("\n\t2: ADD EMPLOYEE BANK DETAILS");
printf("\n\t3: SEARCH EMPLOYEE DETAILS");
printf("\n\t4: GO BACK \n");
printf("\n  SELECT OPETION-->>>");
}

void pay_manage_menu(){
printf("\n\t~~~MANAGE PAYROLL~~~\n");
printf("\n\t1: ADD PAYROLL DETAILS");
printf("\n\t2: SEARCH EMPLOYEE ");
printf("\n\t3: GO BACK \n");
printf("\n SELECT OPETION-->>>");
}


void emp_branch(void){
    char sub_option;
    int isExit=0;
    do{
        em_br_menu();
        fflush(stdin);
        scanf("%c",&sub_option);
        switch(sub_option)
        {
        case '1':
            {
            system("cls");
            emp_List();
            break;
            }
        case '2':
            {
            system("cls");
           add_employee();
           break;
            }
        case '3':
            {
            system("cls");
            del_employee();
            break;
            }
        case '4':
            {
            system("cls");
            update_employee();
            break;
            }
        case '5':
            {
            system("cls");
            search_employee();
            break;
            }
        case '6':
           {
            system("cls");
            branch_list();
               break;
           }
        case '7':
           {
            system("cls");
            add_branch();
               break;
           }
        case '8':
            {
            system("cls");
            isExit=1;
            fflush(stdin);
            getch();
            break;
            }
        }
    }while(isExit==0);
    fflush(stdin);
    getch();
}

void add_branch(){
    int n;
    printf("\n\nEnter number of Branch you want to add :");
    scanf("%d",&n);
    struct branch b[n];
    FILE *fp;
   fp = fopen(BR_FILE,"a+");
   if(fp==NULL){
    printf("file not found");
    exit(0);
   }
   for(int i=0;i<n;i++)
   {
    printf("Enter Branch :");
    fflush(stdin);
    gets(b[i].name);
    fflush(stdin);
    printf("Enter Branch code:");
    gets(b[i].code);
    printf("Enter Branch Id :");
    fflush(stdin);
    scanf("%d",&b[i].id);
    printf("Enter Branch Address:");
    fflush(stdin);
    gets(b[i].address);
   fwrite(&b,sizeof(struct branch),n,fp);
   }
   printf("\n\n\t\t\t....Insert data successfully....");
   fclose(fp);
}

void branch_list(void){
    FILE *fp;
    struct branch b;
    fp= fopen(BR_FILE,"r");
    printf("\t\t\t--------BRANCH LIST-----------\n\n");
    while(fread(&b,sizeof(struct branch),1,fp)){
    printf("\t\tBranch Came:  %s\n",b.name);
    printf("\t\tBranch Code: %s\n",b.code);
    printf("\t\tBranch Id:  %d\n",b.id);
    printf("\t\tBranch Address:  %s\n\n\n",b.address);
    }
    fclose(fp);
}


void add_employee(){
    int n;
    printf("\n\nEnter Number of Employee you insert :");
    scanf("%d",&n);
    struct employee e[n];
    FILE *fp;
   fp = fopen(EMP_FILE,"a+");
   if(fp==NULL){
    printf("file not found");
    exit(0);
   }
   for(int i=0;i<n;i++)
   {
    printf("\n\nEnter FullName:");
    fflush(stdin);
    gets(e[i].name);
    printf("Enter Employee-ID:");
    scanf("%d",&e[i].id);
    printf("Enter Email:");
    fflush(stdin);
    gets(e[i].email);
    printf("Enter Mobile Number:");
    fflush(stdin);
    gets(e[i].mobile);
    fflush(stdin);
    printf("Enter Address:");
    fflush(stdin);
    gets(e[i].address);
    printf("Enter Designation:");
    gets(e[i].designation);
    printf("Enter Joining Date:");
    gets(e[i].join);
    printf("Enter Date Of Birth:");
    gets(e[i].dob);
   fwrite(&e,sizeof(struct employee),n,fp);
   }
   printf("\n\t\t....Insert data successfully....\t\t\n\n");
   fclose(fp);

}

void del_employee(){
 int emp_id;
    int found =0;
    printf("\n\nEnter Employee Id for update:");
    scanf("%d",&emp_id);
    FILE *fp,*fp1;
    struct employee e;
    fp= fopen(EMP_FILE,"r");
    fp1=fopen(TMP_FILE,"w");
    while(fread(&e,sizeof(struct employee),1,fp))
    {
       if(emp_id==e.id)
      {
        found=1;
        printf("\n......Delete successfully......");
       }
      else{
        fwrite(&e,sizeof(struct employee),1,fp1);
       }
    }
fclose(fp);
fclose(fp1);

 if(found){
    fp1=fopen(TMP_FILE,"r");
    fp = fopen(EMP_FILE,"w");

    while(fread(&e,sizeof(struct employee),1,fp1)){
        fwrite(&e,sizeof(struct employee),1,fp);
    }
    fclose(fp);
    fclose(fp1);

 }
 else
    {
    printf("\n\t\t\tSorry..!");
    printf("\tRecord not found");
}
}

void emp_List(){
    FILE *fp;
    struct employee e;
    fp= fopen(EMP_FILE,"r");
   // fwrite(&e,sizeof(struct employee),1,fp);
    printf("\t\t\t------------EMPLOYEE LIST---------------\n");
    while(fread(&e,sizeof(struct employee),1,fp)){
    printf("\t\tEmployee Name : %s\n",e.name);
    printf("\t\tEmployee Id : %d\n",e.id);
    printf("\t\tEmployee Email Id:%s\n",e.email);
    printf("\t\tEmployee Mobile number: %s\n",e.mobile);
    printf("\t\tEmployee Address : %s\n",e.address);
    printf("\t\tEmployee Designation: %s\n",e.designation);
    printf("\t\tEmployee Joining Date: %s\n",e.join);
    printf("\t\tEmployee Date of Birth: %s\n\n\n",e.dob);
    }
    fclose(fp);
}

void update_employee(){
  int emp_id;
    int found =0;
    printf("Enter Employee Id for update:");
    scanf("%d",&emp_id);
    FILE *fp,*fp1;
    struct employee e;
    fp= fopen(EMP_FILE,"r");
    fp1=fopen(TMP_FILE,"w");
    while(fread(&e,sizeof(struct employee),1,fp))
    {
    if(emp_id==e.id)
    {
        found=1;
    printf("\n\nEnter FullName:");
    fflush(stdin);
    gets(e.name);
    printf("Enter Employee-ID:");
    scanf("%d",&e.id);
    printf("Enter Email:");
    fflush(stdin);
    gets(e.email);
    printf("Enter Mobile Number:");
    fflush(stdin);
    gets(e.mobile);
    fflush(stdin);
    printf("Enter Address:");
    fflush(stdin);
    gets(e.address);
    printf("Enter Designation:");
    gets(e.designation);
    printf("Enter Joining Date:");
    gets(e.join);
    printf("Enter Date Of Birth:");
    gets(e.dob);
    }
  fwrite(&e,sizeof(struct employee),1,fp1);
  }
  printf("\t\t.......details updated successfully......");
fclose(fp);
fclose(fp1);

 if(found){
    fp1=fopen(TMP_FILE,"r");
    fp = fopen(EMP_FILE,"w");

    while(fread(&e,sizeof(struct employee),1,fp1)){
        fwrite(&e,sizeof(struct employee),1,fp);
    }
    fclose(fp);
    fclose(fp1);

 }
 else
    {
    printf("\t\tSorry..!\n\t\tRecord not found");
    }
//fclose(fp);
}

void search_employee(){
    int emp_id;
    int found=0;
    printf("Enter Employee Id :");
    scanf("%d",&emp_id);
    FILE *fp;
    struct employee e;
    fp= fopen(EMP_FILE,"r");
  while(fread(&e,sizeof(struct employee),1,fp)){
        if(emp_id==e.id)
    {
        found=1;
    printf("\t\t\t------------SEARCH EMPLOYEE DEATAILS---------------\n");
    printf("\t\tEmployee Name : %s\n",e.name);
    printf("\t\tEmployee Id : %d\n",e.id);
    printf("\t\tEmployee Email Id:%s\n",e.email);
    printf("\t\tEmployee Mobile number: %s\n",e.mobile);
    printf("\t\tEmployee Address : %s\n",e.address);
    printf("\t\tEmployee Designation:%s\n",e.designation);
    printf("\t\tEmployee Joining Date:%s\n",e.join);
    printf("\t\tEmployee Date of Birth: %s\n",e.dob);
    }
    }
    if(found==0)
    {
    printf("\t\t\nSorry..!\n\t\tRecord not found");
    }

    fclose(fp);

}

void set_up(){
    char sub_option;
    int isExit=0;
    do{
        set_up_menu();
        fflush(stdin);
        scanf("%c",&sub_option);
        switch(sub_option)
        {
        case '1':
            {
            bank_list();
            break;
            }
        case '2':
            {
            add_bk_details();
            break;
            }
        case '3':
        {
            search_bank_details();
            break;
        }
        case '4':
            {
            isExit=1;
            fflush(stdin);
            getch();
            break;
            }
        }
    }while(isExit==0);
    fflush(stdin);
    getch();
}



void add_bk_details(){
 int n;
    printf("\n\nEnter number of Bank Details you want to insert:");
    scanf("%d",&n);
    struct bank bk[n];
    FILE *fp;
   fp = fopen(BANK_FILE,"a+");
   if(fp==NULL){
    printf("file not found");
    exit(0);
   }
   for(int i=0;i<n;i++)
   {
    printf("\n\nEnter Name :");
    fflush(stdin);
    gets(bk[i].name);
    fflush(stdin);
    printf("Enter Employee Id :");
    scanf("%d",&bk[i].emp_id);
    printf("Enter Branch :");
    fflush(stdin);
    gets(bk[i].branch);
    printf("Enter email:");
    fflush(stdin);
    gets(bk[i].email);
    printf("Enter Bank Name :");
    gets(bk[i].bank_name);
    printf("Enter ACCOUNT NO:");
    gets(bk[i].acc_no);
    printf("Enter IFSC CODE:");
    gets(bk[i].ifsc_code);
   fwrite(&bk,sizeof(struct bank),n,fp);
   }
   printf("\n\n\t\t\t....Insert bank details successfully....");
   fclose(fp);
}

void bank_list(){
FILE *fp;
    struct bank bk;
    fp= fopen(BANK_FILE,"r");
    fwrite(&bk,sizeof(struct bank),1,fp);
    printf("\n\n\t\t\t----------------EMPLOYEE BANK DETAILS-------------------\n");
    while(fread(&bk,sizeof(struct bank),1,fp)){
    printf("\t\tEmployee Name: %s\n",bk.name);
    printf("\t\tEmployee Id : %d\n",bk.emp_id);
    printf("\t\tEmployee Branch: %s\n",bk.branch);
    printf("\t\tEmployee Email Id:%s\n",bk.email);
    printf("\t\tEmployee Account no  : %s\n",bk.bank_name);
    printf("\t\tEmployee ACcount:%s\n",bk.acc_no);
    printf("\t\tEmployee IFSC Code :%s\n\n",bk.ifsc_code);
    }
    printf("\n\t\t\t\t----------------------------------------------\n");
    fclose(fp);
}
void search_bank_details(){
int id;
    int found;
    printf("Enter Employee Id :");
    scanf("%d",&id);
    FILE *fp;
    struct bank bk;
    fp= fopen(BANK_FILE,"r");
  while(fread(&bk,sizeof(struct bank),1,fp)){
        if(id==bk.emp_id)
    {
        found=1;
    printf("\t\t\t------------SEARCH EMPLOYEE DEATAILS---------------\n");
    printf("\t\tEmployee Name: %s\n",bk.name);
    printf("\t\tEmployee Id : %d\n",bk.emp_id);
    printf("\t\tEmployee Branch: %s\n",bk.branch);
    printf("\t\tEmployee Email Id:%s\n",bk.email);
    printf("\t\tEmployee Account no  : %s\n",bk.bank_name);
    printf("\t\tEmployee ACcount:%s\n",bk.acc_no);
    printf("\t\tEmployee IFSC Code :%s\n",bk.ifsc_code);
    printf("\n\t\t\t\t----------------------------------------------\n");
    }
    }
    if(!found)
    {
    printf("\t\tSorry..!\n\tRecord not found");
    }

    fclose(fp);
}


void pay_manage(){
char sub_option;
    int isExit=0;
    do{
        pay_manage_menu();
        fflush(stdin);
        scanf("%c",&sub_option);
        switch(sub_option)
        {
        case '1':
            {
            manage_payroll();
            break;
            }

        case '2':
        {
            search_em_report();
            break;
        }
    case '3':
            {
            isExit=1;
            fflush(stdin);
            getch();
            break;
            }
        }
    }while(isExit==0);
    fflush(stdin);
    getch();

}


void manage_payroll(){
int n;
    printf("\n\nEnter how many details you want to add :");
    scanf("%d",&n);
    struct employee e[n];
    FILE *fp;
   fp = fopen(MNG_FILE,"a+");
   if(fp==NULL){
    printf("file not found");
    exit(0);
   }
   for(int i=0;i<n;i++)
   {
     printf("Enter Employee Name:");
     fflush(stdin);
     gets(e[i].emp_name);
     fflush(stdin);
    printf("Enter Employee Id:");
    fflush(stdin);
    scanf("%d",&e[i].emp_id);
    fflush(stdin);
    printf("Total working days:");
    fflush(stdin);
    scanf("%d",&e[i].total_working_days);
    fflush(stdin);
    printf("Enter Employee salary:");
    fflush(stdin);
    scanf("%f",&e[i].salary);
   fwrite(&e,sizeof(struct employee),n,fp);
   }
   printf("\n\n\t\t....Insert data successfully....\n");
   fclose(fp);

}

void search_em_report(){

int e_id;
    int found;
    float s1;
    float pf;
    float tf;
    printf("Enter Employee Id :");
    scanf("%d",&e_id);

    //scanf("%f",p.salary);
    FILE *fp;
    struct employee e;
    printf("%d",e.emp_id);

    fp= fopen(MNG_FILE,"r");
  while(fread(&e,sizeof(struct employee),1,fp)){

        if(e_id==e.emp_id)
       {
           pf = e.salary*EPF_RATE;
           tf=e.salary * ETF_RATE;
           s1 = e.salary - (pf+tf);

        found=1;
    printf("\t\t\t------------EMPLOYEE SALARY DETAILS---------------\n");
    printf("\t\tEmployee Name : %s\n",e.emp_name);
    printf("\t\tEmployee Id : %d\n",e_id);
    printf("\t\tEmployee Salary:%.2f\n",s1);
    printf("\t\tEmployee Provident fund:%.2f\n",pf);
    printf("\t\tEmployee Professional fund:%.2f\n",tf);
    }
    }
    if(!found)
    {
    printf("\t\t\nSorry..!\n\t\tRecord not found");
    }

    fclose(fp);

}
void report(){

    int found;
    float s1;
    float pf;
    float tf;

    FILE *fp;
    struct employee e;
    fp= fopen(MNG_FILE,"r");
  while(fread(&e,sizeof(struct employee),1,fp)){
           pf = e.salary*EPF_RATE;
           tf=e.salary * ETF_RATE;
           s1 = e.salary - (pf+tf);

        found=1;
    printf("\t\t\t------------EMPLOYEE SALARY DETAILS---------------\n");
    printf("\t\tEmployee Name : %s\n",e.emp_name);
     printf("\t\tEmployee Id : %d\n",e.emp_id);
    printf("\t\tEmployee Salary:%.2f\n",s1);
    printf("\t\tEmployee Provident fund:%.2f\n",pf);
    printf("\t\tEmployee Professional fund:%.2f\n",tf);
  }

    printf("\n\t\t\t--------------------------------------------------------\n");
    if(!found)
    {
    printf("\n\t\t\t\tSorry..!\n\t\tRecord not found");
    }

    fclose(fp);
}

void pwd(){
char password[100],username[10];
system("color b0");
int i=0;
char ch;
printf("\n\n\n\n\n\n\n");
printf("\n\t\t\t\t\t\t_______LOGIN_______");
printf("\n");
printf("\t\t\t\t****************************************************");
printf("\n\n\n");
printf("\t\t\t\t\t\tUSERNAME:");
gets(username);
printf("\t\t\t\t\t\tPASSWORD:");
while (1){
    ch=getch();
    if(ch==ENTER || ch==TAB){
        password[i] ='\0';
        break;
    }else if (ch==BKSP){
    if(i>0){
        i--;
        printf("\b \b");
    }
    }else{
    password[i++]=ch;
    printf("* \b");
    }
}
if(strcmp(username,"khushbu")==0){
    if(strcmp(password,"12345")==0){
        printf("\n\n\t\t\t\t\t\tLogin successfully...!\n\n");
    }else{
    printf("\n\n\t\t\t\t\t\tWrong PASSWORD..!\n\n");
    exit(0);
    }
}else{
  printf("\n\n\t\t\t\t\t\tWrong USERNAME..!\n\n\n\n\n\n\n\n\n");
  exit(0);
}
printf("\n\t\t\t\t****************************************************\n\n\n");
return 0;
}

