#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int nr_elements;

struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left, *right;
};
typedef struct BinaryTreeNode BinaryTreeNode;
//=========================================================================


//= 1. Crearea arborelui binar ============================================
// Creare nod -------------------------------------------------------
BinaryTreeNode *createNewNode(int data)
{
	BinaryTreeNode *node = malloc(sizeof(BinaryTreeNode));
	node->data = data;

	node->right = node->left = NULL;

	return node;
}

// INSERAREA -------------------------------------------------------
void insert_into_BinaryTree(BinaryTreeNode *current_node, BinaryTreeNode *new_node)
{
	if (current_node)
	{
		if (current_node->data > new_node->data)
		{
			if (current_node->left)
				insert_into_BinaryTree(current_node->left, new_node);
			else
				current_node->left = new_node;
		}
		else
		{
			if (current_node->right)
				insert_into_BinaryTree(current_node->right, new_node);
			else
				current_node->right = new_node;
		}
	}
}
//=========================================================================


//= 2. Afisarea arborelui =================================================
void printBinaryTree_in_2d(BinaryTreeNode *root, int space)
{
	if (root == NULL)
		return;

	// marirea dinstantei a subnivelurilor a arborelui
	space += 10;

	// adaugam spatiu pentru nodul din dreapta
	printBinaryTree_in_2d(root->right, space);

	// printam nodul curent dupa spatiul adaugat
	printf("\n");
	for (int i = 10; i < space; i++)
		printf(" ");
	printf("| %d |\n", root->data);
	// -----------------------------------------

	// adaugam spatiu pentru nodul din dreapta
	printBinaryTree_in_2d(root->left, space);
}

//afisarea in preordine(Preorder) [Root, Left, Right] 
void print_BinaryTree_in_Preorder(BinaryTreeNode *root){
	if(root != NULL){
		printf("%d ", root -> data);
		print_BinaryTree_in_Preorder(root -> left);
		print_BinaryTree_in_Preorder(root -> right);
	}
}
//=========================================================================


//= 3. Calcularea adancimii arborelui =====================================
// => Ideea generala:
//    1. calculam recursiv adancimea subarborelor stanga si dreapta
//    2. height = max(subarbore_dreapta, subarbore_stanga) - gasim maximul adancimii intre subarbore stanga si dreapta
//    3. adancimea arborelui =  height + 1(root); - Adaug 1 pentru nodul curent (root).
int height_of_binary_tree(struct BinaryTreeNode *node)
{
	if (node == NULL)
		return 0;
	else
	{
		int left_side = height_of_binary_tree(node->left);
		int right_side = height_of_binary_tree(node->right);

		if (left_side > right_side)
			return left_side + 1;
		else
			return right_side + 1;
	}
}
//=========================================================================


//= 4. Căutarea unui nod in baza unei chei de căutare=======================
BinaryTreeNode* search_node_in_BinaryTree(BinaryTreeNode *node, int value)
{
	if(node == NULL || node->data == value)// arborele nu are noduri || gasit valoare
		return node;

	if(value > node->data)
		return search_node_in_BinaryTree(node->right, value);

	if(value < node->data)
		return search_node_in_BinaryTree(node->left, value);

	return NULL;
}
//=========================================================================


//=========================================================================
//= 5. calcularea adîncimii unui nod ======================================
// What is depth in a tree?: The depth of a node is the number of edges(links) from that node to the tree's root node.
int findDepth(BinaryTreeNode* root, int x)
{
    if (root == NULL)
        return -1;
 
    int dist = -1; // -1, pentru a evita incrementarea suplimentara
 
    // daca nodul introdus sa gasit
    if ((root->data == x)
        // Altfel, verifica daca x este prezent in nodul stanga
        || (dist = findDepth(root->left, x)) >= 0
        // Altfel, verifica daca x este prezent in nodul dreapta
        || (dist = findDepth(root->right, x)) >= 0)
        return dist + 1;// returnam adancimea nodului

    return dist;
}


//=========================================================================
//= 6 - calcularea înălțimii unui nod =====================================
// conform definiitii: The height of a node in a binary tree is the largest number of edges in a path from a leaf node to a target node.
// 						height - adancimea
// 						edges - conectiune intre noduri (link)
int height_of_node(BinaryTreeNode *parent, int value){
	BinaryTreeNode* tmp_node = search_node_in_BinaryTree(parent, value);
	return height_of_binary_tree(tmp_node)-1;
}
//=========================================================================


//= 7. afișarea tuturor frunzelor arborelui ===============================
void print_all_leafs(BinaryTreeNode *node)
{
	if(node != NULL)
	{
		//consideram nodul frunza, atunci cand nu are niciun fiu
		if(node->left == NULL && node->right == NULL)
			printf("%d ", node->data);
		else
		{
			print_all_leafs(node->left);
			print_all_leafs(node->right);
		}
	}
}
//=========================================================================


//= 8. curatirea elementelor arborelui ====================================
void clear_elements(BinaryTreeNode * node)
{
    if (node == NULL) 
    	return;
 
    clear_elements(node->left);
    clear_elements(node->right);

    node->data=0;
}
//=========================================================================


//= 9. stergerea arborelui binar ==========================================
void delete_binary_tree(BinaryTreeNode * node)
{
    if (node == NULL) 
    	return;
 
    /* parcurgem subarborele stanga si il stergem, apoi subarborele drept si il stergem */
    delete_binary_tree(node->left);
    delete_binary_tree(node->right);

    printf("\n Nodul sters: %d", node->data);
    free(node);
}
//=========================================================================
void check_if_Binary_tree_exists(BinaryTreeNode* root){
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
	srand(time(NULL));
	// nodul parinte parintilor
	BinaryTreeNode *root;

	//---------------------------------------------------------------------
	do
	{
		menu();
		printf("\n| option -> ");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
			{
				root = createNewNode(rand() % 100);

				printf("numar de elemente -> ");
				scanf("%d", &nr_elements);

				for (int i = 0; i < nr_elements; i++)
				{
					BinaryTreeNode *new_node = createNewNode(rand() % 100);

					if (root)
						insert_into_BinaryTree(root, new_node);
					else
						root = new_node;
				}
				break;
			}

			case 2:
			{
				check_if_Binary_tree_exists(root);
				printBinaryTree_in_2d(root, 0);

				printf("\nafisare in preodrine: ");
				print_BinaryTree_in_Preorder(root);
				break;
			}

			case 3:
			{
				check_if_Binary_tree_exists(root);
				printf("adancimea arborelui: %d",height_of_binary_tree(root) );
				break;
			}

			case 4:
			{
				check_if_Binary_tree_exists(root);
				int value;
				printf("valoare (int) spre cautare: "); scanf("%d", &value);

				BinaryTreeNode *tmp_node = search_node_in_BinaryTree(root,value);

				if(tmp_node != NULL)
				{
					printf("\n---Nodul a fost gasit---");
					printf("\nNodul cu adresa: %p",tmp_node);
					printf("\nNodul cu valoarea: %d", tmp_node->data);
				}
				else 
					printf("Valoare data nu a fost intalnita in arbore!");
				break;
			}

			case 5:
			{
				check_if_Binary_tree_exists(root);
				int key;
				printf("selectare nod dupa key: "); scanf("%d", &key);
				printf("adancimea nodului cu key[%d] --> %d", key, findDepth(root, key) );
				break;
			}

			case 6:
			{
				check_if_Binary_tree_exists(root);
				int key;
				printf("selectare nod dupa key: "); scanf("%d", &key);

				printf("inaltimea nodului cu key[%d] --> %d", key, height_of_node(root, key) );
				break;
			}

			case 7:
			{
				check_if_Binary_tree_exists(root);
				printf("Frunzele: ");
				print_all_leafs(root);
				break;
			}

			case 8:
			{
				check_if_Binary_tree_exists(root);

				clear_elements(root);
				break;
			}

			case 9:
			{
				check_if_Binary_tree_exists(root);
				delete_binary_tree(root);
				root=NULL;
				printf("|=== Memoria arborelui a fost eliberata! ===|");
				break;
			}

			default:
				printf("Optiune gresita!");
		}
	} while (option != 0);

	printf("\n");
	return 0;
}

void menu()
{
	printf("\n\n---------------------- MENIU -----------------------------------------------------------------");
	printf("\n1 - citirea de la tastatură a elementelor arborelui");
	printf("\n2 - afișarea la consolă a elementelor arborelui");
	printf("\n3 - calcularea adancimii arborelui");
	printf("\n4 - căutarea unui nod in baza unei chei de căutare;");
	printf("\n5 - calcularea adîncimii unui nod ( nodul va fi selectat în baza unei chei de căutare )");
	printf("\n6 - calcularea înălțimii unui nod ( nodul va fi selectat în baza unei chei de căutare )");
	printf("\n7 - afișarea tuturor frunzelor arborelui");
	printf("\n8 - curățirea elementelor arborelui");
	printf("\n9 - eliberarea memoriei arborelui");
	printf("\n0 - Iesire din program.");
}
