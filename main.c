#include "funcs.h"

void mostrarMenu() {

	int opcion = 0;

	do {
        User mat[MAX_ROW][MAX_COL];
        int counts[8] = {};
        int row, col;

        printf("Filas: ");
        scanf("%d", &row);
        printf("Columnas: ");
        scanf("%d", &col);

		printf(" Opciones  \n\n");
		printf("1. Actualizar matriz \n");
		printf("2. Cantidades de sangre\n");
        printf("3. Mostrar por grupo de sangre\n");
        printf("4. Hacer donacion\n");
		printf(" Opc: ");
		scanf("%d", &opcion);
		printf("\n");
		switch (opcion) {

			case 1:
				
				break;

			case 2:
			
				break;

			case 3:
		
				break;

		}
	} while(opcion!=0);
}

int main(){
	mostrarMenu ();
	return 0;
}

