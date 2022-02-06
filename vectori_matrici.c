#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int vector[8];
int length_array = sizeof(vector)/sizeof(vector[0]);

int read_array_values(int index, int array_limit){
	if(index>array_limit)
		return;
	else {
		scanf("%d", &vector[index]);
		return read_array_values(index+1, array_limit);
	}
}

int show_array_values(int index, int array_limit){
	if(index>array_limit)
		return;
	else {
		printf("%d, ", vector[index]);
		return show_array_values(index+1, array_limit);
	}
}

//==================================================================
void ex2(){
	printf("\n\tNumere negative din vectorul citit: ");
		for (int i=0; i<=length_array; i++)
			if (vector[i] < 0)
				printf("%d, ", vector[i]);
}


int ex3(int index, int array_limit){
	if(index>array_limit)
		return 0;
	else
		return vector[index]+ex3(index+1, array_limit);
}


int ex_4_a(int index, int array_limit){
	if(index>array_limit)
		return;
	else {
		int max = ex_4_a(index+1, array_limit);

		if(vector[index]>max)
			return vector[index];
		else
			return max;
	}
}


int ex_4_b(int index, int array_limit){
	if(index>array_limit)
		return;
	else {
		int min = ex_4_b(index+1, array_limit);

		if(vector[index]<min)
			return vector[index];
		else
			return min;
	}
}


void ex5(){
    int max2=0;
    for(int i=0; i<length_array; i++)
        if(max2<vector[i] && vector[i]!=ex_4_a(0, length_array))
            max2=vector[i];

	printf("\n\tAl doilea numar maximal: %d", max2);
}


void ex6(){
    int par=0,impar=0;
    for(int i=0; i<length_array; i++)
        if(vector[i]%2 == 0) par++;
        else impar++;
	printf("\n\tNumarul total de elemente pare: %d\n\tNumarul total de elemente impare %d", par, impar);
}


void ex7(){
    int nr_negative=0;
    for(int i=0; i<length_array; i++)
        if(vector[i] < 0) nr_negative++;
	printf("\n\tNumar total de numare negative din vectorul citit: %d", nr_negative);
}


void ex8(){
    int vector_copy[length_array];
    for (int i=0; i<length_array; i++)
        vector_copy[i]=vector[i];

	show_array(vector_copy, length_array, "array_copy");
}


void ex9(){
    int nr, posistion;

    printf("\n\tPozitia: "); scanf("%d", &posistion);
    printf("\n\tElementul: "); scanf("%d", &nr);

    if(posistion > length_array || posistion < 0)
        printf("\nPozitia trebuie sa fie de la 1 la %d!", length_array);
    else {
        for(int i=length_array; i>=posistion; i--)
            vector[i] = vector[i-1];

        vector[posistion-1] = nr;
        length_array++;

        show_array(vector, length_array, "array");
    }
}


void ex10(){
    int position;
    show_array(vector, length_array, "vector");
    printf("\n\tIndexul: "); scanf("%d", &position);

    if(position > length_array || position < 0)
        printf("Incorect! pozitia => 0 la %d", length_array);
    else {
        for(int i=position; i<length_array-1; i++)
            vector[i]=vector[i+1];

        length_array--;

        printf("\nVectorul dupa stergerea elementului cu indexul: %d\n", position);
        show_array(vector, length_array, "vector");
    }
}


void ex11(){
    int count;
    for (int i=0; i<length_array; i++){
        count=0;
        for (int j=0; j<=length_array; j++)
            if (vector[i] == vector[j])
                count++;
        printf("\n\tvector[%d] => %d se repeta de %d",i,vector[i],count);
    }
}


void ex12(){
    int k;
    for(int i=0; i<length_array; i++) {
        int count=0;

        for(int j=0,k=length_array; j<k+1; j++)
            if(i!=j)
                if(vector[i]==vector[j])
                    count++;

        if(count==0)
        printf("%d, ",vector[i]);

    }
}


void ex13(){
    int k=0, count=0;
    for(int i=0; i<length_array; i++) {
        for(int j=0,k=length_array; j<k+1; j++)
            if (i!=j)
                if(vector[i]==vector[j])
                count++;
    }
    printf("\n\tNumar total de elemente duplicate -> %d",count);
}


void ex14(){
    printf("\tarray={");
    show_array_values(0, length_array);
    printf("}");

    for(int i=0; i<length_array; i++) {
        for(int j=i+1; j<length_array; j++) {
            if(vector[i] == vector[j]) {
                for(int k=j; k < length_array-1; k++)
                    vector[k] = vector[k+1];


                length_array--;
                j--;
            }
        }
    }
    printf("\n\tVectorul obtinut dupa stergerea elementelor dublicate:\n\tarray = { ");
    show_array_values(0, length_array);
    printf("}");
}


void ex15(){
    int a[5],b[5],c[10];
    int a_lenght=sizeof(a)/sizeof(a[0]);
    int b_lenght=sizeof(b)/sizeof(b[0]);
    int c_lenght=sizeof(c)/sizeof(c[0]);
    int k=0;

    //inserarea valori
    for(int i=0; i<a_lenght; i++){
        a[i]=rand()%10;
        c[k]=a[i];
        k++;
    }

    for(int i=0; i<b_lenght; i++){
        b[i]=rand()%10;
        c[k]=b[i];
        k++;
    }
    //=============================


    show_array(a,a_lenght,"-> a");
    show_array(b,b_lenght,"-> b");
    show_array(c,c_lenght,"-> c");
}
void show_array(int vector[], int lenght_vector, char nume[20]){
    printf("\t%s={",nume);
    for(int i=0; i<lenght_vector; i++)
        if(i==lenght_vector-1)
            printf("%d ", vector[i]);
        else
            printf("%d, ", vector[i]);
    printf("}\n");
}


void ex16(){
    show_array(vector, length_array,"vector");

    for (int min=0, max=length_array-1; min<max; min++, max--) {
        int aux=vector[min];
        vector[min]=vector[max];
        vector[max]=aux;
    }

    show_array(vector, length_array,"vector inversat");
}

void ex17(){
    printf("20.Scrieti un program C pentru a sorta separat elementele pare si impare ale tabloului.\n");
    int par[20], impar[20];
    //Alegerea numere pare =============
    int k=0;
    for (int i=0; i<length_array; i++)
        if(vector[i]%2 == 0){
            par[k]=vector[i];
            k++;
        }
    show_array(par, k,"par");
    ex_20_sort(par, k);
    show_array(par, k,"sortat par");
    //==================================

    // Alegerea numere impare ==========
    k=0;
    for (int i=0; i<length_array; i++)
        if(vector[i]%2 != 0){
            impar[k]=vector[i];
            k++;
        }
    show_array(impar, k,"impar");
    ex_20_sort(impar, k);
    show_array(impar, k,"sortat impar");
    //==================================
}

void ex_20_sort(int a[], int lenght_a) {
    int aux;

    for (int i=0; i<lenght_a; i++) {
        for (int j=i+1; j<lenght_a; j++) {
            if (a[i]>a[j])  {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
}


void ex18(){
    printf("\tarray={");
    show_array_values(0, length_array);
    printf("}");

    int searched_elemenet=8;
    printf("\n\tElementul %d, pozitiile(indexul) gasite: ",searched_elemenet);
    for(int i=0; i<length_array; i++)
        if(vector[i] == searched_elemenet)
            printf("%d ",i);
}


void ex19_sort_crescator(int a[], int lenght_a){
    int aux;
    for (int i=0; i<lenght_a; ++i) {
        for (int j=i+1; j<lenght_a; ++j) {
            if (a[i]>a[j])  {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
}

void ex19_sort_descrescator(int a[], int lenght_a){
    int aux;
    for (int i=0; i<lenght_a; ++i) {
        for (int j=i+1; j<lenght_a; ++j) {
            if (a[i]<a[j])  {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
}



int show_matrix(int a[5][5], int length_matrix, char name[20]){
    printf("%s={", name);
    for(int i=0; i<length_matrix; i++){
        printf("\n\t");
        for(int j=0; j<length_matrix; j++)
            printf("%d, ",a[i][j]);
    }
    printf("\n}\n");
}

void Ex12(){
    int n=5;
    int m_t_superioara[5][5]={
                                {8,5,6,5,8},
                                {0,5,6,4,9},
                                {0,0,1,1,4},
                                {0,0,0,9,5},
                                {0,0,0,0,5}
                            };
    show_matrix(m_t_superioara,n,"m_t_superioara");

    int true_or_false=1, sum=0;
    for(int i=1; i<=n-1; i++)
        for(int j=0; j<=i-1; j++)
            if(m_t_superioara[i][j]!=0)
                true_or_false=0;

    if(true_or_false==0)
        printf("matricea nu este triunghiulara superior");
    else{
        for(int i=1; i<n; i++)
            for(int j=0; j<n; j++)
                sum+=m_t_superioara[i][j];
        printf("Suma matricei triunghiulare superioare: %d",sum);
    }
}

void Ex13(){
    int n=5, sum=0;
    int m_t_inferioara[5][5]={
                                {8,0,0,0,0},
                                {3,5,0,0,0},
                                {4,2,1,0,0},
                                {8,5,6,9,0},
                                {8,5,6,9,2}
                            };
    show_matrix(m_t_inferioara,n,"m_t_inferioara");

    int true_or_false=1;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(m_t_inferioara[i][j]!=0)
                true_or_false=0;

    if(true_or_false!=0){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                sum+=m_t_inferioara[i][j];
        printf("Suma matricei triunghiulare inferiora: %d",sum);
    }
    else
        printf("Matricea nu este triunghiulara inferiora");
}

void Ex15(){
    int matrice[3][3] = {
                            {1,6,9},
                            {1,2,6},
                            {3,6,1}
                        };
    printf("matrix={");
    for(int i=0; i<3; i++){
        printf("\n\t");
        for(int j=0; j<3; j++)
            printf("%d, ",matrice[i][j]);
    }
    printf("\n}\n");

    int i=matrice[0][0], j=matrice[0][1], k=matrice[0][2];
    int determinant = i*(matrice[1][1]*matrice[2][2] - matrice[1][2]*matrice[2][1])
                      -
                      j*(matrice[1][0]*matrice[2][2] - matrice[2][0]*matrice[1][2])
                      +
                      k*(matrice[1][0]*matrice[1][1] - matrice[1][0]*matrice[2][1]);

    printf("\tDeterminantul matricei este => %d", determinant);
}

void Ex17(){
    int m_rarefiata[3][3] = {
                        {1,0,0},
                        {0,1,0},
                        {0,0,1},
                      };
    int n=3,count=0, total_elemente=n*n;

    printf("\n? matrice rarefiata={");
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++)
            printf("%d, ",m_rarefiata[i][j]);
    }
    printf("\n}\n");


    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        if(m_rarefiata[i][j] == 0)
            count++;

    float procente_100_count=((float)count/9)*100;

    printf("\n\tNumar de elemente totale in matrice: %d", total_elemente);
    printf("\n\tNumar total de 0 in matrice: %d", count);
    printf("\n\tProcentajul de 0 in matrice: %f", procente_100_count);


    if(procente_100_count>=70)
        printf("\n\t=> matricea este rarefiata");
    else
        printf("\n\t=> matricea nu este rarefiata");
}

int Ex19(int a[5][5], int n){
    int rot_stanga[5][5];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            rot_stanga[i][j]=a[j][n-1-i];

    printf("rotirea stanga={");
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++)
            printf("%d, ",rot_stanga[i][j]);
    }
    printf("\n}\n");
}

int Ex20(int a[5][5], int n){
    int rot_dreapta[5][5];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            rot_dreapta[i][j]=a[n-1-j][i];

    printf("rotirea dreapta={");
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++)
            printf("%d, ",rot_dreapta[i][j]);
    }
    printf("\n}\n");
}

int Ex21(int a[5][5],int n){
    int rot_sus[5][5];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        rot_sus[i][j]=a[n-1-i][n-1-j];

    printf("rotirea sus={");
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++)
            printf("%d, ",rot_sus[i][j]);
    }
    printf("\n}\n");
}

int main() {
	printf("\n_______________________________________________________");
	printf("\n|       Probleme pentru tablouri unidimensionale      |");
	printf("\n|_____________________________________________________|");

	printf("\n\n1.Scrieti un program C pentru a citi si a imprima elementele unui tablou. - folosind recursia.\n");
		read_array_values(0, length_array);
	printf(" array={ ");
		show_array_values(0, length_array);
	printf("}");
	printf("\n marimea vectorului => %d", length_array);


    printf("\n\n2. Scrieti un program C pentru a imprima toate elementele negative dintr-un tablou.");
	ex2();

	printf("\n\n3.Scrieti un program C pentru a gasi suma tuturor elementelor tabloului. - folosind recursia.");
	printf("\n\tSuma tuturor elementelor tabloului: %d", ex3(0, length_array));


	printf("\n\n4.Scrieti un program C pentru a gasi elementul maxim si minim intr-un tablou. - folosind recursia.");
	printf("\n\tElementul maxim: %d", ex_4_a(0, length_array));
	printf("\n\tElementul minim: %d", ex_4_b(0, length_array));


	printf("\n\n5.Scrieti un program C pentru a gasi al doilea cel mai mare element dintr-un tablou.");
    ex5();

	printf("\n\n6.Scrieti un program C pentru a numara numarul total de elemente pare si impare dintr-un tablou.");
    ex6();


	printf("\n\n7.Scrieti un program C pentru a numara numarul total de elemente negative dintr-un tablou.");
    ex7();


	printf("\n\n8.Scrieti un program C pentru a copia toate elementele dintr-un tablou in alt tablou.\n");
    ex8();

    printf("\n\n9.Scrieti un program C pentru a insera un element intr-un tablou pe o pozitie data de la tastatura.");
	/*  ce am inteles din conditia problemei?
        avem vector a={1,2,3,5}
        se introduce pozitia 1, si elementul=5
        pe ecran trebuie sa arate urmatoarea a={1,5,2,3,5},
        adica am inserat valoare 5 in pozitia 1, neschimband si nestergand valorile initiale
    */
	ex9();


    printf("\n\n10.Scrieti un program C pentru a sterge un element dintr-un tablou in pozitia specificata de la tastatura\n\n");
    ex10();


    printf("\n\n11.Scrieti un program C pentru a numara frecventa relativa fiecarui element dintr-un tablou.");
    ex11();


    printf("\n\n12.Scrieti un program C pentru a imprima toate elementele unice din tablou.\n\tElemente unice: ");
    ex12();


    printf("\n\n13.Scrieti un program C pentru a numara numarul total de elemente duplicate dintr-un tablou.");
    ex13();


    printf("\n\n14.Scrieti un program C pentru a sterge toate elementele duplicate dintr-un tablou.\n");
    ex14();


    printf("\n\n15.Scrieti un program C pentru a imbina doua tablouri in al treilea tablou.\n");
    ex15();


    printf("\n\n16.Scrieti un program C pentru a inversa ordinea elementelor unui tablou.\n");
    ex16();


    printf("\n\n17.Scrieti un program C pentru a pune elemente pare si impare ale unui tablou in doua tablouri separate.\n");
    ex17(); // ex 17 si 20


    printf("\n\n18.Scrieti un program C pentru a cauta un element din tablou si afiza pozitiile gasite.\n");
    ex18();


    printf("\n\n19.Scrieti un program C pentru a sorta elementele tabloului in ordine crescatoare sau descrescatoare.\n");
    printf("array={");
        show_array_values(0,length_array);
    printf("}\n");
    printf("\tSortare crescator:\n\t");
        ex19_sort_crescator(vector,length_array);
        show_array_values(0,length_array);

    printf("\n\tSortare descrescator:\n\t");
        ex19_sort_descrescator(vector,length_array);
        show_array_values(0,length_array);



    printf("\n\n21.Scrieti un program C pentru a roti la stanga un tablou, operatia ROL.\n");
        printf("\tVector Original:\n\t");
        show_array(vector,length_array,"vector");
    // rotirea la stanga un tablou cu o pozitie
        int temp=vector[0];
        for(int i=0; i<length_array-1; i++)
            vector[i]=vector[i+1];

        vector[length_array-1]=temp;
    printf("\tVector dupa operatia ROL:\n\t");
        show_array(vector,length_array,"vector");



    printf("\n\n22.Scrieti un program C pentru a roti dreapta un tablou, operatia ROR.\n");
    printf("\tVector Original:\n\t");
        show_array(vector,length_array,"vector");

        temp=vector[length_array-1];
        for(int i=length_array-1; i>0; i--)
            vector[i]=vector[i-1];
        vector[0]=temp;

    printf("\tVector dupa operatia ROR:\n\t");
        show_array(vector,length_array,"vector");


// =====================================================================================================
// =====================================================================================================
    printf("\n_______________________________________________________");
	printf("\n|       Probleme pentru tablouri bidimensionale       |");
	printf("\n|_____________________________________________________|\n\n");

    int matrice[5][5],matrice2[5][5];
    int n=5;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            matrice[i][j]=rand()%15;
            matrice2[i][j]=rand()%15;
        }

    show_matrix(matrice,n,"matrix1");
    show_matrix(matrice2,n,"matrix2");

    printf("\n\n1.Scrieti un program C pentru a aduna doua matrice.");
    printf("\nsuma 2 matrice ={");
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++){
            printf("%d, ",matrice[i][j]+matrice2[i][j]);
        }
    }
    printf("\n}\n");



    printf("\n\n2.Scrieti un program C pentru a scadea doua matrice.");
    printf("\ndiferenta 2 matrice ={");
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++){
            printf("%d, ",matrice[i][j]-matrice2[i][j]);
        }
    }
    printf("\n}\n");


    printf("\n\n3.Scrieti un program C pentru a efectua multiplicarea matricei cu un scalar.");
    int scalar=5;
    printf("\n%d * matrix1 ={",scalar);
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++){
            printf("%d, ",matrice[i][j]*scalar);
        }
    }
    printf("\n}\n");



    printf("\n\n4.Scrieti un program C pentru a multiplica doua matrice.");
    printf("\nmultiplicarea 2 matrice ={");
    for(int i=0; i<n; i++){
        printf("\n\t");
        for(int j=0; j<n; j++){
            printf("%d, ",matrice[i][j]*matrice2[i][j]);
        }
    }
    printf("\n}\n");



    printf("\n\n5.Scrieti un program C pentru a verifica daca doua matrice sunt egale sau nu.\n\t");
    int equal=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            if(matrice[i][j] != matrice2[i][j]){
                equal=0;
            }
    }
    if(equal==1)
        printf("matricea 1 si 2 sunt egale");
    else
        printf("matricea 1 si 2 nu sunt egale");


    printf("\n\n6.Scrieti un program C pentru a gasi suma elementelor diagonale principale ale unei matrice.");
    int suma=0;
    for(int i=0;i<n;i++)
        suma+=matrice[i][i];
    printf("\n\tSuma elementelor pe diagonala principala din matrice 1: %d",suma);


    printf("\n\n7.Scrieti un program C pentru a gasi suma elementelor diagonalei secundare ale unei matrice.");
    suma=0;
    for(int i=0; i<n; i++)
        suma+=matrice[i][n-i+1];
    printf("\n\tSuma elementelor diagonalei secundare din matrice 1: %d",suma);


    printf("\n\n8.Scrieti un program C pentru a gasi suma fiecarui rand si coloana a unei matrice.");
    printf("\n\tsuma pe rand la matrice1 ={");
    for(int i=0; i<n; i++){
        suma=0;
        for(int j=0; j<n; j++)
            suma+=matrice[i][j];
        printf("\n\t\t%d ",suma);
    }
    printf("\n\t}\n");
    printf("\n\tsuma pe coloana la matrice1 = { ");
    for(int i=0; i<n; i++){
        suma=0;
        for(int j=0; j<n; j++)
            suma+=matrice[j][i];
        printf("%d ",suma);
    }
    printf("}\n");



    printf("\n\n9.Scrieti un program C pentru a schimba diagonalele unei matrice.\n");
    for(int i=0; i<n; i++){
        int aux=matrice[i][i];
        matrice[i][i]=matrice[i][n-i+1];
        matrice[i][n-i+1]=aux;
    }
    show_matrix(matrice,n,"matrix1");



    printf("\n\n10.Scrieti un program C pentru a gasi matricea triunghiulara superioara.\n\t");
    //pentru matrice patratica
    //O matrice se numeste triunghiulara superior daca
    //toate elementele aflate sub diagonala principala a ei sunt nule.
    int true_or_false=1;
    for(int i=1; i<=n-1; i++)
        for(int j=0; j<=i-1; j++)
            if(matrice[i][j]!=0)
                true_or_false=0;

    if(true_or_false==0)
        printf("matricea nu este triunghiulara superior");
    else
        printf("matricea este triunghiulara");



    printf("\n\n11.Scrieti un program C pentru a gasi matricea triunghiulara inferioara.\n\t");
    //O matrice patratica se numeste triunghiulara inferior daca
    //toate elementele aflate deasupra diagonalei principale sunt nule.
    true_or_false=1;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(matrice[i][j]!=0)
                true_or_false=0;

    if(true_or_false!=0)
        printf("Matricea este triunghiulara inferiora");
    else
        printf("Matricea nu este triunghiulara inferiora");


    printf("\n\n12.Scrieti un program C pentru a gasi suma matricei triunghiulare superioare.\n");
    //O matrice se numeste triunghiulara superior daca
    //toate elementele aflate sub diagonala principala a ei sunt nule.
    Ex12();



    printf("\n\n13.Scrieti un program C pentru a gasi suma matricei triunghiulare inferioare.\n");
    //O matrice patratica se numeste triunghiulara inferior daca
    //toate elementele aflate deasupra diagonalei principale sunt nule.
    Ex13();


    printf("\n\n14.Scrieti un program C pentru a gasi transpunerea unei matrice.\n");
    show_matrix(matrice,n,"matrix1");
    int output[n][n];
    printf("\ntranspunerea matrix1={\n\t");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            output[i][j]=matrice[j][i];
            printf("%d, ",output[i][j]);
        }
        printf("\n\t");
    }
    printf("}");


    printf("\n\n15.Scrieti un program C pentru a gasi determinantul unei matrice.\n");
    Ex15();


    printf("\n\n16.Scrieti un program C pentru a verifica daca matricea este unitara.\n\t");
    // matricea unitara este atunci cand toate valorile de pe diagonala principala sunt 1
    // si nr de elemente 1 sunt egale cu n
    int count=0;
    for(int i=0; i<n; i++)
        if(matrice[i][i] == 1)
            count++;

    if(count==n)
        printf("matricea este unitara");
    else
        printf("matricea nu este unitara");


    printf("\n\n17.Scrieti un program C pentru a verifica daca matrix este rarefiata");
    printf("\n(daca numarul de zerouri reprezinta mai mult sau egal cu 70 procente din elementele matricei, atunci matricea este rarefiata)");
    Ex17();


    printf("\n\n18.Scrieti un program C pentru a verifica daca matricea este simetrica.\n\t");
    //o matrice simetrica este o matrice patratica care este egala cu transpusa sa.
    //asa ca voi compara matricea transpusa de la exercitiul 14 si o voi compara cu matricea 1
    true_or_false=1;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(matrice[i][j] != output[i][j])
                true_or_false=0;
    if(true_or_false == 1)
        printf("matricea 1 este simetrica.");
    else
        printf("matricea 1 nu este simetrica.");

    // =============================================================================
    // rotirea jos -> 180 grade, stanga-> -90 grade, dreapta -> 90 grade
    printf("\n\n19.Scrieti un program C pentru a roti la stanga matrica 1.\n");
    Ex19(matrice,n);


    printf("\n\n20.Scrieti un program C pentru a roti la dreapta matricea 1.\n");
    Ex20(matrice,n);


    printf("\n\n21.Scrieti un program C pentru a roti in sus matricea 1.\n");
    Ex21(matrice,n);

   	printf("\n\n");
   	return 0;
}
