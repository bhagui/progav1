# include <stdio.h>
//TP1 Structures

typedef struct Date{
  int year;
  int month;
  int day;
} Date;

typedef struct Personne{
  char nom[10];
  char prenom[10];
  char tel[10];
  Date dob;
} Personne;

typedef struct Annuaire{
  Personne p[100];
  int dernier;
} Annuaire;

Date lire_date ()
{
  Date d;
  // printf("Day?");
  scanf("%d", &d.day);
  //printf("Month?");
   scanf("%d", &d.month);
   //printf("Year?");
  scanf("%d", &d.year);
  return(d);
}

int lire_personne (Personne *ptr_pers)
{
  if (scanf("%s", (*ptr_pers).nom) != EOF)
    {
      //printf("Nom\n");
      //scanf("%s", (*ptr_pers).nom);
      //printf("Prenom\n");
      scanf("%s", ptr_pers->prenom);
      //printf("Telephone");
      (*ptr_pers).dob = lire_date();
      scanf("%s", (*ptr_pers).tel);
      return(0);
    }
  else
    {
      return(1);
    }
}

void affiche_date(Date d)
{
  printf("The date is: %02d/%02d/%04d\n" ,d.day,d.month,d.year);
}

void affiche_personne(Personne p1)
{
  printf("Nom:%s\nPrenom:%s\nTelephone:%s\nDate of birth: %02d/%02d/%04d\n" ,p1.nom,p1.prenom,p1.tel,p1.dob.day,p1.dob.month,p1.dob.year);
}

void construire_annuaire(Annuaire* annu)
{
  int i=0;
  int ind=0;
  while(i==0 && ind<=100)
    {
      i=(lire_personne(&annu->p[ind]));
      annu->dernier++;
      ind++;
    }
} 

void affiche_annuaire(Annuaire annu)
{
  int i;
  for(i=0;i<annu.dernier-1;i++)
    {
      affiche_personne(annu.p[i]);
    }
}


int compare_dates (Date d1, Date d2)
{
  if (d1.year>d2.year)
    {
      return(1);
    }
  else
    {
      if (d1.year<d2.year)
	{
	  return(-1);
	}
      else
	{
	  if (d1.month>d2.month)
	    {
	      return(1);
	    }
	  else
	    {
	      if (d1.month<d2.month)
		{
		  return(-1);
		}
	      else
		{
		  if (d1.day>d2.day)
		    {
		      return(1);
		    }
		  else
		    {
		      if (d1.day<d2.day)
			{
			  return(-1);
			}
		      else
			{
			  return(0);
			}
		    }
		}
	    }
	}
    }
}
  
void tri_date (Annuaire *ptr)
{
  Personne temp;
  int i,j;
  for (i=0;i<(*ptr).dernier-2;i++)
    {
      for (j=0;j<(*ptr).dernier-2;j++)
	{
	  if (compare_dates((*ptr).p[j].dob,(*ptr).p[j+1].dob)==1)
	    {
	       printf("=====\n"); 
	      temp=(*ptr).p[j];
	       affiche_personne(ptr->p[j]);
	      ptr->p[j] = ptr->p[j+1];
	      (*ptr).p[j+1]=temp;
	           
	      affiche_personne(ptr->p[j]);
	      affiche_personne(temp);
	    }
	}
    }
}

int main()
{
  Annuaire annu;
  annu.dernier = 0;
  construire_annuaire(&annu);
  tri_date(&annu);
  affiche_annuaire(annu);
  return 0;
}
