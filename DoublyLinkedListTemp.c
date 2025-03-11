#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>

// Type Declaration
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

//global declaration



//Function declaration
void createList(Node** head, char Resp);
void traverseListTopToBottom(Node* head);
void traverseListBottomToTop(Node* tail);
void insertAtStart(Node** head, int data);
void insertAtEnd(Node** tail, int value);
void insertBeforeValue(Node** head, Node** tail, int value, int data);
void insertAfterValue(Node** head, Node** tail, int value, int data);
void deleteAtStart(Node** head); 
void deleteAtEnd(Node** tail);
void deleteByValue(Node **head, int value);
void emptyList(Node** head);
void gotoxy (int x, int y);
void displayMenu();

/*MAIN FUNCTION*/

int main() {
    Node* head = NULL;
    Node* tail = NULL;
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
                traverseListTopToBottom(head);
                break;
            case 3:
    			traverseListBottomToTop(tail);
    			break;
            case 4:
                printf("Enter value to insert at the start: ");
	    		scanf("%d", &value);
	    		getchar();
	    		insertAtStart(&head, value);
	    		break;
            case 5:
            	printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&tail, value);
                break;
            case 6:
            	printf("Enter value to be inserted: ");
            	scanf("%d", &data);
            	printf("Enter node value to be stored AFTER it\n\tNode Value: ");
            	scanf("%d", &value);
            	insertBeforeValue(&head, &tail, data, value);
            	break;
            case 7:
            	printf("Enter value to be inserted: ");
            	scanf("%d", &data);
            	printf("Enter node value to be stored AFTER it\n\tNode Value: ");
            	scanf("%d", &value);
            	insertAfterValue(&head, &tail, data, value);
            	break;
            case 8:
            	deleteAtStart(&head);
                break;
            case 9:
            	deleteAtEnd(&tail);
				break;
            case 10:
            	printf("Enter value to be deleted\n\tValue => ");
				scanf("%d", &value);
				getchar();
            	deleteByValue(&head, value);
            	break;
            case 11:
            	emptyList(&head);
                break;
            case 12:
            	emptyList(&head);
                printf("Exiting program. Thank you for choosing our program.\n");
                return 0;
            default:
                printf("Invalid choice! Please input a number from 1 to 12.\n");
                Sleep(2000);
                system("CLS");
        }
    }
}

//FUNCTION DEFINITION

//Linked list functions

//1
void createList(Node** head, char Resp){

	
}

//2
void traverseListTopToBottom(Node* head) {

}

//3
void traverseListBottomToTop(Node* tail) {

}

//4

void insertAtStart(Node** head, int data) {

}

//5

void insertAtEnd(Node** tail, int value) {

}

//6

void insertBeforeValue(Node** head, Node** tail,  int value, int data){

}
//7
void insertAfterValue(Node** head, Node** tail, int value, int data){
	Node *NewNode, *Current;
	
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->next=NULL;
	NewNode->prev=NULL;
	NewNode->data=data;
	Current = *head;
	
	if (Current == NULL) {
		printf("Doubly is EMPTY!\nPRESS ANY KEY TO CONTINUE...");
		getchar();
		return;
	} else while (Current->data==value && Current!=NULL) {
		Current = Current->next;
	}
	
	if (Current->data != value) {
		printf("The Value where you want to insert the New Node does not exist!\nPRESS ANY KEY TO CONTINUE...");
		getchar();
		return;
	} else {
		if (Current == *tail) {
			NewNode->prev = *tail;
			NewNode->prev->next = NewNode;
			*tail = NewNode;
		} else {
			NewNode->next = Current->next;
			NewNode->prev = Current;
			Current->next->prev = NewNode;
			Current->next = NewNode;
		}
		Current=NewNode=NULL;
	}
		
}

// 8
void deleteAtStart(Node** head) {

}

//9
void deleteAtEnd(Node** tail) {

}


//10
void deleteByValue(Node **head, int value){
	Node *DelNode;
	DelNode = *head;
	
	if(DelNode == NULL) {
		printf("Double is EMPTY!\nPRESS ANY KEY TO CONTINUE...");
		getchar();
		return;
	} else while (DelNode->data == value && DelNode != NULL) {
		DelNode = DelNode->next;
	} 
	
	if (DelNode->data != value) {
		printf("Value to be deleted NOT FOUND!\nPRESS ANY KEY TO CONTINUE...");
		getchar();
		return;
	} else if (DelNode == *head) {
		*head = (*head)->next;
		(*head)->prev=NULL;
		DelNode->next=NULL;
	} else {
		DelNode->prev->next = DelNode->next;
		DelNode->next->prev = DelNode->prev;
		DelNode->next=NULL;
		DelNode->prev=NULL;
	}
	
	printf("NODE with value of %d DELETED!\nPRESS ANY KEY TO CONTINUE...", DelNode->data);
	getchar();
	free(DelNode);
	DelNode = NULL;
}
//11
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
		printf("<@@ DOUBLY LINKED LIST OPERATIONS @@>\n");

		
		gotoxy(10, 3);
		printf("Menu");
		gotoxy(10, 5);
		printf("[1] CREATION OF LINKED LIST");
		gotoxy(43, 5);
		printf("[2] TRAVERSAL: TOP TO BOTTOM");
		gotoxy(73, 5);
		printf("[3] TRAVERSAL: BOTTOM TO TOP");
		gotoxy(10, 7);
		printf("[4] INSERTION OF NODE AT START");
		gotoxy(43, 7);
		printf("[5] INSERTION OF NODE AT END");
		gotoxy(73, 7);
		printf("[6] INSERTION OF NODE BEFORE");
		gotoxy(77, 8);
		printf("A VALUE");
		gotoxy(10, 9);
		printf("[7] INSERTION OF NODE AFTER");
		gotoxy(14, 10);
		printf("A VALUE");
		gotoxy(43, 9);
		printf("[8] DELETION AT START");
		gotoxy(73, 9);
		printf("[9] DELETION AT END");
		gotoxy(10, 11);
		printf("[10] DELETION BY VALUE");
		gotoxy(43, 11);
		printf("[11] EMPTY LINKED LIST");
		gotoxy(73, 11);
		printf("[12] EXIT PROGRAM");
	
}
