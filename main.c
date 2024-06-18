#include<stdio.h>
#include<stdlib.h>
#define si 100
#define max 50
int top=-1,rear=-1,front=-1;
int ar[si],arr[max];
void array();
void stack();
void queue();
void linked();
void push();
void pop();
void show();
void insert();
void delete();
void display();
void main()
{
    int choice;
    while(choice!=5)
    {
        printf("\n-------Types of insertion-------");
        printf("\nPress 1 For insertion in array");
        printf("\nPress 2 For insertion in stack");
        printf("\nPress 3 For insertion in queue");
        printf("\nPress 4 For insertion in linked list ");
        printf("\nPress 5 EXIT");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
        case 1:
            array();
            break;
        case 2:
            stack();
            break;
        case 3:
            queue();
            break;
        case 4:
            linked();
            break;
        case 5:
            exit(1);
        default:
            printf("\n\tINVALID OPTION !!");
        }
        printf("\n\n\tPress any key to return to main menu");
        getch();
    }
}
array()
{
    int size,i,ch;
    char lp='y';
    while(lp=='y')
    {
        printf("Enter the size of array: ");
        scanf("%d",&size);
        printf("\nPress 1 For simple insertion");
        printf("\nPress 2 For insertion at a given location");
        printf("\nEnter your choice");
        scanf("%d",&ch);
        if(ch==1)
        {
            int A[100];
            printf("\nEnter the elements in array: ");
            for(i=0;i<size;i++)
                {
                    scanf("%d",&A[i]);
                }
            printf("\nElements in the array are:");
            for(i=0;i<size;i++)
                {
                    printf("\n%d",A[i]);
                }
        }
        else if(ch==2)
        {
            int data,pos,B[100];
            printf("\nEnter the elements in array : ");
            for(i=0;i<size;i++)
            {
                scanf("%d",&B[i]);
            }
            printf("\nEnter the location where you want to place the element : ");
            scanf("%d",&pos);
            if(pos>size)
            {
                printf("INVALID LOCATION !!!");
            }
            else
            {
                printf("\nEnter the element which you want to insert at your required location: ");
                scanf("%d",&data);
                for(i=size-1;i>=pos-1;i--)
                {
                    B[i+1]=B[i];
                }
                B[pos-1]=data;
                size++;
                printf("\nArray after insertion of element : ");
                for(i=0;i<size;i++)
                {
                    printf("\n%d",B[i]);
                }
            }
        }
        else
        {
            printf("You entered the wrong choice!!!");
        }
        printf("\nPress 'y' to run again array module or press any key to go to main menu:");
        scanf("%s",&lp);
        }
}
void linked()
{
    char lp='y';
    while(lp=='y')
    {
        struct node
        {
            int data;
            struct node *next;
        };
        struct node *head, *temp, *newnode;
        int i,a,ch;
        printf("\nEnter the number of element:");
        scanf("%d",&a);
        head = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node 1: ");
        scanf("%d", &head->data);
        head->next = NULL;
        temp = head;
        for (i = 2; i <=a; i++)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter data for node %d: ", i);
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            temp->next = newnode;
            temp = temp->next;
        }
        printf("\nPress 1 For insertion at the beginning");
        printf("\nPress 2 For insertion at the end");
        printf("\nPress 3 For insertion after the given location");
        printf("\nEnter your choice :");
        scanf("%d",&ch);
        if(ch==1)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter data : ");
            scanf("%d",&newnode->data);
            newnode->next=head;
            head=newnode;
        }
        else if(ch==2)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter data : ");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        else if(ch==3)
        {
            int pos,j=1;
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter location where you want to insert : ");
            scanf("%d",&pos);
            if(pos>a)
            {
                printf("INVALID LOCATION");
            }
            else
            {
                temp=head;
                while(j<pos)
                {
                    temp=temp->next;
                    j++;
                }
                newnode=(struct node*)malloc(sizeof(struct node));
                printf("\nEnter data : ");
                scanf("%d",&newnode->data);
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
        else
        {
            printf("INVALID OPTION !!");
        }
        printf("\nThe linked list is: ");
        temp = head;
        while (temp != NULL)
        {
            printf("\n%d ", temp->data);
            temp = temp->next;
        }
        printf("\nPress 'y' to run again linked list module or press any key to go to main menu:");
        scanf("%s",&lp);
    }
}
stack()
{
        while(1)
        {
            int chh;
            printf("\n1.Push\n2.Pop\n3.Display\n4.EXIT");
            printf("\nEnter your choice : ");
            scanf("%d",&chh);
            switch(chh)
            {
                case 1:
                    push();
                    break;

                case 2:
                    pop();
                    break;

                case 3:
                    show();
                    break;
                case 4:
                    exit(0);
                default :
                    printf("\nINVALID CHOICE");

            }
        }
}
void push()
{
    int x;
    if(top==si-1)
    {
        printf("OVERFLOW!!!");
    }
    else
    {
        printf("Enter the element : ");
        scanf("%d",&x);
        top=top+1;
        ar[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\nUNDERFLOW!!!");
    }
    else
    {
        printf("Popped element:%d",ar[top]);
        top=top-1;
    }
}
void show()
{
    int i;
    if(top==-1)
    {
        printf("\nUNDERFLOW!!!");
    }
    else
    {
        printf("Elements present in stack : ");
        for(i=top;i>=0;--i)
        {
            printf("\n%d",ar[i]);
        }
    }
}

void queue()
{
    int chh;
    while (1)
    {
        printf("\n1.Insert element to queue ");
        printf("\n2.Delete element from queue ");
        printf("\n3.Display all elements of queue ");
        printf("\n4.EXIT");
        printf("\nEnter your choice : ");
        scanf("%d", &chh);
        switch(chh)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        }
    }
}
void insert()
{
    int item;
    if(rear == max- 1)
    {
        printf("QUEUE OVERFLOW\n");
    }
    else
    {
        if(front== - 1)
        {
            front=0;
        }
        printf("Insert the element in queue : ");
        scanf("%d", &item);
        rear=rear+1;
        arr[rear]=item;
    }
}
void delete()
{
    if(front==-1 || front>rear)
    {
        printf("QUEUE UNDERFLOW\n");
    }
    else
    {
        printf("Element deleted from queue is : %d\n",arr[front]);
        front=front+1;
    }
}
void display()
{
    int i;
    if(front == - 1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("Element in Queue is : ");
        for(i=front;i<=rear;i++)
        {
            printf("\n%d ",arr[i]);
        }
    }
}

