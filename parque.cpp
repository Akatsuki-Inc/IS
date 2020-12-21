#include "parque.h"

Parque::Parque(){}

void Parque::ListarSenderos()
{
    cout<<"Nombre"<<endl;

    for(s_=Sendero_.begin();s_!=Sendero_.end();s_++)
    {
        cout<<(*s_).getNombre()<<endl;
    }
}

bool Parque::BuscarSendero(string nombre,Sendero &sendero)
{
    for(s_=Sendero_.begin();s_!=Sendero_.end();s_++)
    {
        if((*s_).getNombre()==nombre)
        {
        	sendero=(*s_);
            return true;
        }
    }

    return false;
}

void Parque::ListarMonitores()
{
    cout<<"Nombre   |   DNI"<<endl;

    for(m_=Monitor_.begin();m_!=Monitor_.end();m_++)
    {
        cout<<(*m_).getNombre()<<" "<<(*m_).getDNI()<<endl;
    }
}

bool Parque::BuscarMonitor(string DNI,Monitor &monitor)
{
    for(m_=Monitor_.begin();m_!=Monitor_.end();m_++)
    {
        if((*m_).getDNI()==DNI)
        {
            monitor=(*m_);
            return true;
        }
    }

    return false;
}

void Parque::anadirMonitor()
{
    Monitor monitor;
    string aux;
    int aux2;

    cout<<"Introduzca el DNI"<<endl;
    cin>>aux;

    if(!BuscarMonitor(aux,monitor))
    {
        monitor.setDNI(aux);

        cout<<"Introduzca el nombre"<<endl;
        cin>>aux;

        monitor.setNombre(aux);

        cout<<"Introduzca la fecha de nacimiento"<<endl;
        cin>>aux;

        monitor.setFechaNacimiento(aux);

        cout<<"Introduzca el telefono"<<endl;
        cin>>aux2;

        monitor.setTelefono(aux2);

        cout<<"Introduzca la direccion"<<endl;
        cin>>aux;

        monitor.setDireccion(aux);

        cout<<"Introduzca el correo"<<endl;
        cin>>aux;

        monitor.setCorreo(aux);

        cout<<"Introduzca el parque en el que trabaja"<<endl;
        cin>>aux;

        monitor.setParque(aux);

        monitor.setContrasena(monitor.generarContrasena(9));

        cout<<"Esta es su contrase�a: "<<monitor.getContrasena()<<endl;

        Monitor_.push_back(monitor);
    }

    else
    {
        cout<<"El monitor ya existe"<<endl;
    }

}

void Parque::borrarMonitor()
{
    Monitor monitor;
    string aux;
    int aux2;
    int aux3=0;

    ListarMonitores();

    cout<<"\nIntroduce el DNI del Monitor que quiere borrar\n"<<endl;
    cin>>aux;

    if(!BuscarMonitor(aux,monitor))
    {
        cout<<"El Monitor que busca no existe"<<endl;
    }

    else
    {
        do{
            cout<<"¿Seguro que quiere borrar al siguiente Monitor? Se perferan todos sus datos"<<endl;
            cout<<monitor.getNombre()<<" con DNI "<<monitor.getDNI()<<endl;
            cout<<"1.Borrar\n2.Cancelar"<<endl;
            cin>>aux2;

            if(aux2==1)
            {

                for(m_=Monitor_.begin();m_!=Monitor_.end();m_++)
                {
                    if((*m_).getDNI()==monitor.getDNI())
                    {
                        Monitor_.erase(m_);
        
                    }
                }


                cout<<"Monitor borrado con exito"<<endl;
                aux3++;
            }

            else if((aux2>2)||(aux2<1))
            {
                cout<<"Opcion no permitida"<<endl;
            }

            else
            {
                aux3++;
            }

        }while(aux3==0);

    }       

}

void Parque::modificaMonitor()
{
    Monitor oldmonitor;
    Monitor newmonitor;
    string aux;
    int aux2;
    int aux3;

    ListarMonitores();

    cout<<"Introduzca el DNI del Monitor que quiere modificar"<<endl;
    cin>>aux;

    if(!BuscarMonitor(aux,oldmonitor))
    {
        cout<<"El Monitor que busca no existe"<<endl;
    }

    else
    {
        newmonitor=oldmonitor;
        do{
            cout<<"1.Nombre: "<<newmonitor.getNombre()<<endl;
            cout<<"2.DNI: "<<newmonitor.getDNI()<<endl;
            cout<<"3.Correo: "<<newmonitor.getCorreo()<<endl;
            cout<<"4.Fecha de Nacimiento: "<<newmonitor.getFechaNacimiento()<<endl;
            cout<<"5.Direccion: "<<newmonitor.getDireccion()<<endl;
            cout<<"6.Telefono: "<<newmonitor.getTelefono()<<endl;
            cout<<"Introduce que quiere modificar. Pulse 7 para cancelar"<<endl;
            cin>>aux2;

            switch(aux2)
            {
                case 1:
                    cout<<"Introduce el nuevo nombre"<<endl;
                    cin>>aux;

                    newmonitor.setNombre(aux);
                    break;

                case 2:
                    cout<<"Introduce el nuevo DNI"<<endl;
                    cin>>aux;

                    newmonitor.setDNI(aux);
                    break;

                case 3:
                    cout<<"Introduce el nuevo correo"<<endl;
                    cin>>aux;

                    newmonitor.setCorreo(aux);
                    break;

                case 4:
                    cout<<"Introduce la nueva fecha de nacimiento"<<endl;
                    cin>>aux;

                    newmonitor.setFechaNacimiento(aux);
                    break;

                case 5:
                    cout<<"Introduce la nueva direccion"<<endl;
                    cin>>aux;

                    newmonitor.setDireccion(aux);
                    break;

                case 6:
                    cout<<"Introduce el nuevo telefono"<<endl;
                    cin>>aux3;

                    newmonitor.setTelefono(aux3);
                    break;

                case 7: break;

                default:
                    cout<<"Opcion no permitida"<<endl;
                    break;
            }

            if((aux2>0)||(aux2<7))
            {
                for(m_=Monitor_.begin();m_!=Monitor_.end();m_++)
                {
                   if((*m_).getDNI()==oldmonitor.getDNI())
                    {
                        *(m_)=newmonitor;
                    } 
                }

                cout<<"Monitor modificado con exito"<<endl;
            }

        }while(aux2!=7);
    }

}

void Parque::anadirSendero()
{
    Sendero sendero;
    string aux;
    float aux2;

    cout<<"Introduzca el nombre del sendero"<<endl;
    cin>>aux;

    if(BuscarSendero(aux,sendero)==false)
    {
        sendero.setNombre(aux);

        cout<<"Introduzca la descripcion del sendero"<<endl;
        cin>>aux;

        sendero.setDescripcion(aux);

        cout<<"Introduzca la dificultad del sendero"<<endl;
        cin>>aux;

        sendero.setDificultad(aux);

        cout<<"Introduzca la disponibilidad del sendero"<<endl;
        cin>>aux;

        sendero.setDisponibilidad(aux);

        cout<<"Introduzca la longitud del sendero"<<endl;
        cin>>aux2;

        sendero.setLongitud(aux2);

        Sendero_.push_back(sendero);

        cout<<"Sendero a�adido con exito"<<endl;
    }

    else
    {
        cout<<"El sendero ya existe"<<endl;
    }

}


void Parque::actualizaRutas()
{
    list<Ruta> RutasMonitor;
    list<Ruta>::iterator rm;
    int existe=0;

    for(m_=Monitor_.begin();m_!=Monitor_.end();m_++)
    {
        RutasMonitor=(*m_).getRuta();

        for(rm=RutasMonitor.begin();rm!=RutasMonitor.end();rm++)
        {
            for(r_=Ruta_.begin();r_!=Ruta_.end();r_++)
            {
                if((*rm).getIdentificador()==(*r_).getIdentificador())
                {
                    existe=1;
                }
            }

            if(existe==1)
            {
                existe=0;
            }

            else
            {
                Ruta_.push_back(*rm);
            }

        }
    }
} 

void Parque::modificarSendero(){
        Sendero oldsendero;
        Sendero newsendero;
        string respuesta_s;
        int respuesta_i;
        int eleccion=0;

        ListarSenderos();

        cout<<"Introduzca el DNI del Monitor que quiere modificar"<<endl;
        cin>>respuesta_s;

        if(BuscarSendero(respuesta_s,oldsendero)==true)
			{
            	newsendero=oldsendero;

        		while(eleccion!=6){
                        cout << "Eliga una de los atributos que quiera modificar\n";
                        cout << "1) Nombre \n";
                        cout << "2) Brebe descripci�n \n";
                        cout << "3) Dificultad \n";
                        cout << "4) Longitud \n";
                        cout << "5) Disponibilidad \n";
                        cout << "6) Salir\n";

                        cin >> eleccion;

                        switch (eleccion)
                            {
                                
                                case 1: 
                                    cout << "Introduzca el nuevo nombre del sendero: \n";
                                    cin >> respuesta_s;
                                    newsendero.setNombre(respuesta_s);
                                    break;

                                case 2:
                                    cout << "Introduzca la descripici�n: \n";
                                    cin >> respuesta_s;
                                    newsendero.setDescripcion(respuesta_s);
                                    break;

                                case 3:
                                    cout << "Introduzca la dificultad: \n";
                                    cin >> respuesta_s;
                                    newsendero.setDificultad(respuesta_s);
                                    break;
                                
                                case 4:
                                    cout << "Introduzca la longitud: \n";
                                    cin >> respuesta_i;
                                    newsendero.setLongitud(respuesta_i);
                                    break;
                                
                                case 5:
                                    cout << "Introduzca su disponibilidad: \n";
                                    cin >> respuesta_s;
                                    newsendero.setDisponibilidad(respuesta_s);
                                    break;
                                
                                case 6:
                                    cout << "   Saliendo del menu... \n" ;
                                    break;
                                
                                default:
                                    cout << "Su elecci�n no est� en el men�, por favor seleccione una opci�n v�lida \n";
                                    break;
                             }

                        for(s_=Sendero_.begin();s_!=Sendero_.end();s_++)
                            {
                                  if((*s_).getNombre()==oldsendero.getNombre())
                                         {
                                             *(s_)=newsendero;
                                         }
                            }

                   }
        }
}

void Parque::dividirGrupo(int identificador, Monitor monitor){
    list <Visitante> visitantes;
    list <Visitante> visitantes2;
    list <Visitante>::iterator v;
    Ruta ruta2;
    int aux;

    for(r_=Ruta_.begin();r_!=Ruta_.end();r_++)
    {
    	if((*r_).getIdentificador()==identificador)
    	{
    		ruta2=(*r_);

    		visitantes=(*r_).getVisitantes();

    		for(v=visitantes.begin();v!=visitantes.end();v++)
    		{
    			if(aux>(*r_).getAforo()/2)
    			{
    				visitantes2.push_back(*v);
    				visitantes.erase(v);
    			}

    			aux++;
    		}

    		(*r_).setVisitantes(visitantes);
    		ruta2.setVisitantes(visitantes2);

    		time_t aux=ruta2.getFecha();
    		aux+=300;
    		ruta2.setFecha(aux);
    	}
    }

    cambiaMonitor(ruta2,aux);
}

void Parque::cambiaMonitor(Ruta ruta, time_t aux){

	int libre=1;
	int asignado=0;
	list <Ruta> rutas;

	for(m_=Monitor_.begin();m_!=Monitor_.end();m_++)
	{

		if(asignado==0)
		{
			for(r_=rutas.begin();r_!=rutas.end();r_++)

			{
				if((*r_).getFecha()==aux)
				{
					libre=0;
				}
			}

			if(libre==0)
			{
				libre=1;
			}

			else
			{
				(*m_).anadirRuta(ruta);
				asignado=1;
			}

		}
	}

}


void Parque::borrarIncidencia(int identificador){

	for(i_=Incidencia_.begin();i_!=Incidencia_.end();i_++)
	    {
	    	if((*i_).getIdentificador()==identificador)
	    	{
	    		Incidencia_.erase(i_);
	    	}
	    }
}

void Parque::anadirIncidencia(Incidencia incidencia){

	int existe=0;

	for(i_=Incidencia_.begin();i_!=Incidencia_.end();i_++)
    {
    	if((*i_).getIdentificador()==incidencia.getIdentificador())
    	{
    		existe=1;
    	}
    }

	if(existe==0)
	{
		Incidencia_.push_back(incidencia);
	}

	else
	{
		cout<<"Error, la incidencia ya esta registrada"<<endl;
	}
}

