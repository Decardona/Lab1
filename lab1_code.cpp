/* Practica de Laboratorio 1
*  Informatica 2 - 2018_2
*  Prof: Juan Camilo Correa Chica
*  Fecha: Agosto 6/2018
*  Plazo máximo para enviar enlace para clonar el repositorio: Agosto 6/2018 - 09:59pm
*  Estudiante1: Nombres y apellidos completos
*  Estudiante2: Nombres y apellidos completos (Opcional, puede trabajar individualmente)
*  Fecha del ultimo Commit en GitHub: Agregue la fecha y hora del ultimo Commit (aproximada)
*

*  Primera parte: 
*
*  Ejercicio 1: Cree una cuenta en GitHub, que va a utilizar por el resto del curso para presentar
*               sus trabajos de laboratotio de informatica 2. Si lo prefiere tambien descargue una 
*				aplicacion de escritorio para administrar sus repositorios. Una vez creada su cuenta		
*				cree un repositorio llamado Lab1 y agreguele un README file con una descripcion adecuada.
*
*
*  Ejercicio 2: Clone este archivo del GitHub de camilocorreaUdeA y agreguelo al branch "master" de 
*				su repositorio Lab1, a partir de alli trabajara en el siguiente ejercicio.
*
*
*  Ejercicio 3: Diseñe una estructura llamada "Calendario", que solo contiene un campo de bits de tipo 
*				unsigned short int para los componentes de la fecha: anio, mes y dia.
*				Diseñe una funcion llamada "checkDate" que reciba como parametro una estructura "Calendario"
*				esa funcion debe ser capaz de verificar cualquier error en la fecha que este guardada en la
*				estructura que le entra como parametro, es decir, debe verificar que el dia no sea mayor a 31
*				a 30, a 29 o 28 segun el mes, ni menor que 1. Que el mes no sea mayor a 12 ni menor que 1. El
*				anio es un numero entre 0 y 127, el anio 0 corresponde a 1990, luego el anio 2018 por ejemplo
*               corresponderia al anio 28. Tambien debe verificar si el anio es bisiesto, en ese caso Febrero
*               puede tener 29 dias (enlace sugerido: http://www.disfrutalasmatematicas.com/medida/anos-bisiestos.html)
*				La funcion debe retornar un valor booleano que indique si la fecha ingresada esta bien o mal.
*/

#include <iostream>

using namespace std;

//Aqui se declaran las variables globales

//Aqui se declaran los prototipos de las funciones
struct Calendario {
    unsigned short int dia = 0;
    unsigned short int mes = 0;
    unsigned short int anio = 0;
    unsigned short int diasmeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
};
unsigned short int verifica_fecha (struct Calendario);
unsigned short int calcula_bisiesto (unsigned short int annio);

int main()
{
	//Esta funcion es la mas importante del programa
	//En esta funcion se deben invocar las funciones que 
	//usted codifique en C++
	
	//Declarando una variable localecon
    struct Calendario cl1;

    cout<<"Esto es un calendario, vamos aingresar la fecha en tres secciones. Primero el dia, luego el mes y luego el año. Este ultimo va desde 0 a 127"<<endl;
    cout<<"ingresa el dia: "<<endl;
    cin>>cl1.dia;
    cout<<"Ingresa el mes: "<<endl;
    cin>>cl1.mes;
    cout<<"ingresa el año: "<<endl;
    cin>>cl1.anio;

	//Aqui puede invocar su funcion
	
    if(verifica_fecha(cl1))
        cout<<"Fecha "<<cl1.dia<<"-"<<cl1.mes<<"-"<<cl1.anio+1990<<" sin problemas!"<<endl;
	else
        cout<<"Fecha "<<cl1.dia<<"-"<<cl1.mes<<"-"<<cl1.anio+1990<<" NO es valida!"<<endl;
	return 0;
}

unsigned short int verifica_fecha (struct Calendario cl) {
    unsigned short int retorno = 0;
    if (cl.anio > 127)
        retorno = 0;
    else if (cl.mes > 12)
        retorno = 0;
    else if (cl.anio > 127)
        retorno = 0;
    else{
        if (calcula_bisiesto(cl.anio+1990))
            cl.diasmeses[1] = 29;
        if (cl.dia > cl.diasmeses[cl.mes-1] || cl.dia == 0)
            retorno = 0;
        else
            retorno = 1;
    }

    return retorno;
}

unsigned short int calcula_bisiesto(unsigned short int anio){
    unsigned short int factor = 0;
    factor = anio % 4;
    if (factor == 0){
        factor = anio % 100;
        if (factor == 0)
            return 0;
        else
            return 1;
    }
    else{
        factor = anio % 400;
        if (factor == 0)
            return 1;
        else
            return 0;
    }
}


