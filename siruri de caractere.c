#include <stdio.h>
#include <string.h>
#include <ctype.h>

// functia pentru ex 13
void palindrom_da_nu(char sirul[]) {
    // Incep de la stanga sirului si parcurg pana la sfarsit(dreapta) sirul
    int stanga = 0;
    int dreapta = strlen(sirul) - 1;

    // Compareti caracterele pana cand ele is asemenea
    while (dreapta > stanga) {
        if (sirul[stanga++] != sirul[dreapta--]) {
            printf("\n\t sirul: %s nu este palindrom\n", sirul);
            return;
        }
    }
    printf("\n\t sirul: %s este palindrom\n", sirul);
}

// functia pentru ex 19
char caracter_frecvent(char* sirul) {
    int lenght_sir = strlen(sirul), max = 0;
    int count[256]={0}; //256 - numar total de elemente din tabelul ASCII, count[256]={0} il initializez astfel cu valoare 0
    char resultat;

    for(int i=0; i<lenght_sir; i++) {
        count[sirul[i]]++;
        if(max < count[sirul[i]]) {
            max = count[sirul[i]];
            resultat = sirul[i];
        }
    }

    return resultat;
}

// functia pentru ex 36
char * stergere_space_inceput(char *sir_initial) {
    char *sir_aditional=sir_initial;

    while(*sir_aditional++ == ' ');

    if(sir_initial != --sir_aditional) {
        --sir_aditional;
        *sir_aditional++='\0';
        return strcpy(sir_initial, sir_aditional);
    }
    return sir_initial;
}

// functia pentru ex 37
char *stergere_space_sfarsit(char *sir_initial){
    char *sir_aditional=sir_initial;
    sir_aditional= --sir_aditional + strlen(sir_initial);

    while(*sir_aditional--==' ');
        sir_aditional+=2;

    *sir_aditional='\0';
    return sir_initial;
}

// functia pentru ex 39
char *sterge_spatiile(char *sir_initial) {
    char *sir_aditional, *temporar;
    sir_aditional = sir_initial;

    while(*sir_aditional) {
        while(*sir_aditional != ' ' && *sir_aditional) ++sir_aditional;

        if(*sir_aditional==' '  &&  *(sir_aditional+1)==' ') {
            temporar=sir_aditional+1;

            while(*sir_aditional==' '  &&  *sir_aditional) ++sir_aditional;

            *temporar='\0';
            strcat(sir_initial, sir_aditional);
            sir_aditional=temporar;
        }
        else ++sir_aditional;

    }
    return sir_initial;
}

int main() {
	printf("\n|=======================================================|");
	printf("\n|          Probleme pentru siruri de caractere          |");
	printf("\n|_______________________________________________________|\n");

	char sir[100]="hello world!";
	printf(" => sirul \"%s\"",sir);
// ==============================================================================================================
	printf("\n\n 1.Scrieti un program C pentru a afla lungimea unui sir.");
	printf("\n\t Lungimea este %d",strlen(sir));
// ==============================================================================================================


// ==============================================================================================================
	printf("\n\n 2.Scrieti un program C pentru a copia un sir in altul.");
	char sir_copy[100];
	strcpy(sir_copy,sir);
	printf("\n\t Sirul copiat din sirul precedent: %s",sir_copy);
// ==============================================================================================================


// ==============================================================================================================
	printf("\n\n 3.Scrieti un program C pentru a concatena doua siruri.");
	printf("\n\t Concatenarea sir_copy cu sir: %s",strcat(sir_copy,sir));
// ==============================================================================================================


// ==============================================================================================================
	printf("\n\n 4.Scrieti un program C pentru a compara doua siruri.");
	printf("\n\t Rezultatul compararii silrurilor sir_copy cu sir: %i", strcmp("dasdas",sir));
// ==============================================================================================================


// ==============================================================================================================
	printf("\n\n 5.Scrieti un program C pentru a converti dintr-un sir, literele minuscule in majuscule.");
	printf("\n\t sir cu majuscule: %s", strupr(sir));
// ==============================================================================================================


// ==============================================================================================================
	printf("\n\n 6.Scrieti un program C pentru a converti dintr-un sir, literele majuscule in litere mici.");
	printf("\n\t sir cu litere mici: %s", strlwr(sir));
// ==============================================================================================================


// ==============================================================================================================
	printf("\n\n 7.Scrieti un program C pentru a comuta literele minuscule in majuscule si majuscule in minuscule pentru fiecare caracter dintr-un sir.");
    strcpy(sir,"HelLo WorlD!");
    printf("\n\t sir initial: %s", sir);
    for(int i=0; sir[i]; i++)
        if(sir[i]>=65 && sir[i]<=90)
            sir[i]=tolower(sir[i]); // pentru a utiliza functia trebuie biblioteca ctype.h
        else if(sir[i]>=97 && sir[i]<=122)
            sir[i]=toupper(sir[i]); // pentru a utiliza functia trebuie biblioteca ctype.h
    printf("\n\t sir modificat: %s", sir);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 8.Scrieti un program C pentru a gasi numarul total de litere, cifre sau caractere speciale dintr-un sir.");
    strcpy(sir,"12345 *- helloworld");
    printf("\n\t sir: %s", sir);
    int cifre=0,litere=0,caractere_speciale=0;
    //voi numara numaru total, prin compararea cu valorile din tabel ASCII
    for(int i=0; sir[i]; i++){
        if(sir[i]>=33 && sir[i]<=47)
            caractere_speciale++;
        else if(sir[i]>=48 && sir[i]<=57)
            cifre++;
        else if((sir[i]>=65 && sir[i]<=90) || (sir[i]>=97 && sir[i]<=122))
            litere++;
    }
    printf("\n\t Litere: %d",litere);
    printf("\n\t Cifre: %d",cifre);
    printf("\n\t Caractere speciale: %d",caractere_speciale);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 9.Scrieti un program C pentru a numara numarul total de vocale dintr-un sir.");
    int vocale=0;
    strcpy(sir,"hello world!");
    printf("\n\t sir: %s", sir);
    for(int i=0; sir[i]; i++){
        char litera = sir[i];
        if(litera == 'a' || litera == 'e' || litera == 'i' || litera == 'o' || litera == 'u' ||
           litera == 'A' || litera == 'E' || litera == 'I' || litera == 'O' || litera == 'U')
            vocale++;
    }
    printf("\n\t Numar de vocale: %d",vocale);
// ==============================================================================================================




// ==============================================================================================================
    printf("\n\n 10.Scrieti un program C pentru a numara numarul total de consoane dintr-un sir.");
    int consoane=0;
    strcpy(sir,"hello world!");
    printf("\n\t sir: %s", sir);
    for(int i=0; sir[i]; i++){
        char litera = sir[i];
        if( litera == 'b' || litera == 'c' || litera == 'd' || litera == 'f' || litera == 'g' || litera == 'h' ||
            litera == 'j' || litera == 'k' || litera == 'l' || litera == 'm' || litera == 'n' || litera == 'p' ||
            litera == 'q' || litera == 'r' || litera == 's' || litera == 't' || litera == 'v' || litera == 'w' ||
            litera == 'x' || litera == 'y' || litera == 'z' ||

            litera == 'B' || litera == 'C' || litera == 'D' || litera == 'F' || litera == 'G' || litera == 'H' ||
            litera == 'J' || litera == 'K' || litera == 'L' || litera == 'M' || litera == 'N' || litera == 'P' ||
            litera == 'Q' || litera == 'R' || litera == 'S' || litera == 'T' || litera == 'V' || litera == 'W' ||
            litera == 'X' || litera == 'Y' || litera == 'Z')
            consoane++;
    }
    printf("\n\t Numar de consoane: %d",consoane);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 11.Scrieti un program C pentru a numara numarul total de cuvinte dintr-un sir.");
    strcpy(sir,"Programarea in limbajul C!");
    printf("\n\t sir: %s", sir);
    int numar_cuvinte=0;
    for(int i=0; sir[i]; i++)
        if(sir[i]==' ' && sir[i+1]!='\n')
            numar_cuvinte++;
    printf("\n\t Numar de cuvinte: %d",numar_cuvinte);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 12.Scrieti un program C pentru a gasi inversul unui sir.");
    strcpy(sir,"hello world!");
    printf("\n\t sir: %s", sir);
    printf("\n\t Sirul inversat: %s",strrev(sir));
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 13.Scrieti un program C pentru a verifica daca un sir este palindrom sau nu.");
    //Un palindrom este un sir de caractere (de obicei cuvinte, fraze sau numere)
    //care citit de la stanga la dreapta sau de la dreapta la stanga ramane neschimbat.
    palindrom_da_nu("abba");
    palindrom_da_nu(sir);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 14.Scrieti un program C pentru a inversa ordinea cuvintelor dintr-un sir dat.");
    strcpy(sir,"hello world hello world");
    char text_cuvinte_invers[100];
    printf("\n\t Sir: %s", sir);
    int u=strlen(sir);

    printf("\n\t Sirul modificat: ");
    for(int i=strlen(sir); i>=0; i--)
        // afisaz cuvantul de la sfarsit
        if(sir[i]==' ') {
            for(int j=i+1; j<=u; j++)
                printf("%c",sir[j]);

            printf("%c",' ');
            u=--i;
        }

    // afisez cuvantu de la inceput
    for (int i=0; i<=u; i++)
       printf("%c",sir[i]);


// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 15.Scrieti un program C pentru a gasi prima aparitie a unui caracter intr-un sir dat.");
        char caracter = 'o';
        strcpy(sir,"hello world!");
    printf("\n\t sir: %s", sir);
    printf("\n\t caracterul: %c", caracter);
        for(int i=0; sir[i]; i++)
            if(sir[i]==caracter){
                printf("\n\t prima aparitie a caracterului \'%c\' este %d", caracter, i);
                break;
            }
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 16.Scrieti un program C pentru a gasi ultima aparitie a unui caracter intr-un sir dat.");
    printf("\n\t sir: %s", sir);
    printf("\n\t caracterul: %c", caracter);
        int ultima_pozitie_caracter=0;
        for(int i=0; sir[i]; i++)
        if(sir[i]==caracter) ultima_pozitie_caracter=i;

    printf("\n\t ultima aparitie a caracterului \'%c\' este %d", caracter, ultima_pozitie_caracter);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 17.Scrieti un program C pentru a cauta toate aparitiile unui caracter dintr-un sir dat.");
    printf("\n\t sir: %s", sir);
    printf("\n\t caracterul: %c", caracter);
    printf("\n\t toate aparitiile a caracterului \'%c\':");
        for(int i=0; sir[i]; i++)
            if(sir[i]==caracter)
                printf(" %d,", i);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 18.Scrieti un program C pentru a numara aparitiile unui caracter dintr-un sir dat.");
    printf("\n\t sir: %s", sir);
    printf("\n\t caracterul: %c", caracter);
        int count=0;
        for(int i=0; sir[i]; i++)
            if(sir[i]==caracter)
                count++;
	printf("\n\t numar de aparitii a caracterului \'%c\' este %d",caracter,count);
// ==============================================================================================================



// ==============================================================================================================
	printf("\n\n 19.Scrieti un program C pentru a gasi caracterul cu cea mai mare frecventa dintr-un sir.");
    printf("\n\t Sir: %s", sir);
    printf("\n\t Caracterul cu cea mai mare frecventa este \'%c\'",caracter_frecvent(sir));
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 20.Scrieti un program C pentru a gasi caracterul cu frecventa cea mai joasa dintr-un sir.");
    strcpy(sir,"programarea si iar programarea...");
    printf("\n\t Sir: %s", sir);
    int ascii;
    int frecventa_caractere[256];
    for(int i=0; i<256; i++)
        frecventa_caractere[i]=0;


    for(int i=0; sir[i]; i++){
        ascii = (int)sir[i]; // transformam caracterul in valoare tip decimal, care corespunde tabelului ASCII
        frecventa_caractere[ascii] += 1; // incrementam frecventa fiecarui caracter
    }

    //gasim caracterul cu frecventa minima
    int min = 0;
    for(int i=0; i<256; i++)
        if(frecventa_caractere[i] != 0)
            if(frecventa_caractere[min] == 0 || frecventa_caractere[i] < frecventa_caractere[min])
                min = i;
    printf("\n\t Caracterul '%c' are frecventa cea mai joasa => %d.", min, frecventa_caractere[min]);
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 21.Scrieti un program C pentru a numara frecventa fiecarui caracter dintr-un sir.");
    printf("\n\t Sir: %s\n", sir);
        for(int i=0; i<26; i++)
            frecventa_caractere[i] = 0;

        for(int i=0; i<strlen(sir); i++){
            if(sir[i]>='a' && sir[i]<='z')
                frecventa_caractere[sir[i] - 97]++;

            else if(sir[i]>='A' && sir[i]<='Z')
                frecventa_caractere[sir[i] - 65]++;
        }

        for(int i=0; i<26; i++)
            if(frecventa_caractere[i] != 0)
                printf("\t '%c' = %d\n", (i + 97), frecventa_caractere[i]);
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 22.Scrieti un program C pentru a elimina prima aparitie a unui caracter din sir.");
    strcpy(sir,"hello world!");
    caracter='l';
    printf("\n\t Sir: %s, caracter: %c", sir,caracter);
    int true_fals=1;
        for(int i=0; sir[i]; i++){
            if(true_fals) {
                 if(caracter==sir[i]){
                    true_fals=0;
                    sir[i]=sir[i+1];
                 }
            }
            else sir[i]=sir[i+1];
        }
    printf("\n\t Sir modificat: %s", sir);
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 23.Scrieti un program C pentru a elimina ultima aparitie a unui caracter din sir.");
    strcpy(sir,"hello world!");
    caracter='l';
    printf("\n\t Sir: %s, caracter: %c", sir,caracter);
    int index=0;
    for(int i=0; sir[i]; i++)
        if(sir[i] == caracter) index=i;

    for(int i=index; sir[i]; i++){
        sir[i]=sir[i+1];
    }
    printf("\n\t Sir modificat: %s", sir);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 24.Scrieti un program C pentru a elimina toate aparitiile unui caracter din sir.");
    char sir2[100];
    strcpy(sir2,"programarea");
    caracter='g';
    printf("\n\t Sir: %s, caracter: %c", sir2,caracter);
    int lungime_sir = strlen(sir2);
    for(int i = 0; i<lungime_sir; i++){
		if(sir2[i] == caracter){
			for(int j = i; j < lungime_sir; j++)
				sir2[j] = sir2[j + 1];

			lungime_sir--;
			i--;
		}
	}
    printf("\n\t Sir modificat: %s", sir2);
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 25.Scrieti un program C pentru a elimina toate caracterele ce se repeta dintr-un sir dat.");
    strcpy(sir2,"programarea hello");
    printf("\n\t Sir: %s", sir2);
    caracter='*';
    count=0;
    for(int i=0; sir2[i]; i++)
    	if(!(sir2[i]==caracter))
    		for(int j=i+1; sir2[j]; j++){
            	if(sir2[i]==sir2[j])
            	   sir2[j]=caracter;
		    }

    for(int i=0; sir2[i]; i++) {
     	sir2[i]=sir2[i+count];

     	if(sir2[i]==caracter) {
		  count++;
		  i--;
	    }

    }

    printf("\n\t Sir modificat: %s", sir2);
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 26.Scrieti un program C pentru a inlocui prima aparitie a unui caracter cu altul dintr-un sir.");
    caracter='l';
    char caracter_nou='d';
    strcpy(sir,"hello world programing");
    printf("\n\t Sir: %s => schimbare cu caracter \'%c\'", sir,caracter_nou);
    for(int i=0; sir[i]; i++)
        if(sir[i]==caracter){
            sir[i]=caracter_nou;
            break;
        }
    printf("\n\t Sir modificat: %s", sir);
// ==============================================================================================================


// ==============================================================================================================
    strcpy(sir,"hello world");
    printf("\n\n 27.Scrieti un program C pentru a inlocui ultima aparitie a unui caracter cu altul dintr-un sir.");
    printf("\n\t Sir: %s => schimbare cu caracter \'%c\'", sir,caracter_nou);
    index=0;
    for(int i=0; sir[i]; i++)
        if(sir[i]==caracter)
            index=i;
    sir[index]=caracter_nou;
    printf("\n\t Sir modificat: %s", sir);
// ==============================================================================================================



// ==============================================================================================================
    strcpy(sir,"hello world");
    printf("\n\n 28.Scrieti un program C pentru a inlocui toate aparitiile unui caracter cu altul dintr-un sir.");
    printf("\n\t Sir: %s => schimbare cu caracter \'%c\'", sir,caracter_nou);
    for(int i=0; sir[i]; i++)
        if(sir[i]==caracter)
            sir[i]=caracter_nou;
    printf("\n\t Sir modificat: %s", sir);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 29.Scrieti un program C pentru a gasi prima aparitie a unui cuvant intr-un sir dat.");
    char cuvant[20]="world";
    strcpy(sir,"hello world world world hello");
    printf("\n\t Sir: %s", sir);
    printf("\n\t cuvant: %s", cuvant);

    index=0; int gasit=0;
    count=0;
    while(sir[index]) {
        if(sir[index] == cuvant[0]) {
            // compar intregul cuvant cu indicele gasit curente
            count=0;
            gasit = 1;
            while(cuvant[count]) {
                if(sir[index + count] != cuvant[count]) {
                    gasit = 0;
                    break;
                }

                count++;
            }
        }

        if(gasit == 1)
            break;

        index++;
    }

    if(gasit == 1)
        printf("\n\t cuvantul: '%s', s-a gasit la pozitia -> %d.", cuvant, index);
    else
        printf("\n\t cuvantul: '%s', nu s-a gasit", cuvant);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 30.Scrieti un program C pentru a gasi ultima aparitie a unui cuvant intr-un sir dat.");
    printf("\n\t Sir: %s", sir);
    printf("\n\t cuvant: %s", cuvant);
    index=0; gasit=0;
    for(int i=0; i<=strlen(sir) - strlen(cuvant); i++) {
        gasit=1;
        for(int j=0; j<strlen(cuvant); j++)
            if(sir[i + j] != cuvant[j]){
                gasit = 0;
                break;
            }

        if(gasit == 1)
            index = i;
    }

    if(index == -1)
        printf("\n\t cuvantul '%s' nu s-a gasit.", cuvant);
    else
        printf("\n\t Ultima apartitie a cuvantului '%s' se incepe de la pozitia %d", cuvant, index);

// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 31.Scrieti un program C pentru a cauta toate aparitiile unui cuvant intr-un sir dat.");
    printf("\n\t Sir: %s", sir);
    printf("\n\t cuvant: %s \n\t Pozitiile gasite: ", cuvant);
    gasit=0;
    count=0; // pun variabila, ce va socoti numarul aparitiilor, pentru EX 32
    for(int i=0; i<strlen(sir)-strlen(cuvant); i++) {
        gasit=1;
        for(int j=0; j<strlen(cuvant); j++) {
            //in caz cand cuvantul nu sa gasit la pozitia cautata => iesire din for
            if(sir[i + j] != cuvant[j]) {
                gasit = 0;
                break;
            }
        }

        if(gasit == 1){
            printf("%d ",i);
            count++; // pun variabila, ce va socoti numarul aparitiilor, pentru EX 32
        }
    }
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 32.Scrieti un program C pentru a numara aparitiile unui cuvant dintr-un sir dat.");
    printf("\n\t Sir: %s", sir);
    printf("\n\t cuvant: %s", cuvant);
    printf("\n\t Numarul aparitiilor: %d",count);
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 33.Scrieti un program C pentru a elimina prima aparitie a unui cuvant din sir.");
    strcpy(sir2,"hello world world world hello");
    printf("\n\t Sir: %s", sir2);
    printf("\n\t cuvant: %s", cuvant);
    gasit=0;
    for(int i=0; i<strlen(sir2); i++) {
        gasit=1;
        for(int j=0; j<strlen(cuvant); j++) {
            if(sir2[i+j] != cuvant[j]) {
                gasit = 0;
                break;
            }
        }

        // daca cuvantul a fost gasit, atunci il stergem prin metoda shiftarii caracterelor
        if(gasit == 1) {
            for(int j=i; j<=strlen(sir2)-strlen(cuvant); j++)
                sir2[j] = sir2[j + strlen(cuvant)];

            break;
        }
    }
    printf("\n\t Sir: %s", sir2);
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 34.Scrieti un program C pentru a elimina ultima aparitie a unui cuvant din sirul dat.");
    strcpy(sir2,"hello world world world hello");
    printf("\n\t Sir: %s", sir2);
    index=-1; gasit=0;
    printf("\n\t cuvant: %s", cuvant);
    for(int i=0; i<strlen(sir2)-strlen(cuvant); i++) {
        gasit=1;
        for(int j=0; j<strlen(cuvant); j++)
            if(sir2[i+j] != cuvant[j]) {
                gasit = 0;
                break;
            }

        if(gasit == 1)
            index = i;
    }

    if(index == -1)
        printf("\n\t cuvantul '%s' nu s-a gasit",cuvant);
    else {
        // shiftarea caracterelor din dreapta spre stanga
        for(int i=index; i <= strlen(sir2)-strlen(cuvant); i++)
            sir2[i] = sir2[i + strlen(cuvant)];

        printf("\n\t Sir modificat '%s'", sir2);
    }
// ==============================================================================================================



// ==============================================================================================================
    printf("\n\n 35.Scrieti un program C pentru a elimina toate aparitiile unui cuvant din sirul dat.");
    strcpy(sir2,"hello world world world hello");
    printf("\n\t Sir: %s", sir2);
    printf("\n\t cuvant: %s", cuvant);
    gasit=0;
    for(int i=0; i<strlen(sir2); i++) {
        gasit = 1;
        for(int j=0; j<strlen(cuvant); j++) {
            if(sir2[i+j] != cuvant[j])
                gasit = 0;

        }

        // daca cuvantul a fost gasit, atunci il stergem prin metoda shiftarii caracterelor
        if(gasit == 1)
            for(int j=i; j<=strlen(sir2)-strlen(cuvant); j++)
                sir2[j] = sir2[j + strlen(cuvant)];

    }
    printf("\n\t Sir: %s", sir2);
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 36.Scrieti un program C pentru a sterge caracterele de spatii albe de la inceputul unui sir dat.");
    strcpy(sir,"    hello world");
    printf("\n\t Sir: %s", sir);
    printf("\n\t Sir modificat: %s", stergere_space_inceput(sir) );
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 37.Scrieti un program C pentru a sterge caracterele de spatii albe de la sfarsitul unui sir dat.");
    strcpy(sir,"hello world      ");
    printf("\n\t Sir: %s",sir);
    printf("\n\t Sir modificat: %s", stergere_space_sfarsit(sir) );
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 38.Scrieti un program C pentru a taia atat caracterele de spatii albe de inceput, cat si cele de sfarsit din sirul dat.");
    strcpy(sir,"       hello world      ");
    printf("\n\t Sir: %s",sir);
    strcpy(sir, stergere_space_inceput(sir));
    strcpy(sir, stergere_space_sfarsit(sir));
    printf("\n\t Sir modificat: %s", sir);
// ==============================================================================================================


// ==============================================================================================================
    printf("\n\n 39.Scrieti un program C pentru a elimina toate spatiile goale suplimentare din sirul dat.");
    strcpy(sir,"       hello          world      ");
    printf("\n\t Sir: %s",sir);
    sterge_spatiile(sir);
    printf("\n\t Sir modificat: %s", sir);
// ==============================================================================================================


// ==============================================================================================================
    //printf("\n\n 40.Scrieti un program C pentru a sorta literele unui sir dat in ordine alfabetica, fara a schimba pozitia restul caracterelor \n( exemplu: m2a#ma -> a2a#mm).");

// ==============================================================================================================


// ===========================================================================================================
    printf("\n\n 41.Scrieti un program C pentru a sorta cuvintele in ordine alfabetica, dintr-un sir dat.");
    strcpy(sir,"hello world");
    strlwr(sir);
    printf("\n\t Sir: %s",sir);
       for(int i=0; i<strlen(sir)-1; i++) {
          for(int j=i+1; j<strlen(sir); j++) {
             if(sir[i] > sir[j]) {
                char temp=sir[i];
                sir[i]=sir[j];
                sir[j]=temp;
             }
          }
       }
    printf("\n\t Sir modificat: %s", sir);
// ===========================================================================================================

    //printf("\n\n 42.Scrieti un program C pentru a valida o expresie matematica, formata din simbolurile \"0123456789+-*/)(\", daca este introdusa gresit.\n");

    printf("\n\n");
	return 0;
}
