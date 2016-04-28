#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 30

//Declaration de liste chainee de chaines de caracteres
typedef struct cell {
  char val[MAXSIZE];
  struct cell * suiv;
} Cellule, *Ptcellule, *Liste;

//Affichage de la liste en ligne
void afficher_liste(Liste l)
{
  Cellule* ptr = l;
  while (ptr != NULL)
    {
      printf("%s\n",ptr->val);
      ptr = ptr->suiv;
    }
}
//Ajout d'un mot en tete de la liste
void ajout_tete(Liste * l, char *mot)
{
  Ptcellule new = malloc(sizeof(Cellule));
  strcpy(new->val,mot);
  new->suiv = *l;
  *l = new;
}
//Suppression du mot en tete de la liste
void supp_tete(Liste * l)
{
  Liste tmp;
  tmp=(*l)->suiv;
  free(*l);
  *l=tmp;
}
//Ajout un mot dans une liste supposee
// triee dans l'ordre alphabetique
void ajout_alphab(Liste *l, char *mot)
{
  Liste ptr = *l;
  Liste ptravant = NULL;
  if (ptr == NULL || strcmp(ptr->val,mot)>0)
    {
      ajout_tete(l,mot);
    }
  else
    {
      while (ptr != NULL && strcmp(ptr->val,mot)<0 )
	{
	  ptravant = ptr;
	  ptr = ptravant->suiv;
	}
      ajout_tete(&ptr,mot);
      ptravant->suiv = ptr;
    }
}
//Dit si un mot donne est dans la liste
//pas forcement triee
bool appartient(Liste l,char *mot)
{
  bool res = false;
  Liste ptr = l;
  while (ptr != NULL && res == false)
    {
      if (strcmp(ptr->val,mot)==0)
	{
	  res = true;
	}
      ptr = ptr->suiv;
    }
  return res;
}
//Donne la taille de la liste.
int taille(Liste l)
{
  int cmpt = 0;
  Liste ptr = l;
  while (ptr != NULL)
    {
      cmpt++;
      ptr = ptr->suiv;
    }
  return cmpt;
}
//construit une liste triee a partir d'un fichier
void charge_fichier(FILE *fp, Liste *pl)
{
  char mot[MAXSIZE];
  fscanf(fp, "%s", mot);
  
  while (!feof(fp))
    {
      ajout_alphab(pl,mot);
      fscanf(fp, "%s", mot);
    }
}

//Destruction de Liste.
void detruire_liste(Liste* l)
{
  while (*l != NULL)
    {
      supp_tete(l);
    }
}


