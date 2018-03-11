#include <stdio.h>
#include <strings.h>
//Elaborado por Willian Matheus
struct agenda_estrutura {

    int cod;
    char nome[60];
    char e_mail[60];
    char celular[10];
    char rede_social[255];

};
struct agenda_estrutura agenda[10];
main() {

    carga_contatos(agenda);

    int opt;
    do {
        int tam = qtd(agenda);
        printf("Contatos na agenda: %d \n\n", tam);
        printf("Escolha a opcao\n");
        printf("0. Sair\n");
        printf("1. Adicionar contato\n");
        printf("2. Excluir contato\n");
        printf("3. Exibir contatos\n");
        printf("Opcao: ");
        scanf("%d", &opt);

        switch(opt) { //  opção escolhida no menu
        case 0:
            printf("Encerrando programa\n\n");
            return;
        case 1:
            insere_contato(agenda, tam);
            break;
        case 2:
            deleta_contato(agenda, tam);
            break;
        case 3:
            exibe_contatos(agenda, tam);
            break;
        default:
            printf("Comando invalido\n\n");
        }
    } while(opt);

}

int qtd(struct agenda_estrutura agenda[]) {
    int tam = 0, i;
    for(i=0; i<10; i++)
    {
        if(agenda[i].cod != NULL) {
            tam++;
        }
    }

    return tam;
}

void exibe_contatos(struct agenda_estrutura agenda[], int tam) {


    selection_sort(agenda,tam);
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Codigo:%d\n",agenda[i].cod);

        printf("Nome: %s\n", agenda[i].nome);

        printf("e-mail:%s\n", agenda[i].e_mail);

        printf("Celular:%s\n", agenda[i].celular);

        printf("Rede Social:%s\n", agenda[i].rede_social);
        printf(" \n");
    }

}


void carga_contatos(struct agenda_estrutura agenda[]) {
    agenda[0].cod = 1;
    strcpy(agenda[0].nome, "joao");
    strcpy(agenda[0].e_mail,"joao@email.com" );
    strcpy(agenda[0].celular,"85989018423" );
    strcpy(agenda[0].rede_social,"www.facebook.com/jooao21" );

    agenda[1].cod = 3;
    strcpy(agenda[1].nome,"maria" );
    strcpy(agenda[1].e_mail,"maria@email.com" );
    strcpy(agenda[1].celular,"85989018424" );
    strcpy(agenda[1].rede_social,"www.facebook.com/maria1" );

    agenda[2].cod = 2;
    strcpy(agenda[2].nome,"kevin" );
    strcpy(agenda[2].e_mail,"kevin@email.com" );
    strcpy(agenda[2].celular,"85989218423" );
    strcpy(agenda[2].rede_social,"www.facebook.com/kevin21" );

    agenda[3].cod = 6;
    strcpy(agenda[3].nome,"ruan" );
    strcpy(agenda[3].e_mail,"ruan@email.com" );
    strcpy(agenda[3].celular,"85989318423" );
    strcpy(agenda[3].rede_social,"www.facebook.com/ruan32" );

}

void insere_contato(struct agenda_estrutura agenda[], int i) {

    int cod = 0;

    printf("Digite o codigo:\n");
    scanf("%d", &cod);
    int prossegue = cod_existente(agenda,i, cod);

    if(prossegue == 0) {
        agenda[i].cod = cod;
        printf("Digite o nome:\n");
        scanf("%s", agenda[i].nome);

        printf("Digite o e-mail:\n");
        scanf("%s", agenda[i].e_mail);

        printf("Digite o numero do celular:\n");
        scanf("%s", agenda[i].celular);

        printf("Digite o link de uma rede social:\n");
        scanf("%s", agenda[i].rede_social);
        printf(" \n");

        selection_sort(agenda,i);
    } else {
        printf("Codigo ja utilizado:\n");
    }


}

int cod_existente(struct agenda_estrutura agenda[], int tam, int cod) {
    int i, encontrado = 0;
    for(i = 0; i < tam; i++) {
        if(agenda[i].cod == cod) {
            encontrado = 1;
        }
    }

    if(encontrado == 0) {
        return 0;
    } else {
        return 1;
    }
}

void deleta_contato(struct agenda_estrutura agenda[], int tam) {
    int cod, i, encontrado = 0, pos = 0;
    printf("Digite o codigo do contato a ser deletado:\n");
    scanf("%d", &cod);
    for(i = 0; i < tam; i++) {
        if(agenda[i].cod == cod) {
            encontrado = 1;
            pos = i;
        }
    }

    if(encontrado == 0) {
        printf("Contato nao encontrado na agenda!\n");
    } else {
        for(i = pos; i<=tam; i++) {

            if(agenda[i+1].cod != 0) {
                agenda[i] = agenda[i+1];
            }

        }
		
		//limpa o ultimo indice do vetor
        static const struct agenda_estrutura EmptyStruct;
        agenda[tam-1] = EmptyStruct;

    }

}

void selection_sort(struct agenda_estrutura agenda[], int tam)
{
    int i, j, min;
    struct agenda_estrutura aux;
    for (i = 0; i < (tam-1); i++)
    {
        min = i;
        for (j = (i+1); j < tam; j++) {
            if(agenda[j].cod < agenda[min].cod) {
                min = j;
            }
        }
        if (i != min) {
            aux = agenda[i];
            agenda[i] = agenda[min];
            agenda[min] = aux;
        }
    }
}