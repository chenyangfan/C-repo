#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define FILENAME_LEN 20
//define a struct 
struct node {
  int number;
  char name[NAME_LEN+1];
  struct node* next;
};

//insert the nodes in
struct node* insert(struct node* student_list);
//print  a student record
void print_student(struct node* student);
//traversal the whole list
void print_list(struct node* student_list);
//search for a specific user
void search(struct node* student_list);
//delete a npde
struct node* delete(struct node* student_list);
//delete thewhole list
void delete_list(struct node* student_list);
//perform merge sort
struct node* mergesort(struct node* student_list);
//merge 2 list
struct node* merge(struct node* list1, struct node* list2);
//save and load
void save(struct node* student_list);
struct node* load();

int read_line(char line[], int len);

int main(void) {
  int option;
  struct node* student_list = NULL;
  //infinite for loop
  for (;;) {
    printf("\n");
    printf("1: Add a student\n");
    printf("2: Search for a student by number\n");
    printf("3: Delete a student by number\n");
    printf("4: Display all students\n");
    printf("5: Sort students by number\n");
    printf("6: Save the current list\n");
    printf("7: Load the list from a file\n");
    printf("8: Close the current database\n");
    printf("0: Exit\n");
    printf("\n");
    //if option has not successfully assign  a number
    //exit inmediately.
    printf("Enter an option: ");
    if ((scanf ("%d", &option) != 1)) {
      printf("Failure to read an option\n");
      exit(EXIT_FAILURE);
    }


    while (getchar() != '\n');
    
    if(option == 0)
      break;

    switch(option) {
    case 1:
      student_list = insert(student_list);
      break;

    case 2:
      search(student_list);
      break;

    case 3:
      student_list = delete(student_list);
      break;

    case 4:
      print_list(student_list);
      break;

    case 5:
      student_list = mergesort(student_list);
      break;

    case 6:
      save(student_list);
      break;

    case 7:
      if (student_list != NULL) {
	printf("The current student list is not empty.\n");
	printf("Close the current database before loading another.\n");
      }
      else {
	student_list = load();
      }
      break;

    case 8:
      delete_list(student_list);
      student_list = NULL;
      break;

    default:
      printf("Incorrect option\n");
    }
  }

  delete_list(student_list);

  return 0;
}

struct node* mergesort(struct node* student_list) {
  struct node* list1 = student_list;
  struct node* list2 = student_list;
  //return if one student record or no student reord
  if (student_list == NULL || student_list->next == NULL)
    return student_list;
  
  //when list2 reaches the null pointer, list 1 only gets to the middle of the list
  while ((list2 = list2->next) != NULL && (list2 = list2->next) != NULL)
    list1 = list1->next;
  
  //the header of list 2 is the next element of the list 1 currently
  list2 = list1->next;

  //need to break the link indicating the end of list1 
  list1->next = NULL;
  //the first part of the linked list
  list1 = student_list;
  //mergesort each list recursively
  list1 = mergesort(list1);
  list2 = mergesort(list2);
  // after all of the backout phase completed, do the merge 
  return merge(list1, list2);
}

struct node* merge(struct node* list1, struct node* list2) {
  struct node* list;
  struct node *curr, *prev;

  if (list1 == NULL)
    return list2;

  if (list2 == NULL)
    return list1;
  
  //find the smallest number and set it as the head of list
  if (list1->number < list2->number) {
    list = list1;
    list1 = list1->next;
  }
  else {
    list = list2;
    list2 = list2->next;
  }
  //prev now is the head of the list
  prev = list;

  while (list1 != NULL && list2 != NULL) {
    if (list1->number < list2->number) {
      curr = list1;
      list1 = list1->next;
    }
    else {
      curr = list2;
      list2 = list2->next;
    }
    //need to move the pointer to the last node that is why you need prev=curr
    prev->next = curr;
    prev = curr;
  }
  //just append when a list is empty
  while (list1 != NULL) {
    curr = list1;
    list1 = list1->next;
    prev->next = curr;
    prev = curr;
  }

  while (list2 != NULL) {
    curr = list2;
    list2 = list2->next;
    prev->next = curr;
    prev = curr;
  }

  return list;
}

struct node* insert(struct node* student_list) {
  struct node* student = malloc(sizeof(struct node));

  if (student == NULL) {
    printf("Out of memory.\n");
    exit(EXIT_FAILURE);
  }
  //as usually 
  printf("Enter student's name: ");
  read_line(student->name, NAME_LEN);
  printf("Enter student's number: ");
  if (scanf("%d", &student->number) != 1) {
    printf("Incorrect student number.\n");
    exit(EXIT_FAILURE);
  }
  //add TO Front
  student->next = student_list;

  return student;
}

//print one student
void print_student(struct node* student) {
  printf("Number: %d;  Name: %s\n", student->number, student->name);
}
//print the whole list
void print_list(struct node* student_list) {
  while (student_list != NULL) {
    print_student(student_list);
    student_list = student_list->next;
  }
}

void search(struct node* student_list) {
  int number;

  printf("Enter student number: ");
  if (scanf("%d", &number) != 1) {
    printf("Incorrect student number.\n");
    exit(EXIT_FAILURE);
  }

  while (student_list != NULL && number != student_list->number) 
    student_list = student_list->next;

  if (student_list == NULL)
    printf("Not found.\n");
  else
    print_student(student_list);
}

struct node* delete(struct node* student_list) {
  int number;
  struct node *prev, *cur;
  //prev , and cur pointers
  printf("Enter student number: ");
  if (scanf("%d", &number) != 1) {
    printf("Incorrect student number.\n");
    exit(EXIT_FAILURE);
  }
  //initialize cur to the front of the list,and prev equals to null
  for (cur = student_list, prev = NULL;
       cur != NULL && cur -> number != number;
       prev = cur, cur = cur->next)
    ;
  //alternative is
  /*
   cur=student_list;
   prev=null;
   for(cur!=NULL&&cur-> number!=number)
       prev=cur;
       cur=cur->next;
   */

  if (cur == NULL)//means empty , just return the list
    return student_list;

  if (prev == NULL)//if the number is the first that is found, just set the head to the next point.
    student_list = student_list->next;
  else//in general,make the previous node has the point of current node's next,
    prev->next = cur->next;
  //need the free cur when the node is no longer used.
  free(cur);
  return student_list;
}

int read_line(char line[], int len) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n') 
    if (i < len) 
      line[i++] = ch;
  
  line[i] = '\0';

  return i;
}

void delete_list(struct node* student_list) {
  struct node* temp;

  while (student_list != NULL) {
    temp = student_list;
    student_list = student_list->next;
    free(temp);
  }
}
//
void save(struct node* student_list) {
  char filename[FILENAME_LEN + 1];
  FILE *fp;

  printf("Enter the filename: ");
  read_line(filename, FILENAME_LEN);
  //write binary file
  fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Unable to open file %s.\n", filename);
    return;
  }
  //save the linked list into a binary file
  while (student_list != NULL) {
    fwrite(student_list, sizeof(struct node), 1, fp);
    student_list = student_list->next;
  }

  fclose(fp);
}

struct node* load() {
  char filename[FILENAME_LEN + 1];
  FILE *fp;
  struct node *student, *student_list = NULL;

  printf("Enter the filename: ");
  read_line(filename, FILENAME_LEN);
  //fails to load the content from a binary file
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Unable to open file %s.\n", filename);
    return NULL;
  }

  while (1) {
    student = malloc(sizeof(struct node));
    if (student == NULL) {
      printf("Out of memory.\n");
      exit(EXIT_FAILURE);
    }

    if (fread(student, sizeof(struct node), 1, fp) != 1) 
      break;//this will break from the while loop if nothing to be read

    student->next = student_list;
    student_list = student;
  }
  //close the file
  fclose(fp);
  return student_list;
}
