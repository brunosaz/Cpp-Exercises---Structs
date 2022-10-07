#include "cRegistro.h"
#include <iostream>

using namespace std;

cRegistro::cRegistro() {
}

cRegistro::cRegistro(const cRegistro& orig) {
}

cRegistro::~cRegistro() {
}

void cRegistro::lerDados(){
    int n, i=0;
    cout << "Quantos alunos deseja cadastrar? ";
    cin >> n;
    alunos vetAlunos[n];
    
    while(i!=n){
        cout << "ALUNO " << i+1 << endl;
        cout << "Insira o nome do aluno: ";
        cin >> vetAlunos[i].nome;
        cout << "Insira a matrícula do aluno: ";
        cin >> vetAlunos[i].mat;
        cout << "Insira a nota 1: ";
        cin >> vetAlunos[i].n1;
        cout << "Insira a nota 2: ";
        cin >> vetAlunos[i].n2;
        vetAlunos[i].media = this->media(vetAlunos[i].n1,vetAlunos[i].n2);
        system("cls||clear");
        i++;
    }
    
    for (i=0;i<n;i++){
        cout << endl;
        exibir(vetAlunos[i], n, i);
    }
}

float cRegistro::media(float n1, float n2){
    float media;
    media = (n1+n2)/2;
    
    return media;
}

void cRegistro::exibir(alunos aluno, int n, int i){  
    cout << "Aluno " << i+1 << ": " << endl;
    cout << "Nome: " << aluno.nome << endl;
    cout << "Matrícula: " << aluno.mat << endl;
    cout << "Média: " << aluno.media << endl;            
}

