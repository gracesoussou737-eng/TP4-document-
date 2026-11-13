/* file.c - implementation de la file */
#include "file.h"
#include <stdlib.h>
void file_init(File *f) {
    f->tete = NULL;
    f->queue = NULL;
    f->taille = 0;
}
/* On enfile par la queue : O(1) */
int file_enfiler(File *f, int v) {
    FNoeud *n = malloc(sizeof *n);
    if (n == NULL) {
        return -1;
    }
    n->v = v;
    n->suiv = NULL;
    if (f->queue != NULL) {
        f->queue->suiv = n;
    } else {
        f->tete = n; /* file vide */
    }
    f->queue = n;
    f->taille++;
    return 0;
}
/* On defile par la tete : O(1) */
int file_defiler(File *f, int *out) {
    if (f->tete == NULL) {
        return -1; /* file vide */
    }
    FNoeud *n = f->tete;
    if (out != NULL) {
        *out = n->v;
    }
    f->tete = n->suiv;
    if (f->tete == NULL) {
        f->queue = NULL;
    }
    free(n);
    f->taille--;
    return 0;
}
int file_est_vide(const File *f) {
    return f->tete == NULL;
}
void file_detruire(File *f) {
    int tmp;
    while (file_defiler(f, &tmp) == 0) {
    }
}
