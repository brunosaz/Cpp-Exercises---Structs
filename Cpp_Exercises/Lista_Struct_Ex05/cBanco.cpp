#include "cBanco.h"
#include <iostream>

using namespace std;

cBanco::cBanco() {
}

cBanco::cBanco(const cBanco& orig) {
}

cBanco::~cBanco() {
}

void cBanco::gerenciarConta(clientes vetClientes){
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
                cout << endl << "Caso inválido";
        }
    }while(opc!=0); 
}

void cBanco::cadastro(){ //Step 1
    int n=3, i=0;
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
    this->login(vetClientes,n);
}

void cBanco::extrato(clientes cliente){
    system("cls||clear");
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

void cBanco::login(clientes cliente[], int n){
    int opc=1;
    while(opc!=0){
        system("cls||clear");
        long int cpf;
        cout << "Insira o CPF da sua conta para efetuar login: ";
        cin >> cpf;
        int cont = pesquisa(cliente, cpf, n), senha;
        if(cont!=(-1)){
            system("cls||clear");
            cout << "CPF: " << cliente[cont].cpf << endl;
            while(senha!=cliente[cont].senha){
                cout << "Senha: ";
                cin >> senha;
                if(senha==cliente[cont].senha){
                    cout << endl << "Senha correta!" << endl;
                    this->gerenciarConta(cliente[cont]);
                }else
                    cout << endl << "Senha incorreta!" << endl;
            }
        }else
            cout << endl << "CPF inválido!";
        cout << endl << "Deseja efetuar outro login? (1-SIM) (0-NÃO): ";
        cin >> opc;
    }
    system("cls||clear");
    cout << "*********************** SISTEMA ENCERRADO ***********************";
}



