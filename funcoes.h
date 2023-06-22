#include "header.h"

void inicializaVetor(int vetor1[], int vetor2[]) {
  for (i = 0; i < 10; i++) {
    vetor1[i] = -1;
    vetor2[i] = -1;
  }
}
// mensagem de inválido
void invalido() {
  system("clear");
  printf("Opção Inserida\033[0;31m Inválida!!\033[0;37m\n\nTente novamente!");
  printf("\n");
  sleep(2);
}
// retorna numero aleatório para o código
int aleatorio(int dificuldade) { return rand() % dificuldade + 1; }
// Tutorial
void tutorial() {
  system("clear");
  printf("Advinhe o Número é um jogo muito simples!\napós escolher a "
         "dificuldade você terá um simples objetivo:\n\n\033[0;35mDescobrir o "
         "número que nós escolhemos!\033[0;37m\n\nCada chute seu lhe dará uma "
         "dica, use as bem!\nPressione enter para voltar\n");
  getchar();
  getchar();
}
// jogo
void jogo(int resposta, int dif, int qtdpalpites) {
  int chutemai[10], chutemeno[10], chute,
      max = dif, min = 1, palpites = qtdpalpites, ctmai = 0, ctmeno = 0;
  inicializaVetor(chutemai, chutemeno);
  do {
    system("clear");
    printf("\nSeu número está entre %i e %i\nPalpites restantes: ", min, max);
    if (palpites >= 5) {
      printf("\033[0;32m");
    } else if (palpites < 5) {
      printf("\033[0;31m");
    }
    printf("%i\033[0;37m", palpites);
    printf("\n");
    for (i = 0; i < qtdpalpites; i++) { // imprime chutes menores a resposta
      if (chutemeno[i] > 0) {
        printf("%i ", chutemeno[i]);
      }
    }
    printf(" |?|\t");
    for (i = qtdpalpites; i >= 0; i--) { // imprime chutes maiores que a
                                         // resposta
      if (chutemai[i] > 0) {
        printf("%i ", chutemai[i]);
      }
    }
    printf("\nQual o número você acha ser o certo?\n\n");
    scanf("%i", &chute);
    if (chute == resposta) {
      system("clear");
      printf("Parabéns! Você achou o número!\n\nSua resposta era: %i\nUtilizou "
             "%i palpites\nPressione enter para voltar ao menu\n",
             resposta, qtdpalpites - palpites + 1);
      getchar();
      getchar();
    }
    if (chute > resposta && chute <= max && palpites != 0) {
      system("clear");
      max = chute;
      chutemai[ctmai] = chute;
      ctmai++;
      printf("Seu número é menor do que isso");
      palpites--;
    }
    if (chute < resposta && chute >= min && palpites != 0) {
      system("clear");
      min = chute;
      chutemeno[ctmeno] = chute;
      ctmeno++;
      printf("Seu número é maior do que isso");
      palpites--;
    }
    if (chute > max || chute < min) {
      invalido();
    }
  } while (chute != resposta && palpites != 0);

  if (chute != resposta) {
    system("clear");
    printf("\ninfelizmente você não conseguiu acertar!\n\nseu número era : "
           "%i\nPressione enter para continuar",
           resposta);
    getchar();
    getchar();
  }
}
// menu
int menu() {
  int escolha, dif, resposta;
  printf("\n");
  system("clear");
  printf("\tAdvinhe o Número!\n\n\t1. Jogar\n\t2. Tutorial\n\t3. Encerrar\n\n");
  scanf(" %i", &escolha);
  switch (escolha) {
  case 1: // Jogar
    do {
      system("clear");
      printf("\tEscolha sua Dificuldade\n1. \033[0;32mFácil\033[0;37m (entre 1 "
             "e 10, 5 palpites)\n2. Normal (entre 1 e 100, 10 palpites  \n3. "
             "\033[0;31mDificil\033[0;37m (entre 1 e 300, 10 palpites)\n");
      scanf("%i", &dif);
      if (dif < 0 || dif > 3) {
        invalido();
      }
    } while (dif < 0 || dif > 3);
    switch (dif) {
    case 1:
      system("clear");
      printf("Você escolheu: \033[0;32mFácil\n\033[0;37m");
      resposta = aleatorio(FACIL);
      jogo(resposta, FACIL, 5);
      sleep(2);
      break;
    case 2:
      system("clear");
      printf("Você escolheu: Normal");
      resposta = aleatorio(NORMAL);
      jogo(resposta, NORMAL, 10);
      sleep(2);
      break;
    case 3:
      system("clear");
      printf("Você escolheu: \033[0;31mDificil\n\033[0;37m");
      resposta = aleatorio(DIFICIL);
      jogo(resposta, DIFICIL, 10);
      sleep(2);
      break;
    }
    break;
  case 2: // Tutorial
    tutorial();
    break;
  case 3: // Encerrar
    system("clear");
    printf("Espero que tenha se divertido!!\n");
    printf("Encerrando...");
    sleep(1);
    break;
  default:
    invalido();
    break;
  }
  return escolha;
}