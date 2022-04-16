#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
int matrice_adiacenta[SIZE][SIZE];
int matrice_incidenta[SIZE * 2][SIZE];
int size;

void citirea_date_tastatura_matrice_adiacenta()
{
	FILE *file_ptr_MA = fopen("matice_adiacenta.txt","r");

	int line_file[SIZE];
	while(fgets(line, SIZE, file_ptr_MA))
	{
		printf("%s",line_file);
	}

	fclose(file_ptr_MA);
}

void afisare_matrice_adiacenta()
{
	//afisare primul rand de la 0 la n
	printf("\n\tMatrice de adiacenta\n\n   |");
	for (int i = 1; i <= size; i++)
		printf(" %d |", i);
	printf("\n");

	//afisare delimitator
	printf("---|");
	for (int i = 1; i <= size; i++)
		printf("---|");
	printf("\n");

	for (int i = 0; i < size; i++)
	{
		printf(" %d |", i + 1);
		for (int j = 0; j < size; j++)
			printf(" %d |", matrice_adiacenta[i][j]);
		printf("\n");
	}
}

void afisare_lista_de_adiacenta()
{
	FILE *fptr = fopen("lista_de_adiacenta.txt", "w");

	printf("\n\tLista de adiacenta\n");
	for (int i = 0; i < size; i++)
	{
		printf("\n| %d | ", i + 1);
		fprintf(fptr, "\n| %d | ", i + 1);
		for (int j = 0; j < size; j++)
		{
			if (matrice_adiacenta[i][j] == 1)
			{
				printf("%d_", j + 1);
				fprintf(fptr, "%d_", j + 1);
			}
		}
		printf("0");
		fprintf(fptr, "0");
	}

	fclose(fptr);
}

int numarare_arce_din_matricea_adiacenta()
{
	int arce = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matrice_adiacenta[i][j] == 1)
			{
				//aflarea arc in forma u(iesa_din, intra_in)
				printf("\nu%d(%d,%d)", arce + 1, i + 1, j + 1);
				arce++;
			}

	return arce;
}

void inserare_date_in_matrice_incidenta(int nr_arce, int nr_varfuri)
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

			//cautarea buclei
			//if(i == j) matrice_incidenta[arc][i]=2;
		}
}

void afisare_matrice_incidenta(int nr_arce, int nr_varfuri)
{
	//afisare primul rand de la 0 la n
	printf("\n\tMatrice de incidenta\n\n   |");
	for (int i = 1; i <= nr_varfuri; i++)
		printf(" %d |", i);
	printf("\n");

	//afisare delimitator
	printf("---|");
	for (int i = 1; i <= nr_varfuri; i++)
		printf("---|");
	printf("\n");

	for (int i = 0; i < nr_arce; i++)
	{
		if (i >= 10)
			printf("u%d|", i + 1);
		else
			printf("u%d |", i + 1);

		for (int j = 0; j < nr_varfuri; j++)
			if (matrice_incidenta[i][j] == -1)
				printf("%d |", matrice_incidenta[i][j]);
			else
				printf(" %d |", matrice_incidenta[i][j]);
		printf("\n");
	}
}

void editare_matricea_adiacenta()
{
	int linie,coloana,valoare;

	printf("\nlinie: ");
	scanf("%d",&linie);
				
	printf("coloana: "); 
	scanf("%d",&coloana);

	printf("valoare: "); 
	scanf("%d",&valoare);

	matrice_adiacenta[linie][coloana] = valoare;
}

void draw_conditions();
void draw_menu();
int main()
{
	citirea_date_tastatura_matrice_adiacenta();
	afisare_matrice_adiacenta();

	// int nr_arce = numarare_arce_din_matricea_adiacenta();
	// printf("\narce existente: %d\n", nr_arce);

	// inserare_date_in_matrice_incidenta(nr_arce, size);
	// afisare_matrice_incidenta(nr_arce, size);

	// afisare_lista_de_adiacenta();

	draw_menu();
	int option;
	while(option!=0)
	{
		switch(option)
		{
			case 1:{
				editare_matricea_adiacenta();
				break;
			}			
		}
	}

	printf("\n\n");
	return 0;
}

void draw_menu()
{
	printf("\n\n\n|==============================================|");
	printf("\n|                     MENIU                    |");
	printf("\n|----------------------------------------------|");
	printf("\n|  1. editarea varf dupa x linie - x coloana   |");
	printf("\n|  0. exit                                     |");
	printf("\n|----------------------------------------------|");
	printf("\n|=> ");
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


3) Cum se vor realiza aceste metode în limbajul C (C++)?
	1. Matricea de incidenta - din matricea de adiacenta numar catea arce sunt in graf
							   matricea de incidenta are forma urmatoare:
									-> nr.linii = nr.arce
									-> nr.coloane = nr.varfuri
								
								algoritm
								1.Citesc matricea de adiacenta
								2.inscriu -1 la m[nr.arce][nr.arce]
								  inscriu 1 la m[nr.varfuri][nr.varfuri]

	2. Matrice de adiacenta - se vor inscriu valori aleatorii cu rand()%2 -> 0 sau 1

	3. Lista de adiacenta - se citeste matricea de adiacenta, 
							se ia varful grafului si se compara linia matricei, in care indexul corespunde valorii varfului.
							Daca valoare este egala cu 1, atunce se inscrie.
*/