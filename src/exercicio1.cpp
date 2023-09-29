#include<iostream>
#include<string>
#include<ctime>
#include<vector>

using namespace std;

int assento_max = 40;

struct assento {
    int numero;
    int idade;
    string cpf;
    string nome;
};

struct viagem {
    vector<assento> assentos;
};

struct Dia {
    viagem viagens[10];
    string data;
    int dia, mes, ano;
};

void comprar_passagem(vector<Dia>& dias);
void total_viagem(vector<Dia>& dias);
void total_mes(vector<Dia>& dias);
void pegar_nome(vector<Dia>& dias);
void horario_mais_rentavel(vector<Dia>& dias);
void idade_media(vector<Dia>& dias);
string horario(int _index);
bool verificar_data(string data);

int main() 
{
    vector<Dia> Dias;
    Dias.resize(0);
    for(int acao = 1; acao != 0;)
    {
        cout << 
        "1 - Comprar passagem" << endl <<
        "2 - Ver o total arrecadado em uma viagem" << endl <<
        "3 - Ver o total arrecadado em um mes" << endl <<
        "4 - Ver nome de um passageiro em uma poltrona" << endl <<
        "5 - Qual o horario mais rentavel" << endl <<
        "6 - Qual a media de idade dos passageiros" << endl <<
        "0 - Sair" << endl <<
        "Escolha uma opcao:";
        std::cin >> acao;

/*
        if(acao == 1)
            {comprar_passagem(Dias);}
        else if(acao == 2)
            {total_viagem(Dias);}
        else if(acao == 3)
                    {total_mes(Dias);}
        else if(acao == 4)
                    {pegar_nome(Dias);}
        else if(acao == 5)
                    {horario_mais_rentavel(Dias);}
        else if(acao == 6)
                    {idade_media(Dias);}                    
//*/
    }

    cout << "Operacao finalizada" << endl;
    return 0;
}

void comprar_passagem(vector<Dia>& dias)
{
    string data;
    int horario;
    char ida_volta;
    int lugar;

    cout << "Insira local de partida (r = RJ / s = SP)";
    cin >> ida_volta;

    cout << "Digite a data da viagem (dd/mm/aaaa): ";
    cin >> data;
    
    while(!verificar_data(data))
    {
        cout << "Data invalida, insira outra (dd/mm/aaaa): ";
        cin >> data;
    }

    cout << "----- Horarios -----" << endl <<
    "1 - 07:30" << endl << 
    "2 - 10:30" << endl << 
    "3 - 13:30" << endl << 
    "4 - 16:30" << endl << 
    "5 - 19:30" << endl <<
    "Insira o numero do horario de partida (1-5): ";
    cin >> horario;

    while(horario < 1 || horario > 5)
    {
        cout << "Horario invalido, insira apenas numeros de 1 a 5: ";
        cin >> horario;
    }


}

void horario_mais_rentavel(vector<Dia>& dias)
{
    int index = 0;
    int qtde[5] = {0};

    for(int i = 0; i < dias.size(); i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int val = dias[i].viagens[j].assentos.size();
            qtde[(i+1)/2] += val;
        }
    }

    for(int i = 0; i < 5-1; i++)
    {
        if(qtde[i] < qtde[i+1])
        {index = i+1;}
    }

    cout << "O horario mais rentavel e ";
    if(index == 0) {cout << "Janeiro";}
    else if(index == 1) {cout << "Fevereiro";}
    else if(index == 2) {cout << "Marco";}
    else if(index == 3) {cout << "Abril";}
    else if(index == 4) {cout << "Maio";}
    else if(index == 5) {cout << "Junho";}
    else if(index == 6) {cout << "Julho";}
    else if(index == 7) {cout << "Agosto";}
    else if(index == 8) {cout << "Setembro";}
    else if(index == 9) {cout << "Outubro";}
    else if(index == 10) {cout << "Novembro";}
    else {cout << "Dezembro";}
    
    cout << ", com " << qtde[index] << " passagens vendidas, um total de R$" <<
    qtde[index] * 80 << endl << endl;
}

string horario(int index)
{
    index++;
    if(index/2 == 0) {return "06:30";}
    if(index/2 == 1) {return "09:30";}
    if(index/2 == 2) {return "12:30";}
    if(index/2 == 3) {return "15:30";}
    if(index/2 == 4) {return "18:30";}

    return "06:30";
}

bool verificar_data(string data)
{
    std::string d, m, a, str, strm;
    int id, im, ia;
    bool valido = 1;

    str = data;

    d = str.substr(0, 2);
    m = str.substr(3, 2);
    a = str.substr(6, 4);

    id = stoi(d);
    im = stoi(m);
    ia = stoi(a);

    if(im < 1 || im > 12 || id < 1 || id > 31)
        valido = 0;

    if(valido && (im == 4 || im == 6 || im == 9 || im == 11) && id > 30)
        valido = 0;

    if(valido && im == 2)
    {
        if (ia % 4 == 0 && id > 29)
            valido = 0;
        else if (ia % 4 !=0 && id > 28)
            valido = 0;
    }

    return valido;
}

