#include <stdio.h>
#include <stdlib.h>		//para usar o system ("Cls"); -> � usado para "limpar" a tela do sistema
#include <conio.h>		//para usar o getch(); -> � usado para "pegar" o caracter teclado pelo usu�rio (espera at� que um caactere seja teclado)
#include <locale.h>		//para usar o setlocale -> � usado para add caracteres de escrita como '�', '~', '^', etc


#define quantidade_cartas 52		//quantidade de cartas para o jogo

//--------------------------VARI�VEIS GLOBAIS--------------------------//
int i; 
int game = 0; 							//game = 0, jogo rodando / game = 1, game over
int posicaoMenu = 1;					//posi��o inicial da seta no menu (no caso, "Iniciar jogo")
int posicaoJogo = 1;					//posi��o inicial da seta no jogo (no caso, "Puxar carta")
int teclaPressionadaMenu = 0;			//teclas que v�o ser pressionadas no menu (valores em ASCII)
int teclaPressionadaJogo = 0;			//teclas que v�o ser pressionadas no jogo (valores em ASCII)
int high = 0;							//auxiliar que guarda o maior score

FILE *arquivo;

//--------------------------------FUN��ES-------------------------------//

void setaMenu(int posicaoApontadaMenu, int posicaoDesejadaMenu){	/*FUN��O: seta no menu (somente o desenho, n�o movimentos)*/	//posicaoApontadaMenu = posi��o em que a seta aponta; posicaoDesejadaMenu = posi��o que eu quero que a seta aponte
	
	if(posicaoApontadaMenu == posicaoDesejadaMenu){		//se a posi��o que a seta se encontra � igual a que eu quero, ent�o mostrar a seta na frente
		printf("  %c ", 16);		/*16 representa a "setinha" de sele��o*/
	}
	else{
		printf("   ");		//se a posi��o que a seta se encontra � diferente a que eu quero, ent�o mostrar espa�o vazio na frente
	}
	
}

void setaJogo(int posicaoApontadaJogo, int posicaoDesejadaJogo){	/*FUN��O: seta no jogo (somente o desenho, n�o movimentos)*/	//posicaoApontadaJogo = posi��o em que a seta aponta; posicaoDesejadaJogo = posi��o que eu quero que a seta aponte
	
	if(posicaoApontadaJogo == posicaoDesejadaJogo){
		printf("    %c ", 16);
	}
	else{
		printf("    ");
	}
	
}

void menu(){	/*FUN��O: menu (com movimentos da seta)*/
	system ("Cls");
	
	while(teclaPressionadaMenu != 13){		/*13 representa a tecla ENTER*/		//enquanto n�o clicar na tecla 'ENTER' continuar nessa fun��o
		system("Cls");
		
		printf("      MENU\n\n");
		setaMenu(1, posicaoMenu); printf(" Iniciar jogo\n");	//chama a fun��o setaMenu e atribui os valores
		setaMenu(2, posicaoMenu); printf(" Regras\n");
		setaMenu(3, posicaoMenu); printf(" High score\n");
		setaMenu(4, posicaoMenu); printf(" Cr�ditos\n");
		
		teclaPressionadaMenu = getch();		//pegar a ultima tecla digitada
			if(teclaPressionadaMenu == 80 && posicaoMenu != 4){		/*80 representa a tecla baixo*/		//se clicar na tecla 'baixo' em qualquer posi��o que n�o a 4�/ultima, a seta desce
				printf("\a");	//barulho 'beep' para quando mexe a seta/aperta as teclas cima-baixo
				posicaoMenu++;
			}
			else{
				if(teclaPressionadaMenu == 72 && posicaoMenu != 1){		/*72 representa a tecla cima*/		//se clicar na tecla 'cima' em qualquer posi��o que n�o a 1�, a seta sobe
					printf("\a");
					posicaoMenu--;
				}
				else{
					posicaoMenu = posicaoMenu;	//se clicar em outra tecla que n�o seja tecla 'cima', 'baixo' ou 'ENTER', n�o mudar a posi��o
				}						
			}
	}
}



void iniciar(){		/*FUN��O: iniciar jogo (com movimentos da seta)*/
	if(teclaPressionadaMenu == 13 && posicaoMenu == 1){
		system("Cls");
				
				
				
		while(teclaPressionadaJogo != 13){
			system("Cls");
			setaJogo(1, posicaoJogo); printf(" Puxar carta\t\t\t");
			setaJogo(2, posicaoJogo); printf(" Terminar jogada");
			
			teclaPressionadaJogo = getch();	
				if(teclaPressionadaJogo == 75 && posicaoJogo == 2){		/*75 representa a tecla esquerda*/
					printf("\a");
					posicaoJogo--;
				}
				else{
					if(teclaPressionadaJogo == 77 && posicaoJogo == 1){		/*77 representa a tecla direita*/
						printf("\a");
						posicaoJogo++;
					}
					else{
						posicaoJogo = posicaoJogo;
					}						
				}
		}
	}
}

void puxarCarta(){		/*FUN��O: puxar carta no jogo*/
	if(teclaPressionadaJogo == 13 && posicaoJogo == 1){
		system("Cls");
		
		/*1- 'Puxar' mais uma carta
		  2- Se a prox carta gerar uma soma maior que 21 encerrar o jogo, se n�o, continuar*/
	}
}

void terminarJogada(){		/*FUN��O: encerrar a jogada no jogo*/
	if(teclaPressionadaJogo == 13 && posicaoJogo == 2){
		system("Cls");
		
		/*1- Verificar se a pr�xima carta passava ou n�o de 21
		  2- Se a prox carta gerar uma soma maior que 21 add pontos, se n�o subtrair pontos
		  3- Verificar se highscore ou n�o*/
	}
}	

void voltar(){		/*FUN��O: voltar ao menu*/
	teclaPressionadaMenu = getch();
		if(teclaPressionadaMenu == 8){		/*8 representa a tecla BACKSPACE*/
			menu();
		}
}

void instrucao(){		/*FUN��O: mostrar as instru��es do jogo*/
	if(teclaPressionadaMenu == 13 && posicaoMenu == 2){
		system("Cls");
		
		printf("\t\tREGRAS  \t      %c Pressione BACKSPACE para voltar ao menu\n\n", 26);		/*26 representa uma setinha*/
		printf("  'Blackjack' ou 'vinte-e-um' � um jogo de azar \n"
			   "praticado com cartas em casinos e que pode ser \n"
			   "jogado com 1 a 8 baralhos de 52 cartas, em que o\n"
			   "objetivo � ter mais pontos do que o advers�rio, \n"
		       "mas sem ultrapassar a soma de 21.");
		       
		       printf("\n\n\n %c 10, J, Q, K valem 10 pontos.", 6);					/*6 representa o naipe espadas*/
		       printf("\n\n %c �s vale tanto 1 quanto 11 pontos.", 4);				/*4 representa o naipe ouros*/
		       printf("\n\n %c Ao ganhar uma partida, 10 pontos ser�o\n"
			   		  "   adicionados ao score.", 5);								/*5 representa o naipe paus*/
		       printf("\n\n %c Ao perder uma partida, 10 pontos ser�o\n"
			   		  "   subtraidos do score.\n", 3);								/*3 representa o naipe copas*/
		       printf("\n\n %c Ao ganhar uma partida com exatamente 21\n"
			   		  "   pontos, 20 pontos ser�o adicionados ao score.", 2);		/*2 representa um rostinho/smiley-face*/
			   		  
		voltar();
	}
}

void consultarHighScore(){		//N�O EST� FUNCIONANDO!		/*FUN��O: mostrar o highscore do jogo*/
	if(teclaPressionadaMenu == 13 && posicaoMenu == 3){
		system("Cls");
		
		printf("\t  HIGH SCORE  \t\t      %c Pressione BACKSPACE para voltar ao menu\n\n\n", 26);
		
		arquivo = fopen("HighScore21.txt", "r");
		for(i = 0; i < 3; i++){
			fprintf(arquivo, "%d pontos\n", &high);
		}
		fclose(arquivo);
		
	voltar();
	}
}

void creditos(){		/*FUN��O: mostrar os cr�ditos/criadores do jogo*/
	if(teclaPressionadaMenu == 13 && posicaoMenu == 4){
		system("Cls");
		
		printf("\t  CR�DITOS  \t\t      %c Pressione BACKSPACE para voltar ao menu\n\n\n", 26);
		printf("%c Desenvolvedores: Jo�o Pedro Lima Vieira da Silva\n"
			   "\tMatr�cula: 1920026791\n\n", 6);
		printf("%c Desenvolvedores: Larissa Nahan S. D. G. Dantas\n"
			   "\tMatr�cula: 1920026931\n\n", 4);
		printf("%c Desenvolvedores: Rodrigo de Lucena Limeira\n"
			   "\tMatr�cula: 1920026942\n\n", 5);
		
		printf("\n\nTrabalho para o curso de Ci�ncia da Computa��o");
		printf("\nDisciplina T�cnicas de Desenvolvimento de Algoritmos");
		printf("\n\n1� Per�odo - UNIPE - 2019.2");
		
		voltar();
	}
}

//-------------------------------INT MAIN------------------------------//

int main(){
	setlocale(LC_ALL, "");

	while(game == 0){
		menu();
		iniciar();
		instrucao();
		consultarHighScore();
		creditos();
		voltar();
	}
	
	return 0;
}

