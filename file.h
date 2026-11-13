/* file.h - TP3
   File par liste chainee, FIFO */
#ifndef FILE_H
#define FILE_H
#include <stddef.h>
typedef struct FNoeud {
    int v;
    struct FNoeud *suiv;
} FNoeud;
/* On garde tete + queue pour rester en O(1) */
typedef struct {
    FNoeud *tete;
    FNoeud *queue;
    size_t taille;
} File;
void file_init(File *f);
int file_enfiler(File *f, int v);
int file_defiler(File *f, int *out);
int file_est_vide(const File *f);
void file_detruire(File *f);
#endif
