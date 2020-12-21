#include "parque.h"
#include "incidencia.h"
#include "monitor.h"
#include "sendero.h"
#include "ruta.h"
#include "visitante.h"
#include "gtest/gtest.h"

Parque p;
Ruta ruta;

TEST(Parque, anadeIncidencia)
{
	Incidencia i;
	int identificador= 203;
	i.setIdentificador(identificador);
	p.anadirIncidencia(i);
	EXPECT_EQ(p.getIncidencia().size(), 1);
}

TEST(Parque, existeIncidencia)
{
	Incidencia i;
	int identificador= 203;
	i.setIdentificador(identificador);
	p.anadirIncidencia(i);

	p.anadirIncidencia(i);
	EXPECT_EQ(p.getIncidencia().size(), 1);
}

TEST(Parque, borraIncidencia)
{
	Incidencia i;
	int identificador= 203;
	i.setIdentificador(identificador);
	p.anadirIncidencia(i);

	p.borrarIncidencia(identificador);
	EXPECT_EQ(p.getIncidencia().size(), 0);
}

TEST(Parque, noExisteIncidencia)
{
	Incidencia i;
	int identificador= 203;
	i.setIdentificador(identificador);
	p.anadirIncidencia(i);

	p.borrarIncidencia(identificador);

	p.borrarIncidencia(identificador);
	EXPECT_EQ(p.getIncidencia().size(), 0);
}

TEST(Ruta, AnadirVisitante)
{

	list<Visitante> visitantes;
	list<Visitante>::iterator v;

	//Añadimos el primer visitante
	/*Visitante a añadir
	 * 20226488N
	 * Alberto
	 * 633018191
	 * 29/10/2001
	 * Ninguna
	 */

	ruta.anadirVisitante();
	visitantes=ruta.getVisitantes();
	v=visitantes.begin();

	//Anadimos el segundo visitante

	/*Visitante a añadir
	 * 30808810X
	 * Aitana
	 * 123456789
	 * 13/05/2001
	 * Ninguna
	 */

	ruta.anadirVisitante();
	visitantes=ruta.getVisitantes();
	v=visitantes.begin();


	//Comprobamos que haya 2 visitantes
	EXPECT_EQ(visitantes.size(),2);

	//Comprobamos el visitante 1
	EXPECT_EQ((*v).getDNI(),"20226488N");
	EXPECT_EQ((*v).getNombre(),"Alberto");
	EXPECT_EQ((*v).getTelefono(),633018191);
	EXPECT_EQ((*v).getFechaNacimiento(),"29/10/2001");
	EXPECT_EQ((*v).getCondiciones(),"Ninguna");


	//Comprobamos el visitante 2
	v++;

	EXPECT_EQ((*v).getDNI(),"30808810X");
	EXPECT_EQ((*v).getNombre(),"Aitana");
	EXPECT_EQ((*v).getTelefono(),123456789);
	EXPECT_EQ((*v).getFechaNacimiento(),"13/05/2001");
	EXPECT_EQ((*v).getCondiciones(),"Ninguna");

	//Intentamos anadir un visitante con un DNI que ya esta registrado
	/*Visitante a añadir
	 * 20226488N
	 * Alberto
	 * 633018191
	 * 29/10/2001
	 * Ninguna
	 */

	ruta.anadirVisitante();
	visitantes=ruta.getVisitantes();
	v=visitantes.begin();

	EXPECT_EQ(visitantes.size(),2);
}


TEST(Ruta, BorrarVisitante)
{
	list<Visitante> visitantes;

	/*Visitante a borrar
	 * 20226488N
	 * Alberto
	 * 633018191
	 * 29/10/2001
	 * Ninguna
	 */

	ruta.borrarVisitante();
	visitantes=ruta.getVisitantes();

	EXPECT_EQ(visitantes.size(),1);

	/*Visitante a borrar
	 * 20226488N
	 * Alberto
	 * 633018191
	 * 29/10/2001
	 * Ninguna
	 */

	ruta.borrarVisitante();
	visitantes=ruta.getVisitantes();

	EXPECT_EQ(visitantes.size(),1);
}