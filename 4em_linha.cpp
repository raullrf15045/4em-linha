#include <iostream>
#include <string>
using namespace std;

const int LINHAS = 6;
const int COLUNAS = 9;

void mostrarTabuleiro(string tab[LINHAS][COLUNAS]);
int pedeColuna();
void colocaPeca(string peca, int coluna, string tab[LINHAS][COLUNAS]);
bool tabuleiroCheio(string tab[LINHAS][COLUNAS]);
bool ganhouJogo(int &quemGanhou, string tab[LINHAS][COLUNAS]);

int main() {

    string tabuleiro[LINHAS][COLUNAS];


    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = " ";
        }
    }

    int jogador = 1;
    int quemGanhou = 0;
    string peca;

    while (!tabuleiroCheio(tabuleiro) && quemGanhou == 0) {

        mostrarTabuleiro(tabuleiro);

        if (jogador == 1) {
            peca = "X";
            cout << "\nJogador 1 (X)";
        } else {
            peca = "O";
            cout << "\nJogador 2 (O)";
        }

        int coluna = pedeColuna();

        while (coluna < 1 || coluna > COLUNAS || tabuleiro[0][coluna - 1] != " ") {
            cout << "Essa coluna nao esta disponivel. ";
            coluna = pedeColuna();
        }

        colocaPeca(peca, coluna - 1, tabuleiro);

        if (!ganhouJogo(quemGanhou, tabuleiro)) {
            jogador = (jogador == 1) ? 2 : 1;
        }
    }

    mostrarTabuleiro(tabuleiro);

    if (quemGanhou != 0) {
        cout << "\nParabens! O jogador " << quemGanhou << " ganhou!\n";
    } else {
        cout << "\nO jogo terminou empatado!\n";
    }

    return 0;
}

void mostrarTabuleiro(string tab[LINHAS][COLUNAS]) {

    cout << "\n";

    for (int j = 0; j < COLUNAS; j++) {
        cout << "  " << j + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            cout << "| " << tab[i][j] << " ";
        }
        cout << "|" << endl;
    }

    cout << string(COLUNAS * 4 + 1, '-') << endl;
}

int pedeColuna() {

    int coluna;

    cout << "\nEscolhe uma coluna (1-" << COLUNAS << "): ";

    while (!(cin >> coluna)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Isso nao e um numero. Escolhe uma coluna (1-" << COLUNAS << "): ";
    }

    return coluna;
}

void colocaPeca(string peca, int coluna, string tab[LINHAS][COLUNAS]) {

    for (int i = LINHAS - 1; i >= 0; i--) {
        if (tab[i][coluna] == " ") {
            tab[i][coluna] = peca;
            break;
        }
    }
}

bool tabuleiroCheio(string tab[LINHAS][COLUNAS]) {

    for (int j = 0; j < COLUNAS; j++) {
        if (tab[0][j] == " ") {
            return false;
        }
    }


    return true;
}

bool ganhouJogo(int &quemGanhou, string tab[LINHAS][COLUNAS]) {

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {

            if (tab[i][j] == " ") {
                continue;
            }

            string peca = tab[i][j];
            bool ganhou = false;

            if (j + 3 < COLUNAS &&
                tab[i][j + 1] == peca &&
                tab[i][j + 2] == peca &&
                tab[i][j + 3] == peca) {
                ganhou = true;
            }

            if (i + 3 < LINHAS &&
                tab[i + 1][j] == peca &&
                tab[i + 2][j] == peca &&
                tab[i + 3][j] == peca) {
                ganhou = true;
            }

            if (i + 3 < LINHAS && j + 3 < COLUNAS &&
                tab[i + 1][j + 1] == peca &&
                tab[i + 2][j + 2] == peca &&
                tab[i + 3][j + 3] == peca) {
                ganhou = true;
            }

            if (i - 3 >= 0 && j + 3 < COLUNAS &&
                tab[i - 1][j + 1] == peca &&
                tab[i - 2][j + 2] == peca &&
                tab[i - 3][j + 3] == peca) {
                ganhou = true;
            }

            if (ganhou) {
                quemGanhou = (peca == "X") ? 1 : 2;
                return true;
            }
        }
    }

    return false;
}
