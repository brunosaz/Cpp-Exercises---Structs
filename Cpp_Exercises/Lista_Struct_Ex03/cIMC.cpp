#include "cIMC.h"
#include <iostream>
#include <string>

using namespace std;

cIMC::cIMC() {
}

cIMC::cIMC(const cIMC& orig) {
}

cIMC::~cIMC() {
}

void cIMC::lerDados(){
    int n, i=0;
    cout << "Quantas pessoas deseja cadastrar? ";
    cin >> n;
    pessoas vetPessoas[n];
    
    while (i!=n){
        cout << "PESSOA " << i+1 << endl;
        cout << "Insira o Nome: ";
        cin >> vetPessoas[i].nome;
        cout << "Insira o CPF: ";
        cin >> vetPessoas[i].cpf;
        cout << "Insira o Sexo: ";
        cin >> vetPessoas[i].sexo;
        cout << "Insira o Peso(Kg): ";
        cin >> vetPessoas[i].peso;
        cout << "Insira a Altura(m): ";
        cin >> vetPessoas[i].altura;
        cout << endl << endl;
        i++;
    }
    this->metBolha(vetPessoas,n);
    
    int opc=1, cont=0;
    long int cpf;
    do{
        system("clear||cls");
        cout << "Insira o CPF da pessoas que deseja calcular o IMC: ";
        cin.ignore();
        cin >> cpf;
        cont = this->pesquisaBinaria(vetPessoas,cpf,n);
        //cont = this->pesquisaSequencial(vetPessoas, cpf, n); /*pesquisa sequencial*/
        if(cont==(-1)){
            cout << "O CPF buscado não está cadstrado ou foi digitado incorretamente!";
        }else{
            vetPessoas[cont].imc = calcIMC(vetPessoas[cont].altura, vetPessoas[cont].peso);
            exibir(vetPessoas[cont]);
        }
        cout << endl <<  "Deseja buscar outra pessoa? (1-Sim) (0-Não): ";
        cin >> opc;
    }while(opc!=0);
}

/*int cIMC::pesquisaSequencial(pessoas pessoa[], long int chave, int n){
    for(int i=0; i<n; i++){
        if(pessoa[i].cpf==chave){
            return i;           
        }
    }
    return -1;
}*/

float cIMC::calcIMC(float altura, float peso){
    float imc = peso/(altura*altura);
    
    return imc;
}

void cIMC::metBolha(pessoas pessoa[], int n){
    int i, j;
    pessoas temp;
    bool troca;
    troca = true;

    for (i= n-1; (i >= 1) && (troca == true); i--){
        troca = false;
        for (j= 0; j < i ;j++){
            if (pessoa[j].cpf > pessoa[j+1].cpf){
                temp = pessoa[j];
                pessoa[j] = pessoa[j+1];
                pessoa[j+1] = temp;
                troca = true;
            }
        }
    }
}

int cIMC::pesquisaBinaria(pessoas pessoa[], long int chave, int n){
    int inf, sup, meio;
    inf = 0;
    sup = n-1;

    while (inf<=sup){
        meio = (inf+sup)/2;
        if (chave == pessoa[meio].cpf)
            return meio;
        else if (chave < pessoa[meio].cpf)
            sup = meio - 1;
        else
            inf = meio + 1;
    }
    return -1;
}

void cIMC::exibir(pessoas pessoa){
    cout << "Nome: " << pessoa.nome << endl;
    cout << "CPF: " << pessoa.cpf << endl;
    cout << "Sexo: " << pessoa.sexo << endl;
    cout << "Altura: " << pessoa.altura << endl;
    cout << "Peso: " << pessoa.peso << endl;
    cout << "IMC: " << pessoa.imc << endl << endl;
}

