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

  return 0;
}

Tree *build_binary_tree() {
  Tree *new = (Tree *)malloc(sizeof(Tree));
  new->size = 0;
  new->root = NULL;
  return new;
}

Node *get_node(int value) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->value = value;
  new->left = new->right = NULL;
  return new;
}

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
      printf("Valor %d ja existente.\n", value);
      t->size--;
      free(new);
    }
  }

  return t;
}
