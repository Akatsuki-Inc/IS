#ifndef RUTA_H_
#define RUTA_H_
#include "visitante.h"
#include "sendero.h"
#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class Ruta 
{
	private:
	int identificador_;
        string tipo_;
        string modalidad_;
        string actividades_;
        time_t fecha_;
        float longitud_;
        int duracion_;
        int aforo_;
        bool rutaNinos_;
        list<Visitante> visitantes_;
        list<Sendero> sendero_;
        bool aforo_disponible_;


	public:
	Ruta();
	int inline getIdentificador() const {return identificador_;}
        string inline getTipo() const {return tipo_;}
        bool setTipo(string tipo);
        string inline getModalidad() const{return modalidad_;}
        bool setModalidad(string modalidad);
        string inline getActividades() const{return actividades_;}
        void setActividades(string actividades){actividades_=actividades;}
        time_t inline getFecha() const {return fecha_;}
        bool setFecha(time_t fecha);
        float inline getLongitud() const {return longitud_;}
        void inline setLongitud(float longitud){longitud_=longitud;}
        int inline getDuracion() const {return duracion_;}
        void inline setDuracion(int duracion){duracion_=duracion;}
        int inline getAforo() const {return aforo_;}
        void inline setAforo(int aforo){aforo_=aforo;}
        bool inline getrutaNinos() const {return rutaNinos_;}
        void inline setrutaNinos(bool opcion){rutaNinos_=opcion;}
        list<Visitante> inline getVisitantes() const {return visitantes_;}
        void anadirVisitante();
        void borrarVisitante();
        list<Sendero> inline getSenderos() const {return sendero_;}
        void setSenderos(list <Sendero> senderos);
        void inline setVisitantes(list<Visitante> visitantes){visitantes_=visitantes;}
	virtual ~Ruta();
};

#endif /* RUTA_H_ */
