#include <stdio.h>
#include <stdlib.h>

int exercitiu_1(int numar, int puterea) {
    if(puterea != 0)
        return numar*exercitiu_1(numar, puterea-1);
    else
        return 1;
}

void exercitiu_2(int numar) {
    if(numar)
        exercitiu_2(numar-1);
    else
        return;

    printf("%i, ", numar);
}

void exercitiu_3(int curent_nr, int limita) {
    if(curent_nr > limita) return;

    printf("%i, ", curent_nr);
    // +1 par +2 impar
    exercitiu_3(curent_nr+2, limita);
}

int exercitiu_4(int x) {
    if(x==0) return 1;
    else return x+exercitiu_4(x-1);
}

int exercitiu_5(int x, int y) {
    if(x>y)
        return 0;
    else
        return x+exercitiu_5(x+2, y);
}

int exercitiu_6(int numar) {
    //aflarea numarului total de cifre
    int cifre_total = (int) log10(numar);

    if(numar == 0)
        return 0;
    else
        return ((numar%10 * pow(10, cifre_total)) + exercitiu_6(numar/10));
}

int exercitiu_8(int numar) {
    if(numar!=0)
        return numar%10 + exercitiu_8(numar/10);
    else
        return 0;
}

int exercitiu_9(int n) {
   if(n == 0)
      return 1;
   else
      return n * exercitiu_9(n-1);
}

int exercitiu_10(int n) {
   if(n == 0)
      return 0;
   else if(n == 1)
      return 1;
   else
      return (exercitiu_10(n-1) + exercitiu_10(n-2));
}
int main()
{
    int nr=9;
    printf("\n1.Scrieti un program C pentru a gasi puterea oricarui numar folosind recursivitatea.\n");
    printf("%i",exercitiu_1(nr,2));

    printf("\n\n2.Scrieti un program C pentru a imprima toate numerele naturale cuprinse intre 1 si n folosind recursivitatea.\n");
    exercitiu_2(nr);

    printf("\n\n3.Scrieti un program C pentru a imprima toate numerele pare sau impare in intervalul dat folosind recursivitatea.\n");
    exercitiu_3(1,nr);

    printf("\n\n4.Scrieti un program C pentru a gasi suma tuturor numerelor naturale cuprinse intre 1 si n folosind recursivitatea.\n");
    printf("%i",exercitiu_4(nr));

    printf("\n\n5.Scrieti un program C pentru a gasi suma tuturor numerelor pare sau impare in intervalul dat folosind recursivitatea.\n");
    printf("%i",exercitiu_5(1, nr));

    printf("\n\n6.Scrieti un program C pentru a gasi inversarea oricarui numar folosind recursivitatea. ( Ex: 2021 -> 1202\)");
    printf("\n\tInversul al %i este %i",1235, exercitiu_6(1235));

    printf("\n\n8.Scrieti un program C pentru a gasi suma cifrelor unui numar dat folosind recursivitatea.\n");
    printf("\tSuma cifrelor numarului %i este %i",369, exercitiu_8(369));

    printf("\n\n9.Scrieti un program C pentru a gasi factorialul oricarui numar folosind recursivitatea.\n");
    printf("Factorial din %i = %i",nr,exercitiu_9(nr));

    printf("\n\n10.Scrieti un program C pentru a genera al n-lea termen Fibonacci folosind recursivitate.\n");
    printf("al %i-lea termen Fibonacci: %i", nr, exercitiu_10(nr));

    printf("\n");
    return 0;
}
