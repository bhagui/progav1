#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct element
{
  int val;
  struct element *nxt;
} element;

typedef element* llist;

void ajout_tete(llist* l, int val)
{
  element* new = malloc(sizeof(element));
  new->val = val;
  new->nxt = *l;
  *l = new;
}

void affiche_liste(llist l)
{
  element* ptr = l;
  while (ptr != NULL)
    {
      printf("%d\n",ptr->val);
      ptr = ptr->nxt;
    }
}

bool triee(llist l)
{
  bool res =true;
  element* ptr = l;
  while (ptr->nxt != NULL && res!=false)
    {
      if( ptr->val > (ptr->nxt)->val )
	{
	  res =false;
	}
      ptr = ptr->nxt;
    }
  return res;
}

void sup_tete(llist* l)
{
  llist tmp;
  tmp=(*l)->nxt;
  free(*l);
  *l=tmp;
}

void free_list(llist* l)
{
  while (*l != NULL)
    {
      sup_tete(l);      
    }
}

void insert(llist* l, int var)
{
  llist ptr = *l;
  llist ptravant=NULL;
  if (ptr == NULL || ptr->val > var)
    {
      ajout_tete(l,var);
    }
  else
    {
      while (ptr != NULL && (ptr->val) < var)
	{
	  ptravant = ptr;
	  ptr = ptr->nxt;
	  //printf("tot\n");
	}
          //printf("%p\n", ptr);
      if (ptr == NULL)
	{
	  /*element* new = malloc(sizeof(element));
	  new->val = var;
	  ptravant = new;*/
	  ajout_tete(&ptr, var);
	  ptravant->nxt = ptr;
	}
      else
	{
	  if (var != ptr->val)
	    {
	      ajout_tete(&ptr, var);
	      ptravant->nxt = ptr;
	    }
	}
    }
}

void cree_liste (llist* liste1, FILE* fp) {
  int i;
  while (fscanf(fp, "%d", &i) != EOF) {
    insert(liste1,i);
  }
}

int main (int argc, char* argv[])
{
  FILE* fp = fopen(argv[1],"r");
  
  llist liste1 = NULL;
  //ajout_tete(&liste1,7);
  //ajout_tete(&liste1,3);
  cree_liste(&liste1,fp);
  affiche_liste(liste1);
  /* sup_tete(&liste1);
  insert(&liste1, 9);
  insert(&liste1, 5);
  insert(&liste1, 100);
  affiche_liste(liste1);*/
  fclose(fp);
 }

