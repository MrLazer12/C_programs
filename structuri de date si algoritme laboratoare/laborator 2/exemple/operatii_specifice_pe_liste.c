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
    node->next = NULL;
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

void _print_reverse(Node * current_node)
{
    if(current_node)
    {
        _print_reverse(current_node->next);
        printf("%d ",current_node->data);
    }
}
void print_list_reverse(List * list)
{
    if(list)
    {
        printf("\nElementele listei in ordine inversa sunt:\n");
        if(list->head)
        {
            _print_reverse(list->head);
        }
        else
        {
            printf("\nLista este vida!\n");
        }
    }
}


Node * find_middle_node(List *list)
{
    if(list)
    {
        if(list->head)
        {
            Node * lazy = list->head, * fast = list->head->next;
            while(fast&&fast->next)
            {
                fast = fast->next->next;
                lazy = lazy->next;
            }
            return lazy;
        }
    }
    return NULL;
}

void reverse_list(List * list)
{
    if(list)
    {
        if(list->head)
        {
            Node * back = NULL, * current = list->head, * next = NULL;
            while(current)
            {
                next = current->next;
                current->next = back;
                back = current;
                current = next;
            }
            list->head = back;
        }
    }
}


List * merge_list(List * list1, List *list2)
{
    List * result_list = create_list();
    if(list1 && list2)
    {
        if(list1->head && list2->head)
        {
            Node * current = list1->head;
            result_list->head = current;
            while(current->next)
            {
                current  = current->next;
            }
            current->next = list2->head;
            list1->head = NULL;
            list2->head = NULL;
        }
    }
    return result_list;
}

List * divide_list(List *list, int position)
{
    List * result_list = create_list();
    if(list)
    {
        if(list->head)
        {
            if(position == 0)
            {
                result_list->head = list->head;
                list->head = NULL;
            }
            else
            {
                int counter = 0;
                Node * current = list->head;
                while(current)
                {
                    if(counter==(position-1))
                    {
                        result_list->head = current->next;
                        current->next = NULL;
                        break;
                    }
                    counter++;
                    current=current->next;
                }
            }
        }
    }
    return result_list;
}

int main()
{
    List * list1 = create_list();
    for(int i=0; i<5; i++)
    {
        push_front(list1,i);
    }
    print_list(list1);
    List * result = divide_list(list1,2);
    print_list(list1);
    print_list(result);
    delete_list(list1);
    delete_list(result);

    return 0;
}


