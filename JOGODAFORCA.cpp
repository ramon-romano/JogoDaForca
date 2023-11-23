#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){

 string palavras[3] = {"Abacaxi", "Estante", "Borboleta"};

    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];

}

void jogarSozinho(){

    string palavra = retornaPalavraAleatoria();

    cout << "A palavra secreta eh: " << palavra;
}

void menuInicial(){
 int opcao = 0;


 while( opcao < 1 || opcao > 3){

limpaTela();
 cout << "Bem vindo ao Jogo\n";
 cout << "\n1 - Jogar";
 cout << "\n2 - Sobre";
 cout << "\n3 - Sair\n";
 cout << "\nEscolha uma opcao e tecle enter\n";
 cin >> opcao;

 switch(opcao){
 case 1:
    jogarSozinho();
    break;

 case 2:
    cout << "Informacoes do Jogo";
    break;

 case 3:
    cout << "Ate mais!";
    break;
     }

 }
}

int main(){

   srand((unsigned)time(NULL));

   menuInicial();

   return 0;
}
