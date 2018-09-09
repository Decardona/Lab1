/* Practica de Laboratorio 2
*  Informatica 2 - 2018_2
*  Prof: Juan Camilo Correa Chica
*  Fecha: Agosto 27/2018 - Septiembre 3/2018
*  Plazo máximo para enviar enlace para clonar el repositorio: NO definido aun
*  Estudiante1: Diego Esteban Cardona Bedoya
*  Estudiante2: Victor Manuel Parra Julio
*  Fecha del ultimo Commit en GitHub: Agregue la fecha y hora del ultimo Commit (aproximada)
*
* 1. Declare una estructura global con 6 miembros de distinto tipo y en este orden (con sus miembros inicializados):
* int
* char
* float
* char
* double
 * int
 */

/* Declare otra estructura global con 6 miembros de distinto tipo y en este orden (con sus miembros inicializados):
 * int
 * int
 * float
 * char
 * char
 * double
 */

//Declare punteros a cada una de las estructuras e imprima en pantalla el valor de sus miembros haciendo uso
//del operador ->
//Luego imprima de nuevo el valor de los miembros de la estructura pero esta vez haga uso de "type casting",
//operadores y aritmetica de punteros
//Calcule el tamaño de cada estructura con la funcion sizeof() y explique en un comentario sus observaciones
//acerca del resultado obtenido respecto a los tamanios de las estructuras

/*2. Diseñe una funcion llamada foo_function() que debe tener un arreglo unidimensional del tipo y del tamanio que ud prefiera.
 * Declare un puntero al arreglo y luego agregue las lineas de codigo necesarias para lograr que cada vez que
 * se haga un llamado a la funcion foo_function() desde de la funcion main se imprima un elemento distinto del arreglo
 * (en el orden que estan en el arreglo) con ayuda de la aritmetica de punteros.
 */
 
 /*3. Diseñe un menu de inicio para un programa de calculo sencillo. En el menu se debe preguntar por un numero de opcion
  * y cada numero de opcion debe ejecutar una funcion que hace un calculo matematico distinto. Todas las funciones deben
  * recibir un argumento tipo float y un valor de retorno idem. El menu debe realizarse utilizando SOLAMENTE punteros a funciones.
  * Bajo NINGUN motivo puede realizarlo utilizando sentencias "if..else if..else" o "switch..case"

/* Enlaces de internet utiles:
 * http://c.conclase.net/curso/index.php?cap=011
 * http://c.conclase.net/curso/index.php?cap=011b#STR_sizeof
 * https://stackoverflow.com/questions/8657776/pointer-arithmetic-with-structures
 * https://stackoverflow.com/questions/119123/why-isnt-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member
 * http://www.catb.org/esr/structure-packing/
 * https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
 * https://barrgroup.com/Embedded-Systems/How-To/C-Function-Pointers
 */

#include <iostream>
using namespace std;

struct GlobalStruct {
    int entero = 1;
    char ch1 = 'D';
    float flotante = 1.5;
    char ch2 = 'I';
    double doblep = 1.333;
    int entero2 = 50;
};

struct GlobalStruct2 {
    int entero = 10;
    int entero2 = 20;
    float flotante = 1.4;
    char ch1 = 'E';
    char ch2 = 'G';
    double doblep = 1.333;
};

char foo_function();
int contador=-1;

float fn_suma(float n), fn_resta(float n), fn_potencia(float n);

float (*disparador[])(float num) = {fn_suma,fn_resta,fn_potencia};

int main(){

    //Inicializando primera estructura global
    GlobalStruct st1;
    GlobalStruct *pt1 = &st1;
    int selector;
    float numero;

    //Mostrando valores de la estructura st1
    cout<<"Dato entero: "<<pt1->entero<<endl;
    cout<<"Dato char: "<<pt1->ch1<<endl;
    cout<<"Dato flotante: "<<pt1->flotante<<endl;
    cout<<"Char 2: "<<pt1->ch2<<endl;
    cout<<"Dato de doble precision: "<<pt1->doblep<<endl;
    cout<<"Dato entero 2: "<<pt1->flotante<<endl<<endl;

    //Inicializando segunda estructura global
    GlobalStruct2 st2;
    GlobalStruct2 *pt2 = &st2;

    //Mostrando valores de la estructura st2
    cout<<"Segunda estructura"<<endl<<endl<<"Dato entero: "<<pt2->entero<<endl;
    cout<<"Dato entero 2: "<<pt2->entero2<<endl;
    cout<<"Dato flotante: "<<pt2->flotante<<endl;
    cout<<"Char 1: "<<pt2->ch1<<endl;
    cout<<"Char 2: "<<pt2->ch2<<endl;
    cout<<"Dato de doble precision: "<<pt2->doblep<<endl<<endl;

    //uso de type casting
    cout<<"Mostrando valores estructura 1 con uso de type casting"<<endl<<endl;
    cout<<"Dato entero: "<<*((int*)pt1)<<endl;
    cout<<"Dato char: "<<*((char*)pt1+4)<<endl;
    //cout<<"El tamanio float es: "<<sizeof(float)<<endl;
    cout<<"Dato Flotante: "<<*((float*)pt1+2)<<endl;
    cout<<"Dato char 2: "<<*((char*)pt1+12)<<endl;
    cout<<"Dato double: "<<*((double*)pt1+2)<<endl;
    cout<<"Dato entero 2: "<<*((int*)pt1+6)<<endl<<endl;

    cout<<"Mostrando valores estructura 2 con uso de type casting"<<endl<<endl;
    cout<<"Dato entero: "<<*((int*)pt2)<<endl;
    cout<<"Dato entero 2: "<<*((int*)pt2+1)<<endl;
    cout<<"Dato flotante: "<<*((float*)pt2+2)<<endl;
    cout<<"Dato Char 1: "<<*((char*)pt2+12)<<endl;
    cout<<"Dato Char 2: "<<*((char*)pt2+13)<<endl;
    cout<<"Dato Double: "<<*((double*)pt2+2)<<endl<<endl;

    // tamaño de las estructuras
    cout<<"El tamanio total para la estructura 1 es: "<<sizeof (st1)<<"bytes"<<endl;
    cout<<"El tamanio total para la estructura 2 es: "<<sizeof (st2)<<" bytes"<<endl<<endl;
    //Observaciones: Es importante determinar el orden en que se declaran las variables
    //este orden debe ser establecido teniendo en cuenta el tipo de la variable colocando
    // todos los de un mismo tipo en un orden consecutivo para ocupar al maximo el tamaño de la memoria sin dejar espacios reservados
    //innecesariamente. Esto sera determinante en el consumo de memoria.

    // uso de foo_function
    cout<<"ejecutando foo_function con primer llamado. El valor obtenido es: "<<foo_function()<<endl;
    cout<<"ejecutando foo_function con segundo llamado. El valor obtenido es: "<<foo_function()<<endl;
    cout<<"ejecutando foo_function con tercer llamado. El valor obtenido es: "<<foo_function()<<endl;
    cout<<"ejecutando foo_function con cuarto llamado. El valor obtenido es: "<<foo_function()<<endl;
    cout<<"ejecutando foo_function con quinto llamado. El valor obtenido es: "<<foo_function()<<endl;
    cout<<"ejecutando foo_function con sexto llamado. El valor obtenido es: "<<foo_function()<<endl<<endl;

    //Menu de funciones
    cout<<"Menu simple de calculos matematicos. Por favor seleccione:"<<endl;
    cout<<" -> 0 Sumar un numero un numero de veces | -> 1 Restar un numero un numero de veces | -> 2 Potencia de un numero"<<endl;
    cin>>selector;
    cout<<"Indique el numero: ";
    cin>>numero;
    cout<<"El el resultado con la opcion: "<<selector<<" es:"<<disparador[selector](numero)<<endl;



    return 0;
}

char foo_function(){
    char caracter[] = {'D','i','e','g','o'};
    char *ptr = &caracter[0];
    if (contador==4)
        contador=0;
    else
        contador++;
    return ptr[contador];
}

float fn_suma(float num){
    float result = 0;
    for (int i=1;i<=num;i++){
        result+=num;
    }
    return result;
}

float fn_resta(float num){
    float result = 0;
    for (int i=1;i<=num;i++){
        result-=num;
    }
    return result;
}

float fn_potencia(float num){
    float result = 1;
    for (int i=1;i<=num;i++){
        result*=num;
    }
    return result;
}
