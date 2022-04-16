#include <stdio.h>
#include <stdlib.h>

int nr_varfuri;

// ====== IMPLEMENTAREA ALGORITM FORD ============================================================================
void drumul_minim(int j, int matricea_ponderata[][nr_varfuri], int vertex[],int ct, int ct1, int minPath[])
{
    ++ct1;
    for(int i=0; i<nr_varfuri; i++)
    {
        if (matricea_ponderata[i][j]!=0)
        {

            if ((vertex[j]-vertex[i]) == matricea_ponderata[i][j])
            {
                minPath[ct]=i;
                ++ct;
                drumul_minim(i,matricea_ponderata,vertex,ct,ct1,minPath);
            }
        }

        if (j==0) //daca sa ajuns in coloana 0 se afiseaza drumul si se opreste
        {
            printf("\nDrumul minim este: \n");
            for(i=ct-1; i>=0; i--)
            {
                printf("%d  ", minPath[i]+1);
            }
            return;
        }
    }
}


void algoritm_Ford(int matricea_ponderata[][nr_varfuri])
{
    int H[nr_varfuri], minPath[nr_varfuri], ct=0, ct1=0;

    //PAS 1: Atasam fiecarui varf numar 999 ------------------------------------------------
    for(int i = 0; i < nr_varfuri; i++){
        H[i] = 999;
    }
    H[0]=0; // varful initial = 0
    //--------------------------------------------------------------------------------------

    //PAS 2: calculam diferentele Hj - Hi pentru fiecare arc (xi, xj) ----------------------
    for(int k=0; k<nr_varfuri; k++)
    {
        for(int i=0; i<nr_varfuri; i++)
        {
            for(int j=0; j<nr_varfuri; j++)
            {
                if (matricea_ponderata[i][j] != 0)
                {
                    // micsorarea distantei dintre varful initial si xj 
                    if ((H[j]-H[i]) > matricea_ponderata[i][j])
                    {
                        H[j] = H[i]+matricea_ponderata[i][j];
                    }
                    //PASUL 2, se va repeta atata timp cat vor mai exista arce 
                    //pentru care are loc inegalitatea( Hj - Hi > matricea_ponderata[i][j] )
                }
            }
        }
    }
    //----------------------------------------------------------------------------------------

    // PASUL 3: stabilirea secventei de varfuri care va forma drumul minim -------------------
    //primul element din drum este ultimul varf
    minPath[ct]=nr_varfuri-1;
    ++ct;

    drumul_minim(nr_varfuri-1, matricea_ponderata, H, ct,ct1, minPath);    
}
//====================================================================================================




//==== IMPLEMENTAREA Algoritmul Bellman - Calaba =====================================================
void Bellman_Kalaba_recursion(int b, int f, int c, int n,int v, int mat[][nr_varfuri], int minPath[], int p) 
{
    for(int j=b;j<n;j++)
    {

        if ((mat[v-1][f]-mat[c][j])==mat[v-1][j])
        {
            minPath[p]=j;
            printf("%d ", minPath[p]+1);
            ++p;
            Bellman_Kalaba_recursion(j+1,j,j,n,v,mat,minPath,p);
        }
    }
}

void Bellman_Kalaba1(int matricea_ponderata[][nr_varfuri])
{
    int v = nr_varfuri+1, k=0, t, minPath[20];

    //START PASUL 1: presupune introducerea matricii ponderate a grafului, realizand urmatoarele subpasuri
    // 1. M(i,j) = Lij, dacă există arcul (xi, xj) de pondere Lij;
    // 2. M(i,j) = ∞, unde ∞ este un număr foarte mare (de tip întreg maximal pentru calculatorul 
    // dat), dacă arcul (xi, xj) este lipsă;
    // 3. M(i,j) = 0, dacă i = j.

    // PAS 1.2 && 1.3
    for(int i = 0; i < nr_varfuri; i++) 
    {
        for(int j = 0; j < nr_varfuri; j++) 
        {
            // PAS 1.3
            if(i == j) //3. M(i,j) = 0, dacă i = j.
            {
                matricea_ponderata[i][j] = 0;
                continue;
            }
            
            // PAS 1.2
            if(matricea_ponderata[i][j] == 0)  // dacă arcul (xi, xj) este lipsă
            {
                matricea_ponderata[i][j] = 999; // 2. M(i,j) = ∞
            }
        }
    }
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    // PAS 1.1: dacă există arcul (xi, xj) de pondere Lij, atunci M(i,j) = Lij
    for(int i=0; i<nr_varfuri; i++)
    {
        matricea_ponderata[nr_varfuri][i]=matricea_ponderata[i][nr_varfuri-1];
    }
    //END PAS 1========================================================================


    //================================================================================
    //START PASUL 2: calcularea iterativă a vectorului V
    int p=0;
    minPath[p]=0;
    printf("\n\nDrum minim: ");
    printf("%d ", minPath[p]+1);
    ++p;

    Bellman_Kalaba_recursion(1,0,0, nr_varfuri, v, matricea_ponderata, minPath, p);
    //END PAS 2========================================================================
}
//====================================================================================================

int main()
{
    printf("numar de varfuri: "); scanf("%d",&nr_varfuri);

    int matricea_ponderata[nr_varfuri][nr_varfuri];

    // Inserarea in matricea ponderata ------------------------------
    for(int i=0; i<nr_varfuri; i++)
        for(int j=0; j<nr_varfuri; j++)
            scanf("%d",&matricea_ponderata[i][j]);
    //----------------------------------------------------------------

    printf("\n---- ALGORITMUL FORD ---------------\n");
    algoritm_Ford(matricea_ponderata);


    //=====================================================================
    // --- Bellman - Calaba
    printf("\n\n\n---- ALGORITMUL Bellman - Calaba ----");
    Bellman_Kalaba1(matricea_ponderata);
    printf("\n");
    return 0;
}
