#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Estrutura de um nó da árvore.
 */
typedef struct Node {
  int value;           /* O valor contido no nó. */
  struct Node *parent; /* O pai do nó.*/
  struct Node *left;   /* O filho esquerdo do nó. */
  struct Node *right;  /* O filho direito do nó. */
} Node;

/**
 * Estrutura que define a árvore.
 */
typedef struct Tree {
  unsigned int size; /* Número de nós na árvore. */
  Node *root;        /* A raiz da árvore. */
} Tree;

Tree *build_binary_tree();
Node *get_node(int value);
Tree *add(Tree *t, int value);
void pre_order(Node *node);
void in_order(Node *node);
void post_order(Node *node);
bool find(Tree *t, int value);

int main(int argc, char const *argv[]) {
  Tree *tree = build_binary_tree();

  tree = add(tree, 10);
  tree = add(tree, 5);
  tree = add(tree, 18);
  tree = add(tree, 15);
  tree = add(tree, 22);
  tree = add(tree, 0);
  tree = add(tree, 7);
  tree = add(tree, 10);

  pre_order(tree->root);
  printf("\n");

  in_order(tree->root);
  printf("\n");

  post_order(tree->root);
  printf("\n");
  return 0;
}

/**
 * Constrói a árvore binária.
 */
Tree *build_binary_tree() {
  Tree *new = (Tree *)malloc(sizeof(Tree));
  new->size = 0;
  new->root = NULL;
  return new;
}

/**
 * Aloca memória para um novo nó da árvore.
 * @param value O conteúdo armazenado no novo nó.
 * @return Ponteiro para o nó criado.
 */
Node *get_node(int value) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->value = value;
  new->left = new->right = NULL;
  return new;
}

/**
 * Adiciona um novo nó na árvore.
 * @param t Ponteiro para a árvore onde o novo nó será inserido.
 * @param value O conteúdo a ser armazenado no novo nó.
 */
Tree *add(Tree *t, int value) {
  Node *new = get_node(value);
  Node *iterator, *previous;

  if (t->root == NULL) {
    new->parent = NULL;
    t->root = new;
    printf("O valor %d eh a raiz.\n", value);
  } else {
    iterator = t->root;

    /* Itera sobre a árvore até achar o possível pai do nó a ser inserido. */
    while (iterator != NULL) {
      previous = iterator;

      if (value < iterator->value) {
        iterator = iterator->left;
      } else if (value > iterator->value) {
        iterator = iterator->right;
      } else {
        iterator = NULL;
      }
    }

    new->parent = previous;
    t->size++;
    /* Verifica em qual posição, se for o caso, o novo nó será inserido. */
    if (value < previous->value) {
      previous->left = new;
      printf("Valor %d inserido na esquerda do %d.\n", value, previous->value);
    } else if (value > previous->value) {
      previous->right = new;
      printf("Valor %d inserido na direita do %d.\n", value, previous->value);
    } else {
      printf("Valor %d já existente.\n", value);
      t->size--;
      free(new);
    }
  }

  return t;
}

/**
 * Percorre a árvore binária em pré-ordem.
 * @param node Ponteiro para o nó sendo visitado atualmente na recursão.
 */
void pre_order(Node *node) {
  if (node != NULL) {
    printf("%d ", node->value);
    pre_order(node->left);
    pre_order(node->right);
  }
}

/**
 * Percorre a árvore binária em ordem.
 * @param node Ponteiro para o nó sendo visitado atualmente na recursão.
 */
void in_order(Node *node) {
  if (node != NULL) {
    in_order(node->left);
    printf("%d ", node->value);
    in_order(node->right);
  }
}

/**
 * Percorre a árvore binária em pós-ordem.
 * @param node Ponteiro para o nó sendo visitado atualmente na recursão.
 */
void post_order(Node *node) {
  if (node != NULL) {
    post_order(node->left);
    post_order(node->right);
    printf("%d ", node->value);
  }
}

/**
 * Verifica a existência de um determinado valor na árvore.
 * @param t Ponteiro para a árvore onde a busca será realizada.
 * @param value O valor a ser buscado na árvore.
 * @return true caso o valor buscado esteja na árvore, false caso contrário.
 */
bool find(Tree *t, int value) {
  Node *iterator = t->root;

  while (iterator != NULL) {
    if (iterator->value == value) {
      return true;
    } else if (value < iterator->value) {
      iterator = iterator->left;
    } else {
      iterator = iterator->right;
    }
  }
  return false;
}
