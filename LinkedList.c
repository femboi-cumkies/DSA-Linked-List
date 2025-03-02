#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

// Type Declaration
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Function declaration
void createList(Node** head, char Resp);
void traverseList(Node* head);
void insertAtEnd(Node** head, int data);
void insertBeforeValue(Node** head, int *value, int *data);
void insertAfterValue(Node** head, int *value, int *data);
void deleteByValue(Node **head, int value);
void emptyList(Node** head);
void gotoxy (int x, int y);
void displayMenu();

/*MAIN FUNCTION*/

int main() {
    Node* head = NULL;
    int action, value, data;
    char Resp;
    
    while (1) {
		
		system("CLS");
		displayMenu();
        printf("\n\n\nEnter your choice: ");
        scanf("%d", &action);
        getchar();
        

        switch (action) {
            case 1:
                createList(&head, Resp);
                break;
            case 2:
                traverseList(head);
                break;
            case 3:
                
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 5:
            	insertBeforeValue(&head, &data, &value);
            	break;
            case 6:
            	insertAfterValue(&head, &data, &value);
            	break;
            case 7:
            	
            case 8:
            	
            case 9:
            	printf("Enter value to be deleted\n\tValue => ");
				scanf("%d", &value);
				getchar();
            	deleteByValue(&head, value);
            	break;
            case 10:
            	emptyList(&head);
                break;
            case 11:
            	emptyList(&head);
                printf("Exiting program. Thank you for choosing our program.\n");
                return 0;
            default:
                printf("Invalid choice! Please input a number from 1 to 11.\n");
                Sleep(2000);
                system("CLS");
        }
    }
}

//FUNCTION DEFINITION

//Linked list functions

//1
void createList(Node** head, char Resp){
	int Ctr = 1;
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	*head = newNode;
	
	printf("Creating a new linked list.\n");
	
	do {
		printf("Node No. %d\n",Ctr);
    	printf("Enter Data => ");
    	scanf("%d",&newNode->data);
    	getchar();
    	printf("\nAdd another NODE [Y/N]? ");
    	scanf("%c",&Resp);
      if (toupper(Resp) == 'Y')
       {
		Ctr++;
		newNode->next=(Node*)malloc(sizeof(Node));
		newNode = newNode->next;
       }
   }while(toupper(Resp)=='Y');
   getchar();
   newNode->next = NULL;
   newNode = NULL;
   
   printf("\n\nLinked list successfully created!\nPress any key to continue...");
   getchar();

	
}

//2
void traverseList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        printf("\nPress any key to continue...");
		getchar();
        return;
    }

    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    printf("\n\nPress any key to continue...");
    getchar();
}

//3

//4
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    
}

//5

void insertBeforeValue(Node** head, int *value, int *data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	
	printf("Enter Data for new node => ");
	scanf("%d", &newNode->data);
	getchar();
	
	printf("Enter value to insert before => ");
	scanf("%d", value);
	getchar();
	
	Node* CURRENT = *head;
	Node* PREV = NULL;
	int flag = 0;
	
	do{
		
		if (*value == CURRENT->data){
			flag = 1;
		}else{
			PREV = CURRENT;
			CURRENT = CURRENT->next;
		}
	}while (CURRENT != NULL && flag != 1);
	
	if (flag == 1){
		newNode->next = CURRENT;
		
		if (PREV == NULL){
			*head = newNode;
		}else{
			PREV->next = newNode;
		}
		printf("\nNode successfully inserted!");
	}else{
		printf("\nThe value you entered is not in the linked list. Insertion failed.");
	}
	
	newNode = NULL;
	PREV = CURRENT = NULL;
	printf("\nPress any key to continue...");
	getchar();
	
}

//6

void insertAfterValue(Node** head, int *value, int *data){
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	
	printf("Enter Data for new node => ");
	scanf("%d", &newNode->data);
	getchar();
	
	printf("Enter value to insert after => ");
	scanf("%d", value);
	getchar();
	
	Node* CURRENT = *head;
	int flag = 0;
	
	do {
		
		if (CURRENT->data == *value){
			flag = 1;
		}else{
			CURRENT = CURRENT->next;
		}
	}while (CURRENT != NULL && flag != 1);
	
	if (flag == 1){
			newNode->next = CURRENT->next;
			CURRENT->next = newNode;
			printf("\nNode successfully inserted!");
		}else {
			printf("\nThe value you entered is not in the linked list. Insertion failed.");
		}
		
	newNode = NULL;
	printf("\nPress any key to continue...");
	getchar();
	
}
//7

//8

//9

void deleteByValue(Node **head, int value){
	Node *Previous=NULL, *DelNode=*head;
	int Flag=0;

	while (Flag!=1 && DelNode!=NULL)
	{
		if(value==DelNode->data)
			Flag=1;
		else 
		{
			Previous=DelNode;
			DelNode=DelNode->next;
		}
	}

	if (Flag==0)
		printf("Value to be deleted NOT FOUND!\n");
	else
	{
		if (DelNode==*head)
		{
			*head=(*head)->next;
			DelNode->next=NULL;
			printf("\nNode successfully deleted!");
		} else
		{
			Previous->next=DelNode->next;
			DelNode->next=NULL;
			printf("\nNode successfully deleted!");
		}
	}
	printf("\nPress any key to continue...");
	getchar();
	Previous=DelNode=NULL;
}

//10
void emptyList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    *head = NULL;
    printf("The list has been emptied.\n");
    printf("Press any key to continue...");
    getchar();
}

//Misc. Functions

void gotoxy (int x, int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void displayMenu(){
//		system("CLS");

		gotoxy(40, 1);
		printf("<@@ SINGLY LINKED LIST OPERATIONS @@>\n");

		
		gotoxy(10, 3);
		printf("Menu");
		gotoxy(10, 5);
		printf("[1] CREATION OF LINKED LIST");
		gotoxy(43, 5);
		printf("[2] TRAVERSAL OF THE LIST");
		gotoxy(73, 5);
		printf("[3] INSERTION OF NODE AT START");
		gotoxy(10, 7);
		printf("[4] INSERTION OF NODE AT END");
		gotoxy(43, 7);
		printf("[5] INSERTION OF NODE BEFORE");
		gotoxy(47, 8);
		printf("A VALUE");
		gotoxy(73, 7);
		printf("[6] INSERTION OF NODE AFTER A VALUE");
		gotoxy(10, 9);
		printf("[7] DELETION AT START");
		gotoxy(43, 9);
		printf("[8] DELETION AT END");
		gotoxy(73, 9);
		printf("[9] DELETION BY VALUE");
		gotoxy(30, 11);
		printf("[10] EMPTY LINKED LIST");
		gotoxy(63, 11);
		printf("[11] EXIT PROGRAM");
	
}
