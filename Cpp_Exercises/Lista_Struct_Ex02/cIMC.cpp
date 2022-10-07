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
    
    int opc=1, cont=0;
    long int cpf;
    do{
        system("clear||cls");
        cout << "Insira o CPF da pessoas que deseja calcular o IMC: ";
        cin.ignore();
        cin >> cpf;
        cont = this->localizar(vetPessoas, cpf, n);
        if(cont==(-1)){
            cout << "O CPF buscado não está cadstrado ou foi digitado incorretamente!";
        }else{
            vetPessoas[cont].imc = calcIMC(vetPessoas[cont].altura, vetPessoas[cont].peso);
            exibir(vetPessoas[cont]);
        }
        cout << endl << "Deseja buscar outra pessoa? (1-Sim) (0-Não): ";
        cin >> opc;
    }while(opc!=0);
}

int cIMC::localizar(pessoas pessoa[], long int cpf, int n){
    for(int i=0; i<n; i++){
        if(pessoa[i].cpf==cpf){
            return i;           
        }
    }
    return -1;
}

float cIMC::calcIMC(float altura, float peso){
    float imc = peso/(altura*altura);
    
    return imc;
}

void cIMC::exibir(pessoas pessoa){
    cout << "Nome: " << pessoa.nome << endl;
    cout << "CPF: " << pessoa.cpf << endl;
    cout << "Sexo: " << pessoa.sexo << endl;
    cout << "Altura: " << pessoa.altura << endl;
    cout << "Peso: " << pessoa.peso << endl;
    cout << "IMC: " << pessoa.imc << endl << endl;
}

