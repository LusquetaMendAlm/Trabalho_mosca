#include <iostream>
#include <string>

using namespace std;

struct pokemon
{
	string nome;
	string tipo1;
	string tipo2;
	string ataque[2];
    int velocidade;
    bool life; // true = vivo, false = morto
};

void inicializacao(pokemon timeA[], pokemon timeB[])
{
    timeA[0].nome = "Charizard";
    timeA[0].tipo1 = "Fogo";
    timeA[0].tipo2 = "Voador";
    timeA[0].ataque[0] = "Fogo";
    timeA[0].ataque[1] = "Voador";
    timeA[0].velocidade = 100;
    timeA[0].life = true;

    timeA[1].nome = "Dugtrio";
    timeA[1].tipo1 = "Terra";
    timeA[1].tipo2 = "N/A";
    timeA[1].ataque[0] = "Terra";
    timeA[1].ataque[1] = "Pedra";
    timeA[1].velocidade = 120;
    timeA[1].life = true;

    timeA[2].nome = "Jolteon";
    timeA[2].tipo1 = "Eletrico";
    timeA[2].tipo2 = "N/A";
    timeA[2].ataque[0] = "Eletrico";
    timeA[2].ataque[1] = "Dark";
    timeA[2].velocidade = 130;
    timeA[2].life = true;

    timeB[0].nome = "Venusaur";
    timeB[0].tipo1 = "Planta";
    timeB[0].tipo2 = "Veneno";
    timeB[0].ataque[0] = "Planta";
    timeB[0].ataque[1] = "Veneno";
    timeB[0].velocidade = 80;
    timeB[0].life = true;

    timeB[1].nome = "Vaporeon";
    timeB[1].tipo1 = "Agua";
    timeB[1].tipo2 = "N/A";
    timeB[1].ataque[0] = "Agua";
    timeB[1].ataque[1] = "Gelo";
    timeB[1].velocidade = 65;
    timeB[1].life = true;

    timeB[2].nome = "Golem";
    timeB[2].tipo1 = "Pedra";
    timeB[2].tipo2 = "Terra";
    timeB[2].ataque[0] = "Pedra";
    timeB[2].ataque[1] = "Terra";
    timeB[2].velocidade = 45;
    timeB[2].life = true;
}

bool superEfetivo(string ataque, string tipoAdversario)  // Verifica se o ataque é super efetivo contra o tipo do adversário
{
    if (ataque == "Fogo" && tipoAdversario == "Planta") return true;
    if (ataque == "Voador" && tipoAdversario == "Terra") return true;
    if (ataque == "Terra" && tipoAdversario == "Fogo") return true;
    if (ataque == "Pedra" && tipoAdversario == "Voador") return true;
    if (ataque == "Planta" && tipoAdversario == "Terra") return true;
    if (ataque == "Agua" && tipoAdversario == "Fogo") return true;
    if (ataque == "Eletrico" && tipoAdversario == "Agua") return true;
    if (ataque == "Terra" && tipoAdversario == "Eletrico") return true;

    return false;
}

char ganhador (pokemon time1[], pokemon time2[]) // Verifica se algum time venceu
{
    if (time1[0].life == false && time1[1].life == false && time1[2].life == false) 
    {
        return '2'; // Jogador 2 vence
    } 
    else if (time2[0].life == false && time2[1].life == false && time2[2].life == false) 
    {
        return '1'; // Jogador 1 vence
    }
    return 0; // Nao ha vencedor ainda
}

void escolherPokemonVivo(pokemon time[], int &pokemonBatalha) // Permite ao jogador escolher um pokemon vivo para batalhar
{
    while (true) {
        cout << "Escolha um pokemon VIVO:" << endl;
        for (int i = 0; i < 3; i++) {
            if (time[i].life)
                cout << i << ". " << time[i].nome << endl;
        }
        cin >> pokemonBatalha;
        if (pokemonBatalha >= 0 && pokemonBatalha < 3 && time[pokemonBatalha].life)
            break;
        cout << "Opcao invalida ou pokemon morto. Tente novamente." << endl;
    }
}

void interacaoJogador1( pokemon time1[], pokemon time2[], int pokemonBatalha1, int pokemonBatalha2, int &novoPokemon1, int &novoPokemon2) // Interação do Jogador 1
{
    char vencedor = '0';

    int option;
    int attack;

    cout << "Escolha uma opcao:" << endl;
    cout << "1. Atacar                 2. Trocar POKEMON" << endl;

    cin >> option;

	switch(option)
    {
        case 1:
            cout << "1. " << time1[pokemonBatalha1].ataque[0] << "    2. " << time1[pokemonBatalha1].ataque[1] << "    3. Voltar" << endl;
            cin >> attack;
            if (attack < 1 || attack > 2) 
            {
                cout << "Opcao invalida, tente novamente." << endl;
            }
            cout << "Atacando com " << time1[pokemonBatalha1].ataque[attack-1] << "!" << endl;
                
            if (superEfetivo(time1[pokemonBatalha1].ataque[attack - 1], time2[pokemonBatalha2].tipo1) || 
                superEfetivo(time1[pokemonBatalha1].ataque[attack - 1], time2[pokemonBatalha2].tipo2)) 
            {
                cout << "Ataque super efetivo!" << endl;
                time1[pokemonBatalha1].life = false; // Simula que o pokemon adversario foi derrotado
                cout << time2[pokemonBatalha2].nome << " foi derrotado!" << endl;
                if (time2[pokemonBatalha2].life == false) 
                {
                    cout << "Pokemon do jogador 2 foi derrotado!" << endl;
                    vencedor = ganhador(time1, time2);
                    if (vencedor == '1') 
                    {
                        cout << "Jogador 1 venceu!" << endl;
                        break;
                    } 
                    else if (vencedor == '2') 
                    {
                        cout << "Jogador 2 venceu!" << endl;
                        break;
                    }
                    else 
                    {
                        cout << "Escolha outro pokemon para atacar." << endl;
                        escolherPokemonVivo(time2, pokemonBatalha2);
                        novoPokemon2 = pokemonBatalha2; // Atualiza o pokemon do jogador 2
                    }
                } 
                else 
                {
                    cout << "Escolha outro pokemon para atacar." << endl;
                    // Aqui poderia ter uma lógica para trocar o pokemon do jogador 2
                }
            } 
            else 
            {
                cout << "Ataque nao foi muito efetivo." << endl;
            }
        break;
        case 2:
            cout << "1. " << time1[0].nome << "    2. " << time1[1].nome << "    3. " << time1[2].nome << "    4. Voltar" << endl;
            cin >> pokemonBatalha1;
            if (pokemonBatalha1 < 0 || pokemonBatalha1 > 2) 
            {
                cout << "Opcao invalida, tente novamente." << endl;
            }
            else 
            {
                escolherPokemonVivo(time1, pokemonBatalha1);
                novoPokemon1 = pokemonBatalha1; // Atualiza o pokemon do jogador 1
            }
        break;
    }
}

void interacaoJogador2(pokemon time1[], pokemon time2[], int pokemonBatalha1, int pokemonBatalha2, int &novoPokemon1, int &novoPokemon2) // Interação do Jogador 2
{
    char vencedor = '0';

    int option;
    int attack;

    cout << "Escolha uma opcao:" << endl;
    cout << "1. Atacar                 2. Trocar POKEMON" << endl;

    cin >> option;

    switch(option)
    {
        case 1:
            cout << "1. " << time2[pokemonBatalha2].ataque[0] << "    2. " << time2[pokemonBatalha2].ataque[1] << "    3. Voltar" << endl;
            cin >> attack;
            if (attack < 1 || attack > 2) 
            {
                cout << "Opcao invalida, tente novamente." << endl;
            }
            cout << "Atacando com " << time2[pokemonBatalha2].ataque[attack - 1] << "!" << endl;
                
            if (superEfetivo(time2[pokemonBatalha2].ataque[attack - 1], time1[pokemonBatalha1].tipo1) || 
                superEfetivo(time2[pokemonBatalha2].ataque[attack - 1], time1[pokemonBatalha1].tipo2)) 
            {
                cout << "Ataque super efetivo!" << endl;
                time1[pokemonBatalha1].life = false; // Simula que o pokemon adversario foi derrotado
                cout << time1[pokemonBatalha1].nome << " foi derrotado!" << endl;
                vencedor = ganhador(time1, time2);
                if (vencedor == '1') 
                {
                    cout << "Jogador 1 venceu!" << endl;
                    break;
                } 
                else if (vencedor == '2') 
                {
                    cout << "Jogador 2 venceu!" << endl;
                    break;
                }
                else 
                {
                    cout << "Escolha outro pokemon para atacar." << endl;
                    escolherPokemonVivo(time1, pokemonBatalha1);
                    novoPokemon1 = pokemonBatalha1; // Atualiza o pokemon do jogador 1
                }
            } 
            else 
            {
                cout << "Ataque nao foi muito efetivo." << endl;
            }
        break;
        case 2:
            cout << "1. " << time2[0].nome << "    2. " << time2[1].nome << "    3. " << time2[2].nome << "    4. Voltar" << endl;
            cin >> pokemonBatalha2;
            if (pokemonBatalha2 < 0 || pokemonBatalha2 > 2) 
            {
                cout << "Opcao invalida, tente novamente." << endl;
            }
            else 
            {
                escolherPokemonVivo(time2, pokemonBatalha2);
                novoPokemon2 = pokemonBatalha2; // Atualiza o pokemon do jogador 2
            }
        break;
    }
}

int main()
{
	int vencedor = '0';

	pokemon time1[3];
	pokemon time2[3];
	
	inicializacao(time1, time2);
	
	int pokemonBatalha1;
    int pokemonBatalha2;
	
	cout << "Jogador 1,  Escolha o pokemon que voce deseja comecar: " << endl;
	cout << "0. " << time1[0].nome << endl;
	cout << "1. " << time1[1].nome << endl;
	cout << "2. " << time1[2].nome << endl;
	
	cin>>pokemonBatalha1;
	
	cout << "Jogador 2,  Escolha o pokemon que voce deseja comecar: " << endl;
	cout << "0. " << time2[0].nome << endl;
	cout << "1. " << time2[1].nome << endl;
	cout << "2. " << time2[2].nome << endl;
	
	cin>>pokemonBatalha2;

	while(vencedor=='0')
	{

        if(time1[pokemonBatalha1].velocidade >= time2[pokemonBatalha2].velocidade)
        {
            cout << "Jogador 1 comeca atacando!" << endl;

            interacaoJogador1(time1, time2, pokemonBatalha1, pokemonBatalha2, pokemonBatalha1, pokemonBatalha2);
            if (vencedor=='0') interacaoJogador2(time1, time2, pokemonBatalha1, pokemonBatalha2, pokemonBatalha1, pokemonBatalha2);
        }
        else
        {
            cout << "Jogador 2 comeca atacando!" << endl;

            interacaoJogador2(time1, time2, pokemonBatalha1, pokemonBatalha2, pokemonBatalha1, pokemonBatalha2);
            if (vencedor=='0') interacaoJogador1(time1, time2, pokemonBatalha1, pokemonBatalha2, pokemonBatalha1, pokemonBatalha2);
        }
        vencedor = ganhador(time1, time2);
	}
	
	return 0;
}