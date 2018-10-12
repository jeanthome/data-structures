#include <stdio.h>
#include <stdlib.h>

/**
 * Estrutura de um nó da lista.
 */
typedef struct Node {
  int value;             /* Valor salvo no nó. */
  struct Node *previous; /* Ponteiro para o elemento anterior. */
  struct Node *next;     /* Ponteiro para o próximo elemento da lista. */
} Node;

/**
 * Estrutura que define a lista ligada.
 */
typedef struct LinkedList {
  unsigned int size; /* Tamanho da lista. */
  Node *head;        /* Ponteiro para o início da lista. */
  Node *tail;        /* Ponteiro para o final da lista. */
} LinkedList;

LinkedList *build_linked_list();
Node *get_node(int value);
LinkedList *add(LinkedList *l, int value);
LinkedList *add_at_beginning(LinkedList *l, int value);
LinkedList *remove_first(LinkedList *l);
LinkedList *remove_last(LinkedList *l);

int get_first(LinkedList *l);
int get_last(LinkedList *l);
void print(LinkedList *l);
void reverse_print(LinkedList *l);

int main(int argc, char const *argv[]) {

  LinkedList *list = build_linked_list();

  for (int i = 1; i <= 10; i++) {
    list = add(list, i);
  }

  print(list);
  reverse_print(list);

  list = remove_first(list);
  list = remove_last(list);

  print(list);
  reverse_print(list);

  return 0;
}

/**
 * Cria a lista ligada com zero elementos.
 * @return Ponteiro para a lista criada.
 */
LinkedList *build_linked_list() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}

/**
 * Aloca memória para um novo nó na lista.
 * @return Ponteiro para o nó criado.
 */
Node *get_node(int value) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->previous = node->next = NULL;
  node->value = value;
  return node;
}

/**
 * Adiciona um novo elemento no final da lista.
 * @param l Ponteiro para a lista onde o novo elemento será adicionado.
 * @param value O valor a ser adicionado.
 * @return Ponteiro para a lista onde o novo elemento foi adicionado.
 */
LinkedList *add(LinkedList *l, int value) {
  Node *new = get_node(value);

  if (l->head == NULL) {
    l->head = new;
    l->tail = new;
  } else {
    new->previous = l->tail;
    l->tail->next = new;
    l->tail = new;
  }

  l->size++;
  return l;
}

/**
 * Adiciona um novo elemento no início da lista.
 * @param l Ponteiro para a lista onde o novo elemento será adicionado.
 * @param value O valor a ser adicionado.
 * @return Ponteiro para a lista onde o novo elemento foi adicionado.
 */
LinkedList *add_at_beginning(LinkedList *l, int value) {
  Node *new = get_node(value);

  if (l->head == NULL) {
    l->head = new;
    l->tail = new;
  } else {
    new->next = l->head;
    l->head->previous = new;
    l->head = new;
  }

  l->size++;
  return l;
}

/**
 * Remove o primeiro elemento da lista;
 * @param l Ponteiro para a lista.
 * return Ponteiro para a lista atualizada.
 */
LinkedList *remove_first(LinkedList *l) {

  if (l->size > 0) {
    Node *first = l->head;
    l->head->next->previous = NULL;
    l->head = l->head->next;
    free(first);
    l->size--;
  }

  return l;
}

/**
 * Remove o último elemento da lista;
 * @param l Ponteiro para a lista.
 * return Ponteiro para a lista atualizada.
 */
LinkedList *remove_last(LinkedList *l) {

  if (l->size > 0) {
    Node *last = l->tail;
    l->tail->previous->next = NULL;
    l->tail = l->tail->previous;
    free(last);
    l->size--;
  }
  return l;
}

/**
 * Obtém o valor armazenado no primeiro nó da lista.
 * @param l Ponteiro para a lista.
 * @return int com o valor no primeiro nó da lista.
 */
int get_first(LinkedList *l) { return l->head->value; }

/**
 * Obtém o valor armazenado no último nó da lista.
 * @param l Ponteiro para a lista.
 * @return int com o valor no último nó da lista.
 */
int get_last(LinkedList *l) { return l->tail->value; }

/**
 * Imprime o tamanho da lista e seus respectivos elementos, do começo para o
 * final.
 * @param l Ponteiro para a lista a ser impressa.
 */
void print(LinkedList *l) {
  Node *node = l->head;

  printf("Size: %d : ", l->size);
  while (node != NULL) {
    printf("<- %d ->", node->value);
    node = node->next;
  }
  printf("\n\n");
}

/**
 * Imprime o tamanho da lista e seus respectivos elementos, do final para o
 * começo.
 * @param l Ponteiro para a lista a ser impressa.
 */
void reverse_print(LinkedList *l) {
  Node *node = l->tail;
  printf("Size: %d : ", l->size);

  while (node != NULL) {
    printf("<- %d ->", node->value);
    node = node->previous;
  }
  printf("\n\n");
}
