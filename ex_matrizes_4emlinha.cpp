#include <stdio.h>
#include <iostream>
using namespace std;

// JOGO 4 EM LINHA //

const int LINHAS = 6;
const int COLUNAS = 9;

void mostraTabuleiro(string arr[LINHAS][COLUNAS]);
void preencheTabuleiro(string arr[LINHAS][COLUNAS]);
int pedePecaJogador();
bool colocaPecaTabuleiro(string peca, int coluna, string arr[LINHAS][COLUNAS]);
bool tabuleiroCheio(string arr[LINHAS][COLUNAS]);
bool ganhouJogo(int &quemGanhou, string arr[LINHAS][COLUNAS]);

int main() {
    string tabuleiro[LINHAS][COLUNAS];
    int quemJoga = 1;   // 1 = X, 2 = O
    int quemGanhou = 0;
    string peca;

    preencheTabuleiro(tabuleiro);

    do {
        mostraTabuleiro(tabuleiro);
        if (quemJoga == 1) {
            peca = "X";
            cout << "\nJogador 1 (X)";
        } else {
            peca = "O";
            cout << "\nJogador 2 (O)";
        }

        int colunaJogar;
        bool jogou = false;
        //este while vai continuar a pedir coluna ate peca ser colocada
        while (!jogou) {
            colunaJogar = pedePecaJogador();
            jogou = colocaPecaTabuleiro(peca, colunaJogar, tabuleiro);
            if (!jogou) {
                cout << "Coluna invalida ou cheia! Tenta outra.\n";
            }
        }
            //vai tar sempre a alternar a peca (jogador)
        quemJoga = (quemJoga == 1) ? 2 : 1;

    } while (!ganhouJogo(quemGanhou, tabuleiro) && !tabuleiroCheio(tabuleiro));

    mostraTabuleiro(tabuleiro);

    if (quemGanhou != 0) {
        cout << "\nParabens! O jogador " << quemGanhou << " ganhou!\n";
    } else {
        cout << "\nO jogo terminou empatado!\n";
    }

    /*tabuleiro[0][1] = "s";
    mostraTabuleiro(tabuleiro);
    mostraTabuleiro(tabuleiro);*/

    return 0;
}

void preencheTabuleiro(string arr[LINHAS][COLUNAS]){
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            arr[i][j] = " ";
        }
    }
}

void mostraTabuleiro(string arr[LINHAS][COLUNAS]) {
    /*cout << "\nLinha 1: Coluna 2: -"  << arr[0][1] << "-";
    arr[0][1] = "a";*/
    cout << "========== 4 EM LINHA ==============\n";
    cout << "\n";

    for (int j = 0; j < COLUNAS; j++) {
        cout << "  " << j + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            cout << "| " << arr[i][j] << " ";
        }
        cout << "|" << endl;
    }
    for (int j = 0; j < COLUNAS; j++) {
        cout << "----";
    }
    cout << endl;
    //cout << string(COLUNAS * 4 + 1, '-') << endl;

}

int pedePecaJogador() {
    int coluna;
    cout << "\nEscolhe uma coluna (1-" << COLUNAS << "): ";

    while (!(cin >> coluna) || coluna < 1 || coluna > COLUNAS) {
        cout << "Entrada invalida. Escolhe uma coluna (1-" << COLUNAS << "): ";
    }
    return coluna;
}

bool colocaPecaTabuleiro(string peca, int coluna, string arr[LINHAS][COLUNAS]) {
    // o jogador introduz um 1-9 e o array 0-8
    int col = coluna - 1;

    for (int i = LINHAS - 1; i >= 0; i--) {
        if (arr[i][col] == " ") {
            arr[i][col] = peca;
            return true;
        }
    }
    return false;
}

bool tabuleiroCheio(string arr[LINHAS][COLUNAS]) {
    for (int j = 0; j < COLUNAS; j++) {
        if (arr[0][j] == " ") {
            return false;
        }
    }
    return true;
}

bool ganhouJogo(int &quemGanhou, string arr[LINHAS][COLUNAS]) {
    //estes for vao ser usados para verficiar todas as possiveis formas de ganhar
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            string peca = arr[i][j];
            if (peca == " ") continue;
            //linhas horizontasi
            if (j + 3 < COLUNAS &&
                arr[i][j+1] == peca &&
                arr[i][j+2] == peca &&
                arr[i][j+3] == peca) {
                quemGanhou = (peca == "X") ? 1 : 2;
                return true;
            }
            //linhas verticais
            if (i + 3 < LINHAS &&
                arr[i+1][j] == peca &&
                arr[i+2][j] == peca &&
                arr[i+3][j] == peca) {
                quemGanhou = (peca == "X") ? 1 : 2;
                return true;
            }
        }
    }
    return false;
}
