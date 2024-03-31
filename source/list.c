#include <stdio.h>
#include <stdlib.h>

// Structure d'un nœud de la liste chaînée
struct Node {
    int data;           // Donnée du nœud
    struct Node* next;  // Pointeur vers le prochain nœud dans la liste
};

// Alias pour simplifier l'utilisation de la structure
typedef struct Node Node;

// Pointeur vers le début de la liste
Node* head = NULL;

/*
 * Libère la mémoire occupée par tous les nœuds de la liste.
 */
void free_list() {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;  // Sauvegarde du pointeur vers le prochain nœud
        free(current);         // Libération de la mémoire du nœud actuel
        current = next;        // Déplacement vers le prochain nœud
    }

    head = NULL;  // Réinitialisation du pointeur de tête à NULL
}

/*
 * Initialise la liste en la vidant.
 */
void init_list() {
    free_list();  // Libère la mémoire occupée par la liste actuelle
}

/*
 * Affiche tous les éléments de la liste.
 */
void display_list() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    printf("List: [");
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

/*
 * Charge une liste chaînée à partir d'un fichier.
 */
void load_list(char* filename) {
    // À implémenter
}

/*
 * Sauvegarde la liste chaînée dans un fichier.
 */
void save_list(char* filename) {
    // À implémenter
}

/*
 * Ajoute un élément à la fin de la liste.
 */
void append_list(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

/*
 * Supprime le dernier élément de la liste.
 */
void delete_end_of_list() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    Node* current = head;
    Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    free(current);
    previous->next = NULL;
}

/*
 * Supprime le premier élément de la liste.
 */
void delete_start_of_list() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
}

/*
 * Supprime un élément spécifique de la liste.
 */
void delete_element(int data) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    // Recherche de l'élément à supprimer
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    // Si l'élément à supprimer est en tête de liste
    if (current == head) {
        head = head->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

// Fonction principale
int main() {
    // Exemple d'utilisation des fonctions de manipulation de la liste
    append_list(1);
    append_list(2);
    append_list(3);
    display_list();
    delete_start_of_list();
    display_list();
    delete_end_of_list();
    display_list();
    delete_element(2);
    display_list();

    return 0;
}
