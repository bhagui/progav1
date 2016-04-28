# include <stdio.h>
#include <stdbool.h>
#include <string.h>
//TP1 Structures

typedef struct Date{
  int year;
  int month;
  int day;
} Date;

typedef struct Personne{
  char nom[20];
  char prenom[20];
  char tel[10];
  Date dob;
} Personne;

typedef struct Annuaire{
  Personne p[100];
  int dernier;
} Annuaire;

Date lire_date (FILE* fp)
{
  Date d;
  // printf("Day?");
  fscanf(fp,"%d", &d.day);
  //printf("Month?");
  fscanf(fp, "%d", &d.month);
   //printf("Year?");
  fscanf(fp, "%d", &d.year);
  return(d);
}

int lire_personne (Personne *ptr_pers, FILE* fp)
{
  if (fscanf(fp, "%s", (*ptr_pers).nom) != EOF)
    {
      //printf("Nom\n");
      //scanf("%s", (*ptr_pers).nom);
      //printf("Prenom\n");
      fscanf(fp, "%s", ptr_pers->prenom);
      //printf("Telephone");
      (*ptr_pers).dob = lire_date(fp);
      fscanf(fp, "%s", (*ptr_pers).tel);
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

void construire_annuaire(Annuaire* annu, FILE *fp)
{
  int i=0;
  int ind=0;
  while(i==0 && ind<=100)
    {
      i=(lire_personne(&annu->p[ind],fp));
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
      for (j=0;j<(*ptr).dernier-2
	     ;j++)
	{
	  if (compare_dates((*ptr).p[j].dob,(*ptr).p[j+1].dob)==1)
	    {
	      temp=(*ptr).p[j];
	      (*ptr).p[j]=(*ptr).p[j+1];
	      (*ptr).p[j+1]=temp;	      	      
	    }
	}
    }
}

int rech_decho(char per[], Annuaire a)
{
  int i=0 , debut=0 ,fin=0;
  bool found = false;
  fin = a.dernier;
  while (!found && debut<=fin)
    {
      i=((debut+fin)/2);
      if (strcmp(per,a.p[i].nom)==0)
	{
	  found = true;
	}
      else
	{
	  if (strcmp(per,a.p[i].nom)>0)
	    {
	      debut=i+1;
	    }
	  else
	    {
	      fin=i-1;
	    }
	}
    }
  
   if (found==true)
    {
      return i;
    }
  else
    {
      return (-1);
    }
}


void modif_numero (char per[], Annuaire* a)
{
  int i = rech_decho(per, *a);
  if (i>=0)
    {
      printf("Enter new number\n");
      scanf("%s", a->p[i].tel);
    }
  else
    {
      printf("Inconnu\n");
    }
}

void save (FILE* fw, Annuaire a)
{
  int i=0;
  while (i!=a.dernier)
    {
      fprintf(fw,"%s\n%s\n%s\n",a.p[i].nom,a.p[i].prenom,a.p[i].tel);
      fprintf(fw,"%d\n%d\n%d\n",a.p[i].dob.day,a.p[i].dob.month,a.p[i].dob.year);
      i++;
    }
}

int main(int argc, char* argv[])
{
  FILE *fp;
  FILE *fw;
  fw = fopen(argv[2],"w");
  fp = fopen(argv[1],"r");
  char nom[20];
  Annuaire annu;
  int boom;
  annu.dernier = 0;
  construire_annuaire(&annu, fp);
  affiche_annuaire(annu);
  printf("===========\n");
  printf("Enter name\n");
  scanf("%s",&nom);
  //boom=rech_decho(nom,annu);
  //if (boom>=0)
  //{
  //  affiche_personne(annu.p[boom]);
  //}
  //else
  //{
  //  printf("Inconnu\n");
  //}
  modif_numero(nom,&annu);
  save(fw,annu);
  fclose(fp);
}
