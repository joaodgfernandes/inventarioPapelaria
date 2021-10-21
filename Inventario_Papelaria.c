#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 200

typedef struct inv //Estrutura base - PRODUTO
{   
    int code;
    char nome[M];
    int stock; 
} INV;

int ler(INV x[M]) //Opção numero 1 - Inserir um Produto
{ 
    int i=0;
    int p=0;
    
    printf("Quantos produtos quer introduzir? ");
    scanf("%d",&p);

    for(i=0;i<p;i++)
    {
        printf("\nInsira o nome do produto: ");
        scanf(" %s",x[i].nome);
        printf("Insira o codigo do produto: ");
        scanf("%d",&x[i].code);
        printf("Insira o stock do produto: ");
        scanf("%d",&x[i].stock);
    }
    return i;
}

void mostrar(INV x[M],int n) //Procedimento para imprimir o resultado
{ 
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nNome: %s \n",x[i].nome);
        printf("Codigo: 00%d \n",x[i].code);
        printf("Stock: %d \n \n\n", x[i].stock);
    }
}

void mostrarapagar(INV x[M],int n) //Procedimento para imprimir a lista
{ 
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n 00%d -",x[i].code);
        printf(" %s \n",x[i].nome);
    }
}

int procuracode(INV x[M],int n,int proc) //Funçao para fazer uma procura de codigo
{
    int i,r=-1;
    for(i=0;i<n;i++)
    {
        if(x[i].code==proc)
        {
            r=i;
            return r;
        }
    }
    return r;
}

int apagarprod(INV x[M],int n,int k) //Funçao para apagar um produto
{
    int i;
    for(i=k;i<n;i++)
    {
        x[i]=x[i+1];
    }
    return n-1;
}

void alterarprod(INV x[M],int k) //Alterar informação do produto
{
    int c;

        do
        {
        printf("\n Seleccione a informação a alterar: \n---------------------\n| 1 - Nome          |\n| 2 - Codigo        |\n| 3 - Stock         |\n| 4 - Sair          |\n---------------------\n");
        scanf("%d",&c);

        switch (c)
        {
            case 1: // Nome
                printf("Altere o nome do produto: ");
                scanf(" %s",x[k].nome);
                break;
            case 2: // Codigo
                printf("Altere o codigo do produto: ");
                scanf("%d",&x[k].code);
                break;
            case 3: // Stock
                printf("Altere o stock do produto: ");
                scanf("%d",&x[k].stock);
                break;
            case 4: // Sair
                break;
        }
        }
        while (c!=4);
        
}

int novaquanti(INV x[M],int k) //Adição de Stock
{
    int q;
    printf("Indique a quantidade que deseja adicionar ao stock existente: ");
    scanf("%d",&q);

    x[k].stock=x[k].stock+q;
}

int saidaquanti(INV x[M],int k) //Saida de Stock
{
    int q;
    printf("Indique a quantidade da saida de stock: ");
    scanf("%d",&q);

    x[k].stock=x[k].stock-q;
}

int listastock(INV x[M],int n) //Fazer listagem de stock
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nNome: %s \n",x[i].nome);
        printf("Stock: %d \n", x[i].stock);
    }
}

void menu(INV x[M]) //Menu de opções 
{
    int c;   // Variavel para seleccionar a opçao do switch
    int n;   // Variavel para ler os produtos
    int proc; // Variavel para apagar o produto (inteiro para código)
    int k; // Indice do elemento a apagar/alterar

    do
    {
    printf("\n Escolha uma opcao:\n-----------------------------------------------------------------------\n| 1 - Inserir um produto                           | **Menu Inicial** |\n| 2 - Apagar um produto                            -------------------|\n| 3 - Alterar informacao de um produto                                |\n| 4 - Dar entrada de uma nova quantidade de produto                   |\n| 5 - Dar saida de uma quantidade de produto                          |\n| 6 - Fazer listagem de stock                                         |\n| 7 - Encomendar produtos em falta                                    |\n| 8 - Listar informacao de um produto                                 |\n| 9 - Sair                                                            |\n-----------------------------------------------------------------------\n Opcao: ");
    scanf(" %d",&c);

    switch (c)
    {
    case 1: // Inserir um produto
        n=ler(x);
        break;
    
    case 2: // Apagar um Produto
        mostrarapagar(x,n);

        printf("\n Qual e o produto que quer apagar? \n Insira o codigo: ");
        scanf("%d",&proc);
        k=procuracode(x,n,proc);

            if(k==-1)
            {
                printf("O número inserido nao foi encontrado \n\n");
            }
            else
            {
                n=apagarprod(x,n,k);
            }
        mostrarapagar(x,n);
        break;

    case 3: // Alterar informação de um produto
        mostrar(x,n);

        printf("\n Qual e o produto que quer alterar? \n Insira o codigo: ");
        scanf("%d",&proc);
        k=procuracode(x,n,proc);

            if(k==-1)
            {
                printf("O produto que procura nao esta na lista \n");
            }
            else
            {
                alterarprod(x,k);
            }
        mostrar(x,n);
        break;

    case 4: // Dar entrada de uma nova quantidade de produto
        mostrar(x,n);

        printf("\n Qual e o produto com aumento de stock? \n Insira o codigo: ");
        scanf("%d",&proc);
        k=procuracode(x,n,proc);

        if(k==-1)
            {
                printf("O produto que procura nao esta na lista \n");
            }
        else
            {
                novaquanti(x,k);
            }
        mostrar(x,n);
        break;

    case 5: // Dar saida de uma quantidade de produto 
        mostrar(x,n);

        printf("\n Qual é o produto com saida de stock? \n Insira o codigo: ");
        scanf("%d",&proc);
        k=procuracode(x,n,proc);

        if(k==-1)
            {
                printf("O produto que procura nao esta na lista \n");
            }
        else
            {
                saidaquanti(x,k);
            }
        mostrar(x,n);
        break;

    case 6: // Fazer listagem de stock 
        listastock(x,n);
        break;

    case 7: // Encomendar produtos em falta
        
        break;

    case 8: // Listar informacao de um produto  
        break;

    case 9: // Sair
        break;

    }
    }
    while (c!=9);
}

int main()
{
    INV a[M];
    menu(a);
}
