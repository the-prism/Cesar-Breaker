#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

FILE* ouvertureFichier(char* fileName, char* mode);
void fermetureFichier(FILE* pointeur);
int lecture(FILE* pointeur, int* tableau);
short fin(short var, FILE* pointeur);
void ecriture(char* in, char* out, int valeur);
void compteur(int* tableau, char* caractere);
int getMax(int* tableau);
char decaler(char* code, int decode);
char decoder(char input, char max, char min, int decal);

enum Boolean_t {FALSE,TRUE};

int main(int argc, char** argv)
{
  FILE* typewriter;
  int alphabet[26] = {0};
  int decalage;
  if(argc != 3)
  {
    printf("%s\n", "Nombre d'arguments invalide, fermetture du programme");
    exit(1);
  }
  typewriter = ouvertureFichier(argv[1], "r");
  decalage = lecture(typewriter, alphabet) - 4;
  fermetureFichier(typewriter);
  ecriture(argv[1], argv[2], decalage);
  printf("%s Decalage = %d\n", "Fin du programme sauvegarde", decalage);
  printf("%s\n", "Terminé !");
  return 0;
}

FILE* ouvertureFichier(char* fileName, char* mode)
{
  FILE* pointeur;
  pointeur = fopen(fileName, mode);
  if (pointeur == NULL)
  {
    printf("Erreur avec le fichier d'entrée : %d\n", errno);
    exit(1);
  } else {
    return pointeur;
  }
}

void fermetureFichier(FILE* pointeur)
{
  int fermetture;
  fermetture = fclose(pointeur);
  if (fermetture != 0)
  {
    printf("Erreur lors de la fermeture du fichier : %d\n", errno);
    exit(1);
  }
}

int lecture(FILE* pointeur, int* tableau)
{
  short sortie = FALSE;
  int buffer;
  char lettre;
  char* pbuffer;
  int decalage = 0;
  while (sortie == FALSE)
  {
    buffer = fgetc(pointeur);
    sortie = fin(sortie, pointeur);
    if(sortie == FALSE)
    {
      lettre = buffer;
      pbuffer= &lettre;
      compteur(tableau, pbuffer);
      decalage = getMax(tableau);
    }
  }
  return decalage;
}

short fin(short var, FILE* pointeur)
{
  if(feof(pointeur))
  {
    var = TRUE;
  }
  return var;
}

void compteur (int* tableau, char* caractere)
{
  int* pointeur = tableau;
  char value = *caractere;
  int decalage = 0;
  if(*caractere <= 'Z' && *caractere >= 'A')
  {
    decalage = value - 65;
    pointeur = pointeur + decalage;
    *pointeur = *pointeur + 1;
  }
  else if (*caractere <= 'z' && *caractere >= 'a')
  {
    decalage = value - 97;
    pointeur = pointeur + decalage;
    *pointeur = *pointeur + 1;
  }
}

int getMax(int* tableau)
{
  int* pointeur;
  int i, valeur = 0;
  pointeur = tableau;
  for (i = 1; i < 26; ++i)
  {
    if(*pointeur < tableau[i])
    {
      pointeur = &tableau[i];
      valeur = i;
    }
  }
  return valeur;
}

void ecriture(char* in, char* out, int valeur)
{
  FILE* input;
  FILE* output;
  short sortie = FALSE;
  int buffer;
  char lettre;
  char* pbuffer;
  input = ouvertureFichier(in, "r");
  output = ouvertureFichier(out, "w");
  while (sortie == FALSE)
  {
    buffer = fgetc(input);
    sortie = fin(sortie, input);
    if(sortie == FALSE)
    {
      lettre = buffer;
      pbuffer= &lettre;
      lettre = decaler(pbuffer, valeur);
      fputc(lettre,output);
    }
  }
  fermetureFichier(input);
  fermetureFichier(output);
}

char decaler(char* code, int decode)
{
  char final;
  final = *code;
  if(final <= 'Z' && final >= 'A')
  {
    final = decoder(final, 'Z', 'A', decode);
  }
  else if (final <= 'z' && final >= 'a')
  {
    final = decoder(final, 'z', 'a', decode);
  }
  return final;
}

char decoder(char input, char max, char min, int decal)
{
  char temp;
  input = input - decal;
  if(input < min)
  {
    temp = input - min + 1;
    input = max + temp;
  }
  else if(input > max)
  {
    temp = input - max + 1;
    input = max - temp;
  }
  return input;
}