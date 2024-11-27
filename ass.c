#include<stdio.h>  // included the header file tp to do standard input output operations
#include<malloc.h>  // uses malloc.h to use malloc function for memory allocation 
#include<string.h> // this is used to sue string the executions

//creating a struct of node which contains two parts one is student name and another is reference pointer
struct Node{
    char Student_Name[10];  // as there is no string data type in c language then the char data type with size is declared 
    struct Node *next;  // here the pointer next of type node is created
};

//globally declared the head pointer which is initially is set to null because at the initial level there is no any node of which the head contain the address
struct Node *head = NULL;
struct Node *temp;  //declaring the temp pointer of struct node to ease out the traversing opeartions

//creating a function add student to add student to given linked list
void addstudent(char name[10]){  //taking the name as a argument
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));  //creating the new pointer which holds the address of the new memory allocation of the new node
    strcpy(newNode->Student_Name,name);  //here strcpy is because assigning strings directly is not valid in c
    newNode->next=NULL; 
    if(head==NULL){  //checking the condition that if the head is empty means there is no any node linked with it
        head=temp=newNode; // if the condition mathces  then head is assigned to the address of newnode that is now the new node is linked with head
    }
    else{ //if not so 
        temp->next=newNode; //then the next part of the node is linked to the newnode address
        temp=newNode; // temp is now pointing towards the newly created node
    }
    temp->next=head; // in order to implement cyclic linked list the tem->next is assigned as head 
}


//the function listlength() is created with the intention to keep the count of the list that how many elements are left in list 
int listlength(){
    int count=0;
    struct Node *p=head;  //initialising the pointer p with the head value 
    if(head==0){
        printf("No element in the list");  // if there is no address in head then surely the list is empty
    }
    else{
        while(p->next!=head){  //the loop will iterate till it reaches the last node of circular linked lsit
            count=count+1;  //incrementing the count with 1
            p=p->next;
        }
        count=count+1;  // as our loop terminated before so the length of the last node is not counted so in order to count that this incrimention is done
    }
    return count; //returning the value of count
}

//creating the function to traverse in the linked list and print out the student names
void displaystudents(){
    struct Node *t;
    if(head==NULL){
        printf("No Data Found!!");
    }
    else{
        t=head;
        while(t->next!=head){
            printf("Participator: %s \n",t->Student_Name);
            t = t->next;
        }
        printf("Participator:%s ",t->Student_Name);  // as this is a circular linked list and we are terminating the while loop before the last node which points towards the first node so in order to print the name of that node this staement is used
    }

}

//the function to implement elimination process
void elimination(int randomnum) { // this function takes the random number as an argument
    struct Node *mojuda = head, *pichla = NULL;  //declaring the two pointers traverse in the list
    int count_maintain = listlength();  // declared the count maintain variable which stres the value retuned by the listlength function

    if (head == NULL) { //initially checking for the head null condition 
        printf("No data found for elimination.\n"); // if there is no data then the function is returned 
        return;
    }
    // iterating through the loop till there is more than one node left in the linked list
    while (count_maintain > 1) {
        for (int i = 1; i < randomnum; i++) {  // this loop help to reach to the node which have to be eliminated in the random order
            pichla = mojuda;
            mojuda = mojuda->next;
        }
        printf("\nAccording The sequence of Random Number %d\n",randomnum);
        printf("Eliminated student is %s\n", mojuda->Student_Name);

        if (mojuda == head) {
            head = head->next;
            temp->next = head; // Maintain circular link
        } else {
            pichla->next = mojuda->next;
        }

        free(mojuda); // Free eliminated node
        mojuda = pichla->next;
        count_maintain--;
    }

    head = mojuda; // Updating the head to the last remaining node
    printf("\n\n***************************************************************************\n");
    printf("\nThe monitor selected using the selection proces is: %s\n", head->Student_Name);
    printf("\n\n***************************************************************************\n");
}



int main() {
    int count_maintain=0;
    int Num_of_Student;
    char studentName[10];
    int random_num;
    printf("\nWELCOME TO ELECTION SELECTION AND ELIMINATION PROCESS!!\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n\n**************************************************************\n");
    printf("Enter the number of students that participate in Election: ");
    scanf("%d", &Num_of_Student);

    for (int i = 0; i < Num_of_Student; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", studentName); 
        addstudent(studentName);
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Name of participants in election\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    displaystudents();
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\nEnter a random number for elimination process:");
    scanf("%d",&random_num);
    elimination(random_num);

    return 0;
}