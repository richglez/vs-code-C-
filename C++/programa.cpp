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



int main(){
    //variables globales
    int contador = 0;
    int caracter_modificar;
    int emp_modificar;
    char respuesta = 's';
    char opc = 's';
    int opciones;
    
    
    

    

    //menu de opciones
    do{
        
        cout << "MENU\n";
        cout << "\n1.Altas \n2.Consultas \n3.Reportes \n4.Cambios \n5.-Salir del programa \nOpcion: ";
        cin >> opciones;
        
        switch(opciones)
        {
            case 1:
                    contador++;
                      
                    do{
                        
                        if (contador < 1000)
                        {
                            for (int i = 0; i < contador; i++)
                            {
                                fflush(stdin);
                                cout << "\n\nIngresa la clave del empleado: ";
                                cin >> emp[i].clave; //[][][]
                    
                                cout << "\n\nIngresa el nombre del empelado: ";
                                cin >> emp[i].nombre; //[][][]
                                
                            }

                            
                        }
                        else
                        {
                            respuesta = 'n';
                            cout << "Arreglo lleno";
                        }
                        
                        
                        cout << "\n\tOtra alta? s/n: ";
                        cin >> respuesta;
                        

                    }while(respuesta == 's');
                    break;
                        
                    
            
            case 2:
                cout << "\n\t\tConsultas del empleado";
                for (int i=0; i < contador; i++){
                    fflush(stdin);
                    cout << "\n\nClave: " << emp[i].clave;
                    cout << "\nNombre: " << emp[i].nombre;
                }
                break;

                
            case 3:
                cout << "\n\tConsultas del empleado";
                //cout << "\n\nClave: " << emp[i].clave;
                //cout << "\nNombre: " << emp[i].nombre;
                break;
                
            case 4:
                cout << "Que empleado deseas modificar? -clave del empleado: ";
                cin >> emp_modificar;
                
                if(emp_modificar < 1000){
                    cout << "Que deseas modificar? 1=clave, 2=nombre";
                    cin >> caracter_modificar;
                
                    switch(caracter_modificar){
                        case 1:
                            cout << "Cual sera la nueva clave?: ";
                            //cin >> emp[i].clave;
                            break;
                        
                        case 2:
                            cout << "Cual sera el nuevo nombre?: ";
                            //cin >> emp[i].nombre;
                            break;
                    }
                }
                
                else{
                    cout << "El empleado no existe";
                }
                    
                
                
                break;
                
            case 5:
                cout << "\aSaliste del programa.";
                
                break;
        }
        
        cout << "\n\tVolver al menu? s/n: ";
        cin >> opc;
    }while(opc == 's');
        


    system("pause");
}
    





