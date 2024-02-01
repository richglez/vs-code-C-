     /******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

//Estructura
struct empleados{
    int clave;
    char nombre[80];
}emp[1000];;  //declaracion de arrelgo -> Estructura



int main(int argc, char const *argv[])
{
    int contador = 0;


        for (int i=0; i<3; i++) {
            fflush(stdin);
            cout << "\n\nIngresa la clave del empleado: ";
            cin >> emp[i].clave; //[][][]
                    
            cout << "\n\nIngresa el nombre del empelado: ";
            cin >> emp[i].nombre; //[][][]
                    
            contador = contador + 1; //que i se vaya recorriendo

        }

    for (int i = 0; i < contador; i++)
    {
        cout << emp[i].clave << "\n" << emp[i].nombre;/* code */
    }
    
        
    return 0;
}

                    
