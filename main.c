#include "funcs.h"

void menu()
{

    int option = 0;

    printf(" Opciones  \n\n");
    printf("1. Añadir Usuario \n");
    printf("2. Cantidades de sangre\n");
    printf("3. Mostrar por grupo de sangre\n");
    printf("4. Hacer donacion\n");
    printf("5. Salir\n");
    scanf("%d", &option);

    return option;
}

int main()
{
    User mat[8][MAX_COL];
    int counts[8] = {};
    int groupSizes[8] = {};

    int cap;
    printf("Capacidad: ");
    scanf("%d", &cap);

    int option;
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
                makeDonation(mat, counts, cap)
                break;

            case 5:
                break;
            
            default:
                printf("Opcion invalida\n")
                break;
        }
    } while (option != 5)

    return 0;
}