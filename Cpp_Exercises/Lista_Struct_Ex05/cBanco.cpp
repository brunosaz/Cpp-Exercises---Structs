#include "cBanco.h"
#include <iostream>

using namespace std;

cBanco::cBanco() {
}

cBanco::cBanco(const cBanco& orig) {
}

cBanco::~cBanco() {
}

float cBanco::gerenciarConta(clientes vetClientes){
    int opc=0;
    system ("cls||clear");
    do{
        cout << "***************** BANCO ABC *****************" << endl;
        cout << "Operações Disponíveis: "<<endl;
        cout << "1 - Extrato"<<endl;
        cout << "2 - Depósito"<<endl;
        cout << "3 - Saque"<<endl;
        cout << "0 - Sair"<<endl;
        cout << endl << "Insira a opção desejada: ";
        cin >> opc;
        
        switch (opc){
            case 1:
                this->extrato(vetClientes);
                break;
            case 2:
                vetClientes.saldo = this->deposito(vetClientes.saldo);
                this->extrato(vetClientes);
                break;
            case 3:
                vetClientes.saldo = this->saque(vetClientes.saldo);
                this->extrato(vetClientes);
                break;
            case 0:
                cout << "Saindo...";        
                break;
            default:
                cout << endl << "Opção inválida" << endl;
        }
    }while(opc!=0);
    
    return vetClientes.saldo;
}

void cBanco::cadastro(){ //Step 1
    int n=3, i=0, opc, cont;
    clientes vetClientes[n];
    
    while(i<n){
        cout << "Faça o cadastro de sua conta abaixo:" << endl << endl;
        cout << "Nome: ";
        cin >> vetClientes[i].nome;
        cout << "CPF: ";
        cin >> vetClientes[i].cpf;
        cout << "Crie a senha de acesso: ";
        cin >> vetClientes[i].senha;
        system("cls||clear");
        cout << "Para validar a conta faça um depósito inicial!" << endl;
        cout << "Insira o valor do depósito: ";
        cin >> vetClientes[i].saldo;
        cout << endl;
        system("cls||clear");
        i++;
    } 
    this->metBolha(vetClientes,n);
    cont = this->login(vetClientes,n);
    
    do{
        if(cont!=-1){
            cout << "Login efetuado!" << endl;
            vetClientes[cont].saldo = this->gerenciarConta(vetClientes[cont]);
        }else if(cont==-1){
            cout << endl << "Tente fazer login novamente!" << endl;
            this->login(vetClientes,n);
        }
        cout << "Deseja efetuar outro login? (1-SIM) (0-NÃO): ";
        cin >> opc;
        if(opc==1)
            cont = this->login(vetClientes,n); 
        
    }while(opc!=0);
        
}

void cBanco::extrato(clientes cliente){
    system("cls||clear");
    cout << "----------------------------------------------------------" << endl;
    cout << "-------------------------EXTRATO--------------------------" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Nome: " << cliente.nome << endl;
    cout << "CPF: " << cliente.cpf << endl;
    cout << "Saldo: " << cliente.saldo << endl;
    cout << "----------------------------------------------------------" << endl;
}

float cBanco::deposito(float saldo){
    float depos;
    system("cls||clear");
    cout << "Valor do depósito: ";
    cin >> depos;
    saldo += depos;
    
    return saldo;
}

float cBanco::saque(float saldo){
    float saq;
    system("cls||clear");
    cout << "Valor do saque: ";
    cin >> saq;
    saldo -= saq;
    
    return saldo;
}

void cBanco::metBolha(clientes cliente[], int n){
    int i, j;
    bool troca=true;
    clientes temp;
    
    for(i=n-1;(i>=1)&&(troca=true);i--){
        troca = false;
        for (j=0; j<i; j++){
            if(cliente[j].cpf > cliente[j+1].cpf){
                temp = cliente[j];
                cliente[j]=cliente[j+1];
                cliente[j+1]=temp;
                troca = true;
            } 
        }
    }
}

int cBanco::pesquisa(clientes cliente[], long int chave, int n){
    int inf, sup, meio;
    inf = 0;
    sup = n-1;
    
    while(inf<=sup){
        meio = (inf+sup)/2;
        if(cliente[meio].cpf==chave)
            return meio;
        else if(cliente[meio].cpf<chave)
            inf = meio+1;
        else
            sup = meio-1;        
    }
    return -1;
}

int cBanco::login(clientes cliente[], int n){
    int opc=1, i=0;

    system("cls||clear");
    long int cpf;
    cout << "Insira o CPF da sua conta para efetuar login: ";
    cin >> cpf;
    int cont = pesquisa(cliente, cpf, n), senha;
    if(cont!=(-1)){
        system("cls||clear");
        cout << "CPF: " << cliente[cont].cpf << endl;
        while(senha!=cliente[cont].senha && i<3){
            cout << "Senha: ";
            cin >> senha;
            if(senha==cliente[cont].senha){
                cout << endl << "Senha correta!" << endl;
                return cont;
            }else{
                cout << endl << "Senha incorreta!" << endl;
                i++;
            }
        }
        if(i>=3){
            cout << endl << "As tentativas de login alcançaram o limite, tente novamente!";
            return -1;
        }
    }else
        cout << endl << "CPF inválido!";

    return -1;
}



