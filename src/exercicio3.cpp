#include<iostream>
#include<string>
#include<ctime>

using namespace std;

struct produto {
    string nome, codigo;
    float preco;
};

string randCodigo()
{
    string codigo;
    for(int i = 0; i < 13; i++)
        codigo += (int(rand()%10) + 48);

    return codigo;
}

void inserir_produto(produto *arr, int *qtde)
{
    if(*qtde >= 300)
    {
        std::cout << "Voce nao pode mais inserir nenhum produto, pois ja atingiu a capacidade maxima (300)." << std::endl;
        return ;
    }

    produto novo;
    novo.codigo = randCodigo();

    for(int i = 0; i < *qtde; i++)
    {
        if(novo.codigo == arr[i].codigo)
        {
            i = -1;
            novo.codigo = randCodigo();
        }
    } 

    std::cout << "Nome: ";
    std::getline(cin >> ws, novo.nome);

    for(int i = 0; i < *qtde; i++)
    {
        if(novo.nome == arr[i].nome)
        {
            i = -1;
            std::cout << "Esse nome ja existe, por favor insira outro: ";
            std::getline(cin >> ws, novo.nome);
        }

        if(novo.nome.length() > 20)
        {
            i = -1;
            std::cout << "Esse nome e muito grande, insira um menor (20 char max): ";
            std::getline(cin >> ws, novo.nome);
        }
    } 
    //preciso ver a questão das casas decimais aqui
    std::cout << "Preco: ";
    std::cin >> novo.preco;

    arr[*qtde] = novo;
    *qtde += 1;
    std::cout << std::endl;
}

void excluir_produto(produto *arr, int *qtde)
{
    bool check = 1;
    int index;
    string cod;

    std::cout << "Digite o codigo do produto: ";
    std::cin >> cod;

    for(int i = 0; (i < *qtde) && check; i++)
    {
        if(arr[i].codigo == cod)
        {
            index = i;       
            check = 0;
        }
    } 
    
    if(!check)
    {
        *qtde -= 1;
        for(int i = index; i < *qtde; i++)
            arr[i] = arr[i+1];
        
        std::cout << "Produto excluido com sucesso" << std::endl;
    }
    else
    {
        bool tryAgain;
        std::cout << "Produto nao encontrado, deseja tentar denovo? (sim = 1 / nao = 0): "; 
        std::cin >> tryAgain;

        if(tryAgain)
            excluir_produto(arr, qtde);
    }

    std::cout << std::endl;
}

void listarTodos(produto *arr, int qtde)
{
    for(int i = 0; i < qtde; i++)
    {
        std::cout << i+1 << std::endl;
        std::cout << "Codigo: " << arr[i].codigo << endl;
        std::cout << "Nome: " << arr[i].nome << endl;
        std::cout << "Preco: R$";
        printf("%.2f", arr[i].preco);
        std::cout << endl << "---------------------" << endl;
    }

    std::cout << std::endl;
}

void consultar_preco(produto *arr, int qtde)
{
    bool check = 1;
    int index;
    string cod;

    std::cout << "Digite o codigo do produto: ";
    std::cin >> cod;

    for(int i = 0; (i < qtde) && check; i++)
    {
        if(arr[i].codigo == cod)
        {
            index = i;       
            check = 0;
        }
    } 
    
    if(!check)
    {
        std::cout << "Nome: " << arr[index].nome << endl;
        std::cout << "Preco: R$";
        printf("%.2f", arr[index].preco);
        std::cout << endl << "---------------------" << endl;
    }
    else
    {
        bool tryAgain;
        std::cout << "Produto nao encontrado, deseja tentar denovo? (sim = 1 / nao = 0): "; 
        std::cin >> tryAgain;

        if(tryAgain)
            consultar_preco(arr, qtde);
    }

    std::cout << std::endl;
}

int main()
{
    srand(time(0));
    
    produto lista[300] = {};
    int qtde = 0;
    //int qtde = 299;

    std::cout << "Insira um produto: " << std::endl;
    inserir_produto(lista, &qtde);

    for(bool check = 1; check && qtde < 300;)
    {
        std::cout << "Deseja inserir mais algum produto? (sim = 1 / nao = 0): ";
        std::cin >> check;

        if(check)
            inserir_produto(lista, &qtde);
    }

    for(int acao = -1; acao != 0;)
    {
        std::cout << "O que deseja fazer?" << endl <<
        "(1) Inserir um novo produto" << endl <<
        "(2) Excluir um produto" << endl <<
        "(3) Listar todos os produtos" << endl <<
        "(4) Consultar valor de um produto" << endl <<
        "(0) Encerrar" << endl;
        std::cin >> acao;
        std::cout << std::endl;

        if(acao == 1)
            inserir_produto(lista, &qtde);
        if(acao == 2)
            excluir_produto(lista, &qtde);
        if(acao == 3)
            listarTodos(lista, qtde);
        if(acao == 4)
            consultar_preco(lista, qtde);
    }

    std::cout << "Operacao encerrada" << std::endl;
    return 0;
}