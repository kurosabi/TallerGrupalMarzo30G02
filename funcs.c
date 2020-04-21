#include "funcs.h"

/* En general muy bien organizado el código. Hay par comentarios para que revisen.
En particular a nivel de estilo 
Los enums recuerden que deberían estar con mayúscula sostenida */

void updateUser(User* u)
{
    printf("Nombre: ");
    scanf("%20s", u->name);

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
    User u; // Se podría mejoar el nombre de la variable
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
    for (i = 0; i < GROUP; i++)
    {
        // Este sería el lugar ideal para usar enums 
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

// QUé es cap?, el nombre de esa varible no es claro. 
void makeDonation(User mat[][MAX_CAP], int *counts, int cap)
{
    char searchName[20];
    printf("Nombre: ");
    scanf("%19s", searchName);

    int quantity;
    printf("Cantidad: ");
    scanf("%d", &quantity);

    int i, j, found = 0;

    //Se pueden quitar los breaks si se usan variables bandera aquí
    for (i = 0; i < GROUP; i++)
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

void infoDonation(){    
    int n;
    printf("Ingrese un tipo de sangre: \n");
                printf("1: A+\n");
                printf("2: A-\n");
                printf("3: B+\n");
                printf("4: B-\n");
                printf("5: AB+\n");
                printf("6: AB-\n");
                printf("7: O+\n");
                printf("8: O-\n");
                scanf("%d", &n);
                printf("\n");
    // Aquí podría quedar más chévere el código con un switch

    if(n == 1){
        printf("Puedes donarle a usarios A+ y AB+\n");
    }

    else if(n == 2){
        printf("Puedes donarle a usarios A+, AB+, A- y AB-\n");
    }

    else if(n == 3){
        printf("Puedes donarle a usarios B+ y AB+\n");
    }

    else if(n == 4){
        printf("Puedes donarle a usarios B+, B-, AB+ y AB-\n");
    }

    else if(n == 5){
        printf("Solo puedes donarle a usarios AB+\n");
    }

    else if(n == 6){
        printf("Puedes donarle a usarios AB+ y AB-\n");
    }

    else if(n == 7){
        printf("Puedes donarle a usarios A+, B+, AB+ y O+\n");
    }

    else if(n == 8){
        printf("Puedes donarle a TODOS los usarios\n");
    }

    else{
        printf("Has ingresado una opcion invalida\n");
    }
}

 void showMaxDonation(User mat[][MAX_CAP], int *groupSizes){
   int max, i, j, indice, subindice;

   for(i = 0; i < GROUP; i++){
        for(j = 0; j < groupSizes[i]; j++){
            if(mat[i][j].donations > max){
                max = mat[i][j].donations;
                indice = i;
                subindice = j;
            }
        }
    }
    
    if (indice>=0 && subindice>=0){
        printf("La persona que mas ha hecho donaciones es: %s\n", mat[indice][subindice].name);
        printf("Donaciones: %d\n", max); 
    }else{
        printf("Aun no hay mayor donador \n");
    }
   
}