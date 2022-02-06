#include <stdio.h>
#include <math.h>

int a=5,b=6,c=9;

int main(){
    printf("\t|----------------------------------------------------------------|\n");
	printf("\t|            Laboratorul 2: instructiuni de ramificare           |\n");
	printf("\t|________________________________________________________________|\n");
	printf("\n\n1. Scrieti un program C pentru a gasi maxim intre doua numere\n");
        int max_number = 0;
        if(a>b) max_number = a;
        else max_number = b;
	printf("\tmaximul dintre %i si %i => %i",a,b, max_number);



	printf("\n\n2. Scrieti un program C pentru a gasi maxim intre trei numere.\n");
        if(a>b) max_number = a;
        else max_number = b;

        if(max_number > c)  max_number = max_number;
        else max_number = c;
	printf("\tmaximul intre %i,%i,%i => %i", a,b,c,max_number);



	printf("\n\n3. Scrieti un program C pentru a verifica daca un numar este negativ, pozitiv sau zero.\n");
	printf("\t%i => ",a);
        if(a<0) printf("negativ");
        else if(a==0) printf("este 0");
        else printf("pozitiv");



	printf("\n\n4. Scrieti un program C pentru a verifica daca un numar este divizibil cu 5 si 11 sau nu.\n");
	printf("\t%i => ",a);
        if((a%5 == 0)&&(a%11 == 0)) printf("este divizibil 5,11");
        else printf("nu este divizibil cu 5 si 11");


	printf("\n\n5. Scrieti un program C pentru a verifica daca un numar este par sau impar. \n");
	printf("\t%i => ",a);
        if(a%2 == 0) printf("numar par");
        else printf("numar impar");



    int anul = 2015;
	printf("\n\n6. Scrieti un program C pentru a verifica daca un an este bisect sau nu.\n");
	printf("\t%i => ",anul);
        if(anul%4 == 0)
            printf("anul este bisect");
        else if(anul%100 == 0)
            printf("anul nu este bisect");
        else if(anul%400 == 0)
            printf("anul este bisect");
        else
            printf("eroare");



	printf("\n\n7. Scrieti un program C pentru a verifica daca un caracter este sau nu alfabet.\n");
        char litera = 'A';

        if( (litera>='a' && litera<='z') || (litera>='A' && litera<='Z') )
            printf("\t%c => apartine alfabetului", litera);
        else
            printf("\t%c => nu apartine alfabetului", litera);


    printf("\n\n8.Scrieti un program C pentru a introduce orice alfabet si verificati daca este vocala sau consoana.\n");
        litera = 'a';
        if(litera == 'a' || litera == 'e' || litera == 'i' || litera == 'o' || litera == 'u')
            printf("\t%c => este vocala", litera);
        else if(litera == 'b' || litera == 'c' || litera == 'd' || litera == 'f' || litera == 'g' || litera == 'h' ||
                litera == 'j' || litera == 'k' || litera == 'l' || litera == 'm' || litera == 'n' || litera == 'p' ||
                litera == 'q' || litera == 'r' || litera == 's' || litera == 't' || litera == 'v' || litera == 'w' ||
                litera == 'x' || litera == 'y' || litera == 'z')
                printf("\t%c => este consoana", litera);


    printf("\n\n9.Scrieti un program C pentru a introduce orice caracter si verificati daca este alfabet, cifra sau caracter special. \n");
        char caracter = '0';
        printf("\t%c => ",caracter);

        // compararea facuta dupa TABELUL ASCII: https://www.asciitable.com/
        if ((caracter>= 65 && caracter<= 90) || (caracter>= 97 && caracter<=122))
            printf("apartine alfabetului");
        else if(caracter>=48 && caracter<=57)
            printf("este cifra");
        else if(caracter>=33 && caracter<=36)
            printf("caracter special");

    printf("\n\nScrieti un program C pentru a verifica daca un caracter este cu majuscule sau minuscule.\n");
        litera = 'A';
        if(litera>='a' && litera<='z')
            printf("\t%c => este cu minuscula", litera);
        else if(litera>='A' && litera<='Z')
            printf("\t%c => este cu majuscula", litera);


    printf("\n\n11.Scrieti un program C pentru a introduce numarul saptamanii si a imprima ziua saptamanii. \n");
	int nr_sapt = 4;
	printf("\tnr. saptamanii %i => ",nr_sapt);
	switch(nr_sapt){
        case 1: printf("Luni"); break;
        case 2: printf("Marti"); break;
        case 3: printf("Miercuri"); break;
        case 4: printf("Joi"); break;
        case 5: printf("Vineri"); break;
        case 6: printf("Sambata"); break;
        case 7: printf("Duminica"); break;
        default: printf("Eroare: Intr-o saptamana sunt 7 zile.");
	}


	printf("\n\n12.Scrieti un program C pentru a introduce numarul lunii si a imprima numarul de zile din luna respectiva.\n");
        int nr_lunii = 4, luna=4;
        //Ianuarie, Martie, Mai, Iulie, August, Octombrie, Decembrie -> 31 zile
        //Februarie -> 28 sau 29 zile
        //Aprilie, Iunie, Septembrie, Noiembrie -> 30 zile
        printf("\tNr. lunii %i => ", luna);
            if(luna==1 || luna==3 || luna==5 || luna==7 || luna==8 || luna==10 || luna==12)
                printf("31 zile");
            else if(luna==4 || luna==6 || luna==9 || luna==11)
                printf("30 zile");
            else if(luna==2)
                printf("28 sau 29 zile");
            else
                printf("Eroare: intr-un an sunt 12 luni.");


    printf("\n\n14.Scrieti un program C pentru a introduce unghiurile unui triunghi si verificati daca triunghiul este valid sau nu.\n");
        int unghi_1=60,unghi_2=20,unghi_3=100;
        int suma_unghiurilor = unghi_1 + unghi_2 + unghi_3;
        printf("\tTriunghi ABC cu unghiurile: %i,%i,%i",unghi_1,unghi_2,unghi_3);
            if (suma_unghiurilor == 180)
                printf("\n\tSuma unghiurilor: %i => este egal cu 180, deci triunghiul este valid",suma_unghiurilor);
            else
                printf("\n\tSuma unghiurilor: %i => nu este egala cu 180, deci nu este valid",suma_unghiurilor);



	printf("\n\n15.Scrieti un program C pentru a introduce toate laturile unui triunghi si verificati daca triunghiul este valid sau nu.");
	printf("\n\tTeorema: Un triunghi este valid daca suma a 2 laturi este mai mare decat a 3 latura.");
        int latura_1=40,latura_2=50,latura_3=70;
	printf("\n\tTriunghi ABC cu laturile: %i,%i,%i",latura_1,latura_2,latura_3);
	    if (latura_1 + latura_2 <= latura_3 || latura_1 + latura_3 <= latura_2 || latura_2 + latura_3 <= latura_1)
            printf("\n\tsuma a %i+%i=%i > %i, deci este valid",latura_1,latura_2,latura_1+latura_2,latura_3);
        else
            printf("\n\tsuma a %i+%i=%i < %i, deci este valid",latura_1,latura_2,latura_1+latura_2,latura_3);


    printf("\n\n16.Scrieti un program C pentru a verifica daca triunghiul este echilateral, isoscel sau triunghi scalen. \n");
    printf("\t*Dimensiunea latruilor se iau din exercitiu precedent.");
    printf("\n\tTriunghi ABC cu laturile: %i,%i,%i => ",latura_1,latura_2,latura_3);
        if(latura_1 == latura_2 && latura_2 == latura_3)
            printf("Triunghi echilateral");
        else if(latura_1 == latura_2 || latura_2 == latura_3 || latura_3 == latura_1)
            printf("Triunghi isoscel");
        else
            printf("Triunghi scalen");


    printf("\n\n17.Scrieti un program C pentru a gasi toate radacinile unei ecuatii patratice.\n");
        int a=4,b=6,c=9;
    printf("\t%ix^2 + %ix + %i = 0\n",a,b,c);
        int delta = pow(b,2)-4*a*c;
        int x1 = (-b-sqrt(delta))/2*a;
        int x2 = (-b+sqrt(delta))/2*a;
    printf("\tdelta = %i\n",delta);
    printf("\tx1 = %i\n",x1);
    printf("\tx2 = %i\n",x2);
	printf("\n");
	return 0;
}
