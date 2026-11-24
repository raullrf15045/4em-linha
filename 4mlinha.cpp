#include <iostream>
#include <string>
using namespace std;


// JOGO 4 EM LINHA //


const int LINHAS = 6;
const int COLUNAS = 9;


void preencheTabuleiro(string arr[LINHAS][COLUNAS]);
void mostraTabuleiro(string arr[LINHAS][COLUNAS]);
int pedePecaJogador();
bool colocaPecaTabuleiro(string peca, int coluna, string arr[LINHAS][COLUNAS]);
bool tabuleiroCheio(string arr[LINHAS][COLUNAS]);
bool ganhouJogo(int &quemGanhou, string arr[LINHAS][COLUNAS]);


int main() {
    string tabuleiro[LINHAS][COLUNAS];
    int quemJoga = 1;          // 1 = X, 2 = O
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


        int coluna;
        bool colocou = false;


        // Continua a pedir coluna até conseguir colocar a peça
        while (!colocou) {
            coluna = pedePecaJogador();
            colocou = colocaPecaTabuleiro(peca, coluna, tabuleiro);
            if (!colocou) {
                cout << "Coluna invalida ou cheia! Tenta outra.\n";
            }
        }


        // Alterna o jogador
        quemJoga = (quemJoga == 1) ? 2 : 1;


    } while (!ganhouJogo(quemGanhou, tabuleiro) && !tabuleiroCheio(tabuleiro));


    // Mostra o tabuleiro final
    mostraTabuleiro(tabuleiro);


    if (quemGanhou != 0) {
        cout << "\nParabens! O jogador " << quemGanhou << " ganhou!\n";
    } else {
        cout << "\nO jogo terminou empatado!\n";
    }


    return 0;
}


void preencheTabuleiro(string arr[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            arr[i][j] = " ";
        }
    }
}


void mostraTabuleiro(string arr[LINHAS][COLUNAS]) {
    cout << "\n========== 4 EM LINHA ==========\n\n";


    // Números das colunas
    for (int j = 0; j < COLUNAS; j++) {
        cout << " " << j + 1 << " ";
    }
    cout << endl;


    // Tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            cout << "| " << arr[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << string(COLUNAS * 4 + 1, '-') << endl;
}


int pedePecaJogador() {
    int coluna;
    cout << "\nEscolhe uma coluna (1-" << COLUNAS << "): ";


    while (!(cin >> coluna) || coluna < 1 || coluna > COLUNAS) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Escolhe uma coluna (1-" << COLUNAS << "): ";
    }
    return coluna;
}


bool colocaPecaTabuleiro(string peca, int coluna, string arr[LINHAS][COLUNAS]) {
    // O jogador introduz 1-9, o array é 0-8
    int col = coluna - 1;


    // Procura a posição mais baixa disponível (gravidade)
    for (int i = LINHAS - 1; i >= 0; i--) {
        if (arr[i][col] == " ") {
            arr[i][col] = peca;
            return true;   // Conseguiu colocar
        }
    }
    return false;  // Coluna cheia
}


bool tabuleiroCheio(string arr[LINHAS][COLUNAS]) {
    // Se a linha de cima (0) tiver algum espaço livre, ainda não está cheio
    for (int j = 0; j < COLUNAS; j++) {
        if (arr[0][j] == " ") {
            return false;
        }
    }
    return true;  // Todas as posições do topo estão ocupadas
}


bool ganhouJogo(int &quemGanhou, string arr[LINHAS][COLUNAS]) {
    // Verifica horizontal, vertical e as duas diagonais
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            string peca = arr[i][j];
            if (peca == " ") continue;


            // Horizontal (→)
            if (j + 3 < COLUNAS &&
                arr[i][j+1] == peca &&
                arr[i][j+2] == peca &&
                arr[i][j+3] == peca) {
                quemGanhou = (peca == "X") ? 1 : 2;
                return true;
            }


            // Vertical (↓)
            if (i + 3 < LINHAS &&
                arr[i+1][j] == peca &&
                arr[i+2][j] == peca &&
                arr[i+3][j] == peca) {
                quemGanhou = (peca == "X") ? 1 : 2;
                return true;
            }


            // Diagonal principal (↘)
            if (i + 3 < LINHAS && j + 3 < COLUNAS &&
                arr[i+1][j+1] == peca &&
                arr[i+2][j+2] == peca &&
                arr[i+3][j+3] == peca) {
                quemGanhou = (peca == "X") ? 1 : 2;
                return true;
            }


            // Diagonal secundária (↙)
            if (i + 3 < LINHAS && j - 3 >= 0 &&
                arr[i+1][j-1] == peca &&
                arr[i+2][j-2] == peca &&
                arr[i+3][j-3] == peca) {
                quemGanhou = (peca == "X") ? 1 : 2;
                return true;
            }
        }
    }
    return false;
}
