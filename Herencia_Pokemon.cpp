// Herencia_Pokemon.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Daniel Medina

#include <iostream>

using namespace std;

class Pokemon
{
protected:
    std::string Nombre;
    std::string Tipo;
    std::string Color;
    int vida;
    int ataque;

public:

    //Constructor generico
    Pokemon()
    {
        Nombre = "NPC";
        Tipo = "Agua";
        Color = "Azul";
        vida = 100;
        ataque = 10;

    }
    //Constructor especifico
    Pokemon(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _vida)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        ataque = _ataque;
        vida = _vida;
    }
    //Destructor
    ~Pokemon()
    {
        std::cout << "Pokemon" << Nombre << "Fue destruido" << std::endl;
    }
    //Setter
    void setNombre(int n)
    {
        Nombre = n;
    }
    void setTipo(int t)
    {
        Tipo = t;
    }
    void setcolor(int c)
    {
        Color = c;
    }
    void setvida(int v)
    {
        vida = v;
    }
    void setataque(int a)
    {
        ataque = a;
    }
    //Getter
    string getNombre()
    {
        return Nombre;
    }
    string getTipo()
    {
        return Tipo;
    }
    string getColor()
    {
        return Color;
    }
    int getvida()
    {
        return vida;
    }
    int getataque()
    {
        return ataque;
    }
    void Sanar()
    {
        vida += (vida * .40);
        std::cout << "\n" << Nombre << " Vida restablecida \nHP = " << vida << std::endl;
    }
    //Mostrar atributos
    void mostraratributos()
    {
        std::cout << "Nombre" << Nombre << std::endl;
        std::cout << "Tipo" << Tipo << std::endl;
        std::cout << "Color" << Tipo << std::endl;
        std::cout << "Vida" << vida << std::endl;
        std::cout << "Ataque" << ataque << std::endl;
    }
    virtual void atacar(Pokemon* rival)
    {
        std::cout << Nombre << " ataco a " << rival->getNombre() << std::endl;
        rival->setvida((rival->getvida() - ataque));
    }
};
class PokemonAgua : public Pokemon
{
protected:
    int tiempoEnAgua;
    int tiempoEnAire;
public:
    //Constructor Generico
    PokemonAgua() :Pokemon()
    {
        tiempoEnAgua = 20;
        tiempoEnAire = 15;
    }
    //Constructor Especifico 
    PokemonAgua(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _vida, int _tiempoEnAgua, int _tiempoEnAire)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        ataque = _ataque;
        vida = _vida;
        tiempoEnAgua = tiempoEnAgua;
        tiempoEnAire = tiempoEnAire;
    }
    //Destructor
    ~PokemonAgua()
    {
        std::cout << "Pokemon Agua " << Nombre << " ha sido destruido\n" << std::endl;
    }
    //Setter
    void setTiempoEnAgua(int _tiempoEnAgua)
    {
        tiempoEnAgua = _tiempoEnAgua;
    }
    void setTiempoEnAire(int _tiempoEnAire)
    {
        tiempoEnAire = _tiempoEnAire;
    }
    //Getter
    int getTiempoEnAgua()
    {
        return tiempoEnAgua;
    }
    int getTiempoEnAire()
    {
        return tiempoEnAire;
    }
    void Nadar()
    {
        tiempoEnAgua += 100;
        tiempoEnAire = 0;
    }
    void atacar(Pokemon* rival) override
    {
        std::cout << Nombre << " ataco a " << rival->getNombre() << " con un tsunami" << std::endl;
        rival->setvida((rival->getvida() - ataque));
    }
};
class PokemonPlanta : public Pokemon
{
protected:
    int tiempoVida;
public:
    //Constructor Generico
    PokemonPlanta() : Pokemon()
    {
        tiempoVida = 15;
    }
    //Constructor Especifico 
    PokemonPlanta(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _vida, int _tiempoVida)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        ataque = _ataque;
        vida = _vida;
        tiempoVida = _tiempoVida;
    }
    //Destructor
    ~PokemonPlanta()
    {
        std::cout << "Pokemon Planta " << Nombre << " ha sido destruido\n" << std::endl;
    }
    //Setter
    void setTiempoVida(int _tiempoVida)
    {
        tiempoVida = _tiempoVida;
    }
    //Getter
    int getTiempoVida()
    {
        return tiempoVida;
    }

    void Fotosintesis()
    {
        tiempoVida += 50;
    }
    void atacar(Pokemon* rival) override
    {
        std::cout << Nombre << " ataco a " << rival->getNombre() << "sembrandole unos madrazos" << std::endl;
        rival->setvida((rival->getvida() - ataque));
    }
};
class
    PokemonFuego : public Pokemon
{
protected:
    int temperatura;
public:
    //Constructor Generico
    PokemonFuego() :Pokemon()
    {
        temperatura = 15;
    }
    //Constructor Especifico
    PokemonFuego(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _vida, int _tiempoEnAgua, int _temperatura)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        ataque = _ataque;
        vida = _vida;
        temperatura = _temperatura;
    }
    //Destructor
    ~PokemonFuego()
    {
        std::cout << "Pokemon Fuego " << Nombre << " extinguio su llama\n" << std::endl;
    }
    //setter
    void settemperatura( int _temperatura)
    {
        temperatura = temperatura;
    }
    //Getter
    int getTemperatura()
    {
        return temperatura;
    }
    void Calentar()
    {
        temperatura += 100;
    }
    void atacar(Pokemon* rival)override
    {
        std::cout << Nombre << "ataco a" << rival->getNombre() << "quemandolo" << std::endl;
        rival->setvida((rival->getvida() - ataque));
    }
};
 class PokemonElectrico : Pokemon
 {
 protected:
     int Voltaje;
     int Energia;
 public:
     //Constructor Generico
     PokemonElectrico() :Pokemon()
     {
        Voltaje = 100;
        Energia =50 ;
     }
     //Constructor Especifico 
     PokemonElectrico(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _vida, int _voltaje, int _energia)
     {
         Nombre = _nombre;
         Tipo = _tipo;
         Color = _color;
         ataque = _ataque;
         vida = _vida;
         Voltaje = _voltaje;
         Energia = _energia;
     }
     //Destructor
     ~PokemonElectrico()
     {
         std::cout << "Pokemon Electrico " << Nombre << "a sido destruido  \n" << std::endl;
     }
     //setter
     void setVoltaje(int _Voltaje)
     {
         Voltaje = Voltaje;
     }
     void setEnergia(int _Energia)
     {
         Energia = Energia;
     }
     //Getter
     int getVoltaje()
     {
         return Voltaje;
     }
     int getEnergia()
     {
         return Energia;
     }
     void Electrificar()
     {
         Voltaje += 20;
         Energia -= 5;
     }
     void atacar(Pokemon* rival) override
     {
         std::cout << Nombre << " ataco a " << rival->getNombre() << " con rayos" << std::endl;
         rival->setvida((rival->getvida() - ataque));
     }
     



 };
    

int main()
{
    std::cout << "Hello World!\n";
};