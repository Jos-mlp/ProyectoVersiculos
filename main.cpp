#include <iostream>
#include <fstream>
#include <vector>
#include "Lista.h"
#include "Nodo.h"

using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

//variable para guardar el nombre del archivo
string nombre;

//variable para guardar el texto de cada versiculo antes de ser agregado
string texto="";
//variable para guardar el pasaje de cada versiculo antes de ser agregado
string pasaje="";

//variable para saber cuando se esta trabajndo sobre alguna linea que contenga un pasaje
bool pasa = false;
int cont = 0;
Lista versiculos = Lista();

int ComprobarPalabra(string p){
    if(p=="Genesis" || p=="Exodo" || p=="Levitico" || p=="Numeros" || p=="Deuteronomio" || p=="Josue" || p=="Jueces" || p=="Rut" || p=="1Samuel" || p=="2Samuel" || p=="1Reyes" ||
       p=="2Reyes" || p=="1Cronicas" || p=="2Cronicas" || p=="Genesis" || p=="Esdras" || p=="Nehemias" || p=="Ester" || p=="Job" || p=="Salmos" || p=="Proverbios" || p=="Eclesiastes" ||
       p=="Cantares" || p=="Isaias" || p=="Jeremias" || p=="Lamentaciones" || p=="Ezequiel" || p=="Daniel" || p=="Oseas" || p=="Joel" || p=="Amos" || p=="Abdias" || p=="Jonas" ||
       p=="Miqueas" || p=="Nahum" || p=="Habacuc" || p=="Sofonias" || p=="Hageo" || p=="Zacarías" || p=="Malaquías" || p=="Mateo" || p=="Marcos" || p=="Lucas" || p=="Juan" ||
       p=="Hechos" || p=="Romanos" || p=="1Corintios" || p=="2Corintios" || p=="Galatas" || p=="Efesios" || p=="Filipenses" || p=="Colosenses" || p=="1Tesalonicenses" || p=="2Tesalonicenses"||
       p=="1Timoteo" || p=="2Timoteo" || p=="Tito" || p=="Filemon" || p=="Hebreos" || p=="Santiago" || p=="1Pedro" || p=="2Pedro" || p=="1Juan" || p=="2Juan" || p=="3Juan" ||
       p=="Judas" || p=="Apocalipsis") {
            pasa=true;
            cont++;
        }

}

void SepararTexto(string t){
  string aux;
  int i = -1;
  do{
    i++;
    if(t[i] == ' ' || t[i] == '\0'){
        ComprobarPalabra(aux);
        aux="";
    }else{
        aux=aux+t[i];
    }
  } while(t[i] != '\0');
}

bool AbrirArchivo(){
    cout<<"Escriba el nombre del archivo a abrir"<<endl;
    cin>>nombre;
    cout<<endl;
    string filename("versiculos\\" + nombre);
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "El archivo no se encontro: "
             << filename << "'" << endl;
        cout << EXIT_FAILURE;
        return false;
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }


    //Se utiliza para dividir las lineas
    for (const auto &i : lines){
        //cout << i << endl;
        //string aux=i;
        SepararTexto(i);
        //separa el texto del pasaje
        if(pasa==true){
            pasaje = i;
            pasa=false;
            versiculos.InsertarFinal(pasaje,texto);
            texto="";
        }else{
            if(i!=""){
                 texto=texto+i+'\n';
            }
        }

    }


    input_file.close();
    return true;
}

int main()
{
    cout<<"Bienvendio al programa VERSICULOS"<<endl;
    int menu=0;
    bool abrio = AbrirArchivo();
    if(abrio==true){
        do{
        system("cls");
        cout<<"MENU:"<<endl;
        cout<<"1. Listar todos los versiculos"<<endl;
        cout<<"2. Buscar un versiculo"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"seleccione una opcion..."<<endl;
        cin>>menu;
        cout<<endl;

        //Opciones del menu
        if(menu==1){
            string recorrer = versiculos.Recorrer();
            if(recorrer!=""){
              cout<<recorrer<<endl;
            }
        }

        if(menu==2){
            string paraje;
            string ingreso;
            cout<<"Ingrese el Libro: ";
            cin>>ingreso;
            paraje=ingreso;
            cout<<"Ingrese el Capitulo: ";
            cin>>ingreso;
            paraje = paraje + " " + ingreso;
            cout<<"Ingrese el Versiculo: ";
            cin>>ingreso;
            paraje=paraje+":"+ingreso;
            cout<<"____________________________________________________";
            cout<<endl;
            Nodo* aux = versiculos.BuscarEspecifico(paraje);

            if(aux!=nullptr){
                cout<<(aux->ObtenerPasaje())<<endl;
                cout<<(aux->ObtenerTexto());
            }else{
                cout<<"El paraje: " + paraje + " No existe, Ingrese uno valido."<<endl;
            }
        }
        system("pause");
        }while(menu!=3);
    }
    return 0;

}
