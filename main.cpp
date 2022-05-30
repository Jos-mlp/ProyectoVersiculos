#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

string texto;
string nombre;

void ComprobarPalabra(string p){
    cout<<"Palabra: "<<p<<endl;
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

void AbrirArchivo(){
    cout<<"Escriba el nombre del archivo a abrir"<<endl;
    cin>>nombre;
    string filename("versiculos\\" + nombre);
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "El archivo no se encontro: "
             << filename << "'" << endl;
        cout << EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }


    for (const auto &i : lines){
        cout << i << endl;
        string aux=i;
        SepararTexto(i);
    }


    input_file.close();

}

int main()
{
    AbrirArchivo();
}
