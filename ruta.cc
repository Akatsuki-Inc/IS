#include "ruta.h"

Ruta::Ruta() {
	// TODO Auto-generated constructor stub

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
   if((modalidad=="Pie")||(tipo=="Bicicleta"))
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

void Ruta::añadirvisitante(){
    Visitante visitante;
    string aux_s;
    int aux_i;
    list <Visitante>:: iterator it;
    it= visitantes_.begin();

    cout<<"Introduzca el DNI del visitante"<<endl;
    cin>> aux_s;

    visitante.setDNI(aux_s){
        DNI_=aux_s;
    }

    for(long unsigned int i=0; i<visiantes_.size();i++){
        if((*it).getDNI()==visitante.getDNI()){
            cout<<"Ya existe un visitante con el DNI: "<<
            visitante.getDNI()<<endl;
        }

        it++;
    }

    cout<<"Introduzca el nombre del visitante"<<endl;
    cin>> aux_s;

    visitante.setNombre(aux_s){
        nombre_= aux_s;
    }

    cout<<"Introduzca el teléfono del visitante"<<endl;
    cin>> aux_i;

    visitante.setTelefono(aux_i){
        telefono_= aux_i;
    }

    cout<<"Introduzca la fecha de nacimiento  del visitante"<<endl;
    cin>> aux_s;

    visitante.setFechaNacimiento(aux_s){
        fechaNacimiento_= aux_s;
    }

    cout<<"Introduzca las afecciones del visitante. Si no presenta ninguna,
    introduzca *NINGUNA*"<<endl;
    cin>> aux_s;

    visitante.setCondiciones(aux_s){
        condiciones_= aux_s;
    }

    visiantes_.push_back(visitante);
}

void Ruta:: borrarVisitante(){
    Visitante visitante;
    string DNI;
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
        for(long unsigned int j=0;j<jugadores_.size();j++){
            if((*it).getDNI()==DNI){    
                visitantes_.erase(it);
                cout<<"El visitante ha sido eliminado"<<endl;
            }
            i++;
        }
        cout<<"No se ha podido encontrar el DNI"<<endl;
    }
}


void Ruta:: setSenderos(list <Sendero> senderos){
    senderos_=senderos;
}

Ruta::~Ruta() {
	// TODO Auto-generated destructor stub
}
