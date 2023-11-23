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

     //Vetor com palavras disponíveis
    string palavras[3] = {"abacaxi", "manga", "morango"};

    //Indice gerado no intervalo {0,1,2}
    int indiceAleatorio = rand() % 3;

    //Exibe a palavra aleatória
    //cout << palavras[indiceAleatorio];

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){

    int cont = 0;
    string palavraComMascara;

    //Coloca uma máscara
    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }

    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){

    //cout << "A palavra secreta eh: " << palavra << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << mensagem;
    cout << "\nPalavra:" << palavraComMascara << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << "\nTentativas Restantes:" << tentativasRestantes;

    //Exibe as letras arriscadas
    int cont;
    cout << "\nLetras arriscadas:";
    for(cont = 0; cont < letrasJaArriscadas.size();cont++){
        cout << letrasJaArriscadas[cont] << ", ";
    }

}

int jogar(int numeroDeJogadores){

    //Palavra a ser adivinhada
    string palavra;

    //Confere o número de jogadores
    if(numeroDeJogadores == 1){

        //Palavra a ser adivinhada
        palavra = retornaPalavraAleatoria();

    }else{

        cout << "\nDigite uma palavra:";
        cin >> palavra;

    }

    //Tamanho da palavra
    int tamanhoDaPalavra = palavra.size();

    //Palavra mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    ///Variáveis Gerais
    int tentativas = 0, maximoDeTentativas = 10;            //Número de tentativas e erros
    int cont = 0;                                           //Auxiliar para laços de repetição
    char letra;                                             //Letra arriscada pelo usuário
    int opcao;                                              //Opções finais
    string letrasJaArriscadas;                              //Acumula as tentativas do jogador
    string mensagem = "Bem vindo ao jogo!";                 //Feedback do jogador
    string palavraArriscada;                                //Tentativa de arriscar a palavra completa
    bool jaDigitouLetra = false, acertouLetra = false;      //Auxiliar para saber se a letra já foi digitada


    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){

        limpaTela();

        //Exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas,mensagem);

        //Lê um palpite
        cout << "\nDigite uma letra (Ou digite 1 para arriscar a palavra):";
        cin >> letra;

        //Se digitar 1 deixa o usuário arriscar a palavra inteira
        if(letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                 palavraComMascara = palavraArriscada;
            }else{
                 tentativas = maximoDeTentativas;
            }
        }

        //Percorre as letras já arriscadas
        for(cont = 0; cont < tentativas; cont++){

            //Se encontrar a letra
            if(letrasJaArriscadas[cont] == letra){

                mensagem = "Essa letra ja foi digitada!";

                //Indica com a variável booleana
                jaDigitouLetra = true;

            }
        }

        //Se for uma letra nova
        if(jaDigitouLetra == false){

            //Incrementa as letras já arriscadas
            letrasJaArriscadas += tolower(letra);

            //Percorre a palavra real e
            for(cont = 0; cont < tamanhoDaPalavra; cont++){

                //Se a letra existir na palavra escondida
                if(palavra[cont] == tolower(letra)){

                    //Faço aquela letra aparecer na palavraComMascara
                    palavraComMascara[cont] = palavra[cont];

                    acertouLetra = true;

                }
            }

            if(acertouLetra == false){

                mensagem = "Voce errou uma letra!";

            }else{

                mensagem = "Voce acertou uma letra!";

            }

            //Aumenta uma tentativa realizada
            tentativas++;

        }

        //Reinicia auxiliares
        jaDigitouLetra = false;
        acertouLetra = false;

    }

    if(palavra == palavraComMascara){

        limpaTela();
        cout << "Parabens, você venceu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;

    }else{

        limpaTela();
        cout << "Bleh, você perdeu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao;
    }

}

void menuInicial(){

    //Opção escolhida pelo usuário
    int opcao = 0;

    //Enquanto o jogador não digita uma opcao válida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo ao Jogo";
        cout << "\n1 - Jogar Sozinho";
        cout << "\n2 - Jogar em Dupla";
        cout << "\n3 - Sobre";
        cout << "\n4 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER:";

        //Faz a leitura da opcao
        cin >> opcao;

        //Faz algo de acordo com a opcao escolhida
        switch(opcao){
            case 1:
                //Inicia o jogo
                if(jogar(1) == 1){
                    menuInicial();
                }
                break;
            case 2:
                //Inicia o jogo
                if(jogar(2) == 1){
                    menuInicial();
                }
                break;
            case 3:
                //Mostra informacoes do Jogo
                cout << "Informacoes do jogo";
                limpaTela();
                cout << "Jogo desenvolvido por Ramon em 2023";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair";
                cin >> opcao;
                if(opcao == 1){
                    menuInicial();
                }

                break;
            case 4:
                cout << "Ate mais!";
                break;
        }
    }

}

int main(){

    //Para gerar números realmente aleatórios
    srand( (unsigned)time(NULL));

    menuInicial();

    return 0;
}
