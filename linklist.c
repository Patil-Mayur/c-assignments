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

struct student *list1, *list2, *list3;    // structure declaration

main()      // main function
{
  list1 = NULL;
  list2 = NULL;
  list3 = NULL;
  int ch;
  do
  {
    puts("1. Select List 1 For Basic Operations");
    puts("2. Select List 2 For Basic Operations");
    puts("3. Union");
    puts("4. Intersection");
    puts("5. Difference");
    puts("6. Symmetric Difference");
    puts("7. Exit");
    puts("Enter Choice");
    if(scanf("%d", &ch)<=0)
    {
      puts("Enter Integers Only");
      exit(0);
    }
    switch(ch)
    {
      case 1 : choice(list1, ch);break;
      case 2 : choice(list2, ch);break;
      case 3 : break;
      default : puts("Enter a valid choice");
    }
    
  }while(ch != 7);
}

choice(struct student *list, int list_no)     // choice function
{
  int ch;
  do
  {
    if(list_no == 1)
    {
      puts("List 1");
    } else {
      puts("List 2");
    }
    puts("1. Insert");
    puts("2. Deletion");
    puts("3. Is Empty");
    puts("4. Get Total number of records in list");
    puts("5. Get Max Marks");
    puts("6. display");
    puts("7. Exit");
    puts("Please Enter a valid choice");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1 : insert(list);break;
      case 2 : display(list);break;
      case 3 : isEmpty(list);break;
      default : puts("Wrong Option");
    }
  }while(ch != 5);
}

int insert(struct student *list)      //  Insertion function 
{
  struct student  *temp1,*temp=NULL;
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
  temp1 = list;
  while(temp1 != NULL)
  {
    temp1 = temp1->next;
  }
  if(temp1 == NULL)
{  temp1 = temp;
//  list->next = NULL;
  puts("Insertion Successful");
}

}

int display(struct student *list)   // Display function
{
  struct student *temp;
  temp = list;
  puts("=========================================");
  printf("Roll No\tName\tSubject Code\tMarks\n");
  puts("=========================================");
  while(temp != NULL)
  {
    printf("%d", temp->roll_no);
    printf("%s", temp->name);
    printf("%s", temp->subject_code);
    printf("%d", temp->marks);
    temp = temp->next;
  }
}

isEmpty(struct student *list)     // Is Empty function
{
  if(list == NULL)
  {
    puts("List is Empty");
  }
  else
  {
    puts("List is Not Empty");
  }
}

getMaxMarks(struct student *list)     // Get Max Marks function
{
  int max_marks = 0;
  struct student *temp, *temp2;
  temp = list;
  while(temp !=NULL)
  {
    if(max_marks < temp->marks)
    {
      max_marks = temp->marks;
    }
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

sort(struct student *list)      // sorting function
{
  struct student *temp;

}

