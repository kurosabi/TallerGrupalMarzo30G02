#include "funcs.h"

void updateUser(User* u)
{
    printf("Nombre: ");
    scanf("%s", u->name);

    printf("Tipo de sangre: \n");
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
    u->type = typeChoice - 1;

    u->donations = 0;
}

void addUser(User mat[][MAX_CAP], int* groupSizes, int cap)
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
            case 0:
                printf("A+: "); break;
            case 1:
                printf("A-: "); break;
            case 2:
                printf("B+: "); break;
            case 3:
                printf("B+-: "); break;
            case 4:
                printf("AB+: "); break;
            case 5:
                printf("AB+-: "); break;
            case 6:
                printf("O+: "); break;
            case 7:
                printf("O-: "); break;
        }
        printf("%d\n", counts[i]);
    }
}

void searchByType(User mat[][MAX_CAP], int *groupSizes)
{
    printf("Tipo de sangre: \n");
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
    typeChoice--;

    printf("Usuarios:\n");
    int i;
    for (i = 0; i < groupSizes[typeChoice]; i++)
    {
        printf("Nombre: %s\n", mat[typeChoice][i].name);
        printf("Total Donado: %d\n", mat[typeChoice][i].donations);
        printf("===============\n");
    }
}

void makeDonation(User mat[][MAX_CAP], int *counts, int cap)
{
    char searchName[20];
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