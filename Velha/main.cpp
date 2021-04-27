#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace std;

int main ()
{
    const int SIZE = 3;
    int mapa[SIZE][SIZE]; //Mapa do jogo da velha: 0 = Nda; 1 = X; 2 = O;
    int linha, coluna;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            mapa[i][j] = 0;
        }
    }

    bool jogadorUm = false, jogadorDois = false;

    do{
        for (int jogador = 1; jogador < 3; jogador++){ //Rodada de cada jogador
            do {
                system("cls"); //Limpa a tela
                cout << endl << "Jogo da Velha" << endl; //Imprime o título
                for (int i = 0; i < 13; i++){ //Imprime a barra decorativa
                    cout << "_";
                }
                cout << endl << endl;
                for(int i = 0; i < 3; i++){ //Imprime o mapa
                    cout << "|"; //Imprime barra borda esquerda
                    for(int j = 0; j < 3; j++){ //Imprima objetos
                        if (mapa[i][j] == 1){
                            cout << "X|";
                        }else if(mapa[i][j] == 2){
                            cout << "O|";
                        }else{
                            cout << " |";
                        }
                    }
                    cout << endl; //Termina impressão da linha
                } //Fim da impressão do mapa

                cout << endl  << "Jogador " << jogador << ", sua vez:" << endl << endl; //Jogador ativo
                
                do{ //Checa entrada de linha
                    cout << "[Linha]: ";
                    cin >> linha;
                    if (linha > -1 && linha < SIZE){
                        break;
                    } else{
                        cout << "Por favor, digite um numero entre 0 e " << SIZE - 1 << "." << endl;
                    }
                } while (true);

                do{ //Checa entrada de coluna
                    cout << "[Coluna]: ";
                    cin >> coluna;
                    if (coluna > -1 && coluna < SIZE){
                        break;
                    } else{
                        cout << "Por favor, digite um numero entre 0 e " << SIZE - 1 << "." << endl;
                    }
                } while (true);

                if (mapa[linha][coluna] == 0){ //Verificação de jogada inválida
                    mapa[linha][coluna] = jogador;
                    break;
                }else{
                    cout << "Por favor, escolha um local limpo do mapa." << endl;
                    system("pause");
                }
            } while (true);
            
            for (int i = 0; i < SIZE; i++){ //Verificação de vitória
                int soma = 0;
                int somaDois = 0;
                int somaTres = 0;
                int somaQuatro = 0;
                for (int j = 0; j < SIZE; j++){
                    if (mapa[i][j] == jogador){
                        soma++;
                    }
                    if (mapa[j][i] == jogador){
                        somaDois++;
                    }
                    if (mapa [j][j] == jogador){
                        somaTres++;
                    }
                    for (int y = 0; y < 3; y++){
                        if (y == 2){
                            if (mapa [0][j] == jogador){
                                somaQuatro++;
                            }
                        }else{
                            if (mapa [y][j] == jogador){
                                somaQuatro++;
                            }
                        }
                    }
                }
                if (soma == 3 || somaDois == 3 || somaTres == 3 || somaQuatro == 3){
                    if (jogador == 1){
                        jogadorUm = true;
                        break;
                    }else{
                        jogadorDois = true;
                        break;
                    }
                }
            }
            if (jogadorUm == true){ //Para repetição
                break;
            }else if (jogadorDois == true){
                break;
            }

        }
        if (jogadorUm == true){ //Para repetição
            break;
        }else if (jogadorDois == true){
            break;
        }
    } while (true);
    
    system("cls"); //Limpa a tela
    cout << endl << "Jogo da Velha" << endl; //Imprime o título
    for (int i = 0; i < 13; i++){ //Imprime a barra decorativa
        cout << "_";
    }
    cout << endl << endl;
    for(int i = 0; i < 3; i++){ //Imprime o mapa
        cout << "|"; //Imprime barra borda esquerda
        for(int j = 0; j < 3; j++){ //Imprima objetos
            if (mapa[i][j] == 1){
                cout << "X|";
            }else if(mapa[i][j] == 2){
                cout << "O|";
            }else{
                cout << " |";
            }
        }
        cout << endl; //Termina impressão da linha
    } //Fim da impressão do mapa

    if (jogadorUm == true){ //Para repetição
        cout << endl << "Parabens Jogador 1, voce venceu o jogo!!!" << endl;
    }else if (jogadorDois == true){
        cout << endl << "Parabens Jogador 2, voce venceu o jogo!!!" << endl;
    }
    system("pause");
    return 0;
}