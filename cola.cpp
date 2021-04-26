#include <iostream>
using namespace std;

struct nodo{
    string nombren;
    struct nodo *sgte;
};
struct cola{
    nodo *delante;
    nodo *atras;
};
void encolar(struct cola &q,string nombre){
    struct nodo *aux = new(struct nodo);
    aux->nombren = nombre;
    aux->sgte = NULL;
    if(q.delante == NULL){
        q.delante = aux;
    }else{
        (q.atras)->sgte = aux;
    }
    q.atras = aux;
}
string desencolar(struct cola &q){
    string nombre;
    struct nodo *aux;

    aux = q.delante;
    nombre = aux->nombren;
    q.delante = (q.delante)->sgte;
    delete(aux);
    return nombre;
}
void mostrarCola(struct cola q){
    struct nodo *aux;
    aux = q.delante;
    while(aux!=NULL){
        cout<<" "<<aux->nombren;
        aux = aux->sgte;
    }
}
void vaciarCola(struct cola &q){
    struct nodo *aux;
    while(q.delante!=NULL){
        aux = q.delante;
        q.delante = aux->sgte;
        delete(aux);
    }
    q.delante = NULL;
    q.atras = NULL;
}
void menu(){
    cout<<"IMPLEMENTACION DE COLA\n";
    cout<<"1. ENCOLAR\n";
    cout<<"2. DESENCOLAR\n";
    cout<<"3. MOSTRAR COLA\n";
    cout<<"4. VACIAR COLA\n";
    cout<<"5. SALIR\n";
    cout<<"ELIJA\n";
}
int main(){
    struct cola q;
    q.delante = NULL;
    q.atras = NULL;

    string nombre;
    int op;
    string x;

    do{
        menu();cin>>op;
        switch(op){
            case 1: cout<<"Dato a Encolar:\n";
                cin>>nombre;
                encolar(q,nombre);
                cout<<"\nDato: "<<nombre<<" encolado\n";
                break;
            case 2: x = desencolar(q);
                cout<<"\nDato: "<<x<<" Desencolado\n";
                break;
            case 3: cout<<"\nMostrando la Cola\n";
                if(q.delante!=NULL){
                 mostrarCola(q);
                }else{
                    cout<<"\nCola Vacia!\n";
                }
                break;
            case 4: vaciarCola(q);
                cout<<"\nVaciado!\n";
                break;
        }
        cout<<endl;
    }while(op!=5);
    return 0;
}