#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
  int roll_no;
  char name[50];
  char subject_code[10];
  int marks;
  struct student *next;
};
struct student *list1, *list2;    // structure declaration
struct student *difference(struct student *, struct student *);

main()      // main function
{
  list1 = NULL; 
  list2 = NULL; 
  int ch;
  do
  {
    puts("====================\n     Main Menu\n====================");
    puts("1. Select List 1 For Basic Operations like Insertion, Deletion, Max Marks etc");
    puts("2. Select List 2 For Basic Operations like Insertion, Deletion, Max Marks etc");
    puts("3. Union");
    puts("4. Intersection");
    puts("5. Difference");
    puts("6. Symmetric Difference");
    puts("7. Exit\n=====================");
    puts("Enter Choice");
    if(scanf("%d", &ch)<=0)
    {
      puts("Enter Integers Only");
      exit(0);
    }
    switch(ch)
    {
      case 1 : choice(&list1, ch);break;
      case 2 : choice(&list2, ch);break;
      case 3 : uni_on(list1, list2);break;
      case 4 : intersection(list1, list2);break;
      case 5 : list_difference(list1, list2);break;
      case 6 : symmetric_difference(list1, list2);break;
      case 7 : break;
      default : puts("Enter a valid choice");
    }
  }while(ch != 7);
}

choice(struct student **list, int list_no)     // choice function
{
  int ch;
  do
  {
    if(list_no == 1)
      puts("===========================\nCurrent list is List 1\n===========================");
    else
      puts("===========================\nCurrent list is List 2\n===========================");
    puts("1. Insert");
    puts("2. Deletion");
    puts("3. Is Empty");
    puts("4. Get Total number of records in list");
    puts("5. Get Max Marks");
    puts("6. List Unique");
    puts("7. Display");
    puts("8. Return to Main Menu");
    puts("Please Enter a valid choice");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1 : insert(list);break;
      case 2 : delete(list);break;
      case 3 : isEmpty(*list);break;
      case 4 : getNumbRecords(*list);break;
      case 5 : getMaxMarks(*list);break;
      case 6 : unique(list);break;
      case 7 : display(*list);break;
      case 8 : break;
      default : puts("Wrong Option");
    }
  }while(ch != 8);
}

int insert(struct student **list)      //  Insertion function 
{
  struct student  *temp1,*temp=NULL;
  temp1=*list;
  temp = (struct student *)malloc(sizeof(struct student));
  puts("Enter Roll No");
  scanf("%d", &temp->roll_no);
  puts("Enter Name");
  scanf("%s", temp->name);
  puts("Enter Subject Code");
  scanf("%s", temp->subject_code);
  puts("Enter Marks");
  scanf("%d", &temp->marks);
  temp->next = NULL;
  if(temp1 == NULL)
    *list=temp;
  else
  {
    while(temp1->next != NULL)
      temp1 = temp1->next;
    temp1->next = temp;
  }
  puts("Insertion Successful");
}

delete(struct student **list)
{
  int roll, flag = 0;
  char  code[10];
  struct student *temp1,*curr, *prev, *temp2;
  puts("Enter Roll No");
  scanf("%d", &roll);
  puts("Enter Subject code");
  scanf("%s", code);
  temp1 = *list;
  if(temp1 == NULL)
  {
    puts("Record Not Found");return;
  }
  if(temp1->next == NULL && temp1->roll_no == roll && strcmp(temp1->subject_code,code) == 0)
  {
    *list = NULL;flag = 1;
  }
  else if(temp1->roll_no == roll && strcmp(temp1->subject_code,code) == 0)
  {
    *list = temp1->next;
    free(temp1);
    flag = 1;
  } 
  else
  {
    while(temp1 != NULL && temp1->next != NULL)
    {
      if(temp1->next->roll_no == roll && strcmp(temp1->next->subject_code,code) == 0)
      {
         curr = temp1->next;
         temp1->next = temp1->next->next;
         free(curr);
         flag = 1;break;
      }
      temp1 = temp1->next;
    }
  }
  if(flag == 1)
    puts("Record deleted Successfully");
  else
    puts("Record Not Found");
}

isEmpty(struct student *list)     // Is Empty function
{
  if(list == NULL)
    puts("=============\nList is Empty\n=================");
  else
    puts("=============\nList is Not Empty\n=============");
}

int getNumbRecords(struct student *list)     // get number of records function
{
  int counter = 0;
  struct student *temp;
  temp = list;
  while(temp != NULL)
  {
    temp = temp->next;
    counter++;
  }
  printf("There are %d records in the list\n", counter);
}

getMaxMarks(struct student *list)     // Get Max Marks function
{
  int max_marks = 0;
  struct student *temp, *temp2;
  temp = list;
  while(temp !=NULL)
  {
    if(max_marks < temp->marks)
      max_marks = temp->marks;
    temp = temp->next;
  }
  temp2 = list;
  while(temp2 != NULL)
  {
    if(temp2->marks == max_marks)
    {
      printf("%d", temp2->roll_no);
      printf("%s", temp2->name);
      printf("%s", temp2->subject_code);
      printf("%d", temp2->marks);
    }
    temp2=temp2->next;  
  }
}

unique(struct student **list)
{
  struct student *temp1, *temp2, *dup;
  temp1 = *list;
  while(temp1 != NULL && temp1->next!=NULL)
  {
    temp2 = temp1;
    while(temp2->next != NULL)
    {
      if((temp1->roll_no == temp2->next->roll_no) && strcmp(temp1->subject_code, temp2->next->subject_code) == 0)
      {
        dup = temp2->next;
        temp2->next = temp2->next->next;
        free(dup);
      }
      else
        temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
  display(*list);
}

int display(struct student *list)   // Display function
{
  struct student *temp;
  temp = list;
  sort(&list);
  puts("=========================================");
  printf("Roll No\tName\tSubject Code\tMarks\n");
  puts("=========================================");
  while(temp != NULL)
  {
    printf("%d\t%s\t%s\t%d\n", temp->roll_no, temp->name,temp->subject_code,temp->marks);
    temp = temp->next;
  }
  puts("=========================================");
}

uni_on(struct student *node1, struct student *node2)
{
  struct student *temp1, *temp2, *temp3, *temp4, *temp;
  temp1 = node1;
  temp2 = node2;
  temp4 = NULL;
  while(temp1 != NULL)
  {
    temp = (struct student *)malloc(sizeof(struct student));
    temp->roll_no = temp1->roll_no;
    strcpy(temp->name, temp1->name);
    strcpy(temp->subject_code, temp1->subject_code);
    temp->marks = temp1->marks;
    temp->next = NULL;
    if(temp4 == NULL)
    {
      temp4 = temp;
      temp3 = temp4;
    }
    else
    {
      temp3->next = temp;
      temp3 = temp3->next;
    }
    temp1 = temp1->next;
  }
  while(temp2 != NULL)
  {
    temp = (struct student *)malloc(sizeof(struct student));
    temp->roll_no = temp2->roll_no;
    strcpy(temp->name,temp2->name);
    strcpy(temp->subject_code, temp2->subject_code);
    temp->marks = temp2->marks;
    temp->next = NULL;
    if(temp4 == NULL)
    {
      temp4 = temp;
      temp3 = temp4;
    }
    else
    {
      temp3->next = temp;
      temp3 = temp3->next;
    }
    temp2 = temp2->next;
  }
  unique(&temp4);
}

intersection(struct student *node1, struct student *node2)
{
  struct student *temp1,*temp2,*temp3, *temp, *temp4;
  temp1 = node1;
  temp4 = NULL;
  while(temp1 != NULL)
  {
    temp2 = node2;
    while(temp2 != NULL)
    {
      if(temp2->roll_no == temp1->roll_no && (strcmp(temp1->subject_code,temp2->subject_code) == 0))
        break;
      else
        temp2 = temp2->next;
    }
    if(temp2 != NULL)
    {
      temp = (struct student *)malloc(sizeof(struct student));
      temp->roll_no=temp1->roll_no;
      strcpy(temp->name,temp1->name);
      strcpy(temp->subject_code,temp1->subject_code);
      temp->marks=temp1->marks;
      temp->next = NULL;
      if(temp4 == NULL)
      {
        temp4 = temp;
        temp3 = temp4;
      }
      else
      {
        temp3->next = temp;
        temp3 = temp3->next;
      }
    }
    temp1 = temp1->next;
  }
  display(temp4);
}

struct student *difference(struct student *node1, struct student *node2)
{
  struct student *temp1,*temp2, *temp3, *temp4, *temp;
  temp1 = node1;
  temp4 = NULL;
  while(temp1 != NULL)
  {
    temp2 = node2;
    while(temp2 != NULL)
    {
      if(temp2->roll_no == temp1->roll_no && (strcmp(temp1->subject_code,temp2->subject_code) == 0))
        break;
      else
        temp2 = temp2->next;
    }
    if(temp2 == NULL)
    {
      temp = (struct student *)malloc(sizeof(struct student));
      temp->roll_no=temp1->roll_no;
      strcpy(temp->name,temp1->name);
      strcpy(temp->subject_code,temp1->subject_code);
      temp->marks=temp1->marks;
      temp->next = NULL;
      if(temp4 == NULL)
      {
        temp4 = temp;
        temp3 = temp4;
      }
      else
      {
        temp3->next = temp;
        temp3 = temp3->next;
      }
    }
    temp1 = temp1->next;
  }
  return temp4;
}

list_difference(struct student *node1,struct student *node2)
{
  display(difference(node1, node2));
}

symmetric_difference(struct student *node1, struct student *node2)
{
  uni_on(difference(node1, node2), difference(node2, node1));
}

sort(struct student **list)      // sorting function
{
  struct student *temphead, *tempnode, *p;
  int roll, mark;
  char code[10],name[50]; 
  int count = 0, i, j;
  temphead = *list;
  while(temphead != NULL)
  {
    tempnode = temphead->next; 
    while(tempnode != NULL)
    {
      if(temphead->roll_no > tempnode->roll_no || (temphead->roll_no == tempnode->roll_no && strcmp(temphead->subject_code, tempnode->subject_code) > 0))
      {
        roll = tempnode->roll_no;
        strcpy(name, tempnode->name);
        strcpy(code, tempnode->subject_code);
        mark = tempnode->marks;
        
        tempnode->roll_no = temphead->roll_no;
        strcpy(tempnode->name, temphead->name);
        strcpy(tempnode->subject_code, temphead->subject_code);
        tempnode->marks = temphead->marks;
        
        temphead->roll_no = roll;
        strcpy(temphead->name, name);
        strcpy(temphead->subject_code, code);
        temphead->marks = mark;
      }
      tempnode = tempnode->next;
    }
    temphead = temphead->next;
  }
}
