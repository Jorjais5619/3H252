#pragma once
#include "EstadoFoco.hpp"

class Foco
{
private:
    EstadoFoco estadoActual;
    
public:
    Foco(){estadoActual=false}//constructor
    ~Foco(){}//destructor

    void Encender(){}
    void Apagar(){ }
    EstadoFoco MostradoEstado(){}
};