#include <iostream>
#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>
using namespace std;

//HASH LISTA COM OS MÉTODOS DE BUSCAR, INSERIR E REMOÇÃO IMPLEMENTADOE EM SALA

struct Elem {
    int key;

    Elem(int key = 0){
        this->key = key;
    }

    bool operator ==(Elem other){
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

#include <vector>
#include <list>
#include <algorithm>

struct HashLista{
    vector<list<Elem>> vet;

    HashLista(int size):
        vet(size){
    }

    bool insert(Elem elem) {
        int base = elem.key % vet.size();
        auto& lista = vet[base];
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it != lista.end())
            return false;
        lista.push_back(elem);
        return true;
    }

    bool busca(Elem elem) {
        int base = elem.key % vet.size();
        auto& lista = vet[base];
        auto it = std::find(lista.begin(), lista.end(), elem);
        return (it == lista.end());
    }

    bool remocao(Elem elem) {
        int base = elem.key % vet.size();
        auto& lista = vet[base];
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it == lista.end())
            return false;
        lista.erase(it);
        return true;
    }

};

//HASHLINEAR: IMPLEMENTAÇÃO COMEÇOU EM SALA E MÉTODOS DE BUSCAR, REMOVER E ADICIONAR

#include <vector>
#include <list>
#include <algorithm>
#include <pair>

enum Marcador{cheio, vazio,deletado};

struct Elem {
    int key;
    string value;
    Marcador marcador;


    Elem(int key = 0){
        this->key = key;
    }

    bool operator ==(Elem other){
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

struct HashLinear{
    pair<Elem, Marcador> * vet;
    int size ;
    int capacity;
    HashLista(int size){
        vet = new pair<Elem, Marcador>[capacity];
        this->capacity = capacity;
        this->size = 0;
        for(int i = 0; i < capacity; i++){
            vet[i].first = Elem();
            vet[i].second = vazio;
        }
    }

    //BUSCA ATRAVÉS DA IMPLEMENTAÇÃO DO ENCONTRAR/BUSCAR DA LISTA
    int busca(Elem elem){
            int endereço = elem.key % vet.size();
             auto& lista = vet->at(base);
            auto it = std::find(lista.begin(), lista.end(), elem);
            if(it == lista.end())
                return false;
            return it;
    }

    //elem é formado por um conjunto de key(originalmente da hashlista), valor e um marcador
   // (relatando sua situação atual)
    bool remover(Elem elem) {
           int endereço = elem.key % vet.size();
           auto& lista = vet->at(base);
           //find vem direto da implementação de lista
           auto it = std::find(lista.begin(), lista.end(), elem);
           if(it == lista.end()){
               return false;
           }
           lista.erase(it);
           return true;
    }


    //Faz a inserção de um elemento e marcador através da busca feita acima
    bool insert(Elem Nelem){
        //Nelem significa N de novo e elem de elemento
        int it;
        it = busca(Nelem.key);
        int pos = Nelem.key % size;
        if(vet[it] != nullptr)
                vet[it].marcador = deletado;

        while((vet[it].second != vazio) || (vet[it].second != deletado))
            pos = (pos + 1) % capacity;
        vet[it].first = Nelem;
        vet[it].second = cheio;
        size--;
    }
};
