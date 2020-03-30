#include "funcs.h"

void updateUser(User* u)
{
    printf("Nombre: ");
    scanf("%s", u.name);

    printf("Tipo de sangre: ");
    printf("1: A+\n");
    printf("2: A-\n");
    printf("3: B+\n");
    printf("4: B-\n");
    printf("5: AB+\n");
    printf("6: AB-\n");
    printf("7: O+\n");
    printf("8: O-\n");
    int typeChoice;
    scanf("%d", &typeChoice);
    u.type = typeChoice - 1;

    u.donations = 0;
}

void addUser(User mat[][MAX_COL], int* groupSizes, int cap)
{
    User u;
    updateUser(&u);

    if (groupSizes[u.type] < cap)
    {
        mat[u.type][groupSizes[u.type]] = u;
        groupSizes[u.type]++;
    }
    else
    {
        printf("No hay mas espacio para este grupo\n");
    }
}

void displayCounts(int *counts)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        switch (i)
        {
            case 1:
                print("A+: ") break;
            case 2:
                print("A-: ") break;
            case 3:
                print("B+: ") break;
            case 4:
                print("B+-: ") break;
            case 5:
                print("AB+: ") break;
            case 6:
                print("AB+-: ") break;
            case 1:
                print("O+: ") break;
            case 1:
                print("O-: ") break;
        }
        printf("%d\n", counts[i]);
    }
}

//Add searchByType here

void makeDonation(User mat[][MAX_CAP], int *counts, int cap)
{
    char seachName[20];
    printf("Nombre: ");
    scanf("%s", searchName);

    int quantity;
    printf("Cantidad: ");
    scanf("%d", &quantity);

    int i, j, found = 0;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < cap; j++)
        {
            if (!strcmp(searchName, mat[i][j].name))
            {
                mat[i][j].donations += quantity;
                found = 1;
                break;
            }
        }
        
        if (found)
        {
            counts[i] += quantity;
            break;
        }
    }

    if (!found)
        printf("No se encontro un usuario con ese nombre\n");
}