# include <stdio.h>
# include "listechaines.h"

int main(int argc,char* argv[])
{
  Liste l = NULL;
  FILE* fp = fopen(argv[1],"r");
  /*ajout_tete(&l,"Testing");
  ajout_tete(&l,"Deer");
  ajout_tete(&l,"Car");
  ajout_tete(&l,"Bird");
  // afficher_liste(l);
  //supp_tete(&l);
  //afficher_liste(l);
  ajout_alphab(&l,"Elephant");
  afficher_liste(l);
  if (appartient(l,"Bird")==true)
    {
      printf("True\n");
    }
  else
    {
      printf("False\n");
    }
  int size = taille(l);
  printf("%d\n",size);
  //detruire_liste(&l);*/
  charge_fichier(fp,&l);
  supp_tete(&l);
  afficher_liste(l);
  fclose(fp);
}
