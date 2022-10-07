#include "cProduto.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

cProduto::cProduto() {
}

cProduto::cProduto(const cProduto& orig) {
}

cProduto::~cProduto() {
}

void cProduto::cadastro(){
    int n, i=0;
    cout << "Quantos produtos deseja cadastrar? ";
    cin >> n;
    
    produtos vetProdutos[n];
    
    while(i<n){
        cout << "PRODUTO " << i+1 << endl;
        cout << "Insira o nome do produto: ";
        cin >> vetProdutos[i].prod;
        cout << "Insira o código do produto: ";
        cin >> vetProdutos[i].cod;
        cout << "Insira o preço do produto: ";
        cin >> vetProdutos[i].preco;
        cout << endl;
        i++;
    }
    
    this->metBolha(vetProdutos,n);
    this->printList(vetProdutos,n);
    
    int opc, cod, cont;
    while(opc!=0){
        cout << endl << "Veja o valor do produto de acordo com seu código!" << endl;
        cout << "Insira o código: ";
        system("cls||clear");
        cin >> cod;
        cont = this->pesquisa(vetProdutos,cod,n);
        if(cont==(-1)){
            cout << "ERRO: O código do produto não foi encontrado!";
        }else
            this->exibir(vetProdutos[cont]);
        
        cout << "\nDeseja pesquisar outro produto? (1-SIM) (0-Não): ";
        cin >> opc;
    }
    
}

void cProduto::metBolha(produtos produto[], int n){
    int i, j;
    produtos temp;
    bool troca;
    troca = true;
    
    for(int i=n-1;(i>=1) && (troca==true);i--){
        troca = false;
        for(j=0;j<i;j++){
            if(produto[j].cod > produto[j+1].cod){
                temp = produto[j];
                produto[j] = produto[j+1];
                produto[j+1] = temp;
                troca = true;
            }
        }
    }
}

int cProduto::pesquisa(produtos produto[], int cod, int n){
    int sup, inf, meio;
    inf = 0;
    sup = n-1;
    
    while(inf<=sup){
        meio = (inf+sup)/2;
        if(cod==produto[meio].cod)
            return meio;
        else if(cod<produto[meio].cod)
            sup = meio - 1;
        else
            inf = meio + 1;
    }
    return -1;
}

void cProduto::printList(produtos produto[], int n){
    system("cls||clear");
    cout << "***TABELA COM OS PRODUTOS E SEUS CÓDIGOS***" << endl;
    cout << "CÓDIGOS \t\t\t\t PRODUTOS" << endl;
    for (int i=0;i<n;i++){
        cout << produto[i].cod << " \t\t\t\t      " << produto[i].prod << endl;
    }
}

void cProduto::exibir(produtos produto){
    cout << setprecision(2) << fixed;
    cout << "Produto: " << produto.prod;
    cout << endl << "Código: " << produto.cod;
    cout << endl << "Preço:R$" << produto.preco;
}