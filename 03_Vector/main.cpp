#include <iostream>
#include <vector>

using namespace std;

struct Vetor{
    int * data;
    int capacidade;
    int _size;

    Vetor(int capacidade){
        this->capacidade= capacidade;
        this->_size=0;
        this->data = new int[capacidade];
    }

    void push_back(int value){
        if(this->_size == this->capacidade)
            return;
        //this->reserve(2 * capacidade);
        this->data[this->_size] = value;
        this->_size += 1;
    }

    void pop_back(){
        if(this->_size == 0)
            return;
        this->data[_size] = 0;
        this->_size -= 1;
    }

    int at(int indice){
        return this->data[indice];
    }

    int& front(){
        return this-> data[0];
    }

    int& back(){
        return this-> data[_size - 1];
    }

    int * begin(){
        return &this->data[0];
    }

    int * end(){
        return &this-> data[_size-1];
    }

    int size(){
        return this->_size;
    }

    int capacity(){
        return this->capacidade;
    }

    void reserve(int capNova){

        int * vetAux= new int[this->capacidade];//CRIAÇÃO DE VETOR AUXILIAR

        int capaaux= this->capacidade;

        if(size() >= this->capacidade){
            for(int i=0; i<this->capacidade;i++){
                vetAux[i]= this->data[i]; //COPIANDO ARQUIVOS DO VETOR PRINCIPAL PARA O AUXILIAR GARANTINDO QUE OS VALORES ANTIGOS SEJAM SALVOS
            }
            this->capacidade= capNova;
             this->data= new int[this->capacidade];
            for(int i=0; i<capaaux;i++){
                 this->data[i]= vetAux[i];//PASSANDO OS VALORES ANTIGOS NOVAMENTE PARA O VETOR COM O AUXILIO DO vetAux,
                                        //MAS O VETOR COM UM TAMANHO MAIOR DE BLOCO DE MEMÓRIA RESERVADO PELO USUÁRIO
             }
        }
    }
};


int main(){
    Vetor v(5);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.reserve(8);
    v.push_back(5);
    v.push_back(10);



    std:: cout << v.capacity() << endl;
    std:: cout << v.size() << endl;
    std:: cout << v.front() << endl;
    std:: cout << v.back() << endl;
    std:: cout << v.capacity() << endl;




    return 0;
}

