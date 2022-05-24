#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nr_lines;

struct elev {
    char prenume[40];
    int ID;
    float medie;
    struct elev *next;
};
typedef struct elev Elev;

typedef struct list
{
    Elev * head;
} List;

List * create_list()
{
    List * list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

Elev *create_node(char *prenume,int ID,float medie)
{
    Elev *student=malloc(sizeof(Elev));
    strcpy(student->prenume,prenume);
    student->ID=ID;
    student->medie=medie;

    return student;
}

void reverse_list(List * list)
{
    if(list)
    {
        if(list->head)
        {
            Elev * back = NULL, * current = list->head, * next = NULL;
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

void delete_list(Elev *head)
{
    Elev * oldNode;
    while(head != NULL)
    {
        oldNode = head;
        if(head->next != NULL)
        {
            head = head->next;
            free(oldNode->prenume);
            free(oldNode);
        }
    }
}

void push_front(List *list, char *prenume, int ID, float medie)
{
    Elev * new_node = create_node(prenume, ID, medie);
    new_node->next = list->head;
    list->head = new_node;
}

void push_to_the_end(List *list, char *prenume, int ID, float medie)
{
    Elev * new_node = create_node(prenume, ID, medie);
    new_node->next = NULL;

    Elev *temp = list->head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new_node;
}

void removeSubstr (char *string, char *sub) {
    char *match;
    int len = strlen(sub);
    while ((match = strstr(string, sub))) {
        *match = '\0';
        strcat(string, match+len);
    }
}

void read_db(char *file_name, List *list)
{
    FILE * file;
    char * line = NULL;
    size_t lenght = 0;
    ssize_t read;

    file = fopen(file_name, "r");
    if (file == NULL)
        exit(EXIT_FAILURE);
    //-----------------------------------------------------------------

    //-----------------------------------------------------------------
    while((read = getline(&line, &lenght, file)) != -1) 
    {
        char * token = strtok(line, " ");
        char prenume[40];
        int ID;
        double medie;
        
        ID=atoi(token);
        token = strtok(NULL, " ");
        strcpy(prenume, token);

        token = strtok(NULL, " ");
        sscanf(token, "%lf", &medie);

        // printf("%d %s %f\n", ID, prenume, medie);

        push_front(list, prenume, ID, medie);
        nr_lines++;
    }
    //-----------------------------------------------------------------
    reverse_list(list);
    fclose(file);
}

void show_students(List *list)
{
    for(Elev * current_node = list->head; current_node; current_node=current_node->next)
    {
        printf("\nStudent[%d]: %s ", current_node->ID, current_node->prenume);
        printf("\nMedie: %f ", current_node->medie);
    }
    printf("\n");
}

void calculate_average_mark(List *list)
{
    float average=0.0;
    for(Elev * current_node = list->head; current_node; current_node=current_node->next)
    {
        average+=current_node->medie;
    }

    printf("\nMedia pe grupa este: %f/%d = %f\n", average, nr_lines, average/nr_lines);
}

void search_student(List *list, char name[20])
{
    int lenght_name=strlen(name), count=0;

    for(Elev * current_node = list->head; current_node; current_node=current_node->next)
    {
        for(int i=0; i<lenght_name; i++)
        {
            if(name[i] == current_node->prenume[i])
                count++;

            if(count == lenght_name)
            {
                printf("\nStudentul gasit: %d %s %f\n", current_node->ID, current_node->prenume, current_node->medie);
                return;
            }
        }
    }
}

void write_current_list_in_file(List *list, char file_name[20])
{
    FILE * file;
    file = fopen(file_name, "w");
    for(Elev * current_node = list->head; current_node; current_node=current_node->next)
        fprintf(file, "%d %s %f\n", current_node->ID, current_node->prenume, current_node->medie);

    fclose(file);
}

void delete_Node_from_X_position(Elev** head_ref, int position)
{
    if (*head_ref == NULL) return;
 
    Elev* temp = *head_ref;
 
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
 
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    if (temp == NULL || temp->next == NULL) return;
 
    Elev* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void delete_student(List *list, char name[20])
{
    int lenght_name=strlen(name), count=0, j=0;

    for(Elev * current_node = list->head; current_node; current_node=current_node->next)
    {
        j++;
        for(int i=0; i<lenght_name; i++)
        {
            if(name[i] == current_node->prenume[i])
                count++;

            if(count == lenght_name)
            {
                delete_Node_from_X_position(&list->head, j);
                write_current_list_in_file(list, "TI-214.txt");
                return;
            }
        }
    }
}

int menu(int option)
{
    printf("\n 1 | Adaugarea unui elev in baza de date.\n");
    printf(" 2 | Eliminarea unui elev avand un nume.\n");
    printf(" 3 | Cautarea unui elev dupa nume de familie.\n");
    printf(" 4 | Calcularea mediei pe grup.\n");
    printf(" 5 | Afisare studenti\n");
    printf(" 0 | exit.\n");
    printf(" optiunea: ");
    scanf("%d", &option);
    return option;
}

int main()
{
    List * TI_214 = create_list();
    read_db("TI-214.txt", TI_214);
    show_students(TI_214);

    int option;
    do{
        option=menu(option);

        switch(option)
        {
            case 1:
            {
                char prenume[40];
                double medie;

                printf("\nNume_Prenume -> ");
                scanf("%s", prenume);
                printf("\nMedie -> ");
                scanf("%lf", &medie);

                //adauga elev
                nr_lines++;
                push_to_the_end(TI_214, prenume, nr_lines, medie);
                write_current_list_in_file(TI_214, "TI-214.txt");
                break;
            }

            case 2:
            {
                char name[20];
                printf("\nCautare dupa nume de familie: ");
                scanf("%s",name);
                delete_student(TI_214, name);
                break;
            }

            case 3:
            {
                char name[20];
                printf("\nCautare dupa nume de familie: ");
                scanf("%s",name);
                search_student(TI_214, name);
                break;
            }

            case 4:
            {
                calculate_average_mark(TI_214);
                break;
            }

            case 5:
            {
                show_students(TI_214);
                break;
            }
        }
    }while(option!=0);

    printf("\n\n");
    return 0;
}
