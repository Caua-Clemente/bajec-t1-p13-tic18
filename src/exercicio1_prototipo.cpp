#include<iostream>
#include<string>
#include<ctime>

using namespace std;

struct assento {
    int numero;
    int idade = -1;
    string cpf;
    string nome;
};

struct viagem {
    assento assentos[40];
    int qtde = 0;
    string hora;
};

struct dia {
    viagem viagens[10];
};

struct mes {
    dia dias[31];
};

struct ano {
    mes meses[12];
};

void comprar_passagem(ano _ano);
void total_viagem(ano _ano);
void total_mes(ano _ano);
void pegar_nome(ano _ano);
void horario_mais_rentavel(ano _ano);
void idade_media(ano _ano);
string horario(int _index);
bool verificar_data(string data);

int main() 
{
    for(int acao = 1; acao != 0;)
    {
        ano Ano;
        cout << "Escolha uma opcao:" << endl <<
        "1 - Comprar passagem" << endl <<
        "2 - Ver o total arrecadado em uma viagem" << endl <<
        "3 - Ver o total arrecadado em um mes" << endl <<
        "4 - Ver nome de um passageiro em uma poltrona" << endl <<
        "5 - Qual o horario mais rentavel" << endl <<
        "6 - Qual a media de idade dos passageiros" << endl <<
        "0 - Sair" << endl;
        cin >> acao;

        if(acao == 1)
            {comprar_passagem(Ano);}
        else if(acao == 2)
            {total_viagem(Ano);}
        else if(acao == 3)
                    {total_mes(Ano);}
        else if(acao == 4)
                    {pegar_nome(Ano);}
        else if(acao == 5)
                    {horario_mais_rentavel(Ano);}
        else if(acao == 6)
                    {idade_media(Ano);}                    
    }

    cout << "Operacao finalizada" << endl;
    return 0;
}


//void comprar_passagem();
//void total_viagem(viagem _viagem);
//void total_mes(mes _mes[]);

void pegar_nome(ano _ano)
{
    string data;
    int hora;
    int numero_poltrona;
    string resposta;
    bool origem;
    cout << "Insira a data da viagem (dd/mm/aaaa): ";
    cin >> data;

    while(!verificar_data(data))
    {
        cout << "Data invalida, insira novamente (dd/mm/aaaa): ";
        cin >> data;
    }

    cout << "Insira o horario do onibus (1-5): ";
    cin >> hora;

    cout << "Qual a cidade de partida do onibus (r = Rio de Janeiro / s = Sao Paulo): ";
    cin >> resposta;

    if(resposta == "r")
        {origem = 0;}
    else
        {origem = 1;}

    cout << "Insira o numero da poltrona (1-40): ";
    cin >> numero_poltrona;

    
    int im, id, index;
    id = stoi(data.substr(0,2));
    im = stoi(data.substr(3,2));

    index = (hora-1)*2 + origem;
    string nome_passageiro = _ano.meses[im].dias[id].viagens[index].assentos[numero_poltrona].nome;
    if(nome_passageiro == "")
    {cout << "Nao ha nenhum passageiro nesse assento";}
    else
    {cout << "O nome do passageiro e: " << nome_passageiro << endl;}
}

void horario_mais_rentavel(ano _ano)
{
    int index;
    int maior = 0;
    int auxnum;
    for(int m = 0; m < 12; m++)
    {
        auxnum = 0;
        for(int d = 0; d < 31; d++)
        {
            for(int v = 0; v < 10; v++)
            {
                auxnum += _ano.meses[m].dias[d].viagens[v].qtde;
            }
        }
        if(maior < auxnum)
        {
            maior = auxnum;
            index = m;
        }
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
}

void idade_media(ano _ano)
{
    int total = 0;
    int qtde = 0;
    for(int m = 0; m < 12; m++)
    {
        for(int d = 0; d < 31; d++)
        {
            for(int v = 0; v < 10; v++)
            {
                for(int as = 0; as < 40; as++)
                {
                    if(_ano.meses[m].dias[d].viagens[v].assentos[as].idade >= 0)
                    {
                        total += _ano.meses[m].dias[d].viagens[v].assentos[as].idade;
                        qtde++;
                    }
                }
            }
        }
    }

    cout << "A idade media dos passageiros e " << (total/qtde) << endl;
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