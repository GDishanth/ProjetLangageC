#pragma once

/*
 * Définition des valeurs booléennes
 */
#define TRUE 1
#define FALSE 0

/*
 * Structure d'un nœud de la liste chaînée
 */
typedef struct listechainee_st* listechainee_ptr;

struct listechainee_st {
    int N;                      // Donnée du nœud
    listechainee_ptr next;     // Pointeur vers le prochain nœud dans la liste
};

/* Déclaration des fonctions */
void free_list(listechainee_ptr);
void init_list(void);
void display_list(listechainee_ptr);
listechainee_ptr reinit_list(listechainee_ptr);
listechainee_ptr load_list(char*);
listechainee_ptr save_list(listechainee_ptr, char*);
int test_elem_in_list(listechainee_ptr, int);
int test_ix_in_list(listechainee_ptr, int);
int find_elem_ix(listechainee_ptr, int);
listechainee_ptr append_list(listechainee_ptr, int);
listechainee_ptr prepend_list(listechainee_ptr, int);
listechainee_ptr insert_elem_in_list(listechainee_ptr, int, int);
listechainee_ptr delete_end_of_list(listechainee_ptr);
listechainee_ptr delete_start_of_list(listechainee_ptr);
listechainee_ptr delete_elem_in_list(listechainee_ptr, int);

/**
 * vim: et:ts=4:sw=4:sts=4
 * -*- mode: C; coding: utf-8-unix; tab-width: 4; tab-always-indent: t; tab-first-completion: nil -*-
 */
