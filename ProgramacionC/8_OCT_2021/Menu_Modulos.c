/*
 * Fecha 8-OCT-21
 *
 *
 *
 *
 * */

#include <stdio.h>


// Declarar funciones
// Estas funciones imprimen las opciones del menu principal
// y de los modulos 1, 2 y 3
void imprimirMenu(void);
void imprimirModulo1(void);
void imprimirModulo2(void);
void imprimirModulo3(void);

// Estas funciones realizan las tareas de cada modulo
void Modulo1(int opcion);
void Modulo2(int opcion);
void Modulo3(int opcion);

int main()
{
  // Varialbes para obtener opcion seleccionada
  // por el usuario.
  int opcionMenu, opcionModulo; 

  do{ 
  imprimirMenu();
  scanf(" %d", &opcionMenu);
  switch(opcionMenu)
  {
    case 1: do{  
            imprimirModulo1();
            scanf(" %d", &opcionModulo);
            Modulo1(opcionModulo); 
            }while(opcionModulo != 11);
            break;

    case 2: do{ 
            imprimirModulo2();
            scanf(" %d", &opcionModulo);
            Modulo2(opcionModulo);
            break;
            }while(opcionModulo == 14);

    case 3: do{ 
            imprimirModulo3();
            scanf(" %d", &opcionModulo);
            Modulo3(opcionModulo);
            break;
            }while(opcionModulo == 12);
  }


  }while(opcionMenu != 4);
    
  return 0;
}


void imprimirMenu(void)
{
    printf("\n    Universidad Autonoma de Zacatecas"     );
    printf("\n       Ingenieria en Computación"         );
    printf("\n Laboratorio de Lenguaje de Programación 1");
    printf("\n\n  Menu Principal de Programas Realizadas  ");
    printf("\n\n    Elija una Opción : ");
    printf("\n     1.- Modulo 1 \n     2.- Modulo 2\n     3.- Modulo 3\n 4.-Salir del programa\n");

}


void imprimirModulo1(void)
{
  printf("\n\n    Modulo 1"     );
  printf("\n     1.- Mostrar Saludo y Nombre \n     2.- Mostrar saludo y nombre en otra linea \n     3.- Mostrar Saludo y Nombre mostrando el nombre leído\n     4.- Suma de los Nímeros leídos\n     5.- Muestra la distancia saltada y se muestre la distancia en pies y pulgadas\n     6.- Conversiones de Monedas \n     7.- Ventas Realizadas\n     8.- Resolver ecuaciones(Compra de Tacos)\n     9.-  Cuanto se puede Invertir en Fertilizantes\n     10.- Formatear la maquina\n 11.- Regresar al Menu Principal\n\n  ");
  printf("\n  Elija Una Opcion:  ");
}

void imprimirModulo2(void)
{
printf("\n\n    Modulo 2"     );
printf("\n     1.-  Cual es el número mayor de dos números \n     2.- Cual es el número mayor de tres números \n     3.- Cual es el número mayor de cuatro números\n     4.- Programa que muestre de menor a mayor 2 números\n     5.- Programa que muestre de menor a mayor 3 números\n     6.- Programa que muestre de menor a mayor 4 números \n     7.- Programa que lea 3 números e indique cuantos de esos números son pars y cuantos de ellos son cero\n     8.- Modificar el programa para que el usuario efectua la suma, resta y multiplicación de los números leídos\n     9.-  Programa cuál es la moneda original de la cual quiere efectuar la conversión \n     10.- Programa que indiqeu cuánto se debe pagar a un trabajador a partir de las horas trabajadas en la semana\n    11.- Programa que lea 4 números y muestre cual es el mayor y cual es el menor\n    12.-Programa que lea los 3 lados de un trianguloy se indique cual tipo de triangulo es \n  13.- Formatear la maquina\n\n  ");
printf("\n  Elija Una Opcion:  ");                                                  
}

void imprimirModulo3(void)
{
  printf("\n    Modulo 2"     );
  printf("\n  Elija Una Opcion:  ");                                      
}

void Modulo1(int opcion)
{

  switch(opcion)
  {
   case 1:
   {
    char nombre [20];
    puts("Dame tu nombre");
    scanf("%s", nombre);
    printf("Hola mundo %s",nombre);
    break;
   }
   case 2:
   {
    char nombre [20];
    puts("Dame tu nombre");
    scanf("%s",nombre);
    printf("Hola mundo\n%s",nombre);
    break;
   }
   case 3:
   {
    char nombre [20];
    puts("¿Cual es tu nombre?");
    scanf("%s",nombre);
    printf("Hola, mucho gusto en conocerte %s",nombre);
    break;
   }
  
  }

}

void Modulo2(int opcion)
{
  switch(opcion)
  {
    case 1:
          
            break;

    case 2:

            break;
    case 3:

            break;

  }

}


void Modulo3(int opcion)
{

  switch(opcion)
  {
    case 1: 
            break;
  }

}
