#include<iostream>
#include<string>
#include<ctime>

using namespace std;

struct empregado {
    string nome, sobrenome, RG;
    int anoNasci, anoAdm;
    float salario;
};

string randNome(int num)
{
    if(num == 0)
        return "Joao";
    else if(num == 1)
        return "Joana";
    else if(num == 2)
        return "Mario";
    else if(num == 3)
        return "Maria";
    else if(num == 4)
        return "Roberto";
    else if(num == 5)
        return "Roberta";
    else if(num == 6)
        return "Julio";
    else if(num == 7)
        return "Julia";
    else if(num == 8)
        return "Paulo";
    else if(num == 9)
        return "Paula";
}

string randSobrenome(int num)
{
    if(num == 0)
        return "Silva";
    else if(num == 1)
        return "Santos";
    else if(num == 2)
        return "Clemente";
    else if(num == 3)
        return "Seara";
    else if(num == 4)
        return "Borges";
    else if(num == 5)
        return "Cruz";
    else if(num == 6)
        return "Lima";
    else if(num == 7)
        return "Bonfim";
    else if(num == 8)
        return "Teles";
    else if(num == 9)
        return "Santiago";
}

string randRG()
{
    string rg = "";
    char ch;
    for(int i = 0; i < 10; i++)
    {
        ch = rand()%10 + 48; 
        rg += ch;
    }

    return rg;
}

void Reajusta_dez_porcento(empregado* lista, int qtde)
{
    for(int i = 0; i < qtde; i++)
    {
        lista[i].salario *= 1.1;
    }
}

int main()
{
    srand(time(0));
    

    empregado lista[50];
    int qtde = 0;

    std::cout << "Quantidade de funcionarios: ";
    std::cin >> qtde;

    for(int i = 0; i < qtde; i++)
    {
        lista[i].anoNasci = (rand()%21) + 1980;
        lista[i].anoAdm = (rand()%11) + 2013;
        lista[i].nome = randNome(rand()%10);
        lista[i].sobrenome = randSobrenome(rand()%10);
        lista[i].salario = (rand()%5001) + (float((rand()%100)) / 100); 
        lista[i].RG = randRG();
    }

    for(int i = 0; i < qtde; i++)
    {
        std::cout << i+1 << std::endl;
        std::cout << "Nome: " << lista[i].nome << " " << lista[i].sobrenome << endl;
        std::cout << "Ano de nascimento: " << lista[i].anoNasci << endl;
        std::cout << "Ano de adimssão: " << lista[i].anoAdm << endl;
        std::cout << "RG: " << lista[i].RG << endl;
        std::cout << "Salario: RS" << lista[i].salario << endl;
        std::cout << " --------------------- " << endl << endl;
    }

    Reajusta_dez_porcento(lista, qtde);

    for(int i = 0; i < qtde; i++)
    {
        std::cout << i+1 << std::endl;
        std::cout << "Nome: " << lista[i].nome << " " << lista[i].sobrenome << endl;
        std::cout << "Salario: RS" << lista[i].salario << endl;
        std::cout << " --------------------- " << endl << endl;
    }

}