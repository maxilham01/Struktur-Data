//header files included 
#include<stdio.h> 
#include<stdlib.h>
 
//Function Prototype 
void create_node(); 
void display(); 
void delete_node(); 
//structure for node in singly linear linked list 
struct node 
{
    int data;
    struct node *next; 
}*new1,*start,*prev,*temp; 
//new1 pointer stores address of newly created node 
//start pointer stores address of start node in linked list 
//prev pointer stores address of previous node which we want to delete in linked list 
//temp pointer is used for traversing purpose 
int main() 
{
    int ans;
    char ch;
    start=NULL;
    do
    {
        printf("Singly Linear Linked List: \n");
        printf("\t1.create_node\t2.diplay\t3.delete_node\t4.exit ");
        printf("\n Enter your choice: ");
        scanf("%d",&ans);
        switch(ans)
        {
            case 1:create_node();
            break;
            case 2:display();
            break;
            case 3:delete_node();
            break;
            case 4:exit(0);
            default: printf("\n Enter correct choice");
        }
        printf("Do you want to continue press[yes(y) /no(n)] : ");
        fflush(stdin);
        scanf("%c",&ch);
    } while(ch=='y'||ch=='Y');
    return 0; 
} 

//create a node and add new node at the last in the Singly Linier Linked List
void create_node() 
{ 
    //allocate dynamic memory for a single node
    new1=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&new1->data);
    new1->next=NULL; 
    if(start==NULL) //If Linked List is empty 
    { 
        start=new1; 
    } 
    else //If Linked List having at least one node 
    { 
        temp=start; 
        while(temp->next!=NULL) //traverse the list until last node reached 
        { 
            temp=temp->next; 
        } 
        temp->next=new1; 
    } 
    printf("Node inserted at the end of Linked list=%d\n",new1->data); 
} 

//display nodes in Singly Linear Linked List 
void display() 
{
    if(start==NULL)
    {
        printf("Linked list is not created.\n");
    }
    else
    {
        temp=start; 
        printf("Data in the Singly Linear Linked List is as follows:\n"); 
        while(temp!=NULL) 
        { 
            printf("%d \t",temp->data); 
            temp=temp->next; 
        } 
        printf("\n");
    } 
} 

//delete a node from a Singly Linear Linked List 
void delete_node() 
{
    int num;
    int found=0;
    temp=start; 
    if(start==NULL) //Linked list is not created
    {
        printf("\n Linked list is not created ,first create a node.\n");
    }
    else
    {
        printf("Enter value which you want to be deleted: ");
        scanf("%d", &num);
        while((temp!= NULL)&&(found == 0)) //loop for searching the data which we want to { 
        //delete and store address of deleted node into 
        //temp pointer. 
        { 
            if(temp -> data == num) 
            { 
                found =1; 
            } 
            else 
            { 
                temp =temp->next; 
            }
        }
        if(found == 0) // If node is not found
        { 
            printf("\n Node is not present in the Linked List. \n");
        }
        else
        {   //If node is found then node which we want to delete is first // node or other than first node. 
            if(start == temp) //If deleted node is First node in Linked List 
            { 
                start = start->next; 
                temp->next=NULL; 
                free(temp); 
                temp=NULL; 
            } 
            else //If deleted node is other than first node in Linked List 
            { 
                prev=start; 
                while(prev->next!=temp) 
                {
                    prev=prev->next; 
                } 
                prev->next=temp->next; 
                temp->next=NULL;
                free(temp); 
                temp=NULL; 
            } 
        printf("Node deleted =%d\n",num);
        } 
    } 
}