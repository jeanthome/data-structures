#include<stdio.h>
#include<stdlib.h>

/**
* Estrutura de um nó da lista. 
*/
typedef struct Node {
  int value;
  struct Node * next;
} Node;

/**
* Estrutura que define a lista ligada. 
*/
typedef struct LinkedList {
    unsigned int size;
    Node * head;
} LinkedList;

LinkedList * build_linked_list();
Node * get_node();
LinkedList * add(LinkedList * l, int value);
void print(LinkedList * l);

int main(int argc, char const *argv[]) { 
  
  LinkedList *list = build_linked_list();

  for (int i = 0; i < 20; i++) {
    list = add(list, i);
  }
  print(list);
  return 0;
}

/**
* Cria a lista ligada com zero elementos.
* @return Ponteiro para a lista criada.
*/
LinkedList * build_linked_list () {
  LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
  list->size = 0;
  list->head = NULL;
  return list;
}

/**
* Aloca memória para um novo nó na lista.
* @return Ponteiro para o nó criado.
*/
Node * get_node() {
  Node * node = (Node *)malloc(sizeof(Node));
  node->next = NULL;
  return node;
}

/**
* Adiciona um novo elemento no final da lista.
* @param l Ponteiro para a lista onde o novo elemento será adicionado.
* @param value O valor a ser adicionado.
* @return Ponteiro para a lista onde o novo elemento foi adicionado.
*/
LinkedList * add(LinkedList * l, int value) {
  Node *node, *new;
  
  new = get_node();
  new->value = value;

  if ( l->head == NULL ) {
    l->head = new;
  } else {
    node = l->head;
    while (node->next != NULL) {
      node = node->next;
    }
    node->next = new;
  }
  
  l->size++;
  return l;
}

/**
* Imprime o tamanho da lista e seus respectivos elementos.
* @param l Ponteiro para a lista a ser impressa. 
*/
void print(LinkedList * l)  {
  Node * node = l->head;

  printf("Size: %d\n", l->size);
  while (node != NULL) {
    printf(" %d", node->value);
    node = node->next;
  }
  printf("\n");
}



