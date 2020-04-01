#include "funcs.h"

int menu()
{

    int option = 0;

    printf(" Opciones  \n\n");
    printf("1. Aniadir Usuario \n");
    printf("2. Cantidades de sangre\n");
    printf("3. Mostrar por grupo de sangre\n");
    printf("4. Hacer donacion\n");
    printf("5. ¿A que usuarios le puedo donar?\n");
    printf("6. Salir\n");
    scanf("%d", &option);

    return option;
}

int main()
{
    User mat[8][MAX_CAP];
    int counts[8] = {};
    int groupSizes[8] = {};

    int cap;
    printf("Capacidad: ");
    scanf("%d", &cap);

    int option, option2;
    do
    {
        option = menu();
        switch (option)
        {
            case 1:
                addUser(mat, groupSizes, cap);
                break;

            case 2:
                displayCounts(counts);
                break;

            case 3:
                searchByType(mat, groupSizes);
                break;

            case 4:
                makeDonation(mat, counts, cap);
                break;

            case 5:
                printf("¿Que tipo de sangre tienes?: \n");
                printf("1: A+\n");
                printf("2: A-\n");
                printf("3: B+\n");
                printf("4: B-\n");
                printf("5: AB+\n");
                printf("6: AB-\n");
                printf("7: O+\n");
                printf("8: O-\n");
                scanf("%d", &option2);
                printf("\n");
                infoDonation(option2);

            case 6:
                break;
            
            default:
                printf("Opcion invalida\n");
                break;
        }
    } while (option != 5);

    return 0;
}