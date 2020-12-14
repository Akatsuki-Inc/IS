/*
 * ruta.cpp
 *
 *  Created on: 29 nov. 2020
 *      Author: USUARIO
 */

#include "ruta.h"

Ruta::Ruta() {
	// TODO Auto-generated constructor stub

}

bool Ruta::setTipo(string tipo)
{
    if((tipo=="Parcial")||(tipo=="Completa"))
    {
        tipo_=tipo;
        return true;
    }

    else
    {
        return false;
    }
}

bool Ruta::setModalidad(string modalidad)
{
   if((modalidad=="Pie")||(tipo=="Bicicleta"))
    {
        modalidad_=modalidad;
        return true;
    }

    else
    {
        return false;
    } 
}

bool Ruta::setFecha(time_t fecha)
{
    time_t fechaactual=time(NULL);
    if(fecha>fechaactual)
    {
        fecha_=fecha;
        return true;
    }

    else
    {
        return false;
    }
}

Ruta::~Ruta() {
	// TODO Auto-generated destructor stub
}

