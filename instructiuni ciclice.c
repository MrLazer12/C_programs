#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");

    int nr = 11,i=1;

    printf("\t|-----------------------------------------------------------|\n");
	printf("\t|            Laboratorul 2: instructiuni ciclice            |\n");
	printf("\t|___________________________________________________________|\n");


        if(nr<0){
            printf("\t | => numarul n trebuie sa fie pozitiv, numar introdus:\n");
            return 1;
        }

    printf("\t|======|\n");
    printf("\t| n=%i |\n",nr);
    printf("\t|======|\n");
	printf("\n1.Scrieti un program C pentru a imprima toate numerele naturale de la 1 la n. - folosind bucla while.\n");
        while(i<=nr){ printf("%i ",i); i++;}


    printf("\n\n2.Scrieti un program C pentru a imprima toate numerele naturale invers (de la n la 1). - folosind bucla while.\n");
        int numar = nr;
        while(numar > 0){ printf("%i ",numar); numar--;}



    printf("\n\n3.Scrieti un program C pentru a imprima toate alfabetele de la a la z. - folosind bucla while\n");
        char caracter = 'a';
        while(caracter<='z'){ printf("%c ", caracter); caracter++; }



    printf("\n\n4.Scrieti un program C pentru a imprima toate numerele pare intre 1 si 100. - utilizand bucla while \n");
        i=1;
        while(i<=100){
            if(i%2 == 0)
                printf("%i ",i);
            i++;
        }



    printf("\n\n5.Scrieti un program C pentru a imprima toate numerele impare intre 1 si 100.\n");
        i=1;
        while(i<=100){
            if(i%2 != 0)
                printf("%i ",i);
            i++;
        }



    printf("\n\n6.Scrieti un program C pentru a gasi suma tuturor numerelor naturale cuprinse intre 1 si n.\n");
        int suma=0;
        for(i=1; i<=nr;i++){
            suma+=i;
        }
    printf("\tSuma intre 1 si %i => %i",nr,suma);



    printf("\n\n7.Scrieti un program C pentru a gasi suma tuturor numerelor pare intre 1 si n\n");
        suma=0;
        for(i=0; i<nr;i++){
            if(i%2 == 0)
            suma+=i;
        }
    printf("\tSuma intre 1 si %i => %i",nr,suma);



    printf("\n\n8.Scrieti un program C pentru a gasi suma tuturor numerelor impare cuprinse intre 1 si n\n");
        suma=0;
        for(i=0; i<nr;i++){
            if(i%2 != 0)
            suma+=i;
        }
    printf("\tSuma intre 1 si %i => %i",nr,suma);



    printf("\n\n9.Scrieti un program C pentru a imprima tabelul de inmultire a oricarui numar.\n");
        for(i=1; i<=10; i++){
            for(int j=1; j<=9; j++)
                printf("%i * %i = %i\n",i,j,i*j);

            printf("\n");
        }



    printf("\n\n10.Scrieti un program C pentru a numara numarul de cifre dintr-un numar.\n");
        int k=nr;
        for(i=0; k!=0; i++)
            k/=10;

    printf("\t%i numar de cifre -> %i",nr,i);



    printf("\n\n11.Scrieti un program C pentru a gasi prima si ultima cifra a unui numar.\n");
        k=19111111133;
        int prima_cifra=k;
        while(prima_cifra >= 10)
            prima_cifra /= 10;

    printf("\tNumar: %i\n\tprima cifra: %i\n\tultima cifra: %i",k,prima_cifra,k%10);



    printf("\n\n12.Scrieti un program C pentru a gasi prima si ultima cifra a unui numar.\n");
        k=2567;
        prima_cifra=k;
        while(prima_cifra >= 10)
            prima_cifra /= 10;

    printf("\tNumar: %i\n\tsuma primei si ultimei cifre: %i",k,prima_cifra+k%10);


    printf("\n\n13.Scrieti un program C pentru a numara numarul total de note intr-o anumita cantitate.\n");
    printf("*Nu inteleg conditia problemei.*");


    printf("\n\n14.Scrieti un program C pentru a calcula suma cifrelor unui numar.\n");
        int sum=0; k=4567;
    printf("\tNumar: %i ",k);
        while(k!=0){
            sum+=k%10;
            k/=10;
        }
    printf("suma cifrelor: %i",sum);



    printf("\n\n15.Scrieti un program C pentru a calcula produsul cifrelor unui numar.\n");
        int produs=1; k=36548;
    printf("\tNumar: %i",k);
        while(k!=0){
            produs*=k%10;
            k/=10;
        }
    printf(", produsul cifrelor: %i",produs);



    printf("\n\n16.Scrieti un program C pentru a introduce un numar si imprimati invers.\n");
        k=123456;
    printf("\tNumar initial: %i",k);
        int invers=0, restul=0;
        while (k != 0) {
            invers = invers * 10 +  k%10;
            k /= 10;
        }
    printf(", numar inversat: %i", invers);



    printf("\n\n17.Scrieti un program C pentru a verifica daca un numar este palindrom sau nu.\n");
    //Palindrom = numar care scris invers este egal cu el insusi.
    //Exemple de numere care sunt palindroame: 121, 12344321, 100001 etc.
        int numar_palindrom = 1221, numarInitial = numar_palindrom, numarInvers = 0;
    printf("\tNumar: %i, ",numar_palindrom);
        while(numar_palindrom != 0){
            numarInvers = numarInvers * 10 + numar_palindrom % 10;
            numar_palindrom = numar_palindrom / 10;
        }

        if(numarInitial == numarInvers)
            printf("este palindrom");
        else
            printf("nu este palindrom");



    printf("\n\n18.Scrieti un program C pentru a gasi frecventa fiecarei cifre intr-un numar intreg dat.\n");
        k=122355;
    printf("\t Numar: %i\n",k);
        for(i=1; i<=9; i++){
            int count=0;
            int k_clon = k;

            while(k_clon != 0){
                if(k_clon%10 == i)
                    count++;

                k_clon/=10;
            }

            printf("\t\t%i => %i\n",i,count);
        }




    printf("\n\n19.Scrieti un program C pentru a introduce un numar si imprimati-l in cuvinte.\n");
        k=1235;
        int num=0;
    printf("\t%i => ",k);
        //inversarea numarului
        while(k != 0){
            num = (num * 10) + (k % 10);
            k /= 10;
        }

        while(num != 0){
            switch(num % 10)
            {
                case 0: printf("Zero "); break;
                case 1: printf("Unu "); break;
                case 2: printf("Doi "); break;
                case 3: printf("Trei "); break;
                case 4: printf("Patru "); break;
                case 5: printf("Cinci "); break;
                case 6: printf("Sase "); break;
                case 7: printf("Sapte "); break;
                case 8: printf("Opt "); break;
                case 9: printf("Noua "); break;
            }

            num = num / 10;
        }



    printf("\n\n20.Scrieti un program C pentru a imprima toate caracterele ASCII cu valorile lor.\n");
        char ch=' ';
        for (i = 0; i < 256; i++) {
            printf("%i => %c  |",i,ch);

            if(i%8 == 0) printf("\n");

            ch++;
        }
    printf("\n");
    return 0;
}
