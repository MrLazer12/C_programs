#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
int matrice_adiacenta[SIZE][SIZE];
int matrice_incidenta[SIZE*2][SIZE];
int lista_adiacenta[SIZE][SIZE];
int nr_varfuri=0;

//===== CITIREA MATRICII DE ADIACENTA + functii tranformarea acesteea in lista adiacenta si matrice incidenta
void citirea_matrice_adiacenta()
{
	for (int i = 0; i < nr_varfuri; ++i)
	{
		for (int j = 0; j < nr_varfuri; ++j)
		{
			printf("matrice_adiacenta[%d][%d]=",i,j);
			scanf("%d", &matrice_adiacenta[i][j]);
		}
		printf("\n");
	}
}

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

void afisare_lista_de_adiacenta()
{
	FILE* fptr=fopen("lista_de_adiacenta.txt","w");

	printf("\n\tLista de adiacenta\n");
	for(int i=0; i<nr_varfuri; i++)
	{
		printf("\n| %d | ",i+1);
		fprintf(fptr,"\n| %d | ",i+1);
		for(int j=0; j<nr_varfuri; j++)
		{
			if(matrice_adiacenta[i][j] == 1) 
			{ 
				printf("%d_",j+1);
				fprintf(fptr,"%d_",j+1);
			}
		}
		printf("0");
		fprintf(fptr,"0");
	}

	fclose(fptr);
}

int numarare_arce_din_matricea_adiacenta()
{
	int arce=0;
	for(int i=0; i<nr_varfuri; i++)
		for(int j=0; j<nr_varfuri; j++)
			if(matrice_adiacenta[i][j] == 1) 
			{
				//afisare arc in forma u(iesa_din, intra_in)
				printf("\nu%d(%d,%d)",arce+1,i+1,j+1);
				arce++;
			}

	return arce;
}
void inserare_date_in_matrice_incidenta()
{
	int arc=0;
	for (int i = 0; i < nr_varfuri; i++)
		for (int j = 0; j < nr_varfuri; j++)
		{
			if(matrice_adiacenta[i][j] == 1)
			{
				matrice_incidenta[arc][i]=-1;
				matrice_incidenta[arc][j]=1;
				arc+=1;
			}
		}
}
void afisare_matrice_incidenta(int nr_arce)
{
	//afisare primul rand de la 0 la n
	printf("\n\tMatrice de incidenta\n\n   |");
	for(int i=1; i<=nr_varfuri; i++) printf(" %d |",i);
	printf("\n");

	//afisare delimitator
	printf("---|");
	for(int i=1; i<=nr_varfuri; i++) printf("---|");
	printf("\n");

	for(int i=0; i<nr_arce; i++)
	{
		if(i>=10) printf("u%d|",i+1);
		else printf("u%d |",i+1);

		for(int j=0; j<nr_varfuri; j++)
			if(matrice_incidenta[i][j] == -1) printf("%d |",matrice_incidenta[i][j]);
			else printf(" %d |",matrice_incidenta[i][j]);		
		printf("\n");
	}
}
//=============================================================================================================


//============================================================================================================
//===== CITIREA MATRICII DE INCIDENTA + functii tranformarea acesteea in lista adiacenta si matrice adiacenta
void citirea_matrice_incidenta(int nr_arce)
{
	for (int i = 0; i < nr_arce; ++i)
	{
		for (int j = 0; j < nr_varfuri; ++j)
		{
			printf("matrice_incidenta[%d][%d]=",i,j);
			scanf("%d", &matrice_incidenta[i][j]);
		}
		printf("\n");
	}
}

void transformare_matrice_incidenta_in_adiacenta(int nr_arce)
{
    //inserare valori de 0 in adiacenta
    for (int i = 0; i < nr_varfuri; ++i)
    	for (int j = 0; j < nr_varfuri; ++j)
    		matrice_adiacenta[i][j]=0;


    for (int i = 0; i < nr_arce; ++i)
    {
    	int row,col;
        for (int j = 0; j < nr_varfuri; ++j)
        {
            if(matrice_incidenta[i][j] == -1)
                row = j;
            if(matrice_incidenta[i][j] == 1)
                col = j;
        }
        matrice_adiacenta[row][col] = 1;
    }
}
//===========================================================================================================


//===========================================================================================================
//===== CITIREA lista adiacenta  + functii tranformarea acesteea in matrice incidenta si matrice adiacenta
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

void transformare_listaAdiacenta_spre_matriceIndidenta(int total_arce)
{
    for(int i=0; i<total_arce; i++)
    	for(int j=0; j<nr_varfuri; j++)
    		matrice_incidenta[i][j]=0;

    int arc = 0;
    for(int i=0; i<nr_varfuri; i++)
        for(int j=0; j<nr_varfuri; j++)
            if(lista_adiacenta[i][j] != 0)
            {
                matrice_incidenta[arc][i] = -1;
                matrice_incidenta[arc][lista_adiacenta[i][j]-1] = 1;
                arc++;
            }
}
//==================================================================

int main()
{
	int option;
	do
	{
		printf("\n\nAlegeti varianta:");
		printf("\n1. Citirea matricii de adiacenta");
		printf("\n2. Citirea matricii de incidenta");
		printf("\n3. Citirea lista de adiacenta");
		printf("\n0. exit");
		printf("\nOptiunea: "); scanf("%d", &option);

		switch(option)
		{
			case 1:
			{
				printf("Numar de varfuri:");
				scanf("%d",&nr_varfuri);			
				citirea_matrice_adiacenta();
				afisare_matrice_adiacenta();

				afisare_lista_de_adiacenta();

				inserare_date_in_matrice_incidenta();
				afisare_matrice_incidenta(numarare_arce_din_matricea_adiacenta());
				break;
			}

			case 2:
			{
				int nr_arce_din_tastatura;
				printf("Numar de arce:");
				scanf("%d",&nr_arce_din_tastatura);
				printf("Numar de varfuri:");
				scanf("%d",&nr_varfuri);

				citirea_matrice_incidenta(nr_arce_din_tastatura);
				afisare_matrice_incidenta(nr_arce_din_tastatura);

				transformare_matrice_incidenta_in_adiacenta(nr_arce_din_tastatura);
				afisare_matrice_adiacenta();

				int nr_arce_din_adiacenta = numarare_arce_din_matricea_adiacenta();
				if(nr_arce_din_tastatura == nr_arce_din_adiacenta)
					printf("\n\narce introduse: %d\narce calculate din adiacenta: %d\n | sunt egale => transformare din incidenta in adiacenta este corecta",nr_arce_din_tastatura, nr_arce_din_adiacenta);
				else
					printf("\n\narce introduse: %d\narce calculate din adiacenta: %d\n | nu sunt egale => transformare din incidenta in adiacenta este incorecta",nr_arce_din_tastatura, nr_arce_din_adiacenta);
				
				break;
			}

			case 3:
			{
				int nr_arce_din_tastatura;
				printf("Numar de varfuri:");
				scanf("%d",&nr_varfuri);

				citire_lista_adiacenta();
				afisare_lista_de_adiacenta_citita_din_tastatura();

				tranformare_listaAdiacenta_spre_matriceAdiacenta();
				afisare_matrice_adiacenta();

				transformare_listaAdiacenta_spre_matriceIndidenta(numarare_arce_din_matricea_adiacenta());
				afisare_matrice_incidenta(numarare_arce_din_matricea_adiacenta());
			}
		}
	}while(option!=0);
	
	printf("\n");
	return 0;
}
/*
INTREBĂRI DE CONTROL
1) Care sunt metodele de baza de reprezentare a unui graf?
  	metodele de bază de reprezentare a unui graf sunt:
	1. Matricea de incidenta;
	2. Matricea de adiacenta;
	3. Lista de adiacenta (incidenta).


2) Descrieti fiecare din aceste metode.
	1. Matricea de incidenta - este o matrice de dimensiune mxn, unde 
								m - numarul de muchii sau arce(pentru grafuri orientate)
								n - numarul de varfuri a grafului
		La intersectia liniei i cu j, se noteaza:
			-1 - iesa din varf
			1 - intra in varf
			2 - bucla
	

	2. Matricea de adiacenta - este o matrice de dimensiune nxn, unde n este numarul de varfuri.
		La intersectia liniei i cu j, se noteaza:
			1 - varfurile i,j sunt adiacente
			0 - varfurile i,j nu sunt adiacente
	
	3. Lista de adiacenta - este o lista cu formata din n linii(varfuri), 
							pe fiecare linie fiind scrisa varfurile adiacente.
*/