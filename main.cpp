#include <iostream>
#include <fstream>
#include <math.h>
#include <list>
#include <vector>
#include "Evaluador.h"
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Devuelve el atributo *nombre* de *usuario*
string getNombre(Usuario* usuario)
{

    Usuario x=*usuario;

    return x.nombre;
}

//Escribe todos los atributos de *usuario* en un archivo con con nombre *nombre_archivo*
void escribir(string nombre_archivo, Usuario* usuario)
{

    Usuario usr= * usuario;

    ofstream out (nombre_archivo.c_str());
    out<<usr.nombre<<endl;
    out<<usr.edad<<endl;

    out.close();

}


//Lee los atributos de un *Usuario* desde un archivo con nombre *nombre_archivo* y luego lo devuelve
Usuario* leer(string nombre_archivo)
{
    Usuario *usr2= new Usuario("",0);

    ifstream in(nombre_archivo.c_str());
    in >> usr2->nombre;
    in >> usr2->edad;
    in.close();
    return usr2;
}

//Devuelve cuantas veces existe *numero* en *numeros*
int contar(vector<int> numeros, int numero)
{

    int contador=0;

    for(int i=0; i<numeros.size(); i++)
    {
        if (numeros[i]==numero)
        {
            contador=1 + contador;
        }

    }
    return contador;
}

//Devuelve *true* si existe al menos un valor repetido en *cadenas*
bool existeRepetida(list<string> cadenas)
{

    cadenas.sort();
    int c1= cadenas.size();
    cadenas.unique();
    int c2=cadenas.size();

    if (c1==c2)
    {
        return false;

    }
    else
    {
        return true;
    }
}

//Devuelve el contenido de *letras* invertido
vector<char> invertir(vector<char> letras)
{
char contar1=0;
    for (int i=0; i>letras.size(); --i)
    {
       vector<char> respuesta[i];
    }

    return letras;
}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las siguientes clases dado el diagrama adjunto

//Lugar
//Lugar() Constructor vacio
//vendeComida() Funcion abstracta

//Restaurante
//Restaurante() Inicializa atributos
//vendeComida() Devuelve true

//Monumento
//Monumento() Inicializa atributos
//vendeComida() Devuelve false


class Lugar
{
public:

    string nombre;
    double latitud;
    double longitud;

    Lugar()
    {}

    virtual bool vendeComida()=0;

};

class Restaurante : public Lugar

{
public :

    string horario;

    Restaurante(string nombre, double latitud, double longitud, string horario)
    {

        this->nombre=nombre;
        this->latitud=latitud;
        this->longitud=longitud;
        this->horario=horario;

    }

    bool vendeComida ()
    {
        return true;

    }


};

class Monumento : public Lugar
{

public:

    Monumento (string nombre, double latitud, double longitud)
    {
        this->nombre=nombre;
        this->latitud=latitud;
        this->longitud=longitud;

    }

    bool vendeComida()
    {
        return false;
    }


};



///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////

void evaluar();
void evaluar2();

int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////


void evaluar2()
{
    double nota = 0;

    cout<<"**Clase Restaurante**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Restaurante("Burger Queen",5.2,6.2,"24/7").nombre == "Burger Queen"
            && Restaurante("Burger Queen",6.1,6.2,"24/7").latitud == 6.1
            && Restaurante("Burger Queen",5.2,6.6,"24/7").longitud == 6.6
            && Restaurante("Burger Queen",5.2,6.2,"lunes a viernes").horario == "lunes a viernes"

            && Restaurante("Mc Ronald",5.2,6.2,"24/7").nombre == "Mc Ronald"
            && Restaurante("Mc Ronald",10.1,6.2,"24/7").latitud == 10.1
            && Restaurante("Mc Ronald",5.2,8.6,"24/7").longitud == 8.6
            && Restaurante("Mc Ronald",5.2,6.2,"siempre").horario == "siempre"
      )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }
    else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeComida():\t\t";

    if(Restaurante("Burger Queen",5.2,6.2,"24/7").vendeComida()
            && Restaurante("Mc Ronalds",5.2,6.2,"24/7").vendeComida())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }
    else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"**Clase Monumento**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Monumento("Burger Queen",5.2,6.2).nombre == "Burger Queen"
            && Monumento("Burger Queen",6.1,6.2).latitud == 6.1
            && Monumento("Burger Queen",5.2,6.6).longitud == 6.6

            && Monumento("Mc Ronald",5.2,6.2).nombre == "Mc Ronald"
            && Monumento("Mc Ronald",10.1,6.2).latitud == 10.1
            && Monumento("Mc Ronald",5.2,8.6).longitud == 8.6
      )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }
    else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeComida():\t\t";

    if(!Monumento("Burger Queen",5.2,6.2).vendeComida()
            && !Monumento("Mc Ronalds",5.2,6.2).vendeComida())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }
    else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/8"<<endl;
}
