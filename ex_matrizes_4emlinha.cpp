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
    int quemJoga=1; // 1-X -1º jogar // 2-O -2ºjogar !
    int quemGanhou=0;
    int colunaJogar = 0;
    bool jogou = false;
    //int jogador = 1;
    string peca;

    preencheTabuleiro(tabuleiro);

    do {
        mostraTabuleiro(tabuleiro);
        if (quemJoga == 1) {
            peca = "X";
            cout << "\nJogador 1 (X)";
            cin >> peca;
        } else {
            peca = "O";
            cout << "\nJogador 2 (O)";
            cin >> peca;
        }
        int coluna = pedePecaJogador();

        if (quemGanhou != 0) {
        cout << "\nParabens! O jogador " << quemGanhou << " ganhou!\n";
    } else {
        cout << "\nO jogo terminou empatado!\n";
    }

        colunaJogar = pedePecaJogador();
        jogou = colocaPecaTabuleiro("X", colunaJogar, tabuleiro);
    } while (!ganhouJogo(quemGanhou, tabuleiro) && !tabuleiroCheio(tabuleiro));

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

    while (!(cin >> coluna)) {
        cout << "Isso nao e um numero. Escolhe uma coluna (1-" << COLUNAS << "): ";
    }

    return coluna;
}

bool colocaPecaTabuleiro(string peca, int coluna, string arr[LINHAS][COLUNAS]) {
    for (int i = 0; i >= 0; i++) {
        if (arr[i][coluna] == " ") {
            arr[i][coluna] = peca;
            break;
        }
    }
    return false;
}

bool tabuleiroCheio(string arr[LINHAS][COLUNAS]) {
    for (int j = 0; j < COLUNAS; j++) {
        if (arr[0][j] == " ") {
            return true;
        }
    }
}

bool ganhouJogo(int &quemGanhou, string arr[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {

            if (arr[i][j] == " ") {
                continue;
            }

            string peca = arr[i][j];
            bool ganhou = false;


        }
    }

    return false;
}





