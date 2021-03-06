#include <stdio.h>
#include <stdlib.h>

typedef struct element {
  int val;
  int mult;
  struct element* nxt;
} element;

typedef element* liste;

void ajout_tete(liste* l, int val)
{
  element* new = malloc(sizeof(element));
  new->val = val;
  new->mult = 1;
  new->nxt = *l;
  *l = new;
}

void sup_tete(liste* l)
{
  liste tmp;
  tmp=(*l)->nxt;
  free(*l);
  *l=tmp;
}

void affiche_liste(liste l)
{
  element* ptr = l;
  while (ptr != NULL)
    {
      printf("(%d,%d)\n",ptr->val, ptr->mult);
      ptr = ptr->nxt;
    }
}

void insert (liste* l, int var) {
  liste ptr = *l;
  if (ptr == NULL || ptr->val > var) {
    ajout_tete(l,var);
  }
  else {
    if (ptr->val == var) {
      ptr->mult++;
    }
    else {
      insert(&ptr->nxt, var);
    }
  }
}

void cree_liste (liste* l, FILE* fp) {
  int i;
  while (fscanf(fp, "%d", &i) != EOF) {
    insert(l,i);
  }
}

int triee (liste l)
{
  if (l == NULL) {
    return 1;
  }
  
  element* ptr = l; 
  element* ptr1 = ptr->nxt;

  if (ptr1 == NULL) {
    return 1;
  }
  
  if (ptr->val > ptr1->val)
  {
    return 0; 
  }  
  return triee(ptr1) && 1;
}

void dest(liste* l)
{
  liste tmp;
  if (*l != NULL)
    {
      sup_tete(l);
      dest(l);
    }
}

int rech_mult (liste l, int var)
{
  if (l == NULL)
    {
      return 0;
    }
  if (l->val == var)
    {
      return (l->mult);
    }
  else
    {
      rech_mult(l->nxt,var);
    }
}

int cardinal (liste l)
{
  if (l == NULL)
    {
      return 0;
    }
  else
    {
      return (l->mult + cardinal (l->nxt));
    }
}

int main(int argc, char* argv[]) {
  FILE* fp = fopen(argv[1],"r");
  liste l = NULL;
  cree_liste(&l,fp);
  /*ajout_tete(&l,9);
  ajout_tete(&l,5);
  ajout_tete(&l,3);
  insert(&l,2);
  insert(&l,11);*/
  affiche_liste(l);
  int tri=triee(l);
  printf("%d\n",tri);
  dest(&l);
  affiche_liste(l);
  /*int mult=rech_mult(l,100);
  printf("%d\n",mult);
  int card=cardinal(l);
  printf("%d\n",card);*/
  fclose(fp);
}
