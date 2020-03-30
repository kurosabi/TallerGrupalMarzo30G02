void displayUsersByBloodType(User mat[][MAX_COL]){
   int opcion;
   printf( "Ingrese el tipo de sangre:\n" );
   printf( "0. a+" );
   printf( "1. a-" );
   printf( "2. b+" );
   printf( "3. b-" );
   printf( "4. ab+" );
   printf( "5. ab-" );
   printf( "6. o+" );
   printf( "7. o-" );
   scanf("%d", &opcion);
   printf("Usuarios:\n")
   for(i = 0; i < MAX_COL; i++ ){
      printf( "%s\n", mat[opcion][i].name );
      printf( "===============\n");
   }
}