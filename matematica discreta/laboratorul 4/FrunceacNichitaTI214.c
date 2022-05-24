#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int AdjacencyMatrix[50][50];

struct list {
	int data;
	struct list *next;
};

void append(struct list **head, int data)
{
	struct list *newData = (struct list*)malloc(sizeof(struct list));
	newData -> data = data;
	newData -> next = NULL;


	if(!(*head))
	{
		*head = newData;
		return;
	}

	struct list *temp = *head;

	while(temp -> next != NULL)
		temp = temp -> next;

	temp -> next = newData;
}

int popFirst(struct list **head)
{
	int first = (*head) -> data;
	struct list *temp = *head;

	(*head) = (*head) -> next;
	free(temp);

	return first;
}

int checkN(int nod[], int n)
{
	for(int i = 0; i < n; i++)
		if(nod[i] == 0)
			return 1;

	return 0;
}

int checkInList(struct list *head, int data)
{
	while(head){
		if(head -> data == data)
			return 1;
		head = head -> next;
	}

	return 0;
}

void copyLine(int array[], int noduri, int line)
{
	for(int i = 0; i < noduri; i++)
		AdjacencyMatrix[line][i] = array[i];
}

void delLeg(struct list *l1, struct list *l2, int noduri)
{
	int tempArr[noduri], tempNode; 

	while(l1){
		tempNode = l1 -> data;
		for(int i = 0; i < noduri; i++)
			tempArr[i] = 0;

		for(int i = 0; i < noduri; i++)
			if(AdjacencyMatrix[tempNode][i] == 1 && !checkInList(l2,i))
				tempArr[i] = 1;

		copyLine(tempArr,noduri, tempNode);
		l1 = l1 -> next;
	}
}

void grafAcoperire(int noduri, int start)
{
	struct list *FA1 = NULL, *FA2 = NULL, *temp;
	int nod[noduri], tempArr[noduri], current, tempNode;

	for(int i = 0; i < noduri; i++)
		nod[i] = 0;

	nod[start - 1] = 1;
	append(&FA1, start - 1);

	while(checkN(nod, noduri))
	{
		if(FA1){
			current = popFirst(&FA1);
			nod[current] = 1;

			//adaugare toti copii de la nodul current in lista FA2
			for(int i = 0; i < noduri; i++)
				if(AdjacencyMatrix[current][i] == 1 && !nod[i])
					append(&FA2,i);

			//stergere muchiilor care leaga nodurile din FA2
			delLeg(FA2,FA2, noduri);

			//stergea tuturor muchiilor in afara de una care leaga fiecare varg din FA2 cu varfurile din FA1
			delLeg(FA1,FA2, noduri);
			delLeg(FA2,FA1, noduri);

		} else {
			// Se vor schimba cu numele FA1 şi FA2 (FA1 va deveni FA2 şi invers).
			temp = FA1;
			FA1 = FA2;
			FA2 = temp;
		}

		if(!FA1 && !FA2)
			for(int i = 0; i < noduri; i++)
				if(nod[i] == 0)
					append(&FA1,i);
	}
}

void show_AdjacencyMatrix_as_adjanjyList(int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d | ", i+1);
		for(int j = 0; j < n; j++)
			if(AdjacencyMatrix[i][j])
				printf("%d ",j+1);
		printf("0\n");
	}
}

int num_rows_in_file(FILE *f)
{
	int count=0;
	char * line = NULL;
	size_t lenght = 0;
	ssize_t read;

	while((read = getline(&line, &lenght, f)) != -1) 
		count++;

	fseek(f, 0, SEEK_SET);//ne ducem la inceputul fisierului
	return count;
}

int main()
{
	srand(time(0));
	FILE *f = fopen("graf.txt","r");

	int n = num_rows_in_file(f);
	printf("%d",n);
	struct list *head = NULL;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			fscanf(f,"%d", &AdjacencyMatrix[i][j]);

	printf("\nGraful initial:\n");
	show_AdjacencyMatrix_as_adjanjyList(n);

	grafAcoperire(n, 1);

	printf("\nGraful de acoperire:\n");
	show_AdjacencyMatrix_as_adjanjyList(n);

	fclose(f);
	return 0;
}
