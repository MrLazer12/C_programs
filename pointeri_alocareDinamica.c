#include <stdio.h>
#include <string.h>

// ==================================================================================================
void ex7(int matrice[2][2], int rand, int coloane){
    printf("\n transpunerea matrice={\n\t");
    int output[2][2];
    for(int i=0; i<rand; i++) {
        for(int j=0; j<coloane; j++){
            *(*(output + i) + j) = *(*(matrice + i) + j);
            printf("%d, ",*(*(output + i) + j));
        }
        printf("\n\t");
    }
    printf("}");
}

void ex_10_adunarea_doua_matric(int (*matrice1)[2],int (*matrice2)[2],int n){
    printf("\nsuma 2 matrice ={");
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++){
            printf("%d, ",*(*(matrice1 + i) + j) + *(*(matrice2 + i) + j));
        }
    }
    printf("\n}\n");
}

// (*matrice1)[2] - inseamna declararea unui pointer de tip tablou unidimensional de 2 elemente
void ex_10_multiplicarea_doua_matric(int (*matrice1)[2],int (*matrice2)[2],int n){
    printf("\nmultiplicarea 2 matrice ={");
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++){
            printf("%d, ",*(*(matrice1 + i) + j) * *(*(matrice2 + i) + j));
        }
    }
    printf("\n}\n");
}
// ==================================================================================================


// ==================================================================================================
int suma(int *x, int *y) {
   return *x + *y;
}

int lungimea_sir(char*p){
   int count = 0;
   while (*p != '\0') {
      count++;
      p++;
   }
   return count;
}

void copiere_sir(char *sir_sursa, char *sir_destinatie) {
    while(*sir_destinatie) {
        *sir_sursa = *sir_destinatie;
        sir_destinatie++;
        sir_sursa++;
    }
    *sir_sursa = '\0';
}

void interschimbare(int* a, int* b){
    int temporar;
    temporar = *b;
    *b = *a;
    *a = temporar;
}
// ==================================================================================================



// ==== Functii: Inserare, afisare, copiere ==================================================================================================
void inserare_in_matrice(int matrice[2][2], int rand, int coloane) {
    for(int i = 0; i < rand; i++)
        for(int j = 0; j < coloane; j++)
            // (*(matrice + i) + j este echivalenta la expresia &matrice[i][j]
            scanf("%d", (*(matrice + i) + j));
}

void afisare_matrice(int matrice[2][2], int rand, int coloane) {
    printf(" matrice = {");
    for(int i=0; i<rand; i++) {
        printf("\n");
        for(int j=0; j<coloane; j++)
            // *(*(matrice + i) + j) este echivalenta la expresia matrice[i][j]
            printf("%2d ", *(*(matrice + i) + j));
    }
    printf("\n }");
}

void copiere_matrice(int (*matrice_initiala)[2],int (*matrice_copy)[2], int rand, int coloane){
    for(int i=0; i<rand; i++)
        for(int j=0; j<coloane; j++)
            *(*(matrice_copy + i) + j) = *(*(matrice_initiala + i) + j);
}
// ========================================================================================================================



// ===== Functii pentru ex2 alocare dinamica =============================================================================================
void sortarea_randurilor(int (*matrice)[2], int n){
    int UltimulRand = n - 1;

    for(int j = 0; j < n; j++ )
    {
        for (int i = 0; i < n; i++)
            {
                float rand_curent = medie_valoare_rand(matrice,i);
                float rand_urmator = medie_valoare_rand(matrice,j);
                    if(rand_curent > rand_urmator) {
                        int t = matrice[j][i];
                        matrice[j][i] = matrice[UltimulRand - j][i];
                        matrice[UltimulRand - j][i] = t;
                    }
            }
    }

}

int medie_valoare_rand(int matrice_dinamica[2][2], int rand_index){
    float sum=0.0;
    for(int i=0; i<2; i++)
        sum+= (float)matrice_dinamica[rand_index][i];
    return sum/2;
}

// ========================================================================================================================

int main()
{
    printf("\n|=======================================================|");
	printf("\n|                Probleme pentru pointeri               |");
	printf("\n|_______________________________________________________|\n");
    printf("\n\n 1.Scrieti un program C pentru a crea, initializa si utiliza pointeri pentru printarea a diferitor variabile.");
    int* p;
    int a1=5,b=7;
    printf("\n\t a=%d, b=%d",a1,b);

    p=&a1;
    *p=2;

    p=&b;
    *p=222;
    printf("\n\t a=%d, b=%d",a1,b);
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 2.Scrieti un program C pentru a aduna doua numere folosind pointerii.\n");
    int nr1=8,nr2=9;
    printf("\t %d + %d = %d",nr1,nr2,suma(&nr1,&nr2));
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 3.Scrieti un program C pentru a interschimba valorile a doua variabile folosind pointerii.");
    printf("\n\t nr1=%d, nr2=%d",nr1,nr2);
    interschimbare(&nr1,&nr2);
    printf("\n\t nr1=%d, nr2=%d",nr1,nr2);
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 4.Scrieti un program C pentru a initializa si afisa elementele unei matrici folosind pointerii.");
    int matrix[2][2],n=2;
    printf("\n Inserare elemente in matrice. \n");
    inserare_in_matrice(matrix,n,n);

    printf("\n Afisare elemente din matrice.\n");
    afisare_matrice(matrix, n, n);
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 5.Scrieti un program C pentru a copia o matrice in alta folosind pointeri.");
    int matrix_copy[2][2];
    copiere_matrice(matrix,matrix_copy,n,n);

    printf("\nMatricea initiala\n");
    afisare_matrice(matrix, n, n);

    printf("\nMatricea copieta\n");
    afisare_matrice(matrix_copy, n, n);
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 7.Scrieti un program C pentru a transpune o matrice folosind pointeri.");
    ex7(matrix,n,n);
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 10.Scrieti un program C pentru a aduna doua matrice folosind pointeri");
    ex_10_adunarea_doua_matric(matrix,matrix_copy,n);
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 11.Scrieti un program C pentru a multiplica doua matrice folosind pointeri.");
    ex_10_multiplicarea_doua_matric(matrix,matrix_copy,n);
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 12.Scrieti un program C pentru a gasi lungimea sirului folosind pointeri.");
    printf("\n Lungimea \"%s\": %d","hello world",lungimea_sir("hello world"));
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 13.Scrieti un program C pentru a copia un sir in altul folosind pointeri.");
    char sir_copy[40];
    copiere_sir(sir_copy,"hello world!");
    printf("\n Sir: %s\n Sir copiet: %s","hello world!",sir_copy);
// ========================================================================================================================







// ========================================================================================================================
    printf("\n\n\n|=======================================================|");
	printf("\n|          Probleme pentru alocarea dinamica            |");
	printf("\n|_______________________________________________________|\n");
    printf("\n\n 1.Scrieti un program C pentru alocarea unui sir de caractere si initializarea acestuia.");
    char* sir = calloc(20, sizeof(char)); //parametrii 1 - numar de elemente ce trebu alocate, 2 - dimensiunea fiecarui element
    strcpy(sir,"hello world!");
    printf("\n sir = %s",sir);
    free(sir);
// ========================================================================================================================


// ========================================================================================================================
    printf("\n\n 2.Scrieti un program C pentru alocarea unei matrici bidimensionale si sortarea randurilor acestea in baza mediei valorilor a fiecarui rand.");
    printf("\n (la sortare se va interschimba pointerii ce indica spre randul matricei, dar nu valorile randurilor matricei)\n");

    int **matrice_dinamica = calloc(n, sizeof(int));

	inserare_in_matrice(matrice_dinamica,n,n);
    afisare_matrice(matrice_dinamica, n, n);

    sortarea_randurilor(matrice_dinamica, n);

    printf("\nMatricea sortata\n");
    afisare_matrice(matrice_dinamica, n, n);

	free(matrice_dinamica);
// ========================================================================================================================
    printf("\n");
    return 0;
}
