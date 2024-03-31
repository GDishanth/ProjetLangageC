#include <stdlib.h>
#include <limits.h>
#include "list/list.h"
#include <CUnit/Basic.h>

/* Liste chaînée courante */
extern listechainee_ptr curlist;

/*
 * Test pour init_list
 */
void test_1_1_init_list(void) {
    /* Initialisation de la liste */
    init_list();
    /* Vérification que la liste est nulle après initialisation */
    CU_ASSERT(curlist == NULL);
}

/*
 * Test pour reinit_list
 */
void test_1_2_reinit_list(void) {
    /* Création d'une liste */
    listechainee_ptr list = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
    CU_ASSERT(list != NULL);
    list->N = 1;
    list->next = NULL;
    /* Réinitialisation de la liste */
    CU_ASSERT(reinit_list(list) == curlist);
}

/* Autres tests similaires pour les autres fonctions... */
