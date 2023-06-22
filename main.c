#include "funcoes.h"

int main(void) {
  int opcao;
  do {
    srand((unsigned)time(NULL));
    system("clear");
    opcao = menu();
  } while (opcao != 3);
}