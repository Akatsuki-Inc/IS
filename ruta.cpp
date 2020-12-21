#include "ruta.h"
Ruta::Ruta()
{

}

bool Ruta::setTipo(string tipo)
{
    if((tipo=="Parcial")||(tipo=="Completa"))
    {
        tipo_=tipo;
        return true;
    }

    else
    {
        return false;
    }
}

bool Ruta::setModalidad(string modalidad)
{
   if((modalidad=="Pie")||(modalidad=="Bicicleta"))
    {
        modalidad_=modalidad;
        return true;
    }

    else
    {
        return false;
    } 
}

bool Ruta::setFecha(time_t fecha)
{
    time_t fechaactual=time(NULL);
    if(fecha>fechaactual)
    {
        fecha_=fecha;
        return true;
    }

    else
    {
        return false;
    }
}

void Ruta::anadirVisitante(){
    Visitante visitante;
    string aux_s;
    int aux_i;
    int existe=0;
    list <Visitante>:: iterator it;
    it= visitantes_.begin();

    cout<<"Introduzca el DNI del visitante"<<endl;
    cin>> aux_s;

    visitante.setDNI(aux_s);

    for(long unsigned int i=0; i<visitantes_.size();i++){
        if((*it).getDNI()==visitante.getDNI()){
            cout<<"Ya existe un visitante con el DNI: "<<
            visitante.getDNI()<<endl;
            existe=1;
        }

        it++;
    }

    if(existe==0)
    {
        cout<<"Introduzca el nombre del visitante"<<endl;
        cin>>aux_s;

        visitante.setNombre(aux_s);

        cout<<"Introduzca el tel�fono del visitante"<<endl;
        cin>> aux_i;

        visitante.setTelefono(aux_i);

        cout<<"Introduzca la fecha de nacimiento  del visitante"<<endl;
        cin>> aux_s;

        visitante.setFechaNacimiento(aux_s);

        cout<<"Introduzca las afecciones del visitante. Si no presenta ninguna,introduzca *NINGUNA*"<<endl;
        cin>> aux_s;

        visitante.setCondiciones(aux_s);

        visitantes_.push_back(visitante);
    }
}

void Ruta:: borrarVisitante(){
    Visitante visitante;
    string DNI;
    int encontrado=0;
    list <Visitante>:: iterator it;
    it= visitantes_.begin();

    cout<<"Introduzca el DNI del visitante"<<endl;
    cin>> DNI;

    if(visitantes_.empty()){
        cout<<"La lista esta vacia"<<endl;
    }

    if(!visitantes_.empty()){  
        list <Visitante>::iterator it; 
        it=visitantes_.begin();
        for(long unsigned int j=0;j<visitantes_.size();j++){
            if((*it).getDNI()==DNI){    
                visitantes_.erase(it);
                cout<<"El visitante ha sido eliminado"<<endl;
                encontrado=1;
            }
            j++;
        }

        if(encontrado=0)
        {
            cout<<"No se ha podido encontrar el DNI"<<endl;
        }
    }
}


void Ruta:: setSenderos(list <Sendero> senderos){
    sendero_=senderos;
}

Ruta::~Ruta() {
	// TODO Auto-generated destructor stub
}


