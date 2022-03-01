#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lungimea_listei=0;

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


int is_empty(List *a)
{
    return (a->head)?0:1;
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
void eliberarea_memoriei(List *list)
{
    clear_list(list);
    free(list);
}

void draw_menu();
void lista_citirea_din_tastatura(List *list)
{
    for(int i=0; i<lungimea_listei; i++)
    {
    	int number;
        scanf("%d",&number);
        push_front(list, number);
    }
}
void sortarea_listei(List *list)
{
    Node *c; int ord,aux;
    do
    {
        c=list->head;
        ord=1;
        while(c->next)
        {
                if(c->data > c->next->data)
                    {
                        aux=c->data;
                        c->data=c->next->data;
                        c->next->data=aux;
                        ord=0;
                    }
            c=c->next;
        }
    } while(ord==0);
}
void inserare_la_sfarsit(List *list, int number)
{
    struct Node *newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->next = NULL;

    struct Node *temp = list->head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}
void insert_at_X_position(Node** current, int pos, int data)
{
    if (pos < 1 || pos > lungimea_listei + 1)
        printf("Invalid position!\n");
    else {
        while (pos--) {
            if (pos == 0) {
                Node* temp = create_node(data);
                temp->next = *current;

                *current = temp;
            }
            else
              // Alocare pointer dublu pentru a indica la
              // pointer indicând la adresa următoarului nod
              current = &(*current)->next;
        }
        lungimea_listei++;
    }
}
void delete_Node_from_X_position(Node** head_ref, int position)
{
    // daca lista este nula
    if (*head_ref == NULL)
        return;
 
    // memorarea capul listei
    Node* temp = *head_ref;
 
    if (position == 0) {
        *head_ref = temp->next;
        // stergerea capul vechi al listei
        free(temp);
        return;
    }
 
    // Găsirea nodului anterior al nodului care urmează să fie șters
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    // Dacă poziția este mai mare decât numărul de noduri
    if (temp == NULL || temp->next == NULL)
        return;
 
    // Nodul temp->next este nodul pentru a fi sters
    // memorez pinterul la urmatorul nod pentru a fi sters
    Node* next = temp->next->next;

    // Eliberarea nodului din lista
    free(temp->next);
 
    // ruperea legaturii a nodului sters din lista
    temp->next = next;
}


int main()
{
    List * my_list = create_list();

    int option;
    do
    {
        draw_menu();
        printf("\noption-> ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                printf("Dati numar de elemente in lista: ");
                scanf("%d",&lungimea_listei);                
                lista_citirea_din_tastatura(my_list);
                break;
            }

            case 2:
            {
                if(!is_empty(my_list))
                    print_list(my_list);
                else
                    printf("Lista este goala!");
                break;
            }

            case 3:
            {
                if(!is_empty(my_list))
                {
                    int data;
                    printf("valoare spre cautare -> ");
                    scanf("%d",&data);


                    if(search_list(my_list,data) != 0 )
                        printf("valoarea %d a fost gasita!\nsearch result: %d", data, search_list(my_list,data) );
                    else
                        printf("valoarea %d nu a fost gasita!\nsearch result: %d", data, search_list(my_list,data) );
                }
                else
                    printf("Lista este goala!");
                break;              
            }

            case 4:
            {
                if(my_list != NULL)
                {
                    eliberarea_memoriei(my_list);
                    my_list = create_list();
                }
                else
                    printf("lista is null");
            }

            case 5:
            {
                if(!is_empty(my_list))
                {
                    sortarea_listei(my_list);
                }
                else
                    printf("Lista este goala!");
                break;  
            }

            case 6:
            {
                if(!is_empty(my_list))
                {
                    int number;
                    scanf("%d",&number);
                    inserare_la_sfarsit(my_list,number);
                }
                else
                    printf("Lista este goala!");
                break;                
            }

            case 7:
            {
                if(!is_empty(my_list))
                {
                    int number;
                    scanf("%d",&number);
                    push_front(my_list, number);
                }
                else
                    printf("Lista este goala!");
                break;                
            }

            case 8:
            {
                if(!is_empty(my_list))
                {
                    int position;
                    printf("pozitia: ");
                    scanf("%d", &position);

                    int number;
                    printf("numar: ");
                    scanf("%d",&number);

                    insert_at_X_position(&my_list->head, position, number);
                }
                else
                    printf("Lista este goala!");
                break;  
            }

            case 9:
            {
                if(!is_empty(my_list))
                {
                    int position;
                    printf("pozitia: ");
                    scanf("%d", &position);

                    delete_Node_from_X_position(&my_list->head, position);
                }
                else
                    printf("Lista este goala!");
                break;  
            }

            case 10:
            {
                if(!is_empty(my_list))
                    reverse_list(my_list);
                else
                    printf("Lista este goala!");
                break;
            }

            case 11:
            {
                if(!is_empty(my_list))
                    clear_list(my_list);
                else
                    printf("Lista este goala!");
                break;
            }
        }
    }while(option!=0);

    printf("\n");
    return 0;
}

/*
    1.Să se elaboreze un program ce va aloca dinamic o listă simplu înlățuită de structuri și va realiza următoarele funcții, 
    unde funcțiile date reprezintă opțiuni organizate într-un meniu în cadrul programului:
*/
void draw_menu()
{
	printf("\n------------------------------MENIU----------------------------------------------------------");
	printf("\n 1. citirea de la tastatură a elementelor listei;");
	printf("\n 2. afișarea la consolă a elementelor listei;");
	printf("\n 3. căutarea unui element după o valoarea a unui cîmp din structură");
    printf("\n    și returnarea poziției unde se află primul element găsit;");
	printf("\n 4. eliberarea memoriei listei;");
	printf("\n 5. sortarea elementelor după un cîmp a structurii;");
	printf("\n 6. inserarea unui element nou la capătul listei;");
	printf("\n 7. inserarea unui element nou la începutul listei;");
	printf("\n 8. insearea unui element la o poziție X (introdusă de la tastatură) în cadrul listei;");
	printf("\n 9. ștergerea unui element de pe o poziție X ( introdusă de la tastatură) din cadrul listei;");
	printf("\n10. inversarea ordinei elementelor din listă;");
	printf("\n11. curățirea listei.");
	printf("\n-----------------------------------------------------------------------------------------------");
}