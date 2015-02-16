#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct detalheDoNome{
  char primNome[40];
  char nomeMeio[40];
  char ultimoNome[40];
};

struct enderecoEstudante {
    char cidade[40];
    int numero;
};

struct fichaDoEstudante{
    struct detalheDoNome nome;
    struct enderecoEstudante endereco;
    char sexo;
};

int contaEstudantePrimLetraIgual(struct fichaDoEstudante fich[]){

    int i=0,cont=0;

    while(i<2){

        if(fich[i].nome.primNome[0]==fich[i].nome.nomeMeio[0]&&fich[i].nome.primNome[0]==fich[i].nome.ultimoNome[0]){

            cont++;
        }else{
            cont= cont;
        }

        i++;
    }

    return cont;

}
void mostraEstudante(struct fichaDoEstudante fich[] , char cidad[]){

    int i=0,flag=0;
    for(i=0;i<2;i++){
        if(strcmp(cidad,fich[i].endereco.cidade)==0){

            printf("O nome deste estudante e %s\n",fich[i].nome.nomeMeio);
        }
    }
}

int main()
{
    struct fichaDoEstudante ficha[2];
    int i;
    puts("sisteminha cadastro 2 estudantes\n");
    for(i=0;i<2;i++){

        printf("Informe o nome do estudante\n");
        //scanf("%s",&ficha[i].nome.primNome);
        gets(ficha[i].nome.primNome);

        printf("Informe o nome do meio do estudante\n");
        //scanf("%s",&ficha[i].nome.nomeMeio);
        gets(ficha[i].nome.nomeMeio);

        printf("Informe o ultimo nome do estudante\n");
        //scanf("%s",&ficha[i].nome.ultimoNome);
        gets(ficha[i].nome.ultimoNome);

        printf("Informe o nome da cidade do estudante\n");
        gets(ficha[i].endereco.cidade);

        printf("Informe o numero do endereco do estudante\n");
        scanf("%d",&ficha[i].endereco.numero);
        getchar();

        printf("Informe o sexo do estudante\n");
        scanf(" %c",&ficha[i].sexo);
        getchar();

   }

   for(i=0;i<2;i++){

        printf("O nome do estudante e %s %s %s\n",ficha[i].nome.primNome,ficha[i].nome.nomeMeio,ficha[i].nome.ultimoNome);

   }

   printf("\n\n\n");

   printf("Quantidade de alunos retornados pela primeira funcao = %d\n",contaEstudantePrimLetraIgual(ficha));
   char cidad[40];

   for(i=0;i<2;i++){
       puts("informe um nome de cidade\n");
       gets(cidad);
       mostraEstudante(ficha,cidad);
       cidad[40];
   }

    return 0;
}
