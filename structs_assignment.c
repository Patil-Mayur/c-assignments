#include<stdio.h>
#include<string.h>

int counter1 = -1;
int counter2 = -1;
int counter3 = -1;
struct student
{
  int roll_no;
  char subject_code[10];
  char name[50];
  int marks;
};

/* function initialization */

struct student list1[25];
struct student list2[25];
struct student list3[50];

void options_for_selection();
void choice(struct student *, int *);
void insert(struct student *, int);
void display(struct student *, int);
void sort(struct student *, int);
int main()
{
  init_choice();
}

void options_for_selection()
{
  puts("1. Insertion");
  puts("2. Deletion");
  puts("3. Get Number of records");
  puts("4. Check if Empty or not");
  puts("5. Check if full or not");
  puts("6. Get Max Marks");
  puts("7. List unique Entries");
  puts("8. List union of two lists");
  puts("9. List intersection of two lists");
  puts("10. List difference of two lists");
  puts("11. List Symmetric Difference between two lists");
  puts("12. Go to Main Menu to Exit OR Change List");
  puts("13. Display");
}

int init_choice()
{
  int ch;
  do
  {
    puts("Main Menu");
    puts("1. First List");
    puts("2. Second List");
    puts("3. Exit");
    printf("Enter list choice:\n");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1 : choice(list1, &counter1);break;
      case 2 : choice(list2, &counter2);break;
      case 3 : puts("Thanks For visitng");
      default : puts("Not a valid choice");
    }
  }while(ch != 3);
}

void choice(struct student list[], int *counter)
{
  int choice, temp;
  do
  {
    options_for_selection(); /* prints list of options along with choice code */
    printf("Please Enter a valid choice:\n");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1 : insert(list, ++*counter);break;
      case 2 : temp = delete(list, *counter);
               (temp == 1) ? --*counter : *counter;
               break;
      case 3 : getNumRecords(list, *counter);break;
      case 4 : isEmpty(list, *counter);break;
      case 5 : isFull(list, *counter);break;
      case 6 : getMaxMarks(list, *counter);break;
      case 7 : list_unique(list, *counter);break;
      case 8 : list_union();break;
      case 9 : list_intersection();break;
      case 10 : list_difference();break;
      case 11 : list_symmetric_diff();break;
      case 12 : display(list, *counter);break;
      case 13 : puts("Change List");break;
      default : printf("Not a valid choice\n");break;
    }
  }while(choice != 13);
}

void insert(struct student list[],int counter)
{
  printf("%d", counter);
  int roll, marks, i, j, flag;
  char name[50], code[10];
  flag = 0; 
  puts("Enter Roll-no : ");
  scanf("%d", &roll);
  for(i = 0; i <= counter; i++)
  {
    if(roll == list[i].roll_no)
    {
      printf("Roll No Found with Name : %s\n", list[i].name);break;
    }
  }
  list[counter].roll_no = roll;
  puts("Enter Name : ");
  scanf("%s", list[counter].name);
  puts("Enter subject code : ");
  scanf("%s", list[counter].subject_code);
  puts("Enter Marks : ");
  scanf("%d", &list[counter].marks);
}

int delete(struct student list[], int counter)
{
  if(counter < 0)
  {
    puts("Record Not Present");
    return 0;
  }
  int i, roll, found, j;
  char code[10];
  found = 0;
  puts("Enter roll no :");
  scanf("%d", &roll);
  puts("Enter Subject Code :");
  scanf("%s", code);
  for(i = 0; i <= counter; i++)
  {
    if((roll == list[i].roll_no) && (strcmp(list[i].subject_code, code) == 0))
    {
      found = 1;
      if(counter != 0)
      {
        for(j = i; j < counter; j++)
        {
          puts("hgola");
          list[j] = list[j + 1];
        }
      }
      list[counter].roll_no = '\0';
      *list[counter].name = '\0';
      *list[counter].subject_code = '\0';
      list[counter].marks = '\0';
      break;
    }
  }
  if(found == 1)
  {
    puts("Record successfully Deleted");
    return 1;
  }
  else
  {
    puts("Record Not Found");
    return 0;
  }
}

int getNumRecords(struct student list[], int counter)
{
  printf("There are %d records in the list\n\n", counter + 1);
}

int isEmpty(struct student list[], int counter)
{
  if(counter < 0)
  {
    printf("The list is empty\n");
  }
  else
  {
    printf("The list is not empty\n");
  }
}

int isFull(struct student list[], int counter)
{
  if(counter == 24)
  {
    printf("The list is full\n");
  }
  else
  {
    printf("The list is not full\n");
  }
}

int getMaxMarks(struct student list[], int counter)
{
  int roll_nos[40], max_marks = 0;
  int i, j, k;
  char code[10];
  puts("Enter subject code:");
  scanf("%s", code);
  j = 0;k = 0;
  for(i = 0; i <= counter; i++)
  {
    if((list[i].marks > max_marks) && (strcmp(list[i].subject_code, code) == 0))
    {
      max_marks = list[i].marks;
    }
  }
  printf("Roll No  Name\tSubject Code  Marks\n");
  printf("====================================================\n");
  for(i = 0; i <= counter; i++)
  {
    if((list[i].marks == max_marks) && (strcmp(list[i].subject_code, code) == 0)){
      printf("%d \t %s \t %s \t %d\n", list[i].roll_no, list[i].name, list[i].subject_code, list[i].marks);    
    }
  }
}

int list_unique(struct student list[], int counter)
{
  int i,j, new_counter, delete_count;
  if(counter <= 0)
  {  
    puts("Either Record is not present or only 1 record is present");
    return -1;
  }
  delete_count = 0;
  for(i = 0; i < counter; i++)
  {
    for(j = i+1; j <= counter; j++)
    {
      if((list[i].roll_no != '\0') && (list[i].roll_no == list[j].roll_no) && (strcmp(list[i].subject_code, list[j].subject_code) == 0))
      {
        list[j].roll_no = '\0';
        *list[j].name = '\0';
        *list[j].subject_code = '\0';
        list[j].marks = '\0';
        ++delete_count;   
      }
    }
  }
  new_counter = counter - delete_count;
  for(i=0; i<=new_counter; i++)
  {
    if(list[i].roll_no == '\0')
    {
      list[i] = list[i+1];
    }
  }
/*  while(list[i].roll_no != '/0')
  {
    
  }*/
  display(list, new_counter);
  printf("=====%d\n%d\n%d\n======", new_counter, delete_count, counter);
  return new_counter;  
}

int list_union()
{
  int i, j;
  for(i = 0;i <= counter1;i++)
  {
    list3[i].roll_no = list1[j].roll_no;
    
  }
}

int list_intersection()
{
  int i,j;
  for(i = 0; i <=counter1; i++)
  {
    for(j = 0; j <= counter2; j++)
    {
      if((list1[i].roll_no == list2[j].roll_no)&&(strcmp(list1[i].subject_code, list2[j].subject_code) == 0))
      {
        ++counter3;
        list3[counter3].roll_no = list1[i].roll_no;
        strcpy(list3[counter3].name, list1[i].name);
        strcpy(list3[counter3].subject_code, list1[i].subject_code);
        list3[counter3].marks = list1[i].marks;
      }
    }
  }
  display(list3, counter3);
}

int list_difference()
{
  int i,j;
  for(i = 0; i <=counter1; i++)
  {
    for(j = 0; j <= counter2; j++)
    {
      if((list1[i].roll_no == list2[j].roll_no)&&(strcmp(list1[i].subject_code, list2[j].subject_code) == 0))
      {
        //do nothing
      }
      else
      {
        ++counter3;
        list3[counter3].roll_no = list1[i].roll_no;
        strcpy(list3[counter3].name, list1[i].name);
        strcpy(list3[counter3].subject_code, list1[i].subject_code);
        list3[counter3].marks = list1[i].marks;
      }
    }
  }
  display(list3, counter3);
}

int list_symmetric_diff()
{
  int i,j;
  for(i = 0; i <=counter1; i++)
  {
    for(j = 0; j <= counter2; j++)
    {
      if(!((list1[i].roll_no == list2[j].roll_no)&&(strcmp(list1[i].subject_code, list2[j].subject_code) == 0)))
      {
        ++counter3;
        list3[counter3].roll_no = list1[i].roll_no;
        strcpy(list3[counter3].name, list1[i].name);
        strcpy(list3[counter3].subject_code, list1[i].subject_code);
        list3[counter3].marks = list1[i].marks;
      }
    }
  }
  for(i = 0; i <=counter1; i++)
  {
    for(j = 0; j <= counter2; j++)
    {
      if(!((list2[i].roll_no == list1[j].roll_no)&&(strcmp(list2[i].subject_code, list1[j].subject_code) == 0)))
      {
        ++counter3;
        list3[counter3].roll_no = list2[i].roll_no;
        strcpy(list3[counter3].name, list2[i].name);
        strcpy(list3[counter3].subject_code, list2[i].subject_code);
        list3[counter3].marks = list2[i].marks;
      }
    }
  }
  display(list3, counter3);
}

void display(struct student list[], int counter)
{
  int i;
  sort(list, counter);
  printf("Roll No  Name\tSubject Code  Marks\n");
  printf("==============================================\n");
  for(i = 0; i <= counter; i++)
  {
    printf("%d \t %s \t %s \t %d\n", list[i].roll_no, list[i].name, list[i].subject_code, list[i].marks);
  }
}

void sort(struct student list[], int counter)
{
  int i,j;
  struct student temp;
  for(i = 0; i < counter; i++)
  {
    for(j = i+1; j <= counter; j++)
    {
      if(list[i].roll_no > list[j].roll_no)
      {
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
      if(list[i].roll_no == list[j].roll_no)
      {
        if(strcmp(list[i].subject_code, list[j].subject_code) > 0)
        {
          temp = list[i];
          list[i] = list[j];
          list[j] = temp;
        }
      }
    }
  }
}
