#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A binary search tree (BST), also called an ordered or sorted binary tree, 
// is a rooted binary tree data structure whose internal nodes each store a key greater than all the keys in the node's left subtree and 
// less than those in its right subtree.
/* example of BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

struct binary_search_node
{
	int key, age;
	float media;
	char name[50];
	struct binary_search_node *left, *right;
};
typedef struct binary_search_node binary_search_node;
//==========================================================================

//= 1. Crearea arborelui binar ============================================
// INSERAREA ---------------------------------------------------------------
char random_students[][50] = {"Braguta Maxim", "Buza Catalin", "Captarenco Vasile", "Cojocari Dragos", "Corobschinski Iana"};
int nr_elements=5;

binary_search_node *getNewNode(int key)
{
    binary_search_node *newNode = malloc(sizeof(binary_search_node));
	newNode->key = key;
	newNode->age = rand() % 20 + 15;
	newNode->media = (float)rand()/(float)(RAND_MAX/5.0) + 5.0;
	strcpy(newNode->name, random_students[rand() % 5]);

    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct binary_search_node *insert_into_Binary_Search_Tree(binary_search_node *root, int key)
{
    if(root == NULL)
        return getNewNode(key);

    if(root->key < key)
        root->right = insert_into_Binary_Search_Tree(root->right,key);

    else if(root->key > key)
        root->left = insert_into_Binary_Search_Tree(root->left,key);

    return root;
}
//=========================================================================


//= 3. Căutarea unui nod in baza unei chei de căutare=======================
binary_search_node* search_node_in_BinaryTree(binary_search_node *node, int value)
{
	if(node == NULL || node->key == value)// arborele nu are noduri || gasit valoare
		return node;

	if(value > node->key)
		return search_node_in_BinaryTree(node->right, value);

	if(value < node->key)
		return search_node_in_BinaryTree(node->left, value);

	return NULL;
}
//=========================================================================


//= 2. Afisarea arborelui =================================================
// 4. Inorder (Left, Root, Right) =========================================
void print_Tree_in_Inorder(binary_search_node *node){
	if(node != NULL){
		print_Tree_in_Inorder(node->left);

		printf("\nKey --> %d", node->key);
	    printf("\nage --> %d", node->age);
	    printf("\nmedia --> %f", node->media);
	    printf("\nnuma prenume --> %s", node->name);
	    printf("\n---------------------------------------\n");

		print_Tree_in_Inorder(node->right);
	}
}
//=========================================================================

// 5. afisarea in preordine(Preorder) [Root, Left, Right] 
void print_Tree_in_Preorder(binary_search_node *node){
	if(node != NULL){
		printf("\nKey --> %d", node->key);
	    printf("\nage --> %d", node->age);
	    printf("\nmedia --> %f", node->media);
	    printf("\nnuma prenume --> %s", node->name);
	    printf("\n---------------------------------------\n");

		print_Tree_in_Preorder(node->left);
		print_Tree_in_Preorder(node->right);
	}
}
//=========================================================================

//= 6.Postorder (Left, Right, Root) =======================================
void print_Tree_in_Postorder(binary_search_node* node){
	if(node != NULL){
		print_Tree_in_Postorder(node -> left);
		print_Tree_in_Postorder(node -> right);

		printf("\nKey --> %d", node->key);
	    printf("\nage --> %d", node->age);
	    printf("\nmedia --> %f", node->media);
	    printf("\nnuma prenume --> %s", node->name);
	    printf("\n---------------------------------------\n");
	}
}
//=========================================================================

//=========================================================================
// 7 - parcurgere DFS
void DFS(binary_search_node *root)
{
    if (root)
    {
        if (root->left)
        {
            DFS(root->left);
        }

        if (root->right)
        {
            DFS(root->right);
        }

		printf("\nKey --> %d", root->key);
	    printf("\nage --> %d", root->age);
	    printf("\nmedia --> %f", root->media);
	    printf("\nnuma prenume --> %s", root->name);
	    printf("\n---------------------------------------\n");
    }
}
//=========================================================================


//=========================================================================
//= 9 - balansarea arborelui
// Conditii pentru arbore balansat:
// 1. diferenta intre subarborele stanga si drept pentru orice nod nui mai mult decat 1
// 2. subarborele stanga ii balansat
// 3. subarborele drept ii balansat

int check_if_is_balanced(binary_search_node *root, int *height) 
{
	// Verificare daca este gol
	int leftHeight = 0, rightHeight = 0;
	int l = 0, r = 0;

	if (root == NULL) 
	{
	  	*height = 0;
	    return 1;
	}

	l = check_if_is_balanced(root->left, &leftHeight);
	r = check_if_is_balanced(root->right, &rightHeight);

	*height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

	if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
	    return 0;
	else
		return l && r;
}
//=========================================================================

//=========================================================================
// 10 - oglindirea arborelui
void oglindirea_arborelui(binary_search_node* root)
{
    if(root==NULL)
        return;
    else
    {
        binary_search_node *aux;
        oglindirea_arborelui(root->left);
        oglindirea_arborelui(root->right);

        aux = root->left;
        root->left = root->right;
        root->right = aux;
    }
}
//=========================================================================

//= 11. curatirea elementelor arborelui ====================================
void clear_elements(binary_search_node * node)
{
    if (node == NULL) 
    	return;
 
    clear_elements(node->left);
    clear_elements(node->right);

    node->key=0;
    node->age=0;
    node->media=0.0;
    strcpy(node->name,"");
}
//=========================================================================


//= 12. stergerea arborelui binar de cautare ==========================================
void delete_binary_tree(binary_search_node * node)
{
    if (node == NULL) 
    	return;
 
    /* parcurgem subarborele stanga si il stergem, apoi subarborele drept si il stergem */
    delete_binary_tree(node->left);
    delete_binary_tree(node->right);

    printf("Nodul sters: key[%d]\n", node->key);
    free(node);
}
//=========================================================================
void check_if_BinarySearchTree_exists(binary_search_node* root){
	if(root == NULL)
		{
			printf("\n |==== arborele nu exista! ====|\n");
			exit(2);
		}	
}
void menu();

int main()
{
	int option;
	binary_search_node *root = NULL;
	srand(time(NULL));

	do
	{
		menu();
		printf("\n| option -> ");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
			{
				for (int i = 0; i < nr_elements; i++)
 					root = insert_into_Binary_Search_Tree(root, i);
				break;
			}

			case 2:
			{
				check_if_BinarySearchTree_exists(root);
				printf("\nAfisarea in preordine [Root, Left, Right] ");
				print_Tree_in_Preorder(root);

				printf("\nAfisarea in inordine (Left, Root, Right) ");
				print_Tree_in_Inorder(root);

				printf("\nAfisarea in postordine (Left, Right, Root) ");
				print_Tree_in_Postorder(root);
				break;
			}

			case 3:
			{
				check_if_BinarySearchTree_exists(root);
				int key;
				printf("key: "); scanf("%d", &key);

				binary_search_node *tmp_node = search_node_in_BinaryTree(root,key);

				if(tmp_node != NULL)
				{
					printf("\n---Nodul a fost gasit---");
					printf("\nNodul cu adresa: %p",tmp_node);
					printf("\nKey --> %d", tmp_node->key);
					printf("\nNume Prenume --> %s", tmp_node->name);
					printf("\nMedia --> %f", tmp_node->media);
					printf("\nVarsta --> %d", tmp_node->age);
				}
				else 
					printf("Valoare data nu a fost intalnita in arbore!");
				break;
			}

			case 4:
			{
				check_if_BinarySearchTree_exists(root);
				print_Tree_in_Inorder(root);
				break;
			}

			case 5:
			{
				check_if_BinarySearchTree_exists(root);
				print_Tree_in_Preorder(root);
				break;
			}

			case 6:
			{
				check_if_BinarySearchTree_exists(root);
				print_Tree_in_Postorder(root);
				break;
			}

			case 7:
			{
				DFS(root);
				break;
			}

			case 9:
			{
				int height = 0;
				if (check_if_is_balanced(root, &height) )
				    printf("Arborele este balansat");
				else
				    printf("Arborele nu este balansat");
				break;
			}

			case 10:
			{
				oglindirea_arborelui(root);
				break;
			}

			case 11:
			{
				check_if_BinarySearchTree_exists(root);

				clear_elements(root);
				break;
			}

			case 12:
			{
				delete_binary_tree(root);
				root=NULL;
				printf("|=== Memoria arborelui a fost eliberata! ===|");
				break;
			}
		}
	} while (option != 0);

	printf("\n");
	return 0;
}

void menu()
{
	printf("\n\n---------------------- MENIU --------------------------------------------------------------------------------------------------------");
	printf("\n 1 | - citirea de la tastatură a elementelor arborelui;");
	printf("\n 2 | - afisarea la consolă a elementelor arborelui;");
	printf("\n 3 | - cautarea unui nod în baza cîmpului cheie și afișarea cîmpurilor nodului găsit;");
	printf("\n 4 | - parcurgerea arborelui în inordine;");
	printf("\n 5 | - parcurgerea arborelui în preordine;");
	printf("\n 6 | - parcurgerea arborelui în postordine;");
	printf("\n 7 | - parcurgerea arborelui în adîncime( DFS);");
	printf("\n 8 - parcurgerea arborelui în lărgime ( BFS);");
	printf("\n 9 | - balansarea arborelui");
	printf("\n10 | - oglindirea arborelui (orice nod copil drept, devine un nod copil stîng și analog orice nod copil stîng devine un nod copil drept),");
	printf("\n 	   ține cont că dupa oglindirea arborelui binar de căutare proprietatea între nod și copii se va schimba,");
	printf("\n 	   prin urmare si căutarea deja se va face în altă ordine;");
	printf("\n11 | - curățirea elementelor arborelui;");
	printf("\n12 | - eliberarea memoriei arborelui.");
}