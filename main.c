#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[20];
    int grades[4];
};

struct Node
{
    struct student s ;
    struct Node * prev;

};


struct Node * tail;

struct student fillStudent();
struct Node * createNode(struct student s1);
void checkchoice(int choice, struct student s1);
int printMenu();
int push(struct student s1);
struct student pop();
void printStudent(struct student s);

int main()
{
    struct student s;
    int choice;
    int flag=1;




    while (flag)
    {
        choice= printMenu();
        checkchoice(choice,s);

    }


    return 0;
}
int push(struct student s)
{
    int retval=0;
    struct Node *ptr;

    ptr = createNode(s);

    if ( ptr )
    {
        if(!tail) // The list is Empty
        {
            tail = ptr;
        }
        else // There is a list
        {
            ptr -> prev = tail;
            tail = ptr;
        }
        retval=1;
    }
    return retval;
}
struct student pop()
{

    struct student st;
    st.id=-1;
    struct Node *ptr;

    ptr = tail;

    if (tail)
    {
        st = tail -> s;
        tail = ptr -> prev;
        free(ptr);

    }
    return st;
}
struct Node * createNode(struct student s1)
{
    struct Node *ptr;

    ptr = (struct Node*)malloc(sizeof(struct Node));

    if (ptr)
    {
        ptr -> s = s1;
        ptr -> prev = NULL;
    }
    return ptr;
};
int printMenu()
{
    int choice;


    printf("\n****** MENU ******\n");
    printf("\n1.push\n");
    printf("\n2.pop\n");
    printf("\n3.exit\n");
    printf("\nEnter your choice:\n");
    scanf("%d",&choice);

    if (choice <1 || choice > 3)
    {
        printf("\nPlease Enter Valid Number\n");
    }
    return choice;
}
void checkchoice(int choice, struct student s1)
{

    int flag;

    switch(choice)

    {
    case 1:

    {
        s1 = fillStudent();
        flag = push(s1);
        if (flag)
        {
            printf("\nStudent Added Succesfuly...\n");

        }
        else
        {
            printf("\nStack is full\n");
        }
    }

    break;

    case 2:

    {

        s1 = pop();

        if (s1.id!=-1)
        {
            printStudent(s1);

        }
        else
        {
            printf("Stack is empyt");
        }
    }

    break;

    case 3:

        exit(0);

        break;



    }

}
struct student fillStudent()
{
    struct student s;
    int i;

    printf("Please Enter Student ID:\n");
    scanf("%d",&s.id);

    printf("Please Enter Studet Name:\n");
    scanf("%s",s.name);

    for (i=0; i<4; i++)
    {
        printf("Please Enter Studet Grade %d : ",i+1);
        scanf("%d",&s.grades[i]);
    }
    return s;

}
void printStudent(struct student s)
{
    int k, sum=0 ;
    printf("\nstudent id : %d \n",s.id);
    printf("student name : %s \n",s.name);

    for (k=0; k<4; k++)
    {
        printf("studet Grade %d = %d\n",k+1,s.grades[k]);
        sum+=s.grades[k];

    }
    printf("Total grades= %d\n",sum);
}

