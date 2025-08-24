#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    struct Student* next;
};

// Function Prototypes
void addStudent(struct Student** head, int id, char name[]);
void dropStudent(struct Student** head, int id);
void searchStudent(struct Student* head, int id);
void displayStudents(struct Student* head);
void reverseList(struct Student** head);
struct Student* cloneList(struct Student* head);
int countStudents(struct Student* head);

// Add Student
void addStudent(struct Student** head, int id, char name[]) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Student* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Student %s added successfully!\n", name);
}

// Drop Student
void dropStudent(struct Student** head, int id) {
    struct Student *temp = *head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("Student with ID %d dropped successfully!\n", id);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with ID %d not found!\n", id);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student with ID %d dropped successfully!\n", id);
}

// Search Student
void searchStudent(struct Student* head, int id) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Student Found: ID=%d, Name=%s\n", temp->id, temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %d not found!\n", id);
}

// Display Students
void displayStudents(struct Student* head) {
    if (head == NULL) {
        printf("No students enrolled!\n");
        return;
    }
    printf("Enrolled Students:\n");
    struct Student* temp = head;
    while (temp != NULL) {
        printf("ID=%d, Name=%s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

// Reverse List
void reverseList(struct Student** head) {
    struct Student *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("Student list reversed successfully!\n");
}

// Clone List
struct Student* cloneList(struct Student* head) {
    if (head == NULL) return NULL;

    struct Student* newHead = NULL;
    struct Student* temp = head;
    while (temp != NULL) {
        addStudent(&newHead, temp->id, temp->name);
        temp = temp->next;
    }
    printf("Student list cloned successfully!\n");
    return newHead;
}

// Count Students
int countStudents(struct Student* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    struct Student* course = NULL;
    struct Student* backup = NULL;
    int choice, id;
    char name[50];

    do {
        printf("\n---- Course Enrollment Management ----\n");
        printf("1. Add Student\n");
        printf("2. Drop Student\n");
        printf("3. Search Student\n");
        printf("4. Display Students\n");
        printf("5. Reverse Student List\n");
        printf("6. Clone Enrollment List\n");
        printf("7. Count Students\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                addStudent(&course, id, name);
                break;

            case 2:
                printf("Enter ID to Drop: ");
                scanf("%d", &id);
                dropStudent(&course, id);
                break;

            case 3:
                printf("Enter ID to Search: ");
                scanf("%d", &id);
                searchStudent(course, id);
                break;

            case 4:
                displayStudents(course);
                break;

            case 5:
                reverseList(&course);
                break;

            case 6:
                backup = cloneList(course);
                break;

            case 7:
                printf("Total Students Enrolled: %d\n", countStudents(course));
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
