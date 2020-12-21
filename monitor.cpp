/*
 * monitor.cpp
 *
 *  Created on: 29 nov. 2020
 *      Author: Jose Manuel Flores Barranco
 */

#include "monitor.h"

Monitor::Monitor()
{

}

bool Monitor::buscarRuta(int identificador, Ruta &ruta)
{   
	for(r_=rutas_.begin();r_!=rutas_.end();r_++)
	{
		if((*r_).getIdentificador()==identificador)
		{
			ruta=(*r_);
			return true;
		}
	}

	return false;
}

void Monitor::crearRuta(){
        Ruta ruta;
        int eleccion=0, respuesta_i;
        string respuesta_s;
        cout << "1) Tipo \n";
        cout << "2) Modalidad \n";
        cout << "3) Longitud \n";
        cout << "4) Duracion estimada \n";
        cout << "5) Aforo maximo \n";
        cout << "6) ¿Ninos? \n";
        cout << "7) Terminar \n";

        while(eleccion!=7){
            switch (eleccion)
            {
                
                case 1:
                    cout << "Introduzca el tipo: \n";
                    cin >> respuesta_s;
                    ruta.setTipo(respuesta_s);
                    break;

                case 2:
                    cout << "Introduzca la modalidad: \n";
                    cin >> respuesta_s;
                    ruta.setModalidad(respuesta_s);
                    break;
                
                case 3:
                    cout << "Introduzca la longitud: \n";
                    cin >> respuesta_i;
                    ruta.setLongitud(respuesta_i);
                    break;
                
                case 4:
                    cout << "Introduzca su duracion: \n";
                    cin >> respuesta_i;
                    ruta.setDuracion(respuesta_i);
                    break;
                
                case 5:
                    cout << "Introduzca el aforo maximo: \n";
                    cin >> respuesta_i;
                    ruta.setAforo(respuesta_i);
                    break;
            
                case 6:
                    cout << "Introduzca si es una ruta de ni�os: \n";
                    cin >> respuesta_s;

                    if(respuesta_s=="si"||respuesta_s=="Si")
                    {
                    	ruta.setrutaNinos(true);
                    }

                    else
                    {
                    	ruta.setrutaNinos(false);
                    }
                    break;
            
                case 7:
                    cout << "   Saliendo del menu... \n" ;
                    break;
                
                default:
                    cout << "Su eleccion no esta en el menu, por favor seleccione una opcion valida \n";
                    break;
                }
            }
            rutas_.push_back(ruta);
        }

void Monitor::actualizarRuta(int identificador){
            Ruta ruta;
            string respuesta_s;
            int respuesta_i, eleccion;
            cout << "Indique el identificador de la ruta que quiera actualizar \n";
            cin >> identificador;
            buscarRuta(identificador,ruta);
            cout << "1) Tipo \n";
            cout << "2) Modalidad \n";
            cout << "3) Longitud \n";
            cout << "4) Duracion estimada \n";
            cout << "5) Aforo maximo \n";
            cout << "6) ¿Ninos? \n";
            cout << "7) Terminar \n";

            while(eleccion!=7){
                switch (eleccion)
                {
                    case 1:
                        cout << "   Tipo actual: " << ruta.getTipo();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_s;
                        ruta.setTipo(respuesta_s);
                        break;

                    case 2:
                        cout << "   Modalidad actual: " << ruta.getModalidad();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_s;
                        ruta.setModalidad(respuesta_s);
                        break;
                
                    case 3:
                        cout << "   Longitud actual: " << ruta.getLongitud();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_i;
                        ruta.setLongitud(respuesta_i);
                        break;
                
                    case 4:
                        cout << "   Duracion actual: " << ruta.getDuracion();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_i;
                        ruta.setDuracion(respuesta_i);
                        break;
                
                    case 5:
                        cout << "   Aforo maximo actual: " << ruta.getAforo();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_i;
                        ruta.setAforo(respuesta_i);
                        break;
                
                    case 6:
                        cout << "   ¿Ruta de ninos?: " << ruta.getrutaNinos();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_s;
                        ruta.setrutaNinos(true);
                        break;
                
                    case 7:
                        cout << "   Saliendo del menu... \n" ;
                        break;
                
                    default:
                        cout << "Su eleccion no esta en el menu, por favor seleccione una opcion valida \n";
                        break;
                    }
                }
                rutas_.push_back(ruta);
        }

bool Monitor::cancelaRuta(int identificador){
    list<Ruta>::iterator pos;
    pos = rutas_.begin();
			if(!rutas_.empty()){
				for(long unsigned int i = 0; i<rutas_.size(); i++){
					if((*pos).getIdentificador()==identificador){
						rutas_.erase(pos);
                        return true;
					}
					pos++;
				}
			}
            cout << "No se ha podido encontrar una ruta que tenga ese identificador \n";
            return false;
}

Incidencia Monitor::crearIncidencia(){
    float latitud, longitud;
    string aux;
    Incidencia incidencia;
    Ubicacion ubicacion;

    cout << "Introduzca el nombre del sendero: ";
    cin >> aux;
    incidencia.setSendero(aux);
    cout << "\n";

    cout << "Introduzca una breve descripci�n de la incidencia que ha encontrado:\n";
    cin >> aux;
    incidencia.setDescripcion(aux);
    cout << "\n";

    cout << "A continuacion, introduzca la latitud en la que se encuentra: ";
    cin >> latitud;

    cout << "A continuacion, introduzca la longitud en la que se encuentra: ";
    cin >> longitud;

    ubicacion.latitud=latitud;
    ubicacion.longitud=longitud;

    incidencia.setUbicacion(ubicacion);

    return incidencia;
}

string Monitor::generarContrasena(int size) {
    char contrasena[size];
    srand(time(NULL));
    for(int i=0; i < size; i++)
        contrasena[i] = 33 + rand() % (126 - 33);

    return contrasena;
    
}

Monitor::~Monitor() {

}

