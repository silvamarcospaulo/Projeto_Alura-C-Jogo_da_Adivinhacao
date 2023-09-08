#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

void imprimeQuebraDeLinha (){
//Imprime quebras de Linhas simulando um clear do TERMINAL
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void gatilhoQuebraDeLinha(){
//Um gatilho para a função imprimeQuebraDeLinha()
   printf ("\nAperte ENTER para continuar!\n");
   char variavelQuebraDeLinha;
   scanf ("%c", &variavelQuebraDeLinha);
   if (variavelQuebraDeLinha){
      imprimeQuebraDeLinha();
   }
}

int geraNumero(int numeroSecreto){
   srand(time(NULL));
   numeroSecreto = 1 + rand() % 2;
   return numeroSecreto;
}

void menu(){
   printf ("Escolha uma opção:\n");
   printf("\n\n");
   printf("1- Novo Jogo.\n");
   printf("2- Scoreboard.\n");
   printf("3- Regras.\n");
   printf("4- Créditos.\n");
   printf("5- Encerrar.\n");
   printf("\n");
}

void scoreboard(){
   gatilhoQuebraDeLinha();
   printf("IMPLEMENTAR\n");
   gatilhoQuebraDeLinha();
}

void regras(){
   gatilhoQuebraDeLinha();
   printf("Ao inciar o jogo escolha um chute entre 1 e 50.\n");
   printf("Caso acerte, o jogo irá avisar.\n");
   printf("Caso erre o chute o jogo irá te dar mais chances.\n");
   printf("Se seu chute for maior ou menor que o número secreto lhe avisaremos.\n");
   printf("\n");
   printf("Boa sorte!\n");
   printf("\n");
}

void creditos(){
   gatilhoQuebraDeLinha();
   printf("O Jogo da Adivinhação.\n");
   printf("Maio de 2023.\n");
   printf("\n");
   printf("Desenvolvido por Marcos Paulo Silva.\n");
   printf("www.linkedin/in/souomarcos\n");
   printf("www.github.com/souomarcos\n");
   printf("\n");
   printf("Projeto desenvolvido com o auxilio do curso\nIntroducao a Programação com C - Parte 1 da Alura.\n");
}

int encerrarJogo(jogarNovamente){
   //Imprime os Créditos do jogo na tela do TERMINAL e encerra o programa
   gatilhoQuebraDeLinha();
   printf("Obrigado por jogar O Jogo da Adivinhação!\n");
   creditos();
   printf("\n\n");
   jogarNovamente = 2;
   return jogarNovamente;
}

void imprimirTrofeu(){
      printf("             /__________\n");
      printf("            '._==_==_=_.'\n");
      printf("            .-:      /-.\n");
      printf("            | |:.     | |\n");
      printf("            '-|:.     |-'\n");
      printf("              :::.    /\n");
      printf("               '::. .'\n");
      printf("                 ) (\n");
      printf("               _.' '._\n");
      printf("              '''''''''')\n\n\n");
}

//Programa principal

int main(){

   setlocale(LC_ALL, "Portuguese");      
   int jogarNovamente;
   int i;
   int numeroSecreto;
   int tentativa;

   do {
      imprimeQuebraDeLinha();

      printf("\n---------------------------------\n");
      printf("Bem Vinho ao Joga da Adivinhação!");
      printf("\n---------------------------------\n");
      printf("\n\n\n");

      gatilhoQuebraDeLinha();

      menu();
      int opcaoMenu = 0;
      scanf("%d", &opcaoMenu);

      switch (opcaoMenu){

         case 1:
            jogarNovamente = 1;
            do {
               numeroSecreto = 0;
               tentativa = 0;
               gatilhoQuebraDeLinha();

               numeroSecreto = geraNumero(numeroSecreto);

               printf("Vamos começar?\n\n");
               gatilhoQuebraDeLinha();

               for (i=1; i<=3; i++){
                  printf("Tentativa %d\n\n", i);
                  printf("Digite um número entre 1 e 50!\n\n");
                  scanf("%d", &tentativa);
                  printf("\n\nO seu chute foi: %d.\n\n", tentativa);
                  if ((i < 4) && (tentativa == numeroSecreto)){
                     gatilhoQuebraDeLinha();
                     printf("Parabéns!!!!!\n");
                     printf("Você acertou o número secreto!!!!!\n\n");
                     printf("O NÚMERO SECRETO É: %d\n", numeroSecreto);
                     imprimirTrofeu();
                     gatilhoQuebraDeLinha();
                     break;
                  }else{
                     gatilhoQuebraDeLinha();
                     printf("O número secreto não é %d!\n");
                     if (i==1){
                        printf("Você ainda tem mais 2 tentativas!\n\n");
                     }else if (i==2){
                        printf("Você ainda tem mais 1 tentativa!\n\n");
                     }
                     gatilhoQuebraDeLinha();
                  }
                  if((i == 3) && (tentativa != numeroSecreto)){
                     printf("O número secreto é %d!!!!!\n", numeroSecreto);
                     printf("Infelismente as suas chances se esgotaram, tente novamente em uma outra partida!!!!!\n");
                     printf("Espero que tenha se divertido e até logo!!!!!\n");
                     gatilhoQuebraDeLinha();        
                  }
               }
               printf("Escolha uma opção:\n");
               printf("1- Desejo jogar novamente!\n");
               printf("2- Desejo encerrar o jogo!.\n");
               scanf("%d", &jogarNovamente);

            } while (jogarNovamente == 1);
            break;

         case 2:
            //Scoreboard
            //Imprime o placar dos jogadores que jogaram o jogo previamente na tela do TERMINAL
            scoreboard();
            jogarNovamente = 1;
            break;

         case 3:
            //Regras
            //Imprime as REGRAS do jogo na tela do TERMINAL
            regras();
            gatilhoQuebraDeLinha();
            jogarNovamente = 1;
            break;

         case 4:
            creditos();
            gatilhoQuebraDeLinha();
            jogarNovamente = 1;
            break;

         case 5:
            encerrarJogo(jogarNovamente);
            gatilhoQuebraDeLinha();
            jogarNovamente = 0;
            break;
         }
   }while (jogarNovamente == 1);

   return 0;
}