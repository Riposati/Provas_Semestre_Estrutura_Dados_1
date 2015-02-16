#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct disciplina{
    char nomeDiscip[40];
    struct disciplina *prox;
};

struct disciplinasFavoritas{
    struct disciplina *end;
    struct disciplinasFavoritas *prox;
};

struct estudante{
    char nomeEstud[40];
    struct estudante *prox;
    struct disciplinasFavoritas *discip;
};

struct estudante *insereEstud(struct estudante *ini,char nomeEstud[40]){

    struct estudante *aux = (struct estudante *)malloc(sizeof(struct estudante));

    strcpy(aux->nomeEstud,nomeEstud);
    aux->prox = NULL;
    aux->discip = NULL;

    if(ini==NULL){
        ini = aux;
    }else{

        struct estudante *ult = ini;

        while(ult->prox!=NULL){

            ult = ult->prox;
        }ult->prox = aux;

        aux->prox = NULL;
    }

    return ini;
}

void mostraEstudante(struct estudante *ini){

    struct estudante *aux = ini;

    while(aux!=NULL){
        printf("Nome do estudante = %s\n",aux->nomeEstud);
        aux = aux->prox;
    }

}



struct disciplina *insereDiscip(struct disciplina *ini,char nomeDiscip[40]){

    struct disciplina *aux = (struct disciplina *)malloc(sizeof(struct disciplina));

    strcpy(aux->nomeDiscip,nomeDiscip);
    aux->prox = NULL;

    if(ini==NULL){
        ini = aux;
    }else{

        struct disciplina *ult = ini;

        while(ult->prox!=NULL){

            ult = ult->prox;
        }ult->prox = aux;

        aux->prox = NULL;
    }

    return ini;
}

void mostraDisciplinas(struct disciplina *ini){

    struct disciplina *aux = ini;

    while(aux!=NULL){
        printf("Nome da disciplina = %s\n",aux->nomeDiscip);
        aux = aux->prox;
    }

}

struct disciplinasFavoritas *insereDiscipFavorita(struct estudante *iniEstud,struct disciplina *iniDiscip,char nomeEstudante[40],char nomeDisciplina[40],struct
                          disciplinasFavoritas *inicioFavoritas){

    struct estudante *aux = iniEstud;

    while(aux!=NULL && strcmp(aux->nomeEstud,nomeEstudante)!=0){

        aux = aux->prox;

    }

    if(aux==NULL){

        puts("Estudante inexistente\n");

    }else{
        /// achei o estudante ///
        struct disciplina *aux2 = iniDiscip;

        while(aux2!=NULL && strcmp(aux2->nomeDiscip,nomeDisciplina)!=0){

            aux2 = aux2->prox;
        }

         if(aux2==NULL){

            puts("Disciplina inexistente\n");

        }else{


            ///achei a disciplina ///

            struct disciplinasFavoritas *aux3 = (struct disciplinasFavoritas *)malloc(sizeof(struct disciplinasFavoritas));

            aux3->end = aux2;
            aux3->prox = NULL;

            if(aux->discip==NULL){

                aux->discip = aux3;

            }else{

                struct disciplinasFavoritas *aux4 = aux->discip;

                while(aux4->prox!=NULL){
                    aux4 = aux4->prox;
                }

                aux4->prox = aux3;
                aux3->prox = NULL;
            }
        }
    }
}


struct estudante *mostrarDiscipFav(struct estudante *inicioEst,struct disciplinasFavoritas *iniDFav){

    struct estudante *aux = inicioEst;
    struct disciplinasFavoritas *aux2 = iniDFav;

    while(aux!=NULL){

        printf("\nNome do estudante = %s\n",aux->nomeEstud);

        if(aux->discip!=NULL){

            aux2 = aux->discip;

            while(aux2!=NULL){
                printf("disciplina favorita = %s\n", aux2->end);
                aux2 = aux2->prox;
            }

        }else{

            puts("Estudante sem disciplinas favoritas cadastradas para ele!\n");

        }

        aux = aux->prox;
    }

    return inicioEst;


}


struct estudante *contaDiscipFavoritas(struct estudante *inicioEst,struct disciplinasFavoritas *iniDFav){

    struct estudante *aux = inicioEst;
    struct disciplinasFavoritas *aux2 = iniDFav;

    struct estudante *aux3 = inicioEst;
    struct disciplinasFavoritas *aux4 = iniDFav;

    char resp[40];

    int menor = 0;

    strcpy(resp,aux3->nomeEstud);

    if(aux3->discip!=NULL){

            aux4 = aux3->discip;

            while(aux4!=NULL){
                menor++;
                aux4 = aux4->prox;
            }

        }

    int cont = 0;

    while(aux!=NULL){

            aux2 = aux->discip;

            while(aux2!=NULL){
                cont++;
                aux2 = aux2->prox;
            }

            if(menor > cont){
                strcpy(resp,aux->nomeEstud);
                break;
            }
        cont=0;
        aux = aux->prox;
    }

    /*
        printf("valor do menor = %d\n",menor);
        printf("valor do cont = %d\n",cont);
    */
    printf("\n%s\n",resp);

    return inicioEst;

}

struct disciplina *pesquisaDisciplinas(struct disciplina *ini,char nome[40]){

    struct disciplina *aux = ini;

    while(aux!=NULL && strcmp(aux->nomeDiscip,nome)!=0){

        aux = aux->prox;
    }

    if(aux==NULL){

        printf("Disciplina %s nao cadastrada\n",nome);
        return NULL;

    }else{
        printf("Disciplina %s encontrada e retornado o endereco!\n",nome);
        return aux;
    }

}

int main()
{

    struct estudante *iniEst = NULL;
    struct disciplina *iniDiscip = NULL;
    struct disciplinasFavoritas *iniDiscipFavoritas = NULL;

    iniEst = insereEstud(iniEst,"Vitor");
    iniEst = insereEstud(iniEst,"Bruno");
    iniEst = insereEstud(iniEst,"Leonardo");

    iniDiscip = insereDiscip(iniDiscip,"Algoritmo");
    iniDiscip = insereDiscip(iniDiscip,"Est. Dados");
    iniDiscip = insereDiscip(iniDiscip,"Modelagem");
    iniDiscip = insereDiscip(iniDiscip,"Ingles");
    iniDiscip = insereDiscip(iniDiscip,"Algebra");

    printf("\n--------------------------------------------------------------------------\n");
        puts("Lista de estudantes cadastrados:\n");
        mostraEstudante(iniEst);
    printf("\n--------------------------------------------------------------------------\n");

    printf("\n");

    printf("\n--------------------------------------------------------------------------\n");
        puts("Lista de Disciplinas cadastradas:\n");
        mostraDisciplinas(iniDiscip);
    printf("\n--------------------------------------------------------------------------\n");


    iniDiscipFavoritas = insereDiscipFavorita(iniEst,iniDiscip,"Vitor","Algoritmo",iniDiscipFavoritas);
    iniDiscipFavoritas = insereDiscipFavorita(iniEst,iniDiscip,"Vitor","Modelagem",iniDiscipFavoritas);

    iniDiscipFavoritas = insereDiscipFavorita(iniEst,iniDiscip,"Bruno","Ingles",iniDiscipFavoritas);

    iniDiscipFavoritas = insereDiscipFavorita(iniEst,iniDiscip,"Leonardo","Est. Dados",iniDiscipFavoritas);
    iniDiscipFavoritas = insereDiscipFavorita(iniEst,iniDiscip,"Leonardo","Modelagem",iniDiscipFavoritas);
    iniDiscipFavoritas = insereDiscipFavorita(iniEst,iniDiscip,"Leonardo","Ingles",iniDiscipFavoritas);

    printf("\n");

    printf("\n--------------------------------------------------------------------------\n");
        puts("Lista de disciplinas favoritas por aluno:\n");
        iniEst = mostrarDiscipFav(iniEst,iniDiscipFavoritas);
    printf("\n--------------------------------------------------------------------------\n");

    printf("\n--------------------------------------------------------------------------\n");
        puts("Aluno com menor quantidade de disciplinas cadastradas como favoritas:\n");
        iniEst = contaDiscipFavoritas(iniEst,iniDiscipFavoritas);
    printf("\n--------------------------------------------------------------------------\n");

    printf("\n");

    printf("\n--------------------------------------------------------------------------\n");
        puts("Funcao que busca disciplina:\n");
        iniDiscip = pesquisaDisciplinas(iniDiscip,"Modelagem");
        iniDiscip = pesquisaDisciplinas(iniDiscip,"Teste");
    printf("\n--------------------------------------------------------------------------\n");
    printf("\n");

    system("pause");

    return 0;
}
