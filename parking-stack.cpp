#include <stdio.h>
#include <locale.h>

int est1[5] = {0,0,0,0,0};
int est2[5] = {0,0,0,0,0};
int manobra[5] = {0,0,0,0,0};
int vagas1 = 5;
int vagas2 = 5;
int livres = 10;

int estaCheio();
void estacionarCarro();
void retirarCarro();

int main() {
	setlocale(LC_ALL, "Portuguese");
    // menu
    printf("\n--Pilha de Estacionamento--\n");
    int escolha = 9;
    
    while (escolha != 4) {
        printf("1 - Estacionar\n");
        printf("2 - Retirar carro\n");
        printf("3 - Vagas livres\n");
        printf("4 - Sair\n");
        scanf("%d", &escolha);
        
        switch(escolha) {
            case 1:
                estacionarCarro();
                break;
            case 2:
                retirarCarro();
                break;
            case 3:
                printf("\nVagas livres %d\n", livres);
                break;
            case 4:
                printf("Fim do expediente...\n");
                break;
            default:
                printf("Selecione uma opção válida.\n");
        }
    }
    
    return 0;
}

int estaCheio() {
    return livres == 0;
}

void estacionarCarro() {
    if (estaCheio()) {
        printf("Estacionamento cheio.\n");
    } else {
        int placa;
        printf("Informe os números da placa do carro: ");
        scanf("%d", &placa);
        
        if (vagas1 > 0) {
            est1[5 - vagas1] = placa;
            vagas1--;
            livres--;
        } else if (vagas2 > 0) {
            est2[5 - vagas2] = placa;
            vagas2--;
            livres--;
        }
    }
    printf("Carro estacionado.\n");
}

void retirarCarro() {
    int placa;
    printf("Informe os números da placa do carro para ser retirado: ");
    scanf("%d", &placa);
    
	if(vagas1 > 0){
		int top = 4 - vagas2;
		int i = 0;
		while(placa != est2[top]){
			manobra[i] = est2[top];
			i++;
			top--;
			printf("Manobrando...\n");
		}
		i--;
		top--;
		while(i >= 0){
			est2[i] = manobra[top];
			i--;
			top++;
		}
		vagas2++;
		livres++;
	}else if(vagas2 >= 0){
		int top = 4 - vagas1;
		int i = 0;
		while(placa != est1[top]){
			manobra[i] = est1[top];
			i++;
			top--;
			printf("Manobrando...\n");
		}
		i--;
		top--;
		while(i >= 0){
			est1[i] = manobra[top];
			i--;
			top++;
		}
		vagas1++;
		livres++;
	}else{
		printf("Vish, carro não encontrado no estacionamento...\n\n");
	}
    
    printf("Carro de placa %d retirado do estacionamento.\n", placa);
}

