#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int nc = 60;
const int nl = 20;

struct Par{
    int l, c;
    Par(int l = 0, int c = 0){
        this->l = l;
        this->c = c;
    }
};

 vector<Par> getvizinhos(Par p){
    vector<Par> vetor;
    vetor.push_back(Par(p.l, p.c + 1));
    vetor.push_back(Par(p.l, p.c - 1));
    vetor.push_back(Par(p.l + 1, p.c));
    vetor.push_back(Par(p.l - 1, p.c));
    return vetor;
 }

void mostrar(vector<string> & mat){
    cout << string(50, '\n');
    for(string s : mat)
        cout << s << endl;
        getchar();
}

vector<Par> embaralhar(vector<Par> vet){
    int i;
    for(i=0; i < (int)vet.size(); i++){
        int aleat = rand() % vet.size();
        swap(vet[i], vet[aleat]);
//        int aux= vet[i];
//        vet[i]= vet[aleat];
//        vet[aleat]= aux;
    }
    return vet;
}

int queimar(vector<string> &mat, int l, int c, int especificador){
    int cont=0;
    if(l < 0 || l >= nl){
        return 0;
    }
    if(c < 0 || c >= nc){
        return 0;
    }
    if(mat[l][c] != '#'){
        return 0;
    }

    //MUDANÇAS FEITAS POR MIM
    if(especificador >  9){
        especificador= 0;
    }


    mat[l][c] = '0'+ especificador;
    cont++;
    mostrar(mat);


    for(Par p : embaralhar(getvizinhos(Par(l, c)))){
            cont +=  queimar(mat, p.l, p.c, especificador+1);
    }
    mostrar(mat);

    //RETORNO DA RECURÇÃO
    if(mat[l][c] != '#'){
        mat[l][c]= '*';
    }

    return cont;
}



int main()
{
    srand(time(NULL));
    //os containers tem uma construção padrao
    //container<tipo> nome(qtd, elemento_default)
    //cria um vetor de string
    //com nl elementos da string default
    //a string default sao 30 char ' '
    vector<string> mat(nl, string(nc, '#'));
    int narvores = nl * nc * 1.5;
    //insere varias arvores em lugares aleatorios
    //muitas serao superpostas
//    for(int i = 0; i < narvores; i++){ //PREENCHER COM ÁRVORES
//        mat[rand() % nl][rand() % nc] = '#';
//    }
    mostrar(mat);
    int total = queimar(mat, 0, 0, 0);
    cout << total << " arvores queimaram\n";


    return 0;
}
