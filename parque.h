#ifndef PARQUE_H
#define PARQUE_H
#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include "sendero.h"
#include "ruta.h"
#include "visitante.h"
#include "monitor.h"
#include "incidencia.h"

using namespace std;

class Parque{
private:
	string ubicacion_, fechaReconocimiento_, premios_;
	int superficie_;
	list <Sendero> Sendero_;
    list <Sendero>::iterator s_;
	list <Ruta> Ruta_;
    list <Ruta>::iterator r_;
	list <Monitor> Monitor_;
    list <Monitor>::iterator m_;
	list <Incidencia> Incidencia_;
	list <Incidencia>::iterator i_;

    void ListarSenderos();
	bool BuscarSendero(string nombre,Sendero &sendero);
	void ListarMonitores();
	bool BuscarMonitor(string DNI,Monitor &m);
public:
	Parque();

	inline string getUbicacion(){return ubicacion_;}

	void setUbicacion(string ubicacion){
		ubicacion_=ubicacion;
	}

	inline string getPremios(){return premios_;}

	void setPremios(string premios){
		premios_=premios;
	}

	inline int getSuperficie(){return superficie_;}

	void setSeperficie(int superficie){
		superficie_=superficie;
	}

	inline string getFecha(){return fechaReconocimiento_;}

	void setFecha(string fechaReconocimiento){
		fechaReconocimiento_=fechaReconocimiento;
	}

    list <Incidencia> inline getIncidencia(){return Incidencia_;}

	list <Sendero> inline getSendero(){return Sendero_;}

	inline list <Ruta> getRutas(){return Ruta_;}

	void actualizaRutas();

	void modificarSendero();

	void anadirSendero();

	inline list <Monitor> getMonitores(){return Monitor_;}

	void anadirMonitor();

	void borrarMonitor();

	void modificaMonitor();

	void dividirGrupo(int identificador, Monitor monitor);

	void cambiaMonitor(Ruta ruta,time_t aux);

	inline list <Incidencia> getIncidencias(){return Incidencia_;}

	void borrarIncidencia(int identificador);

	void anadirIncidencia(Incidencia incidencia);
};



#endif
