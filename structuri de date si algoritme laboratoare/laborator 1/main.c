#include <stdio.h>
#include <stdlib.h>
#include <time.h>//biblioteca pentru generare numere aleatoare

struct ex1
{
    int nr1;
    char character;
};
typedef struct ex1 array_ex1;
array_ex1 *dinamic_array = NULL;

void ex1_citirea_tablou_static(int lenght, array_ex1 ex1_array[])
{
    for(int i=0; i<lenght; i++)
    {
        ex1_array[i].nr1 = rand()%20;
        ex1_array[i].character = rand()%127;
    }
    printf("\ncitirea cu rand() -> succes!\n");
}
void ex2_citirea_tablou_dinamic(int lenght)
{
    if(dinamic_array==NULL)
        dinamic_array=calloc(lenght,sizeof(dinamic_array));

    for(int i=0; i<lenght; i++)
    {
        dinamic_array[i].nr1 = rand()%20;
        dinamic_array[i].character = rand()%127;
    }
    printf("\ncitirea cu rand() -> succes!\n");
}

void ex1_afisare_tablou_static(int lenght, array_ex1 ex1_array[])
{
    for(int i=0; i<lenght; i++)
    {
        printf("\nStructArray[%d]: ",i);
        printf(" nr -> %d, ",ex1_array[i].nr1);
        printf("character -> %c",ex1_array[i].character);
    }
}

void ex1_search_position_chr(char chr,int lenght, array_ex1 ex1_array[])
{
    int found=0;
    printf("\n\t| Caracterul pentru cautare: %c\n\t| Rezultat: ", chr);

    for(int i=0; i<lenght; i++)
        if(ex1_array[i].character == chr)
        {
            printf("Pozitia primului element gasit => %d", i);
            found=1;
            break;
        }

    if(found==0) printf("Nu s-a gasit caracterul.");
}

void free_array_memory(array_ex1 dinamic_array[])
{
    free(dinamic_array);
}

int insert_to_structArray(int size, array_ex1 dinamic_array[],int position)
{
    array_ex1 x;
    x.nr1=155; x.character='Z';

    printf("\n\tThe new struct array: nr=\'%d\', character=\'%c\'",x.nr1,x.character);

    size++;
    //dinamic_array=realloc(dinamic_array,sizeof(array_ex1)*size);

    for (int i = size-1; i >= position; i--)
        dinamic_array[i] = dinamic_array[i - 1];
 
    dinamic_array[position - 1] = x;

    return size;
}
int delete_from_StructArray(int size, array_ex1 dinamic_array[], int pos)
{
    if(pos < 0 || pos > size)
    {
        printf("Pozitie incorecta! Introduceti din 1 la %d", size);
    }
    else
    {
        for(int i=pos-1; i<size-1; i++)
        {
            dinamic_array[i] = dinamic_array[i + 1];
        }

        size--;
        //dinamic_array=realloc(dinamic_array,sizeof(array_ex1)*size);
    }
    return size;
}

void sort_array(int lenght, array_ex1 unsorted_array[]);
void draw_menu();

int main()
{
    srand(time(NULL));//astfel numerele aleatoare de fiecare data vor fi diferite

    printf(" EX 1: Sa se elaboreze un program ce va aloca static un tablou unidimensional de structuri si va realiza urmatoarele functii:");
    printf("\n\t I   - citirea de la tastatura a elementelor tabloului");
    printf("\n\t II  - afisarea la consola a elementelor tabloului");
    printf("\n\t III - cautarea unui element dupa o valoarea a unui camp din structura");
    printf("\n\t       si returnarea pozitiei unde se afla primul element gasit");
    int size=4;
    array_ex1 static_array[size];
    ex1_citirea_tablou_static(size, static_array);
    ex1_afisare_tablou_static(size, static_array);


    printf("\n\n\t|Cautarea dupa camp \'caracter\' din structura si returnarea pozitiei unde se afla primul element gasit\n\t|=> ");
    ex1_search_position_chr('t', 4, static_array);
//===========================================================


// EX 2 -----------------------------------------------------
//===========================================================
    printf("\n\n\t| Exercitiul 2");
    int option;
    do {
        draw_menu();
        printf("\n\t|=> "); scanf("%d",&option);

        switch(option){
            case 1:
                ex2_citirea_tablou_dinamic(size);
                break;
            case 2:{
                if(dinamic_array == NULL){
                    printf("\t| Nu s-a facut citirea datelor!");
                }
                else {
                    ex1_afisare_tablou_static(size,dinamic_array);
                }
                
                break;
            }
            case 3:
                if(dinamic_array == NULL)
                    printf("\t| Nu s-a facut citirea datelor!");
                else
                    ex1_search_position_chr('t', size,dinamic_array);
                break;
            case 4:{
                if(dinamic_array == NULL)
                    printf("\t| Nu s-a facut citirea datelor!");
                else{
                    free_array_memory(dinamic_array);
                    dinamic_array=NULL;
                }
                break;
            }
            case 5:
                if(dinamic_array == NULL)
                    printf("\t| Nu s-a facut citirea datelor!");
                else
                    sort_array(size,dinamic_array);
                break;
            case 6:
                if(dinamic_array == NULL)
                    printf("\t| Nu s-a facut citirea datelor!");
                else
                    size = insert_to_structArray(size,dinamic_array,size+1);
                break;
            case 7:
                if(dinamic_array == NULL)
                    printf("\t| Nu s-a facut citirea datelor!");
                else
                    size = insert_to_structArray(size,dinamic_array,1);
                break;
            case 8:{
                if(dinamic_array == NULL)
                    printf("\t| Nu s-a facut citirea datelor!");
                else{
                    printf("\tPosition: ");
                    int pos;
                    scanf("%d",&pos);
                    size = insert_to_structArray(size,dinamic_array,pos);
                }
                break;
            }
            case 9:{
                if(dinamic_array == NULL)
                    printf("\t| Nu s-a facut citirea datelor!");
                else{
                    printf("\tPosition: ");
                    int pos;
                    scanf("%d",&pos);
                    size = delete_from_StructArray(size,dinamic_array,pos);
                }
                break;
            }
            default:
                printf("\t| Optiune gresita!");
        }
    } while(option!=0);
//===========================================================
    printf("\n");
    return 0;
}
void sort_array(int lenght, array_ex1 unsorted_array[])
{
    for(int i=0; i<lenght-1; i++)
        for(int j=i+1; j<lenght; j++)
            if(unsorted_array[i].nr1 > unsorted_array[j].nr1)
            {
                array_ex1 aux=unsorted_array[i];
                unsorted_array[i]=unsorted_array[j];
                unsorted_array[j]=aux;
            }
}

void draw_menu()
{
    printf("\n\t|======================================================================|");
    printf("\n\t| 1 - citirea de la tastatura a elementelor tabloului                  |");
    printf("\n\t| 2 - afisarea la consola a elementelor tabloului                      |");
    printf("\n\t| 3 - cautarea unui element dupa o valoarea a unui camp din structura  |");
    printf("\n\t|     si returnarea pozitiei unde se afla primul element gasit         |");
    printf("\n\t| 4 - eliberarea memoriei tabloului                                    |");
    printf("\n\t| 5 - sortarea elementelor dupa un camp a structurii                   |");
    printf("\n\t| 6 - inserarea unui element nou la capatul tabloului                  |");
    printf("\n\t| 7 - inserarea unui element nou la inceputul tabloului                |");
    printf("\n\t| 8 - insearea unui element la o pozitie X                             |");
    printf("\n\t|     (introdusa de la tastatura) in cadrul tabloului                  |");
    printf("\n\t| 9 - stergerea unui element de pe o pozitie X                         |");
    printf("\n\t|     (introdusa de la tastatura) din cadrul tabloului                 |");
    printf("\n\t| 0 - exit                                                             |");
    printf("\n\t|======================================================================|");
}
