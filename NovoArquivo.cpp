#include <iostream>
#include <string>

using namespace std;

struct pokemon
{
	string nome;
	string tipo1;
	string tipo2;
	string ataque1;
	string ataque2;
};

void inicializacao(pokemon timeA[], pokemon timeB[])
{
	timeA[0].nome = "Charizard";
    timeA[0].tipo1 = "Fogo";
    timeA[0].tipo2 = "Voador";
    timeA[0].ataque1 = "Fogo";
    timeA[0].ataque2 = "Voador";

    timeA[1].nome = "Dugtrio";
    timeA[1].tipo1 = "Terra";
    timeA[1].tipo2 = "N/A";
    timeA[1].ataque1 = "Terra";
    timeA[1].ataque2 = "Pedra";

    timeA[2].nome = "Jolteon";
    timeA[2].tipo1 = "Eletrico";
    timeA[2].tipo2 = "N/A";
    timeA[2].ataque1 = "Eletrico";
    timeA[2].ataque2 = "Dark";

    timeB[0].nome = "Venosaur";
    timeB[0].tipo1 = "Planta";
    timeB[0].tipo2 = "Veneno";
    timeB[0].ataque1 = "Planta";
    timeB[0].ataque2 = "Veneno";

    timeB[1].nome = "Vaporeon";
    timeB[1].tipo1 = "Agua";
    timeB[1].tipo2 = "N/A";
    timeB[1].ataque1 = "Agua";
    timeB[1].ataque2 = "Gelo";

    timeB[2].nome = "Golem";
    timeB[2].tipo1 = "Pedra";
    timeB[2].tipo2 = "Terra";
    timeB[2].ataque1 = "Pedra";
    timeB[2].ataque2 = "Terra";
}

int main(int argc, char** argv)
{
	bool vencedor1 = false;
	bool vencedor2 = false;

	pokemon time1[3];
	pokemon time2[3];
	
	inicializacao(time1, time2);
	
	int pokemonBatalha;
	
	cout << "Jogador 1,  Escolha o pokemon que voce deseja comecar: " << endl;
	cout << "0. " << time1[0].nome << endl;
	cout << "1. " << time1[1].nome << endl;
	cout << "2. " << time1[2].nome << endl;
	
	cin>>pokemonBatalha1;
	
	cout << "Jogador 2,  Escolha o pokemon que voce deseja comecar: " << endl;
	cout << "0. " << time2[0].nome << endl;
	cout << "1. " << time2[1].nome << endl;
	cout << "2. " << time2[2].nome << endl;
	
	cin>>pokemonBatalha1;

	while(vencedor1==false || vencedor2==false)
	{
		
	}
	
	return 0;
}