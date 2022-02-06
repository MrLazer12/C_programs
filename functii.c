#include <stdio.h>
#include <math.h>

float pi = 3.6;

int cubul_nr(int numar){
	return pow(numar,3);
}

void cercul(float raza){
	printf("\n\tDiametrul cercului = %f", (2*raza));
	printf("\n\tCircumferinta cercului = %f", (2*pi*raza));
	printf("\n\tAria cercului = %f", (pi*pow(raza,2)));
}

int maxim(int a, int b){
	if(a>b) return a;
	else return b;
}

int par_impar(int numar){
	if(numar%2 == 0) return 1;
	else return 0;
}

//EX5------------------------------
int numar_prim(int numar){
    int k=0,result=0;
    for(int i=1; i<=9; i++)
        if(numar%numar == 0 && numar%i == 0)
            k++;

    if(k==2)
        return 1;
    else
        return 0;
}

int armstrong_nr(int numar){
	//An Armstrong number of three digits is an integer such that the sum of the cubes of its digits is equal to the number itself.
	//For example, 371 is an Armstrong number since 3**3 + 7**3 + 1**3 = 371.
	int sum=0, nr_initial=numar;
	while(numar != 0){
		sum+=pow(numar%10,3);
		numar/=10;
	}

	if(nr_initial == sum)
		return 1;
	else
		return 0;
}

int nr_perfect(int numar){
	int sum=0;

	for(int i=1; i<numar; i++){
		if(numar%i == 0)
			sum+=i;
	}

	if(sum == numar)
        return 1;
	else
        return 0;
}

int nr_puternic(int numar){
    int count=0;

    for(int i=1; i<=numar; i++){
        if(numar%i == 0)
            if(numar%(i*i) == 0)
                count++;
    }

    if(count>=2)
        return 1;
    else
        return 0;
}
//=================================

int main(){
	int nr = 6;
	printf("\n1. Scrieti un program C pentru a gasi cubul oricarui numar folosind functia.\n");
	printf("\tcubul numarului %i este %i",nr,cubul_nr(nr));


	printf("\n\n2.Scrieti un program C pentru a gasi diametrul, circumferinta si aria cercului folosind functiile.");
        cercul(nr);


	printf("\n\n3.Scrieti un program C pentru a gasi maxim si minim intre doua numere folosind functii.\n");
	printf("\tMaximul intre %i si %i este %i",nr, 9, maxim(nr,9));


	printf("\n\n4.Scrieti un program C pentru a verifica daca un numar este par sau impar folosind functiile.\n");
	printf("\tNumar %i este %i",nr,par_impar(nr));


	printf("\n\n5.Scrieti un program C pentru a verifica daca un numar este prim, Armstrong sau un numar perfect folosind functii.\n");
	printf("\n\tNumarul: %i",nr);
	printf("\n\tnumar prim: %i", numar_prim(nr));
	printf("\n\tnumar armstrong: %i", armstrong_nr(nr));
	printf("\n\tnumar perfect: %i", nr_perfect(nr));


	printf("\n\n6.Scrieti un program C pentru a gasi toate numerele prime intre intervalul dat folosind functiile.\n");
        int punct1 = 9, punct2 = 35;
	printf("\tintervalul [%i,%i]\n",punct1,punct2);
        for(int i=punct1; i<=punct2; i++)
            if(numar_prim(i) == 1)
                printf("\t=> %i este prim\n",i);


    printf("\n\n7.Scrieti un program C pentru a imprima toate numerele puternice intre intervalul dat folosind functiile. \n");
        punct1 = 1, punct2 = 50;
	printf("\tintervalul [%i,%i]\n\t",punct1,punct2);
        for(int i=punct1; i<=punct2; i++)
            if(nr_puternic(i) == 1)
        printf("%i, ",i);


    printf("\n\n8.Scrieti un program C pentru a imprima toate numerele Armstrong intre intervalul dat folosind functiile.\n");
        punct1=1,punct2=2190;
	printf("\tintervalul [%i,%i]\n\t",punct1,punct2);
        for(int i=punct1; i<=punct2; i++)
            if(armstrong_nr(i) == 1)
                printf("%i, ",i);


    printf("\n\n9.Scrieti un program C pentru a imprima toate numerele perfecte intre intervalul dat folosind functiile.\n");
        punct1=1,punct2=2190;
	printf("\tintervalul [%i,%i]\n\t",punct1,punct2);
        for(int i=punct1; i<=punct2; i++)
            if(nr_perfect(i) == 1)
                printf("%i, ",i);


	printf("\n\n");
	return 0;
}
