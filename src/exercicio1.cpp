#include<iostream>
#include<string>
#include<ctime>
#include<vector>

using namespace std;

int assento_max = 40;
int valor_passagem = 80;

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
void total_viagem(vector<Dia> dias);
void total_mes(vector<Dia> dias);
void pegar_nome(vector<Dia> dias);
void horario_mais_rentavel(vector<Dia> dias);
void idade_media(vector<Dia> dias);
string horario(int _index);
bool verificar_data(string data);

int main() 
{
    vector<Dia> Dias;
    Dias.resize(0);
    for(int acao = 1; acao != 0;)
    {
        cout << endl << 
        "1 - Comprar passagem" << endl <<
        "2 - Ver o total arrecadado em uma viagem" << endl <<
        "3 - Ver o total arrecadado em um mes" << endl <<
        "4 - Ver nome de um passageiro em uma poltrona" << endl <<
        "5 - Qual o horario mais rentavel" << endl <<
        "6 - Qual a media de idade dos passageiros" << endl <<
        "0 - Sair" << endl <<
        "Escolha uma opcao: ";
        std::cin >> acao;

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
    int index = -1;

    cout << "Insira local de partida (r = RJ / s = SP): ";
    cin >> ida_volta;
    int int_ida_volta = (ida_volta == 'r' ? 0 : 1);

    cout << "Digite a data da viagem (dd/mm/aaaa): ";
    cin >> data;

    while(!verificar_data(data))
    {
        cout << "Data invalida, insira outra (dd/mm/aaaa): ";
        cin >> data;
    }

    for(int i = 0; i < dias.size(); i++)
    {
        if(data == dias[i].data)
        {
            index = i;
            exit;
        }
    }

    if(index == -1)
    {
        Dia diaAux;
        diaAux.data = data;
        diaAux.dia = stoi(data.substr(0,2));
        diaAux.mes = stoi(data.substr(3,2));
        diaAux.ano = stoi(data.substr(6,4));
        dias.push_back(diaAux);
        index = dias.size() - 1;
    }

    cout << "----- Horarios -----" << endl <<
    "1 - 07:30" << endl << 
    "2 - 10:30" << endl << 
    "3 - 13:30" << endl << 
    "4 - 16:30" << endl << 
    "5 - 19:30" << endl <<
    "Insira o numero do horario de partida (1-5): ";
    cin >> horario;

    for(bool check = 0; check == 0;)
    {
        check = 1;
        if (horario < 1 || horario > 5)
        {
            cout << "Horario invalido, insira apenas numeros de 1 a 5: ";
            cin >> horario;
            check = 0;
        }

        if(dias[index].viagens[horario+int_ida_volta].assentos.size() == 40)
        {
            cout << "Onibus cheio, insira um outro horario: ";
            cin >> horario;
            check = 0;
        }
    }

    horario--;
    vector<assento> aux_assentos = dias[index].viagens[(horario*2)+int_ida_volta].assentos;

    cout << "----- Poltronas disponiveis -----" << endl;

    int arr_aux[40];
    for(int i = 0; i < 40; i++)
    {
        arr_aux[i] = i;
    }

    for(int i = 0; i < aux_assentos.size(); i++)
    {
        arr_aux[aux_assentos[i].numero-1] = -1;
    }

    for(int i = 0; i < 40; i++)
    {
        if(arr_aux[i] > -1)
        {
            cout << arr_aux[i] + 1 << endl;
        }
    }

    cout << "Insira o numero da poltrona desejada: ";
    cin >> lugar;

    for(bool check = 0; check == 0;)
    {
        check = 1;
        if (lugar < 1 || lugar > 40)
        {
            cout << "Lugar invalido, insira apenas numeros de 1 a 40: ";
            cin >> lugar;
            check = 0;
        }

        if(arr_aux[lugar-1] == -1)
        {
            cout << "Lugar ocupado, insira um outro lugar: ";
            cin >> lugar;
            check = 0;
        }
    }
    
    assento assento_final;
    cout << "Digite o nome do passageiro: ";
    getline(cin >> ws, assento_final.nome);

    cout << "Digite o cpf do passageiro: ";
    cin >> assento_final.cpf;

    cout << "Digite a idade do passageiro: ";
    cin >> assento_final.idade;

    assento_final.numero = lugar;

    dias[index].viagens[(horario*2)+int_ida_volta].assentos.push_back(assento_final);
    cout << "Compra realizada com sucesso" << endl;
}

void total_viagem(vector<Dia> dias)
{
    string data;
    int horario;
    char ida_volta;
    int index = -1;

    cout << "Insira local de partida (r = RJ / s = SP): ";
    cin >> ida_volta;
    int int_ida_volta = (ida_volta == 'r' ? 0 : 1);

    cout << "Digite a data da viagem (dd/mm/aaaa): ";
    cin >> data;

    while(!verificar_data(data))
    {
        cout << "Data invalida, insira outra (dd/mm/aaaa): ";
        cin >> data;
    }

    for(int i = 0; i < dias.size(); i++)
    {
        if(data == dias[i].data)
        {
            index = i;
            exit;
        }
    }

    if(index == -1)
    {
        cout << "Nao ha nenhuma viagem registrada nessa data" << endl;
        return;
    }

    cout << "----- Horarios -----" << endl <<
    "1 - 07:30" << endl << 
    "2 - 10:30" << endl << 
    "3 - 13:30" << endl << 
    "4 - 16:30" << endl << 
    "5 - 19:30" << endl <<
    "Insira o numero do horario de partida (1-5): ";
    cin >> horario;

    for(bool check = 0; check == 0;)
    {
        check = 1;
        if (horario < 1 || horario > 5)
        {
            cout << "Horario invalido, insira apenas numeros de 1 a 5: ";
            cin >> horario;
            check = 0;
        }

        if(dias[index].viagens[horario+int_ida_volta].assentos.size() == 0)
        {
            cout << "Nao ha nenhuma viagem registrada nesse horario, insira outro: " << endl;
            cin >> horario;
            check = 0;
        }
    }

    int qtde = dias[index].viagens[horario+int_ida_volta].assentos.size();
    
    cout << "O valor arrecadado na viagem foi de R$" << qtde * valor_passagem << endl;
}

void total_mes(vector<Dia> dias)
{
    int num_mes, qtde = 0;
    cout << "Digite o numero do mes: ";
    cin >> num_mes;

    while(num_mes < 1 || num_mes > 12)
    {
        cout << "Numero de mes invalido, insira apenas de 1 a 12: ";
        cin >> num_mes;
    }

    for(int i = 0; i < dias.size(); i++)
    {
        if(dias[i].mes == num_mes)
        {
            for(int j = 0; j < 10; j++)
            {
                qtde += dias[i].viagens[j].assentos.size();
            }
        }
    }

    cout << "O valor arrecadado no mes " << num_mes << " foi de R$" << qtde * valor_passagem << endl;
}

void pegar_nome(vector<Dia> dias)
{
    string data;
    int horario;
    char ida_volta;
    int index = -1;
    int num_poltrona;

    cout << "Insira local de partida (r = RJ / s = SP): ";
    cin >> ida_volta;
    int int_ida_volta = (ida_volta == 'r' ? 0 : 1);

    cout << "Digite a data da viagem (dd/mm/aaaa): ";
    cin >> data;

    while(!verificar_data(data))
    {
        cout << "Data invalida, insira outra (dd/mm/aaaa): ";
        cin >> data;
    }

    for(int i = 0; i < dias.size(); i++)
    {
        if(data == dias[i].data)
        {
            index = i;
            exit;
        }
    }

    if(index == -1)
    {
        cout << "Nao ha nenhuma viagem registrada nessa data" << endl;
        return;
    }

    cout << "----- Horarios -----" << endl <<
    "1 - 07:30" << endl << 
    "2 - 10:30" << endl << 
    "3 - 13:30" << endl << 
    "4 - 16:30" << endl << 
    "5 - 19:30" << endl <<
    "Insira o numero do horario de partida (1-5): ";
    cin >> horario;

    for(bool check = 0; check == 0;)
    {
        check = 1;
        if (horario < 1 || horario > 5)
        {
            cout << "Horario invalido, insira apenas numeros de 1 a 5: ";
            cin >> horario;
            check = 0;
        }

        if(dias[index].viagens[horario+int_ida_volta].assentos.size() == 0)
        {
            cout << "Nao ha nenhuma viagem registrada nesse horario, insira outro: " << endl;
            cin >> horario;
            check = 0;
        }
    }

    vector<assento> assento_aux = dias[index].viagens[horario+int_ida_volta].assentos;

    for(bool check = 0; check == 0;)
    {
        cout << "Digite o numero da poltrona: ";
        cin >> num_poltrona;

        for(int i = 0; i < assento_aux.size(); i++)
        {
            if(assento_aux[i].numero == num_poltrona)
            {
                check = 1;
                cout << "O nome do passageiro da poltrona " << num_poltrona <<
                " e " << assento_aux[i].nome << endl;
                i = assento_aux.size();
            }
        }

        if(!check)
        {
            cout << "Nenhum passageiro nessa poltrona, deseja inserir outro numero? (sim = 1 / nao = 0): ";
            cin >> check;
            check = !check;
        }
    }
    
}

void horario_mais_rentavel(vector<Dia> dias)
{
    int index = 0;
    int qtde[5] = {0};

    for(int i = 0; i < dias.size(); i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int val = dias[i].viagens[j].assentos.size();
            qtde[(j+1)/2] += val;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if(qtde[i] < qtde[i+1])
        {index = i+1;}
    }

    cout << "O horario mais rentavel e " << horario(index);
    
    cout << ", com " << qtde[index] << " passagens vendidas, um total de R$" <<
    qtde[index] * valor_passagem << endl << endl;
}

void idade_media(vector<Dia> dias)
{
    int index = 0;
    int qtde = 0;
    int total = 0; 

    for(int i = 0; i < dias.size(); i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < dias[i].viagens[j].assentos.size(); k++)
            {
                qtde++;
                total += dias[i].viagens[j].assentos[k].idade;
            }
        }
    }

    int media = total / qtde;
    cout << "A media de idade dos passageiros e de " << media << " anos" << endl;
}

string horario(int index)
{
    if(index == 1) {return "07:30";}
    if(index == 2) {return "10:30";}
    if(index == 3) {return "13:30";}
    if(index == 4) {return "16:30";}
    if(index == 5) {return "19:30";}

    return "07:30";
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
