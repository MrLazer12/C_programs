#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;

void initialize_array(int simple_array[])
{
	for(int i=0; i<n; i++)
		simple_array[i]=i;
}

void show_simple_array(int simple_array[])
{
	printf("Array = { ");
	for(int i=0; i<n; i++)
		printf("%d ", simple_array[i]);
	printf("}\n");
}

void delete_array(int simple_array[])
{
	free(simple_array);
}

void bubbleSort(int array[]) 
{
  	for (int step = 0; step < n - 1; ++step) 
  	{
    	for (int i = 0; i < n - step - 1; ++i) 
    	{
     		if (array[i] > array[i + 1]) 
     		{
		        int temp = array[i];
		        array[i] = array[i + 1];
		        array[i + 1] = temp;
      		}
    	}
  	}
}

// ==================================================================
// implementarea algoritm de sortare quickSort
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) 
{
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j < high; j++) {
	    if (array[j] <= pivot) 
	    {
	      	i++;
	    	swap(&array[i], &array[j]);
	    }
	}

	swap(&array[i + 1], &array[high]);
	  
	return (i + 1);
}

void quickSort(int array[], int low, int high) {
	if (low < high) {
	    int pi = partition(array, low, high);
	    
	    quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}
// ==================================================================


int linear_search(int simple_array[], int search_value)
{
	for(int i=0; i<n; i++)
		if(simple_array[i] == search_value)
			return 0;

	return -1;
}

int binarySearch(int array[], int x, int low, int high) 
{
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

void menu();

int main()
{
	printf("Elemente in array -> "); 
	scanf("%d",&n);

	int option, *simple_array=malloc(n*sizeof(int));
	srand(time(NULL));

	initialize_array(simple_array);

	do
	{
		menu();
		printf("\n| option => "); scanf("%d", &option);

		switch(option)
		{
			case 1:
			{
				clock_t tic = clock();
				
				bubbleSort(simple_array);
				
				clock_t toc = clock();
    		printf("\nbubbleSort -> timp: %f secunde\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    		//-----------------------------------------------------------------------------------


    		//-----------------------------------------------------------------------------------
				tic = clock();
				
				quickSort(simple_array, 0, n - 1);
				
				toc = clock();
    		printf("quickSort  -> timpul: %f secunde\n", (double)(toc - tic) / CLOCKS_PER_SEC);
				break;
			}

			case 2:
			{
				int search_value;
				printf("\nValoare spre cautare: "); scanf("%d",&search_value);

				clock_t tic = clock();
				
				int result = linear_search(simple_array,  n-1);
				if (result == -1)
				    printf("Valoarea %d: Nu sa gasit", search_value);
				else
				    printf("Valoarea %d, s-a gasit!", search_value);
				
				clock_t toc = clock();
    		printf("\nlinear_search -> timp: %f secunde\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    		//-----------------------------------------------------------------------------------


				//-----------------------------------------------------------------------------------
				tic = clock();
				
				result = binarySearch(simple_array, n-1, 0, n - 1);
				if (result == -1)
				    printf("Valoarea %d: Nu sa gasit", search_value);
				else
				    printf("Valoarea %d, s-a gasit!", search_value);
				
				toc = clock();
    		printf("\nbinarySearch -> timp: %f secunde\n", (double)(toc - tic) / CLOCKS_PER_SEC);
				break;
			}

			case 3:
			{
				show_simple_array(simple_array);
				break;
			}
		}
	} while(option != 0);

	printf("\n");
	return 0;
}

void menu()
{
	printf("\n-------------------MENIU-------------------------------------");
	printf("\n1 - sortarea tabloului bubbleSort");
	printf("\n    sortarea tabloului quickSort");
	printf("\n-------------------------------------------------------------");
	printf("\n2 - căutarea unui număr - metoda de căutare linear search");
	printf("\n    căutarea unui număr - metoda de căutare binary search");
	printf("\n3 - afisarea tabloului");
}