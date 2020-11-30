#ifndef PARQUE_H
#define PARQUE_H
#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
using namespace std;

class Parque{
private:
	string ubicacion_, fechaReconocimiento_, premios_;
	int superficie_;
	list <Sendero> Sendero_;
	list <Ruta> Ruta_;
	list <Monitor> Monitor_;
	list <Incidencia> Incidencia_;
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

	inline list <Sendero> getSendero(){return Sendero_;}

	inline list <Ruta> getRutas(){return Ruta_;}

	void actualizaRutas();

	void añadirRuta(Ruta ruta);

	void modificarSendero(list <Sendero> sendero){
		Sendero_=sendero;
	}

	void añadirSendero();

	inline list <Monitor> getMonitores(){return Monitor_;}

	void añadirMonitor();

	void borrarMonitor();

	void modificaMonitor();

	void dividirGrupo();

	void cambiaMonitor();

	inline list <Incidencia> getIncidencias(){return Incidencia_;}

	void borrarIncidencia();

	void añadirIncidencia(Incidencia incidencia);
};



#endif