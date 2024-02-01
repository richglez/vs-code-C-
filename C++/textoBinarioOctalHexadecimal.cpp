     /******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    string texto;
    int decimal, binario, hexadecimal, octal;
    int residuo = 0, exponente = 1;
    int cont = 0;


    cout << "\tPractica: 1.8.- Cadenas binaria - Binario, Octal y Hexadecimal";
    cout << "\nIngrese un texto: ";
    cin >> texto;


//----------------------------------------------------------------------------------------------------------
    cout << "\n\tDecimal: ";
    for (int i = 0; i < texto.length(); i++) //[][][].legngth = cantidad de caracteres en un texto string
    {
        decimal = texto[i]; //conversion de texto[0][1][2]...longitud de la cadena   conviertelo a numero ASCII
        cout << decimal; //ve imprimiendo todos los numeros
    }


    cout << "\n\tBinario: ";
    for (int x = 0; x < 8; x++)//[h][o][l][a]
    {
        binario = texto[x];  //conversion de texto[0][1][2]...longitud
        
        residuo = binario % 2;
        binario = binario / 2;
        cout << residuo;
    }


    cout << "\n\tOctal: ";
    for (int y = 0; y < 8; y++)
    {
        decimal = texto[y];  //conversion de texto[0][1][2]...longitud
        residuo = decimal % 8;
        octal = residuo * exponente + octal;
        exponente = exponente * 10;
        decimal = decimal / 8;
        cout << octal;

    }
    



    cout << "\n\tHexadecimal: ";
    for (int h = 0; h < 8; h++)
    {
        decimal = texto[h];  //conversion de texto[0][1][2]...longitud
        residuo = decimal % 16;
        hexadecimal = residuo * exponente + hexadecimal;
        exponente = exponente * 10;
        decimal = decimal / 16;
        cout << hexadecimal;
    }


    
    
    


    
    


    return 0;
}
