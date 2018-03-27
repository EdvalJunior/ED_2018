#include <iostream>

using namespace std;

int resta_um(int* v, int jogadores){
	int mortes = 0, i = 0;

	for (i = 0; i < jogadores; i++){
		if(v[i] == 0){
			mortes++;
		}
	}

	if (mortes == jogadores-1){
		return 1;
	}

	return 0;
}

void mata(int* v, int jogadores, int escolhido){
	int alvo = escolhido + 1;

	while(v[alvo%jogadores] != 1){
		alvo++;
	}

	v[alvo%jogadores] = 0;

	return;
}

int pega_proximo(int* v, int jogadores, int escolhido){
	int i = escolhido+1;

	while(v[i%jogadores] != 1){
		i++;
	}

	return i;
}

void imprimir(int* v, int jogadores){
	int i = 0;
	
	for(i=0; i<jogadores; i++){
		cout<<v[i];
	}
	cout<<""<<endl;
	cout<< endl;
}

int main(){
	int jogadores,escolhido;
	cout<<("Entre com a quantidade de jogaderes:\n");
	cin>>jogadores;
	cout<<("Escolha a posição inicial:\n");
	cin>>escolhido;
	escolhido--;

	int v[jogadores],i;

	for (i = 0; i < jogadores; i++){
		v[i]=1;
	}

	while(!resta_um(v,jogadores)){
		imprimir(v,jogadores);
		mata(v,jogadores,escolhido);
		escolhido = pega_proximo(v,jogadores,escolhido);
	}
	
	imprimir(v,jogadores);
	
	for (i = 0; i < jogadores; i++){
		if(v[i]==1){
			cout<< "O vencedor esta na posicao:"<<i+1<<endl;
		}
	}

	return 0;
}
