#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int inbeg(struct node**);
int inpos(struct node**);
int inend(struct node**);
int delbeg(struct node**);
int delpos(struct node**);
int delend(struct node**);
int findel(struct node**);
int findnextel(struct node**);
int findprevel(struct node**);
int islastel(struct node**);
int isempty(struct node**);
int dellist(struct node**);
int disp(struct node*);
int main()
{
    int i=1;
    struct node *head=NULL;
    while(i!=0)
    {
        printf("enter your choice :\t1)insert\t2)delete\t3)find\n4)findlast\t5)findempty\t6)delete list\t7)exit\n");
        int ch,ch1,ch2,ch3;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("enter choice :\t1)insert at beg\t2)insert at position\t3)insert at end.");
                printf("\n");
                scanf("%d",&ch1);
                switch(ch1)
                {
                    case 1:
                    {
                        inbeg(&head);
                        break;
                    }
                    case 2:
                    {
                        inpos(&head);
                        break;
                    }
                    case 3:
                    {
                        inend(&head);
                        break;
                    }
                    default :
                    {
                        printf("wrong input .....");
                        i=0;
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                printf("delete at :\t1)beg\t2)pos\t3)end.");
                printf("\n");
                scanf("%d",&ch2);
                switch(ch2)
                {
                    case 1:
                    {
                        delbeg(&head);
                        break;
                    }
                    case 2:
                    {
                        delpos(&head);
                        break;
                    }
                    case 3:
                    {
                        delend(&head);
                        break;
                    }
                    default :
                    {
                        printf("wrong input.....");
                        i=0;
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                printf("1)find elment\n2)findnext\n3)findprev");
                printf("\n");
                scanf("%d",&ch3);
                switch(ch3)
                {
                    case 1:
                    {
                        findel(&head);
                        break;
                    }
                    case 2:
                    {
                        findnextel(&head);
                        break;
                    }
                    case 3:
                    {
                        findprevel(&head);
                        break;
                    }
                    default :
                    {
                        printf("input is wrong....");
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                islastel(&head);
                break;
            }
            case 5:
            {
                isempty(&head);
                break;
            }
            case 6:
            {
                dellist(&head);
                break;
            }
            case 7:
            {
                printf("end");
                i=0;
                break;
            }
            default :
            {
                printf("\nwrong input...try again.");
                break;
            }
        }
        disp(head);
    }
}
int inbeg(struct node** head)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nthe data to be inserted at beg : ");
    scanf("%d",&newnode->data);
    temp=*head;
    newnode->next=temp;
    *head=newnode;
}
int inpos(struct node** head)
{
    struct node *newnode,*temp,*kemp;
    newnode=(struct node*)malloc(sizeof(struct node*));
    int pos,k=0;
    printf("\nenter the position where u want to add new node within the size : ");
    scanf("%d",&pos);
    printf("\nenter the data to be inserted in pos : ");
    scanf("%d",&newnode->data);
    temp=*head;
    while(k<pos)
    {
        kemp=temp;
        temp=temp->next;
        k++;
    }
    kemp->next=newnode;
    newnode->next=temp;
}
int inend(struct node** head)
{
    struct node *kemp,*newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nenter the data to be entered at the end : ");
    scanf("%d",&newnode->data);
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
int delbeg(struct node** head)
{
    struct node *temp;
    temp=*head;
    *head=temp->next;
    free(temp);
}
int delend(struct node** head)
{
    struct node *kemp,*temp;
    temp=*head;
    while(temp->next!=NULL)
    {
        kemp=temp;
        temp=temp->next;
    }
    kemp->next=NULL;
    free(temp);
}
int delpos(struct node** head)
{
    struct node *temp,*kemp,*jump;
    int pos,k=0;
    printf("\nenter the positon to be deleted : ",&pos);
    scanf("%d",&pos);
    temp=*head;
    while(k<pos)
    {
        jump=temp;
        temp=temp->next;
        k++;
    }
    kemp=temp->next;
    jump->next=kemp;
    free(temp);
}
int findel(struct node** head)
{
    int j,y=0,z=-1;
    struct node *temp=*head;
    printf("\nenter the element to find : \n");
    scanf("%d",&j);
    while(temp!=NULL)
    {
        y++;
        if(z!=-1)
        {
            break;
        }
        if(j==temp->data)
        {
            printf("\nelement found at %d",--y);
            z++;
        }
        temp=temp->next;
    }
    if(z==-1)
    {
        printf("\nelement not found in the list\n");
    }
}
int findnextel(struct node** head)
{
    int j,y=0,z=-1;
    struct node *temp=*head;
    printf("\nenter the element to find next: \n");
    scanf("%d",&j);
    while(temp->next!=NULL)
    {
        y++;
        if(z!=-1)
        {
            break;
        }
        temp=temp->next;
        if(j==temp->data)
        {
            temp=temp->next;
            z++;
            printf("\n%d\n",temp->data);
            temp->next=NULL;
        }
    }
}
int findprevel(struct node** head)
{
    int j,y=0,z=-1;
    struct node *temp=*head,*prev=*head;
    printf("\nenter the element to find prev: \n");
    scanf("%d",&j);
    while(temp->next!=NULL)
    {
        y++;
        if(z!=-1)
        {
            break;
        }
        if(j==temp->data)
        {
            z++;
            printf("\nthe prev element : %d\n",prev->data);
        }
        if(y>1)
        {
            prev=prev->next;
        }
        temp=temp->next;
    }
}
int islastel(struct node** head)
{
    struct node* temp=*head;
    int kg;
    printf("\nenter the value to be found : \n");
    scanf("%d",&kg);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->data==kg)
    {
        printf("\nelement found at the last of the list\n");
    }
    else
    {
        printf("\nelement not found at last of list\n");
    }
}
int isempty(struct node**head)
{
    struct node*temp=*head;
    if(temp==NULL)
    {
        printf("\nthe list is empty\n");
    }
    else
    {
        printf("\nlist is not empty\n");
    }
}
int dellist(struct node**head)
{
    struct node *temp = *head;
    struct node *kemp;
    while (temp != NULL)
    {
       kemp = temp->next;
       free(temp);
       temp = kemp;
    }
    *head = NULL;
}
int disp(struct node *head)
{
    struct node *temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}



enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
1
enter choice :	1)insert at beg	2)insert at position	3)insert at end.
1

the data to be inserted at beg : 10

10->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
1
enter choice :	1)insert at beg	2)insert at position	3)insert at end.
3

enter the data to be entered at the end : 20

10->20->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
1
enter choice :	1)insert at beg	2)insert at position	3)insert at end.
2

enter the position where u want to add new node within the size : 1

enter the data to be inserted in pos : 15

10->15->20->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
2
delete at :	1)beg	2)pos	3)end.
3

10->15->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
2
delete at :	1)beg	2)pos	3)end.
2

enter the positon to be deleted : 1

10->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
2
delete at :	1)beg	2)pos	3)end.
1

NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
1
enter choice :	1)insert at beg	2)insert at position	3)insert at end.
1

the data to be inserted at beg : 10

10->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
1
enter choice :	1)insert at beg	2)insert at position	3)insert at end.
3

enter the data to be entered at the end : 30

10->30->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
1
enter choice :	1)insert at beg	2)insert at position	3)insert at end.
2

enter the position where u want to add new node within the size : 1

enter the data to be inserted in pos : 20

10->20->30->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
3
1)find elment
2)findnext
3)findprev
1

enter the element to find : 
20

element found at 1
10->20->30->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
3
1)find elment
2)findnext
3)findprev
2

enter the element to find next: 
20

30

10->20->30->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
3
1)find elment
2)findnext
3)findprev
3

enter the element to find prev: 
20

the prev element : 10

10->20->30->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
4

enter the value to be found : 
20

element not found at last of list

10->20->30->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
4

enter the value to be found : 
30

element found at the last of the list

10->20->30->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
5

list is not empty

10->20->30->NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
6

NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
5

the list is empty

NULL
enter your choice :	1)insert	2)delete	3)find
4)findlast	5)findempty	6)delete list	7)exit
7
end
NULL
