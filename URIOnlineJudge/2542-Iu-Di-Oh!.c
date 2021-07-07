#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int atributo;
	while(scanf("%d", &atributo) != EOF) {

		int qtMarcos, qtLeon;
		scanf("%d%d", &qtMarcos, &qtLeon);

		int cartMarcos[qtMarcos][atributo], cartLeon[qtLeon][atributo];
		int i, j;

		for(i = 0; i < qtMarcos; i++) {
			for(j = 0; j < atributo; j++)
				scanf("%d", &cartMarcos[i][j]);
		}

		for(i = 0; i < qtLeon; i++) {
			for(j = 0; j < atributo; j++)
				scanf("%d", &cartLeon[i][j]);
		}

		int cartaEscolhidaMarcos, cartaEscolhidaLeon;
		scanf("%d%d", &cartaEscolhidaMarcos, &cartaEscolhidaLeon);
		
		int sorteio;
		scanf("%d", &sorteio);

		if(cartMarcos[cartaEscolhidaMarcos - 1][sorteio - 1] > cartLeon[cartaEscolhidaLeon - 1][sorteio - 1])
			printf("Marcos\n");
		
		else if(cartMarcos[cartaEscolhidaMarcos - 1][sorteio - 1] < cartLeon[cartaEscolhidaLeon - 1][sorteio - 1])
			printf("Leonardo\n");
		
		else
			printf("Empate\n");
		
	}


	return 0;
}