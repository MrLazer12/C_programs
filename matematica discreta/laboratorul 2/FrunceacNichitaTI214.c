#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
int nr_varfuri = 0;

int lista_adiacenta[SIZE][SIZE];
int matrice_adiacenta[SIZE][SIZE];
int coada[SIZE], viz[SIZE];

//===========================================================================================================
void afisare_matrice_adiacenta()
{
	//afisare primul rand de la 0 la n
	printf("\n\tMatrice de adiacenta\n\n   |");
	for (int i = 1; i <= nr_varfuri; i++)
		printf(" %d |", i);
	printf("\n");

	//afisare delimitator
	printf("---|");
	for (int i = 1; i <= nr_varfuri; i++)
		printf("---|");
	printf("\n");

	for (int i = 0; i < nr_varfuri; i++)
	{
		printf(" %d |", i + 1);
		for (int j = 0; j < nr_varfuri; j++)
			printf(" %d |", matrice_adiacenta[i][j]);
		printf("\n");
	}
}
//============================================================================================================


//===========================================================================================================
void citire_lista_adiacenta()
{
	printf("Introduceti elementele listei:\n");
    for(int i=0; i<nr_varfuri; i++)
    {
        int k=0;
        printf("x%d: ",i+1);
        for(int j=0; j<nr_varfuri;j++)
        {
            scanf("%d",&lista_adiacenta[i][j]);
            if(lista_adiacenta[i][j]==0)
                break;
        }
     }
}
void afisare_lista_de_adiacenta_citita_din_tastatura()
{
	printf("Lista de adiacenta introdusa:\n");
	for(int i=0; i<nr_varfuri; i++)
	{
		printf("x%d: ",i+1);
		for(int j=0; j<nr_varfuri; j++)
		{
			if(lista_adiacenta[i][j]!=0)
				printf("%d_",lista_adiacenta[i][j]);
			else if(lista_adiacenta[i][j]==0){
				printf("%d",0);
				break;
			}
		}
		printf("\n");
	}
}

void tranformare_listaAdiacenta_spre_matriceAdiacenta()
{
    for(int i=0; i<nr_varfuri; i++)
    	for(int j=0; j<nr_varfuri; j++)
    		matrice_adiacenta[i][j]=0;


    for(int i=0; i<nr_varfuri; i++)
        for(int j=0; j<nr_varfuri; j++)
            if(lista_adiacenta[i][j] != 0)
                matrice_adiacenta[i][lista_adiacenta[i][j]-1] = 1;
}
//===========================================================================================================


//===========================================================================================================
//===== PARCURGEREA IN LARGIME A GRAFULUI - Algoritmul de parcurgere in latime (BFS - Breadth First Search):
//Observa??ie: Dac?? graful nu este conex, nu se vor vizita toate v??rfurile.
void parcurgere_in_largime(int varf_de_plecare)
{
	//initializez coada
    int coada[nr_varfuri], stanga=-1, dreapta=-1;
    
    coada[++stanga]=varf_de_plecare;
    ++dreapta;
    viz[varf_de_plecare]=1;//vizitez varful initial

    while(stanga>=dreapta) //parcurgerea coadei pana nu va deveni nula
    {
        varf_de_plecare=coada[dreapta++];

        for(int i=0; i<nr_varfuri; i++)
        {
            if(matrice_adiacenta[varf_de_plecare][i]==1 && viz[i]==0)
            {
                coada[++stanga]=i;//inserez in coada varful vizitat
                viz[i]=1;//marchezi varful dat ca vizitat
            }
        }
    }

    //afisez coada, cu varfurile vizitate
    for(int i=0; i<nr_varfuri; i++)
    	printf("%d ",coada[i]+1);
}
int parcurgere_in_largime2(int varf_de_plecare)
{
	int k,stanga,dreapta;

	//initializez coada
	stanga=dreapta=1;
	coada[1]=varf_de_plecare;
	viz[varf_de_plecare]=1;//vizitez varful initial

	while(stanga<=dreapta)//cat timp coada nu este vida
	{
	    k=coada[stanga];

	    for(int i=1; i<=nr_varfuri; i++)
	      	if(viz[i]==0 && matrice_adiacenta[k][i]==1)
	      	{
	        	coada[++dreapta]=i;
	        	viz[i]=1;
	      	}
	    stanga++;//sterg din coada
	}

    //afisez coada, cu varfurile vizitate
    for(int i=0; i<nr_varfuri; i++)
    	printf("%d ",coada[i]+1);

	return dreapta;//numar de varfuri vizitate
}
//===========================================================================================================


//===========================================================================================================
//===== Parcurgerea ??n ad??ncime(dfs-"Depth First Search")
//Observa??ie: Dac?? graful nu este conex, nu se vor vizita toate v??rfurile.
void parcurgere_in_adancime(int varf_de_plecare)
{
  	viz[varf_de_plecare]=1; //vizitam varful curent x
	printf("%d ", varf_de_plecare);

  	for(int i=1; i<=nr_varfuri; i++) //determinam vecinii nevizitati ai lui x
	    if(matrice_adiacenta[varf_de_plecare][i]==1 && viz[i]==0)
	    {
	    	parcurgere_in_adancime(i); //continuam parcurgerea cu vecinul curent i
	    }
}
//===========================================================================================================

int main()
{
	int nod_main;
	printf("Numar de varfuri:");
	scanf("%d", &nr_varfuri);

	citire_lista_adiacenta();
	tranformare_listaAdiacenta_spre_matriceAdiacenta();
	afisare_matrice_adiacenta();
	afisare_lista_de_adiacenta_citita_din_tastatura();


	printf("\n\nDati varful de plecare: ");
	scanf("%d", &nod_main);
	printf("Parcurgerea in largime: ");
	//parcurgere_in_largime(nod_main);
	printf("\nNumar de varfuri vizitate: %d",parcurgere_in_largime2(nod_main) );

	// golim lista varfurilor vizitate dupa parcurgerea in largime
	for(int i=0; i<SIZE; i++) 
		viz[i]=0;

	printf("\n\nDati varful de plecare: ");
	scanf("%d", &nod_main);

	printf("Parcurgerea prin adancime: ");
	parcurgere_in_adancime(nod_main);

	printf("\n");
	return 0;
}

/*
??NTREB??RI DE CONTROL
1. Defini??i structurile principale de date: liste, fire de a??teptare, stive, arbori.
	*structuri de liste - fiecare tip de list?? define??te o mul??ime de ??iruri finite de elemente de tipul declarat.
	*fire de a??teptare - Firele de a??teptare (FA, r??nd, coad??, ??ir de a??teptare) se vor folosi pentru a realiza algoritmul de prelucrare elementelor.
	*stive - se utilizeaz?? pentru a realiza algoritmul de prelucrare a elementelor dup?? principiul "ultimul sosit - primul prelucrat" (LIFO).
	*arbori - mul??ime de structuri fiecare din care va consta dintr-un obiect de baz?? numit v??rf sau r??d??cina arborelui dat ??i o list?? de elemente din mul??imea definit??,

2. Care sunt opera??iile definite pentru aceste structuri de date?
	*firele de a??teptare:
		-> Formarea unui FA vid;
		-> Verificare dac?? FA nu este vid;
		-> Alegerea primului element cu eliminarea lui din FA;
		-> Introducerea unei valori noi ??n calitate de ultim element al FA.

	*stivele sunt urm??toarele:
		-> Formarea unei stive vide;
		-> Verificare la vid;
		-> Alegerea elementului din topul stivei cu sau f??r?? eliminare;
		-> Introducerea unui element nou ??n topul stivei.

	*arbori vor fi:
		-> Formarea unui arbore trivial;
		-> Alegerea sau ??nlocuirea r??d??cinii arborelui;
		-> Alegerea sau ??nlocuirea listei r??d??cinilor subarborilor;
		-> Opera??iile de baz?? care sunt valabile pentru liste.

3. Care este principiul de organizare a prelucr??rii elementelor ??n firele de a??teptare ??i ??n stive?
	*firele de a??teptare - acestea lucreaza dupa principiul "primul sosit - primul servit".
	*stive - acestea lucreaza principiul "ultimul sosit - primul prelucrat". 

4. Defini??i no??iunea de parcurgere a grafului in adancime/largime.

5. Ce fel de structuri de date se vor utiliza ??n c??utarea ??n ad??ncime/l??rgime?
	*pentru cautarea in adancime, se va utiliza stiva
	*pentru cautarea in largime, se va utiliza fire de a??teptare
*/