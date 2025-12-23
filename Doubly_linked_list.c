 
#include <stdio.h>
#include <stdlib.h>



struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;



void insert(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}



void displayEven() {
    struct node *temp = head;
    printf("Even numbers: ");
    while (temp != NULL) {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;
    return 1;
}



void displayPrime() {
    struct node *temp = head;
    printf("Prime numbers: ");
    while (temp != NULL) {
        if (isPrime(temp->data))
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



void findSum() {
    int sum = 0;
    struct node *temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum = %d\n", sum);
}



void sumAndAverage() {
    int sum = 0, count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    printf("Sum = %d\nAverage = %.2f\n", sum, (float)sum / count);
}



void findMinMax() {
    struct node *temp = head;
    int min = temp->data, max = temp->data;

    while (temp != NULL) {
        if (temp->data < min) min = temp->data;
        if (temp->data > max) max = temp->data;
        temp = temp->next;
    }
    printf("Min = %d\nMax = %d\n", min, max);
}

int main() {
    insert(10);
    insert(7);
    insert(4);
    insert(15);
    insert(2);

    displayEven();
    displayPrime();
    findSum();
    sumAndAverage();
    findMinMax();

    return 0;
}
 
#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[30];
    float marks;
    struct student *prev;
    struct student *next;
};

struct student *head = NULL;



void insertStudent(int roll, char name[], float marks) {
    struct student *newnode = (struct student *)malloc(sizeof(struct student));
    newnode->roll = roll;
    newnode->marks = marks;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct student *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}



void displayPass() {
    struct student *temp = head;
    printf("\nPassing Students (Marks > 40):\n");
    while (temp != NULL) {
        if (temp->marks > 40) {
            printf("Roll: %d  Name: %s  Marks: %.2f\n",
                   temp->roll, temp->name, temp->marks);
        }
        temp = temp->next;
    }
}

int main() {
    insertStudent(1, "Rahul", 65);
    insertStudent(2, "Anita", 35);
    insertStudent(3, "Suresh", 78);
    insertStudent(4, "Neha", 42);

    displayPass();
    return 0;
}

