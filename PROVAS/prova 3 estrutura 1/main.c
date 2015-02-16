#include <stdio.h>
#include <stdlib.h>

/* Prova final estrutura dados  */

struct pilha {
    float valor;
    struct pilha *abaixo;
};

struct nivel3{
    float dadoN3;
    struct nivel3 *proxN3;
};

struct nivel2{
    float dadoN2;
    struct nivel2 *proxN2;
    struct nivel3 *primN3;
};

struct nivel1{
    int dadoN1;
    struct nivel1 *proxN1;
    struct nivel2 *primN2;
};

struct nivel1 *insereN1(struct nivel1 *ini,int valor){

    struct nivel1 *aux = (struct nivel1 *)malloc(sizeof(struct nivel1));

    aux->dadoN1 = valor;
    aux->proxN1 = NULL;
    aux->primN2 = NULL;

    if(ini==NULL){

        ini = aux;
    }else{

        struct nivel1 *ult = ini;

        while(ult->proxN1!=NULL){

            ult = ult->proxN1;
        }
        ult->proxN1 = aux;
        aux->proxN1 = NULL;
        aux->primN2 = NULL;
    }

    return ini;
}

void mostrarNivel1(struct nivel1 *ini){

    struct nivel1 *aux = ini;

    puts("Nivel 1:");
    while(aux!=NULL){

        printf("%d -> ",aux->dadoN1);
        aux = aux->proxN1;
    }

    printf("\n");
}

struct nivel2 *insereN2(struct nivel1 *ini,struct nivel2 *iniNivel2,float valor,int valorInt){

    struct nivel1 *aux2 = ini;
    struct nivel2 *aux = (struct nivel2 *)malloc(sizeof(struct nivel2));

    aux->dadoN2 = valor;
    aux->proxN2 = NULL;
    aux->primN3 = NULL;

    while(aux2!=NULL && aux2->dadoN1!=valorInt){

        aux2 = aux2->proxN1;
    }

    if(aux2!=NULL){ /// achei a chave do nível 1

        if(aux2->primN2==NULL){

            aux2->primN2 = aux;
        }else{

            struct nivel2 *aux3 = aux2->primN2;

            while(aux3->proxN2!=NULL){

                aux3 = aux3->proxN2;
            }

            aux3->proxN2 = aux;
            aux->proxN2 = NULL;
        }

    }else{

        puts("Chave inexistente no nivel 1\n");
    }

}

void mostrarNivel2(struct nivel1 *iniNivel1 , struct nivel2 *iniNivel2){

    struct nivel1 *aux = iniNivel1;
    struct nivel2 *aux2 = iniNivel2;

    while(aux!=NULL){

        printf("chave do nivel 1 = %d\n",aux->dadoN1);

        if(aux->primN2!=NULL){

            aux2 = aux->primN2;

            while(aux2!=NULL){
                printf("chave nivel 2 = %f\n",aux2->dadoN2);
                aux2 = aux2->proxN2;
            }

        }else{

            puts("Sem valor alocado no nivel 2!");
        }

        aux = aux->proxN1;
    }

}

struct nivel3 *insereN3(struct nivel1 *ini,struct nivel2 *iniNivel2,struct nivel3 *iniNivel3,int valorNivel1,float valorNivel2,float valorNivel3){

    struct nivel1 *aux = ini;
    struct nivel3 *aux3 = (struct nivel3 *)malloc(sizeof(struct nivel3));
    struct nivel3 *aux4;

    aux3->dadoN3 = valorNivel3;
    aux3->proxN3 = NULL;

    while(aux!=NULL && aux->dadoN1!=valorNivel1){

        aux = aux->proxN1;
    }

    if(aux!=NULL){ /// achei a chave do nível 1

        struct nivel2 *aux2 = aux->primN2;

        while(aux2!=NULL && aux2->dadoN2!=valorNivel2){

            aux2 = aux2->proxN2;
        }

        if(aux2!=NULL){ /// achei a chave do nivel 2

            if(aux2->primN3==NULL){

                aux2->primN3 = aux3;

            }else{

                aux4 = aux2->primN3;

                while(aux4->proxN3!=NULL){

                    aux4 = aux4->proxN3;
                }

                aux4->proxN3 = aux3;
            }

    }else{

        puts("Chave inexistente no nivel 2\n");
    }

    }else{


        puts("Chave inexistente no nivel 1\n");

    }

}

struct pilha *push(struct pilha *topo,float valor){

    struct pilha *aux = (struct pilha *)malloc(sizeof(struct pilha));

    aux->valor = valor;
    aux->abaixo = NULL;

    if(topo==NULL){
        aux->abaixo = NULL;
    }else{
        aux->abaixo = topo;
    }

    topo = aux;
    return topo;
}

void mostraPilha(struct pilha *topo){

    struct pilha *aux = topo;

    while(aux->abaixo!=NULL){

        printf("%.2f ",aux->valor);
        aux = aux->abaixo;
    }

     printf("%.2f ",aux->valor);
}

void mostrarNivel3(struct nivel1 *iniNivel1 , struct nivel2 *iniNivel2, struct nivel3 *iniNivel3){

    struct nivel1 *aux = iniNivel1;
    struct nivel2 *aux2 = iniNivel2;
    struct nivel3 *aux3 = iniNivel3;

    while(aux!=NULL){ /// NÍVEL 1

        printf("------------------------- chave do nivel 1 = %d-----------------\n",aux->dadoN1);

        if(aux->primN2!=NULL){

            aux2 = aux->primN2;

            while(aux2!=NULL){
                printf("chave nivel 2 = %f\n",aux2->dadoN2);

                if(aux2->primN3!=NULL){

                    aux3 = aux2->primN3;

                    while(aux3!=NULL){
                        printf("chave nivel 3 = %f\n",aux3->dadoN3);
                        aux3 = aux3->proxN3;
                    }
                }else{

                    puts("Sem valor alocado no nivel 3!");

                }

                aux2 = aux2->proxN2;
            }
        }else{

            puts("Sem valor alocado no nivel 2!");
        }

        printf("\n");

        aux = aux->proxN1;
    }
}


struct nivel1 *imprimeInverso(struct nivel1 *ini){

        struct pilha *iniPilha = NULL;
        struct nivel1 *aux = ini;

        while(aux!=NULL){
            if(aux->proxN1!=NULL){
                if(aux->primN2!=NULL){
                    iniPilha = push(iniPilha,aux->dadoN1);
                    while(aux->primN2!=NULL){
                            iniPilha = push(iniPilha,aux->primN2->dadoN2);
                            if(aux->primN2->primN3!=NULL){
                                while(aux->primN2->primN3!=NULL){
                                    iniPilha = push(iniPilha,aux->primN2->primN3->dadoN3);
                                    aux->primN2->primN3 = aux->primN2->primN3->proxN3;
                                }
                            }
                        aux->primN2 = aux->primN2->proxN2;
                    }

                }else{

                    iniPilha = push(iniPilha,aux->dadoN1);
                }
            }else{
                 if(aux->primN2!=NULL){
                    iniPilha = push(iniPilha,aux->dadoN1);
                    while(aux->primN2!=NULL){
                        iniPilha = push(iniPilha,aux->primN2->dadoN2);
                        aux->primN2 = aux->primN2->proxN2;
                    }
                }
            }

            aux = aux->proxN1;
        }

        if(iniPilha!=NULL)
            mostraPilha(iniPilha);
}

int main()
{

    struct nivel1 *iniNivel1 = NULL;
    struct nivel2 *iniNivel2 = NULL;
    struct nivel3 *iniNivel3 = NULL;

    iniNivel1 = insereN1(iniNivel1,4);
    iniNivel1 = insereN1(iniNivel1,7);
    iniNivel1 = insereN1(iniNivel1,15);
    iniNivel1 = insereN1(iniNivel1,19);
    iniNivel1 = insereN1(iniNivel1,26);

    //mostrarNivel1(iniNivel1);

    iniNivel2 = insereN2(iniNivel1,iniNivel2,7.2,7);
    iniNivel2 = insereN2(iniNivel1,iniNivel2,7.6,7);
    iniNivel2 = insereN2(iniNivel1,iniNivel2,7.8,7);

    iniNivel2 = insereN2(iniNivel1,iniNivel2,26.9,26);

    //mostrarNivel2(iniNivel1,iniNivel2);

    iniNivel3 = insereN3(iniNivel1,iniNivel2,iniNivel3,7,7.8,7.83);
    iniNivel3 = insereN3(iniNivel1,iniNivel2,iniNivel3,7,7.2,7.25);
    iniNivel3 = insereN3(iniNivel1,iniNivel2,iniNivel3,7,7.2,7.28);

    mostrarNivel3(iniNivel1,iniNivel2,iniNivel3);

    printf("\n\nPara o terceira prova de estrutura de dados 1 a resposta e : \n");
    iniNivel1 = imprimeInverso(iniNivel1);
    printf("\n\n\n");

    system("pause");

    return 0;
}
