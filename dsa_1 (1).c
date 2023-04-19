#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login_system()
{
	int v=0,t=0;
    char username[10],c=' ';
    char password[10],code[10];
    char user[10]="user";
    char passwords[10]="pass";
    do
    {
        printf("\n  **************************  LOGIN FORM  **************************  ");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &username);
        printf(" \n                       ENTER PASSWORD:-");
        while(t<10)
        {
            password[t]=getch();
            c=password[t];
            if(c==13)
                break;
            else
                printf("*");
            t++;
        }
        password[t]='\0';
        t=0;
        if(strcmp(username,"user")==0 && strcmp(password,"pass")==0)
        {
            printf("  \n\n\n       WELCOME TO PRISON MANAGEMENT SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            v++;
            getch();
        }
    }while(v<=2);
	if (v>2)
	{
		printf("\nSorry you have Entered the Wrong Username and Password for Four Times!!!");
		getch();
    }
    system("cls");
}

struct prisoner
{
    char name[50];
    int age;
    char crime[100];
    char gender[10];
    char nationality[50];
    char address[100];
    char sentence[100];
    struct prisoner *next;
};

struct staff
{
    char name[50];
    int age;
    char gender[10];
    char nationality[50];
    char address[100];
    char position[50];
    struct prisoner *prisoners[4];
    struct staff *next;
};

struct visitor
{
    char name[50];
    char id[10];
    char purpose[100];
    struct Visitor *next;
};

void add_prisoner(struct prisoner **head)
{
    struct prisoner *new_prisoner = malloc(sizeof(struct prisoner));
    printf("Enter prisoner name: ");
    scanf("%s", new_prisoner->name);
    printf("Enter prisoner age: ");
    scanf("%d", &new_prisoner->age);
    printf("Enter prisoner crime: ");
    scanf("%s", new_prisoner->crime);
    printf("Enter prisoner gender: ");
    scanf("%s", new_prisoner->gender);
    printf("Enter prisoner nationality: ");
    scanf("%s", new_prisoner->nationality);
    printf("Enter prisoner address: ");
    scanf("%s", new_prisoner->address);
    printf("Enter prisoner sentence: ");
    scanf("%s", new_prisoner->sentence);
    new_prisoner->next = *head;
    *head = new_prisoner;
    printf("Prisoner added successfully.\n");
    printf("--------------------\n");
}

void add_staff(struct staff **head)
{
    struct staff *new_staff = malloc(sizeof(struct staff));
    printf("Enter staff name: ");
    scanf("%s", new_staff->name);
    printf("Enter staff age: ");
    scanf("%d", &new_staff->age);
    printf("Enter staff gender: ");
    scanf("%s", new_staff->gender);
    printf("Enter staff nationality: ");
    scanf("%s", new_staff->nationality);
    printf("Enter staff address: ");
    scanf("%s", new_staff->address);
    printf("Enter staff position: ");
    scanf("%s", new_staff->position);
    int i;
    for (i = 0; i < 4; i++)
    {
        new_staff->prisoners[i] = NULL;
    }
    new_staff->next = *head;
    *head = new_staff;
    printf("Staff member added successfully.\n");
    printf("--------------------\n");
}

void add_visitor(struct visitor **head)
{
    struct visitor *newVisitor = (struct visitor*) malloc(sizeof(struct visitor));
    printf("Enter Visitor name: ");
    scanf("%s", newVisitor->name);
    printf("Enter Visitor ID: ");
    scanf("%s", newVisitor->id);
    printf("Enter the visitor's purpose: ");
    scanf("%s", newVisitor->purpose);
    newVisitor->next = NULL;
    if (*head == NULL)
    {
        *head = newVisitor;
    }
    else
    {
        struct visitor *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newVisitor;
    }
    printf("Visitor added successfully.\n");
    printf("--------------------\n");
}

void assign_prisoner(struct staff *staff_head, struct prisoner *prisoner_head)
 {
    char staff_name[50];
    char prisoner_name[50];
    printf("Enter staff member name: ");
    scanf("%s", staff_name);
    printf("Enter prisoner name: ");
    scanf("%s", prisoner_name);
    struct staff *current_staff = staff_head;
    while (current_staff != NULL)
    {
        if (strcmp(current_staff->name, staff_name) == 0)
        {
            break;
        }
        current_staff = current_staff->next;
    }
    if (current_staff == NULL)
    {
        printf("Staff member not found.\n");
        return;
    }
    struct prisoner *current_prisoner = prisoner_head;
    while (current_prisoner != NULL)
    {
        if (strcmp(current_prisoner->name, prisoner_name) == 0)
        {
            break;
        }
        current_prisoner = current_prisoner->next;
    }
    if (current_prisoner == NULL)
    {
        printf("Prisoner not found.\n");
        return;
    }
    int i;
    for (i = 0; i < 4; i++)
    {
        if (current_staff->prisoners[i] == NULL)
        {
            current_staff->prisoners[i] = current_prisoner;
            printf("Prisoner assigned to staff member successfully.\n");
            printf("--------------------\n");
            return;
        }
    }
    printf("Staff member already has 4 prisoners assigned to them.\n");
    printf("--------------------\n");
}

void delete_prisoner(struct prisoner **head)
{
    char name[50];
    printf("Enter the name of the prisoner you want to delete: ");
    scanf("%s", name);
    struct prisoner *current = *head;
    struct prisoner *prev = NULL;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (prev == NULL)
            {
                *head = current->next;
            } else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Prisoner deleted successfully.\n");
            printf("--------------------\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Prisoner not found.\n");
    printf("--------------------\n");
}

void view_prisoners(struct prisoner *head)
{
    struct prisoner *current = head;
    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Crime: %s\n", current->crime);
        printf("Gender: %s\n", current->gender);
        printf("Nationality: %s\n", current->nationality);
        printf("Address: %s\n", current->address);
        printf("Sentence: %s\n", current->sentence);
        printf("--------------------\n");
        current = current->next;
    }
}

void view_staff(struct staff *head)
 {
    struct staff *current = head;
    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Gender: %s\n", current->gender);
        printf("Nationality: %s\n", current->nationality);
        printf("Address: %s\n", current->address);
        printf("Position: %s\n", current->position);
        printf("Prisoners assigned:\n");
        int i;
        for (i = 0; i < 4; i++) {
            if (current->prisoners[i] != NULL)
            {
                printf("- %s\n", current->prisoners[i]->name);
            }
        }
        current = current->next;
        printf("--------------------\n");
    }
}
void view_visitors(struct visitor *head)
{
    struct visitor *current = head;
    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        printf("ID: %s\n", current->id);
        printf("Purpose: %s\n", current->purpose);
        printf("------------------------\n");
        current = current->next;
    }
}

void search_visitor(struct visitor *head, char id[])
{
    struct visitor *current = head;
    while (current != NULL)
    {
        if (strcmp(current->id, id) == 0)
        {
            printf("Name: %s\n", current->name);
            printf("ID: %s\n", current->id);
            printf("Purpose: %s\n", current->purpose);
            printf("------------------------\n");
            return;
        }
        current = current->next;
    }
    printf("Visitor with ID %s not found.\n", id);
}

void calculate_allowance()
{
    char prisoner_name[50],crime[50];
    float work_done;
    printf("Enter the name of the prisoner: ");
    scanf("%s", prisoner_name);
    printf("Enter the crime committed by the prisoner %s: ",prisoner_name);
    scanf("%s", crime);
    printf("Enter the number of hours of work done by %s: ", prisoner_name);
    scanf("%f", &work_done);
    float allowance;
    if (strcmp(crime, "Murder") == 0)
    {
        allowance = work_done * 5;
    }
    else if (strcmp(crime, "Drug") == 0)
    {
        allowance = work_done * 10;
    }
    else if (strcmp(crime, "Robbery") == 0)
    {
        allowance = work_done * 15;
    }
    else if (strcmp(crime, "Robbery") == 0)
    {
        allowance = work_done * 10;
    }
    else
    {
        allowance = work_done * 5;
    }
    printf("%s's allowance for %0.2f hours of work is Rs. %0.2f.\n", prisoner_name, work_done, allowance);
    printf("--------------------\n");
}

void health_checkup()
{
    char prisoner_name[50],disease[50];
    printf("Enter the name of the prisoner: ");
    scanf("%s", prisoner_name);
    printf("Enter the disease for %s: ",prisoner_name);
    scanf("%s", disease);
    if (strcmp(disease, "diabetes") == 0 || strcmp(disease, "cardiac") == 0)
    {
        printf("CHECKUP NEEDED EVERY MONTHLY FOR %s",prisoner_name);
    }
    else if (strcmp(disease, "bp") == 0)
    {
        printf("CHECKUP NEEDED EVERY WEEKLY FOR %s",prisoner_name);
    }
    else if (strcmp(disease, "dental") == 0)
    {
        printf("CHECKUP NEEDED ONCE FOR TWO MONTHS FOR %s",prisoner_name);
    }
    else
    {
        printf("NO REGULAR CHECKUP NEEDED  FOR %s\n",prisoner_name);
    }
    printf("--------------------\n");
}

int main()
{
    login_system();
    printf("\n\n\t***********************************\n");
    printf("\t\t*PRISONER RECORD*\n");
    printf("\t***********************************");
    struct prisoner *prisoner_head = NULL;
    struct staff *staff_head = NULL;
    struct visitor *visitor_head = NULL;
    int choice;
    char vid[10];
    do
    {
        printf("Enter your choice:\n");
        printf("1. Add prisoner\n");
        printf("2. Add staff member\n");
        printf("3. Assign prisoner to staff member\n");
        printf("4. Delete prisoner\n");
        printf("5. View prisoners\n");
        printf("6. View staff\n");
        printf("7. Find allowance\n");
        printf("8. Add Visitor\n");
        printf("9. View Visitor\n");
        printf("10. Search Visitor\n");
        printf("11. health checkup\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: add_prisoner(&prisoner_head);
                    break;
            case 2: add_staff(&staff_head);
                    break;
            case 3: assign_prisoner(staff_head, prisoner_head);
                    break;
            case 4: delete_prisoner(&prisoner_head);
                    break;
            case 5: view_prisoners(prisoner_head);
                    break;
            case 6: view_staff(staff_head);
                    break;
            case 7: calculate_allowance(&prisoner_head);
                    break;
            case 8: add_visitor(&visitor_head);
                    break;
            case 9: view_visitors(visitor_head);
                    break;
            case 10: printf("Enter the id of the visitor: ");
                     scanf("%s",vid);
                     search_visitor(visitor_head,vid);
                     break;
            case 11: health_checkup(&prisoner_head);
                    break;
            case 12: exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 11.\n");
        }
    } while (choice != 4);
    return 0;
}
