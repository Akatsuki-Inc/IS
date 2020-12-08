 /*
 * monitor.cpp
 *
 *  Created on: 29 nov. 2020
 *      Author: Jose Manuel Flores Barranco
 */

#include "monitor.h"

Monitor::Monitor(){}

void Monitor::crearRuta(){
        Ruta ruta;
        int eleccion, respuesta_i;
        string respuesta_s;
        cout << "1) Tipo \n";
        cout << "2) Modalidad \n";
        cout << "3) Longitud \n";
        cout << "4) Duración estimada \n";
        cout << "5) Aforo máximo \n";
        cout << "6) ¿Niños? \n";
        cout << "7) Terminar \n";

        while(n==1){
            switch (eleccion)
            {
                
                case 1: 
                    cout << "Introduzca el parque al que pertenece: \n";
                    cin >> respuesta_s;
                    ruta.setParque(respuesta_s)

                case 2:
                    cout << "Introduzca el tipo: \n";
                    cin >> respuesta_s;
                    ruta.setTipo(respuesta_s);
                    break;

                case 3:
                    cout << "Introduzca la modalidad: \n";
                    cin >> respuesta_s;
                    ruta.setModalidad(respuesta_s);
                    break;
                
                case 4:
                    cout << "Introduzca la longitud: \n";
                    cin >> respuesta_i;
                    ruta.setLongitud(respuesta_i);
                    break;
                
                case 5:
                    cout << "Introduzca su duracion: \n";
                    cin >> respuesta_i;
                    ruta.setDuracion(respuesta_i);
                    break;
                
                case 6:
                    cout << "Introduzca el aforo maximo: \n";
                    cin >> respuesta_i;
                    ruta.setAforo(respuesta_i);
                    break;
            
                case 7:
                    cout << "Introduzca si es una ruta de niños: \n";
                    cin >> respuesta_s;
                    ruta.setRutaNiños(respuesta_s);
                    break;
            
                case 8:
                    cout << "   Saliendo del menu... \n" ;
                    n=0;
                    break;
                
                default:
                    cout << "Su elección no está en el menú, por favor seleccione una opción válida \n"
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
            Ruta = buscarRuta(identificador);
            cout << "1) Tipo \n";
            cout << "2) Modalidad \n";
            cout << "3) Longitud \n";
            cout << "4) Duración estimada \n";
            cout << "5) Aforo máximo \n";
            cout << "6) ¿Niños? \n";
            cout << "7) Terminar \n";

            while(n==1){
                switch (eleccion)
                {
                    case 1:
                        cout << "   Tipo actual: " << ruta.getTipo();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_s;
                        ruta.setTipo(respuesta_s);
                        break;

                    case 2:
                        cout << "   Modalidad actual: " << ruta.Modalidad();
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
                        cout << "   Duración actual: " << ruta.getDuracion();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_i;
                        ruta.setDuracion(respuesta_i);
                        break;
                
                    case 5:
                        cout << "   Aforo máximo actual: " << ruta.getAforo();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_i;
                        ruta.setAforo(respuesta_i);
                        break;
                
                    case 6:
                        cout << "   ¿Ruta de niños?: " << ruta.RutaNiños();
                        cout << "Introduzca su respuesta: \n";
                        cin >> respuesta_s;
                        ruta.setRutaNiños(respuesta_s);
                        break;
                
                    case 7:
                        cout << "   Saliendo del menu... \n" ;
                        n=0;
                        break;
                
                    default:
                        cout << "Su elección no está en el menú, por favor seleccione una opción válida \n"
                        break;
                    }
                }
                rutas_.push_back(ruta);
        }

void Monitor::cancelaRuta(int identificador){
    list<Ruta>::iterator pos;
    pos = rutas_.begin();
			if(!rutas_.empty()){
				for(long unsigned int i = 0; i<rutas_.size(); i++){
					if((*pos).getIdentificador()==identificador()){
						rutas_.erase(*pos);
                        return true;
					}
					pos++;
				}
			}
            cout << "No se ha podido encontrar una ruta que tenga ese identificador \n";
            return false;
}

void Monitor::crearIncidencia(){
    float latitud, longitud;
    string parque, sendero, descripcion;
    Incidencia incidencia;

    cout << "Introduzca el nombre del parque: ";
    cin >> incidencia.parque;
    cout << "\n";

    cout << "Introduzca el nombre del sendero: ";
    cin >> incidencia.sendero;
    cout << "\n";

    cout << "Introduzca una breve descripción de la incidencia que ha encontrado:\n"
    cin >> incidencia.descripcion;

    cout << "A continuacion, introduzca la latitud en la que se encuentra: ";
    cin >> incidencia.latitud;

    cout << "A continuacion, introduzca la longitud en la que se encuentra: ";
    cin >> incidencia.longitud;

    incidencias_.push_back(incidencia);
}

string Monitor::generarContraseña(int size) {
    
    string contraseña;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve(size);

    for (int i = 0; i < size; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    
    return contraseña;
    
}
Monitor::~Monitor() {

}