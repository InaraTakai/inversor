/* Data de submissao: COLOCAR DATA NAO ESQUECER
 * Nome: Inara Takashi
 * RA: 174975
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int tam_buffer=100;

typedef struct Elemento_da_pilha{
    char *dados;
    struct Elemento_da_pilha *proximo;
}Elemento;

struct Localizar{
  Elemento *inicio;
  int tamanho;
} Pilha;

void iniciar(struct Localizar *p){
  p->inicio = NULL;
  p->tamanho = 0;
}

void empilhar(struct Localizar *p, char * dados){
  Elemento *novo_elemento;
  novo_elemento = (Elemento *) malloc (sizeof (Elemento));
  novo_elemento->dados = (char *) malloc (tam_buffer * sizeof (char));
  strcpy(novo_elemento->dados, dados);
  novo_elemento->proximo = p->inicio;
  p->inicio = novo_elemento;
  p->tamanho++;
}

int desempilhar (struct Localizar *p){
  Elemento *p_elemento;
  if (p->tamanho == 0){
    return -1;
  }
  p_elemento = p->inicio;
  p->inicio = p->inicio->proximo;
  free (p_elemento->dados);
  free (p_elemento);
  p->tamanho--;
  return 0;
}

void mostrar(struct Localizar *p){
  Elemento *atual;
  int i;
  atual = p->inicio;

  for(i=0;i<p->tamanho;++i){
    printf("%c", atual->dados[0]);
    atual = atual->proximo;
  }
}

int main() {
  struct Localizar pilha;
  int i,j,x;
  char letra;
  char buffer[tam_buffer];


  fgets(buffer, tam_buffer, stdin);
  // printf("%s", buffer);

  iniciar(&pilha);
  x=0;
  for (i=0;i<100;i++){
    letra = buffer[i];

    if (letra != ' ' && letra != '\n'){
      empilhar(&pilha, &letra);
    }else if (letra == ' ' || letra == '\n'){
      mostrar(&pilha);
      for(j=x;j<i;j++){
       desempilhar(&pilha);
     }
     if (letra == ' '){
       printf(" ");
     }else if (letra == '\n'){
       printf("\n");
       i=100;
     }
     x=i+1;
   }
 }
 return 0;
}
