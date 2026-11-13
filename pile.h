/* pile.h - TP3 ESGIS L2 IIRT
   Pile par liste chainee, LIFO */
#ifndef PILE_H
#define PILE_H
#include <stddef.h>
typedef struct PNoeud {
    int v;
    struct PNoeud *suiv;
} PNoeud;
typedef struct {
    PNoeud *sommet;
    size_t taille;
} Pile;
void pile_init(Pile *p);
int pile_empiler(Pile *p, int v);
int pile_depiler(Pile *p, int *out);
int pile_est_vide(const Pile *p);
void pile_detruire(Pile *p);
#endif
