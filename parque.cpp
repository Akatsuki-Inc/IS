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

void Parque::añadirMonitor()
{
    Monitor monitor;
    string aux;
    int aux2;

    cout<<"Introduzca el DNI"<<endl;
    cin>>aux;

    if(BuscarMonitor(aux,monitor)==false)
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

        monitor.setContraseña(monitor.generarContraseña(9));

        cout<<"Esta es su contraseña: "<<monitor.getContraseña()<<endl;

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

    if(BuscarMonitor(aux,monitor)==false)
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
                Monitor_.remove(monitor);
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

    if(BuscarMonitor(aux,oldmonitor)==false)
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

void Parque::añadirSendero()
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

        cout<<"Sendero añadido con exito"<<endl;
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
        Sendero sendero;
        int eleccion, n, respuesta_i;
        string respuesta_s;
        cout << "¿Quiere que se le desplieguen los nombres de los senderos registrados? [S] [N]\n";
        while(1){
            cin >> respuesta_s;
            if (respuesta_s == "S"){
                ListarSenderos();
                break;
            }
            else if(respuesta_s == "N"){
                break;
            }
            else{
                cout << "ERROR: Por favor, introduzca una de las opciones disponibles [S] [N]\n";
            }
        }
		cout << "Indique el nombre del sendero que quiere modificar \n";
        cin >> respuesta_s;


        //nombre, breve descripción, su grado de dificultad, la longitud de éstos, disponibilidad
        while(1){
            if(BuscarSendero(respuesta_s, getSendero()==false){
                cout << "El sendero elegido no se encuentra entre los requistrados, inténtelo de nuevo \n";
            }
            else{
                for(s_=getSendero().begin();s_!=getSendero().end();s_++){
                    if((*s_).getNombre()==respuesta_s){
                        sendero(*s_);
                        getSendero().erase(s_);
                    }
                    while(1){
                        cout << "Eliga una de los atributos que quiera modificar\n"
                        cout << "1) Nombre \n";
                        cout << "2) Brebe descripción \n";
                        cout << "3) Dificultad \n";
                        cout << "4) Longitud \n";
                        cout << "5) Disponibilidad \n";
                        cout << "6) Salir\n"

                        cin >> eleccion;

                        while(n==1){
                            switch (eleccion)
                            {
                                
                                case 1: 
                                    cout << "Introduzca el nuevo nombre del sendero: \n";
                                    cin >> respuesta_s;
                                    sendero.setNombre(respuesta_s)

                                case 2:
                                    cout << "Introduzca la descripición: \n";
                                    cin >> respuesta_s;
                                    sendero.setDescripcion(respuesta_s)
                                    break;

                                case 3:
                                    cout << "Introduzca la dificultad: \n";
                                    cin >> respuesta_s;
                                    sendero.setDificultad(respuesta_s);
                                    break;
                                
                                case 4:
                                    cout << "Introduzca la longitud: \n";
                                    cin >> respuesta_i;
                                    sendero.setLongitud(respuesta_i);
                                    break;
                                
                                case 5:
                                    cout << "Introduzca su disponibilidad: \n";
                                    cin >> respuesta_s;
                                    sendera.setDisponibilidad(respuesta_s);
                                    break;
                                
                                case 6:
                                    cout << "   Saliendo del menu... \n" ;
                                    n=0;
                                    break;
                                
                                default:
                                    cout << "Su elección no está en el menú, por favor seleccione una opción válida \n"
                                    break;
                                }
                            }
                            getSendero_.push_back(sendero);
                        }
                }
            }
        }
	}

void Parque::dividirGrupo(int identificador, Monitor monitor){
    Ruta ruta;
    list <Visitante> n_visitantes;

    int i=0;

    for(s_=getRutas().begin();s_!=getRutas().end();s_++){
            if((*s_).getIdentificador()==identificador){
                ruta(*s_);
                for(v_=(*s_).getVisitantes().end();s_!=(*s_).getVisitantes().begin();v_--){
                        while((i>=(*v_).getAforo()/2)&&(i>=(*s_).getAforo()){
                            n_visitantes.push_back(*v_);
                            (*s_).getVisitantes().pop_back();                   
                        }
                }
            }
    }
    ruta.setVisitantes(n_visitantes);
    ruta.setMonitor(monitor);
    getRutas().push_back(ruta);
}

void Parque::cambiaMonitor(Monitor monitor){

    cout << "Elija el identificador de la ruta que quiere cambiar el monitor\n";
    cin >> identificador;
    for(s_=getRutas().begin();s_!=getRutas().end();s_++){
            if((*s_).getIdentificador()==identificador){
                (*s_).setMonitor(monitor);
            }
    }

}

void Parque::borrarIncidencia(){
    int identificador;
    cout << "Introduce el identificador de la incidencia\n";
    cin >> identificador;

    for(s_=getIncidencias().begin();s_!=getIncidencias().end();s_++){
            if((*s_).getIdentificador()==identificador){
                getIncidencias().erase(s_);
            }
    }
}

void Parque::añadirIncidencia(Incidencia incidencia){
    float latitud, longitud;
    string parque, sendero, descripcion;

    cout << "Introduzca el sendero donde se encuentra la incidencia";
    cin >> respuesta_s;

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

    getIncidencias().push_back(incidencia);
}

Parque::~Parque() {

}