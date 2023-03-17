// Objetos_Pokemon.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Daniel Medina

#include <iostream>
using namespace std;

class Pokemon
{
    int vida;
    int ataque;
    string Raza;

//Constructor generico
Pokemon()
{
    vida = 100;
    ataque = 10;
    Raza = "Estarbienpinshipendejoux";
}
//Constructor especifico
Pokemon()
{
    vida = 100;
    ataque = 10;
    Raza = "Estarbienpinshipendejoux";
}
//Destructor
~Pokemon()
{
    std::cout << "Pokemon" << Raza << "Fue destruido" << std::endl;
}
//Setter
void setvida(int v)
{
    vida = v;
}
void setataque(int a)
{
    ataque = a;
}
void setRaza(int r)
{
    Raza = r;
}
//Getter
int getvida()
{
    return vida;
}
int getataque()
{
    return ataque;
}
string getRaza()
{
    return Raza;
}
//Mostrar atributos
void mostraratributos()
{
    std::cout << "Vida" << vida << std::endl;
    std::cout << "Ataque" << ataque << std::endl;
    std::cout << "Raza:" << Raza << std::endl;
}


};



int main()
{
    std::cout << "Hello World!\n";
}
