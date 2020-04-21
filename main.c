#include <stdio.h>
#include <stdbool.h>
#include<time.h>
#include <string.h>
#include<stdlib.h>
// #include<windows.h>

struct date{
    int day,month,year;
};
//create this global to help check valid date dont want to change code and just want it store when function done
    struct date dat;
    struct date dat2;
struct Diary{
    char note[1500];
    char title[100];
    int id;
    struct date dat;
};

struct Diary diary[100];
int n=0;
int id;
char titl[100];
int count[100];
int f;
//create MenuDisplay
void MenuDisplay();

//create search menu
void searchMenu();
//create menu
void createMenu();
//date Menu
void dateMenu();
//choice Menu
void choiceMenu();
//deleteMenu
void deleteMenu();
//Load file
void loadfile();
//create diary
void createDiary();
//show all diary
void showAllDiary();
//check Date
void checkDate();
//check Date v2
void checkDatev2();
//search title or date
void searchByTitleOrDate();
//update title and note
void updateTitle();
//delete diary
void deleteDiary();
//write file
void writeInFile();
//check two date
bool checkDate1(struct date dat, struct date dat2);
//check and dislay between dates
void checkBetweenDate(struct date dat,struct date dat1);
//Input date
void anotherDate();
//check empty string
bool checkEmptyString(int i);
//Display information
void displayInfo(int i);
//Load diary id;
bool loadID();
void updateNote1();
void deleteNote1();
void updateTitle1();
//show update
void showUpdate(char titl[100]);
int main(){
    //declare variable
    int f=0;
    int choice1;
    int choice;
     struct date dat,dat2;
    char buffer;
    //processing
    loadfile();
    while(1){

        MenuDisplay();
        printf("Choice :");
        scanf("%d",&choice);
        system("clear||cls");
        if(choice==1){
        system("clear||cls");

            createDiary();
        }else if(choice ==2){

            showAllDiary();

        }else if(choice==3){
            system("clear||cls");
            searchByTitleOrDate();
        }else if(choice==4){
            system("clear||cls");

            updateTitle();

        }else if (choice==5)
        {
            
          anotherDate();

        }else if (choice==6)
        {
            system("clear||cls");

            deleteDiary();
        }
        else if (choice==7){
           writeInFile();
            printf("Exit the porgram.\n");
            break;
        }

    }
}
void deleteNote1(){

     for (int i = 0; i < n; i++)
        {
          diary[i].id=i+1;
        if (strcmp(diary[i].title,titl)==0)
        {
        	count[i]=diary[i].id;
		  
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (id==count[i])
        {
            f=1;
            strcpy(diary[i].title,"");
            strcpy(diary[i].note,"");
            printf("Note deleted.\n");
        }    
    }
}
void updateNote1(){
    char buffer;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    for (int i = 0; i < n; i++)
    {
        diary[i].id=i+1;
        if (strcmp(diary[i].title,titl)==0)
        {
        	count[i]=diary[i].id;
		  
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (id==count[i])
        {
            f=1;
            scanf("%c",&buffer);
            printf("\n\nNew Note:");
            scanf("%[^\n]s",diary[i].note);
            diary[i].dat.day=tm.tm_mday;
            diary[i].dat.month=tm.tm_mon +1;
            diary[i].dat.year=tm.tm_year+1900;
            printf("Update note successful\n\n");
        }
    }
}
void updateTitle1(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
        for (int i = 0; i < n; i++)
        {
            diary[i].id=i+1;
        if (strcmp(diary[i].title,titl)==0)
            {
        	count[i]=diary[i].id;
		  
            }
        }
       for (int i = 0; i < n; i++){
            if (id==count[i])
            {
                f=1;
                printf("\n\nNew Title:");
                scanf("%s",diary[i].title);
                diary[i].dat.day=tm.tm_mday;
                diary[i].dat.month=tm.tm_mon +1;
                diary[i].dat.year=tm.tm_year+1900;
                printf("Update title successful\n\n");
            }
        }
}
void showUpdate(char titl[100]){
    
    for (int i = 0; i < n; i++)
    {
        if (strcmp(diary[i].title,titl)==0)
        {
            displayInfo(i);
        }
        
    }
}
bool loadID(){
    for (int i = 0; i < n; i++)
    {
        diary[i].id=i+1;
        if (strcmp(diary[i].title,titl)==0)
        {
        	count[i]=diary[i].id;
		  
        }
    }
    for (int i=0; i<n;i++){
	    if(count[i]==id)
	    {
		printf("%d",diary[i].id);
        printf("%s",diary[i].note);
		return true;
	    }	
    }
  return false;
}


void MenuDisplay(){
     printf("=======================================================================================================================\n\n");
    printf("\t\t\t====================\n");
    printf("\t\t\t+++++Diary Note+++++\n");
    printf("\t\t\t====================\n\n");
    printf("1.Create diary note.\n\n");
    printf("2.Show all diary.\n\n");
    printf("3.Show detail of a specific diary by title or date.\n\n");
    printf("4.Update a diary.\n\n");
    printf("5.Show all diary from a create date to another created date.\n\n");
    printf("6.Delete a diary.\n\n");
    printf("7.exit program.\n\n");
    printf("=======================================================================================================================\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");

}
void searchMenu(){
    printf("1.Search by Title.\n\n");
    printf("2.Search by date:\n\n");
    printf("3.back to main menu.\n\n");
}
void createMenu(){
    printf("1.Create Title cant space and note\n\n");
    printf("2.Back to main menu.\n\n");
}
void dateMenu(){
    printf("1.Want to search now\n\n");
    printf("2.Back to main menu\n\n");
}
void choiceMenu(){
    printf("1.Change Title.\n\n");
    printf("2.Change Note.\n\n");
     printf("3.Back to main Menu\n\n");
}
void deleteMenu(){
    printf("1.Delete diary note:\n\n");
    printf("2.Back to main menu.\n\n");
}
void displayInfo(int i){
    printf("\t\t%d|%s|%d-%d-%d|%s\n\n", diary[i].id,diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
}


//check emptystring
bool checkEmptyString(int i){
    if (strcmp(diary[i].title,"")!=0&&strcmp(diary[i].note,"")!=0)
    {
        return true;
    }
    return false;
}

//create loadfile
char titl[100];
void loadfile(){
    FILE *file;

    //display menu
    file=fopen("diary.txt","r");
    while (fscanf(file,"%s %d %d %d %[^\n]",diary[n].title,&diary[n].dat.day,&diary[n].dat.month,&diary[n].dat.year,diary[n].note)!=EOF)
        {
        n++;
    }
}
//create diary
void createDiary(){
    //declare variable
    struct Diary di;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int choice;

    char buffer;

    //processing
    while (1)
    {
    createMenu();
    printf("Choice:");
    scanf("%d",&choice);
    if (choice==1)
    {
    scanf("%c",&buffer);
    printf("\nTitle: ");
    scanf("%s",diary[n].title);
    scanf("%c",&buffer);
    printf("\nNote: ");
    fgets(diary[n].note,1500,stdin);
    diary[n].dat.day=tm.tm_mday;
    diary[n].dat.month=tm.tm_mon+1;
    diary[n].dat.year=tm.tm_year+1900;
    diary[n].id=n;
    n=n+1;
    }else if (choice==2)
    {
        break;
    }
    }
}
int num=0;
//show all the information
void showAllDiary(){
    int f=0;
    printf("=======================================================================================================================\n\n");
    printf("\t\tNo|Title|Date(day-month-year)|Note\n\n");
    for (int i = 0; i <n; i++)
    {
    if(checkEmptyString(i)){
        diary[i].id=i+1;
        f=1;
        displayInfo(i);
    }
    }
    if (f==0)
    {
        printf("No Diary!!\n\n");
    }
    printf("=======================================================================================================================\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");

}

//search title or date
void searchByTitleOrDate(){
    int p;
    int choice;
    char buffer;
    char topic[100];
    while (1){
        showAllDiary();
       searchMenu();
        printf("Choice:");
        scanf("%d",&choice);
            if (choice==1)
            {
                p=0;
            printf("\n\nSearch Title:");
            scanf("%s",topic);
            }else if (choice==2)
            {
                p=0;
                printf("\n\nSearch day month year by space:");
                scanf("%d",&dat.day);
                scanf("%d",&dat.month);
                scanf("%d",&dat.year);
                checkDate();

            }else if (choice==3)
            {
                p=1;
                break;
            }printf("\t\tNo|Title|Date(day-month-year)|Note\n\n");
    for(int i=0;i<n;i++){

       diary[i].id=i+1;
        if (choice==1)
        {
            if(strcmp(diary[i].title,topic)==0&&checkEmptyString(i)){
                p=1;
                displayInfo(i);
            }
        }else if (choice==2)
        {
            if (dat.year==diary[i].dat.year&&dat.month==diary[i].dat.month&&dat.day==diary[i].dat.day&&checkEmptyString(i))
            {
                p=1;
                displayInfo(i);
            }
        }
    }
    if (p==0)
    {
        printf("No result.\n");
    }
    }
}
//Update title and Note
void updateTitle(){
    char title[100];
    int choice;
    char buffer;
    f=0;

    while (1)
    {
        showAllDiary();
        choiceMenu();
        printf("Choice:");
        scanf("%d",&choice);
        if (choice==1||choice==2){
            f=0;
            printf("\n\nSearch title:");
            scanf("%s",titl);
            printf("\t\tNo|Title|Date(day-month-year)|Note\n\n");
        for (int i = 0; i <n; i++){
            diary[i].id=i+1;
            if (choice==1){
                if (strcmp(diary[i].title,titl)==0){
                showUpdate(titl);
                printf("No of diary update:");
                scanf("%d",&id);
                    updateTitle1();
                    break;
                }
               
            }
            
            else if (choice==2){
                if (strcmp(diary[i].title,titl)==0){
                   showUpdate(titl);
                    printf("No to update note:");
                    scanf("%d",&id);
                    updateNote1();
                    break;
                }
            }
        }
        }else if (choice==3){
            break;
        }

        if (f==0)
        {
            printf("Cant found!\n\n");
        }
    }
}
//delete diary
void deleteDiary(){
    f=0;
    int choice;
    while (1)
    {
        showAllDiary();
        deleteMenu();
        printf("Choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            f=0;
            printf("\n\nSearch diary note by title:");
            scanf("%s",titl);
        }else if (choice==2)
        {
            
            break;
        }
        printf("\t\tNo|Title|Date(day-month-year)|Note\n\n");
    for (int i = 0; i <n; i++)
    {
        diary[i].id =i+1;
        if (choice==1)
        {
            if(strcmp(diary[i].title,titl)==0){
            showUpdate(titl);

              printf("No to update note:");
                scanf("%d",&id);
                    deleteNote1();
               
                break;
            }
        }
    }
    if(f==0){
        printf("Cant found.\n");
    }
    }
}
//write date
void checkDate(){
     while(1){
         if (dat.year>=1900)
         {
             if (dat.year%4==0)
         {
             if (dat.month>=1&&dat.month<=12)
             {

                 if (dat.month==1||dat.month==3||dat.month==5||dat.month==8||dat.month==10||dat.month==12)
                 {
                     if (dat.day>=1&&dat.day<=31)
                     {
                       break;
                     }else
                     {
                         printf("\nPlease input day(1-31)\n\n");
                         scanf("%d",&dat.day);
                     }
                 }else if (dat.month==4||dat.month==6||dat.month==9||dat.month==11)
                 {
                     if (dat.day>=1&&dat.day<=30)
                     {
                         break;
                     }else
                     {
                         printf("\nPlease input day(1-30)\n\n");
                         scanf("%d",&dat.day);
                     }
                 }else if (dat.month==2)
                 {
                     if (dat.day>=1&&dat.day<=29)
                     {
                         break;
                     }else
                     {
                          printf("\nPlease input day(1-29)\n\n");
                         scanf("%d",&dat.day);
                     }
                 }
         }  else
            {
                 printf("\nPlease input month 1-12\n\n");
                 scanf("%d",&dat.month);
            }
         }else if (dat.year%4!=0)
         {
              if (dat.month>=1&&dat.month<=12)
             {
                 if (dat.month==1||dat.month==3||dat.month==5||dat.month==8||dat.month==10||dat.month==12)
                 {
                     if (dat.day>=1&&dat.day<=31)
                     {
                       break;
                     }else
                     {
                         printf("\nPlease input day(1-31)\n\n");
                         scanf("%d",&dat.day);
                     }
                 }else if (dat.month==4||dat.month==6||dat.month==9||dat.month==11)
                 {
                     if (dat.day>=1&&dat.day<=30)
                     {
                         break;
                     }else
                     {
                         printf("\nPlease input day(1-30)\n\n");
                         scanf("%d",&dat.day);
                     }
                 }else if (dat.month==2)
                 {
                     if (dat.day>=1&&dat.day<=28)
                     {
                         break;
                     }else
                     {
                          printf("\nPlease input day(1-28)\n\n");
                         scanf("%d",&dat.day);
                     }
                 }
             }else
             {
                 printf("\nPlease input month 1-12\n\n");
                 scanf("%d",&dat.month);
             }
         }
        }else
         {
             printf("\nPlease input year start 1900 up:\n");
             scanf("%d",&dat.year);
         }
         }
    }
//check dat 2
void checkDatev2(){
     while(1){
         if (dat2.year>=1900)
         {
             if (dat2.year%4==0)
         {
             if (dat2.month>=1&&dat2.month<=12)
             {

                 if (dat2.month==1||dat2.month==3||dat2.month==5||dat2.month==8||dat2.month==10||dat2.month==12)
                 {
                     if (dat2.day>=1&&dat2.day<=31)
                     {
                       break;
                     }else
                     {
                         printf("\nPlease input day(1-31)\n\n");
                         scanf("%d",&dat.day);
                     }
                 }else if (dat2.month==4||dat2.month==6||dat2.month==9||dat2.month==11)
                 {
                     if (dat2.day>=1&&dat2.day<=30)
                     {
                         break;
                     }else
                     {
                         printf("\nPlease input day(1-30)\n\n");
                         scanf("%d",&dat.day);
                     }
                 }else if (dat2.month==2)
                 {
                     if (dat2.day>=1&&dat2.day<=29)
                     {
                         break;
                     }else
                     {
                          printf("\nPlease input day(1-29)\n\n");
                         scanf("%d",&dat2.day);
                     }
                 }
         }  else
            {
                 printf("\nPlease input month 1-12\n\n");
                 scanf("%d",&dat2.month);
            }

         }else if (dat2.year%4!=0)
         {
              if (dat2.month>=1&&dat2.month<=12)
             {
                 if (dat2.month==1||dat2.month==3||dat2.month==5||dat2.month==8||dat2.month==10||dat2.month==12)
                 {
                     if (dat2.day>=1&&dat2.day<=31)
                     {
                       break;
                     }else
                     {
                         printf("\nPlease input day(1-31)\n\n");
                         scanf("%d",&dat2.day);
                     }
                 }else if (dat2.month==4||dat2.month==6||dat2.month==9||dat2.month==11)
                 {
                     if (dat2.day>=1&&dat2.day<=30)
                     {
                         break;
                     }else
                     {
                         printf("\nPlease input day(1-30)\n\n");
                         scanf("%d",&dat2.day);
                     }
                 }else if (dat2.month==2)
                 {
                     if (dat2.day>=1&&dat2.day<=28)
                     {
                         break;
                     }else
                     {
                          printf("\nPlease input day(1-28)\n\n");
                         scanf("%d",&dat2.day);
                     }
                 }
             }else
             {
                 printf("\nPlease input month 1-12\n\n");
                 scanf("%d",&dat2.month);
             }
         }
        }else
         {
             printf("\nPlease input year start 1900 up:\n");
             scanf("%d",&dat2.year);
         }
         }
    }
//Write in file
void writeInFile(){
    FILE *file;
    file =fopen("diary.txt","w");
    for (int i = 0; i <n; i++)
    {
        if (!checkEmptyString(i))
        {
            fprintf(file,"%s %s",diary[i].title,diary[i].note);
        }else
        {
            fprintf(file,"%s %d %d %d %s\n",diary[i].title,diary[i].dat.day,diary[i].dat.month,diary[i].dat.year,diary[i].note);
        }
    }
    fclose(file);
}
//check between two date
bool checkDate1(struct date dat, struct date dat2){
    if (dat.year<dat2.year)
    {
        return true;

    }else if (dat.year==dat2.year)
    {
        if (dat.month < dat2.month)
        {
            return true;
        }
       else if (dat.month==dat2.month)
        {
            if (dat.day<dat2.day)
            {
                return true;
            }else if (dat.day==dat2.day)
            {
                return true;
            }else
            {
                return false;
            }
        }else
        {
            return false;
        }
    }else
    {
        return false;
    }
}
//check anotherdate
void checkBetweenDate(struct date dat,struct date dat1){
    int f=0;
    printf("\t\t====The result===\n\n");
    for (int i = 0; i <n; i++)
    {
        diary[i].id=i+1;
        if (checkDate1(dat,diary[i].dat)&&checkDate1(diary[i].dat,dat1)&&checkEmptyString(i))
        {
            f++;    
            displayInfo(i);
        }
    }

      if (f==0){
            printf("Not found!!.\n");
        }
    printf("_______________________________________________________________________________________________________________________\n\n\n");

}
//checking between date and date
void anotherDate(){
    int f=0;
    int choice1;
    while (1)
    {
        printf("\t\t=========================================\n");
        printf("\t\t+Checking from create day to another day+\n");
        printf("\t\t=========================================\n");

        showAllDiary();
        dateMenu();
        printf("Choice:");
        scanf("%d",&choice1);
        if (choice1==1)
        {
           printf("\n\nPlease enter create date\n\n");
           printf("Begin date input day month year by space:");
           scanf("%d %d %d",&dat.day,&dat.month,&dat.year);
            checkDate();

           printf("\n\nPlease enter another date\n\n");
             printf("Another date input day month year by space:");
           scanf("%d %d %d",&dat2.day,&dat2.month,&dat2.year);
                checkDatev2();
        checkBetweenDate(dat,dat2);
        }
        else if (choice1==2)
        {
            f=1;
            break;
        }
    }
}
