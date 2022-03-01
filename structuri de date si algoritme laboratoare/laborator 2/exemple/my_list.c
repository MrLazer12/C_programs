#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
} Node;

typedef struct List
{
    Node * head;
} List;

List * create_list()
{
    List * list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

Node * create_node(int data)
{
    Node * node = malloc(sizeof(Node));
    node->data = data;
    return node;
}

void push_front(List *list, int data)
{

    Node * new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
}

int pop_front(List *list)
{
    Node * old_node = list->head;
    int return_value = 0;
    if(old_node)
    {
        list->head = list->head->next;
        return_value = old_node->data;
        free(old_node);
    }
    return return_value;
}

int search_list(List *list, int data)
{
    int counter = 0;
    for(Node * current_node = list->head; current_node; current_node=current_node->next)
    {
        if(current_node->data==data)
        {
            return counter;
        }
        counter++;
    }
    return -1;
}


void print_list(List *list)
{
    printf("\nElementele listei:\n");
    if(list->head==NULL)
    {
        printf("\nLista este vida!\n");
        return;
    }
    for(Node * current_node = list->head; current_node; current_node=current_node->next)
    {
        printf("%d ",current_node->data);
    }
    printf("\n");
}

void clear_list(List *list)
{
    Node * current_node = list->head, * back_node =NULL;
    while(current_node)
    {
        back_node = current_node;
        current_node=current_node->next;
        free(back_node);
    }
    list->head = NULL;
}

void delete_list(List *list)
{

    clear_list(list);
    free(list);
}

int is_empty(List *a)
{
    return (a->head)?0:1;
}

void main()
{
    List * a = create_list();
    printf("\nInceputul pasului 1:\n");
    push_front(a,10);
    for(int i=0; i<5; i++)
    {
        push_front(a,rand()%100);
    }
        print_list(a);
    printf("\nSfirsitul pasului 1:\n");

    int found_position = search_list(a,10);
    if(found_position!=-1)
    {
        printf("\nA fost gasit numarul 10 pe pozitia %d!\n",found_position);
    } else
    {
        printf("\nNumarul 10 nu a fost gasit in lista!\n");
    }
    //clear_list(a);

    printf("\nInceputul pasului 2:\n");
    while(!is_empty(a))
    {
        int value = pop_front(a);
        printf("value = %d\n",value);
        //print_list(a);
    }
    printf("\nSfirsitul pasului 2:\n");
    print_list(a);
    delete_list(a);
}
