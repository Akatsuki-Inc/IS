#include "parque.h"
#include "gtest/gtest.h"

Ruta ruta;

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