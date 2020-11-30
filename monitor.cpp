 /*
 * monitor.cpp
 *
 *  Created on: 29 nov. 2020
 *      Author: Jose Manuel Flores Barranco
 */

#include "monitor.h"

Monitor::Monitor() {

}
string generarContraseña(int size) {
    
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