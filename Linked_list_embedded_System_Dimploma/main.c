#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    int data;
    struct node *next;

} node_t;

void CreateFirstNode(int value);
void InsertNodeLast(int value);
void InsertNodeAfterHead(int value);
void InsertAnyPosition(int position,int value);
void DeleteAnyNode(int postion);
void DeleteFirstNode(void);
void DeleteNodeLast(void);
void DisplayLinkedList(void);
int CountElements(void);







node_t *head=NULL;


int main()
{
    int counter=0;

    printf("Linked List Program\n");

    CreateFirstNode(100);
    InsertNodeLast(200);
    InsertNodeLast(300);
    InsertNodeLast(400);
    InsertNodeLast(500);
    InsertNodeAfterHead(900);
    printf("\n");
    InsertAnyPosition(0,2000);
    DeleteFirstNode();
    DeleteNodeLast(); // thier is a wrong in this function
    DeleteAnyNode(1);


   // DeleteAnyNode(1); // thier is a wrong in this function
    printf("display of the linked list\n");
    DisplayLinkedList();
    printf("\n");
    counter=CountElements();
    printf(" Number of Elemnet is : %i\n",counter);






    return 0;
}
/////////////////////////////////////////////////////////////////
/*creat first node in linked list and return  address it  */
void CreateFirstNode(int value)
{
    node_t *FirstNode=NULL; // pointer to node


    FirstNode =(node_t *) malloc(sizeof(node_t));
    if(NULL==FirstNode)
    {
        printf("Sory NULL pointer\n");

    }
    else
    {
        FirstNode->data=value;
        FirstNode->next=NULL;
        head=FirstNode;

    }


}
////////////////////////////////////////////////////////////////
void InsertNodeLast(int value)
{
    node_t *temp_ptr=head;

    node_t *LastNode=NULL;


    LastNode =(node_t *) malloc(sizeof(node_t));
    if(NULL==LastNode)
    {
        printf("Sory NULL pointer\n");
    }
    else
    {
        while(temp_ptr->next!=NULL)
        {
            temp_ptr=temp_ptr->next;
        }
        LastNode->data=value;
        temp_ptr->next=LastNode;
        LastNode->next=NULL;

    }

}
///////////////////////////////////////////
void DisplayLinkedList(void)
{
    node_t *temp_ptr=head;
    while(temp_ptr!=NULL)
    {
        printf("%i\t",temp_ptr->data);
        temp_ptr=temp_ptr->next;
    }

}

//////////////////////////////////////////////////
void InsertNodeAfterHead(int value)
{


  node_t *firsNode=NULL;


    firsNode =(node_t *) malloc(sizeof(node_t));
    if(NULL==firsNode)
    {
      printf("Sory NULL pointer : \n");
    }
    else
    {
       firsNode->data=value;
       firsNode->next=head;
       head= firsNode;
    }

}
///////////////////////////////////////////////////////////////

int CountElements(void)
{
  node_t *temp_ptr=head;
  int count=0;


  while(temp_ptr!=NULL)
  {
    count++;
    temp_ptr=temp_ptr->next;

  }
  return count;
}
//////////////////////////////////////////////
void InsertAnyPosition(int position,int value)
{
  node_t *Node=NULL;
  node_t *temp_ptr=head;

  int i=0;


    Node =(node_t *) malloc(sizeof(node_t));
    if(NULL==Node)
    {
       printf("Sory NULL Pointer \n");
    }
    else
    {
        if((position<0)||(position>CountElements()))
        {
          printf("Sorry thier is  a worng in postion please try again  \n");
        }
        else if(position==0)
        {
         InsertNodeAfterHead(value);
        }
        else if(position==CountElements())
        {
          InsertNodeLast(value);
        }
        else
        {
            for(i=0;i<position;i++)
            {
             Node->data=value;
             Node->next=temp_ptr->next;
             temp_ptr->next=Node;
            }


        }
    }
}
/////////////////////////////////////////////////
void DeleteFirstNode(void)
{
  node_t *delete_ptr=head;

    head=delete_ptr->next;
    free(delete_ptr);

}
//////////////////////////////////////////
void DeleteNodeLast(void)
{
  node_t *first_ptr=head;
  node_t *previous_ptr=NULL;
  while(first_ptr->next!=NULL)
  {
      previous_ptr=first_ptr;
     first_ptr=first_ptr->next;

  }
  previous_ptr->next=NULL;
  free(first_ptr);


}
/////////////////////////////////////////////////////////////////////
void DeleteAnyNode(int postion)
{
  node_t *first_ptr=head;
  node_t *previous_ptr=NULL;
  int i=0;
  if((postion<0)||(postion>CountElements()))
  {
   printf("Sorry thier is  a worng in postion please try again  \n");

  }
  else if(postion==0)
  {
   DeleteFirstNode();
  }
  else if(postion==CountElements())
  {
    DeleteNodeLast();
  }
  else
  {

      for(i=0;i<postion;i++)
      {
        previous_ptr=first_ptr;
        first_ptr=first_ptr->next;

      }
      previous_ptr->next=first_ptr->next;
      free(first_ptr);
  }
}

