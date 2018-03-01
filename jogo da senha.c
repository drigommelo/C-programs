#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#define TAM_SENHA 4

#define LIM_SENHA 6

#define NUM_TENTATIVA 10



int main(){



	int backup[TAM_SENHA], senha[TAM_SENHA], tenta[TAM_SENHA];

	int qsenha[LIM_SENHA], qtenta[LIM_SENHA];

	int num_tenta, num_certo, num_deslo;

	int acerto, erro;

	int m, n;

	char comando;



	do {

		printf("---------BEM VINDO---------\n");

		printf("\nINSTRU%c%cES: Digite i\nJOGAR: Digite j\nSAIR: Digite s\n\nSUA RESPOSTA:", 128, 229);



		comando=getche();

	  printf("\n");



		if (comando=='i') {

				system("cls");

				printf("---------INSTRU%c%cES---------\n", 128, 229);

				printf("\n%c Este %c um jogo para dois jogadores", 254, 130);

				printf("\n%c O jogador 1 digita a senha, que estar%c oculta", 254, 160);

				printf("\n%c O jogador 2 tentar%c descobrir a senha", 254, 160);

				printf("\n%c S%c ser%co aceitos n%cmeros de 1 a 6 nas senhas", 254, 224, 198, 163);

				printf("\n%c O jogo mostrar%c a quantidade de n%cmeros deslocados e certos", 254, 160, 163);

				printf("\n%c Voc%c s%c tem 10 tentativas", 254, 136, 224);



				printf("\n\nPressione qualquer tecla para continuar. . .");

				getch();

				system("cls");

		} else if (comando=='j') {

				system("cls");

				do {

					erro=0;

					printf("\nDigite a senha: ");	//INPUT DA SENHA//

					for (n=0; n<TAM_SENHA; n++){

					backup[n]=getch()-48;

					printf("*");

						if ((backup[n]<1)||(backup[n]>LIM_SENHA)) {

							printf("\n\nDADOS INCORRETOS\n");

							n=TAM_SENHA;

							erro=1;

						}

					}

				} while (erro==1);



				printf("\n");



				num_tenta=1;

				acerto=0;

				while((num_tenta<=NUM_TENTATIVA)&&(acerto==0)){	//TENTATIVAS//



					//DEFINICOES IMPORTANTES PARA A FUNCIONAMENTO DO CODIGO://

					num_certo=0;

					num_deslo=0;

					for (n=0; n<TAM_SENHA; n++){

						senha[n]=backup[n];

					}



					do {

						erro=0;

						printf("\nTentativa %d de 10: ", num_tenta);	//INPUT DA TENTATIVA//

						for(n=0; n<TAM_SENHA; n++){

							tenta[n]=getche()-48;

							if ((tenta[n]<1)||(tenta[n]>LIM_SENHA)) {

								printf("\n\nDADOS INCORRETOS\n");

								n=TAM_SENHA;

								erro=1;

							}

						}

					} while (erro==1);



					for (n = 0; n < TAM_SENHA; n++) {	//DEFINICAO DE NUMEROS CERTOS//

						if (tenta[n]==senha[n]) {

							num_certo++;

							tenta[n]=0;

							senha[n]=0;

						}

					}



					for (n = 0; n < LIM_SENHA; n++) {	//DEFINICAO DA QUANTIDADE DE NUMEROS//

						qtenta[n]=0;

						qsenha[n]=0;

						for (m = 0; m < TAM_SENHA; m++) {

							if (n+1==tenta[m]) {

								qtenta[n]++;

							} else if (n+1==senha[m]) {

								qsenha[n]++;

							}

						}

					}



					for (n = 0; n < LIM_SENHA; n++) {  //DEFINICAO DE SENHAS DESLOCADAS//

						while ((qsenha[n]>0)&&(qtenta[n]>0)) {

							qsenha[n]--;

							qtenta[n]--;

							num_deslo++;

						}

					}



					printf("\nN%cmero de acertos: %d", 163, num_certo);

					printf("\nN%cmeros deslocados: %d", 163, num_deslo);

					printf("\n\n");



					if (num_certo == TAM_SENHA){	//EM CASO DE ACERTO//

						acerto++;

						printf("ACERTOU\n");

					}if ((acerto==0)&&(num_tenta==10)){	//EM CASO DE ERRO TOTAL//

						printf("FIM DE JOGO\n");

					}

					num_tenta++;

				}



				printf("\nPressione qualquer tecla para continuar. . .");

				getch();

				system("cls");

		} else if (comando=='s'){

				system("cls");

				printf("\nObrigado por jogar");

				break;

		} else {
				system("cls");

				printf("\nPor favor, digite entradas v%clidas\n", 160);

				printf("\nPressione qualquer tecla para continuar. . .");

				getch();

				system("cls");

		}

	} while(comando!='s');



	printf("\n\n");

	system("pause");

}
