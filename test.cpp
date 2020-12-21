#include "parque.h"
#include "incidencia.h"
#include "monitor.h"
#include "sendero.h"
#include "ruta.h"
#include "visitante.h"
#include "gtest/gtest.h"

Monitor monitor;
Parque p;
Ruta ruta;

TEST(Ruta, CrearRuta)
{

	list<Ruta> rutas;
	list<Ruta>::iterator pos;

	//Añadimos la primera ruta
	/*Ruta a añadir
	 * Parcial
	 * A pie
	 * longitud=2,5km
	 * 3h15m
	 * Aforo=12
	 * Niños=No
	*/
	 

	monitor.crearRuta();
	rutas=monitor.getRuta();
	pos=rutas.begin();

	//Anadimos la segunda ruta

	/*Ruta a añadir
	 * Completa
	 * En bicicleta
	 * 2,1
	 * 1h15m
	 * 7
	 * Si
	 */
	 

	monitor.crearRuta();
	rutas=monitor.getRuta();
	pos=rutas.begin();


	//Comprobamos que haya 2 rutas
	EXPECT_EQ(rutas.size(),2);

	//Comprobamos el posisitante 1
	EXPECT_EQ((*pos).getTipo(),"Parcial");
	EXPECT_EQ((*pos).getModalidad(),"Pie");
	EXPECT_EQ((*pos).getLongitud(),2500);
	EXPECT_EQ((*pos).getDuracion(),195);
	EXPECT_EQ((*pos).getAforo(),12);
	EXPECT_EQ((*pos).getrutaNinos(),false);


	//Comprobamos la ruta 2
	pos++;

	EXPECT_EQ((*pos).getTipo(),"Completa");
	EXPECT_EQ((*pos).getModalidad(),"Bicicleta");
	EXPECT_EQ((*pos).getLongitud(),2100);
	EXPECT_EQ((*pos).getDuracion(),75);
	EXPECT_EQ((*pos).getAforo(),7);
	EXPECT_EQ((*pos).getrutaNinos(),true);
}


TEST(Monitor, CancelaRuta)
{

	Monitor monitor_2;
	list<Ruta> rutas;
	rutas=monitor_2.getRuta();

	Ruta ruta1;
	ruta1.setIdentificador(034);
	rutas.push_back(ruta1);

	/* Ruta a borrar
	 * ID = 034
	 */
	EXPECT_EQ(rutas.size(),1);

	monitor_2.cancelaRuta(034);
	rutas=monitor_2.getRuta();

	EXPECT_EQ(rutas.size(),0);

	/*Ruta a borrar
	 * ID = 034
	 */
	 

	monitor_2.cancelaRuta(034);
	rutas=monitor_2.getRuta();

	EXPECT_EQ(rutas.size(),0);
}

TEST(Monitor, CancelaRuta)
{
	list<Ruta> rutas;

	/* Ruta a borrar
	 * ID = 034
	 */
	 

	monitor.cancelarRuta(034);
	rutas=monitor.getRutas();

	EXPECT_EQ(rutas.size(),1);

	/*Ruta a borrar
	 * ID = 034
	 */
	 

	monitor.cancelarRuta(034);
	rutas=monitor.getRutas();

	EXPECT_EQ(rutas.size(),1);
}

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