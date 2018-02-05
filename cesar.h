#ifndef CESAR_H
#define CESAR_H

/**
* La fonction ouverture fichier permet d'ouvrier un fichier dans un certain mode et retourne un pointeur vers le filestream
* @param fileName : Chaine de caractère définissant le fichier à ouvrir.
* @param mode : Chaine de caractère définissant le mode d'ouverture du fichier
* @return : Retourne un filepointeur sur le fichier ouvert
*/
FILE* ouvertureFichier(char* fileName, char* mode);

/**
* La fonction permet d'effectuer la fermetture d'un fichier ouvert
* @param pointeur : pointeur de fichier du fichier à fermer.
*/
void fermetureFichier(FILE* pointeur);

/**
* La fonction lecture effectue la lecture d'un fichier et calcule de décalage des lettres.
* @param pointeur : pointeur sur le fichier à lire
* @param tableau : pointeur du tableau de compteurs
* @return la valeur de la lettre la plus présente dans le fichier.
*/
int lecture(FILE* pointeur, int* tableau);

/**
* Vérifie si le pointeur de fichier est rendu à la fin du fichier.
* @param var : valeur de sortie de la lecture, FALSE si on de quitte pas, TRUE si on quitte
* @param pointeur : pointeur du fichier qu'on vérifie si on est rendu à la fin
* @return TRUE si la fin est ateinte, valeur entrée en paramètre si non
*/
short fin(short var, FILE* pointeur);

/**
* Écriture du fichier de sortie.
* @param in : nom du fichier d'entrée.
* @param out : nom du fichier de sortie.
* @param valeur : valeur de décalage.
*/
void ecriture(char* in, char* out, int valeur);

/**
* Compte les occurence de la lettre en paramère et incrémente les valeurs dans le tableau de compteur.
* @param tableau : tableau de compteurs
* @param caractere : lettre à vérifier
*/
void compteur(int* tableau, char* caractere);

/**
* Trouver la valeur maximale dans le tableau de compteurs
* @param tableau : pointeur du tableau de compteurs
* @return la position la plus élevée
*/
int getMax(int* tableau);

/**
* Décale une lettre selon la veleur entrée en paramètre
* @param code : lettre à décaler
* @param decode : valeur de décalage
* @return le caractère décodé
*/
char decaler(char* code, int decode);

/**
* Décode une lettre, vérifie qu'elle est bien entre deux lettres spécifiées en tenant compte de la valeur de décalage
* @param input : lettre à décoder
* @param max : lettre maximale
* @param min : lettre minimale
* @param decal : valeur de décalage
* @return la lettre décodée
*/
char decoder(char input, char max, char min, int decal);

/**
* Type boolean, FALSE = 0 TRUE = 1
*/
enum Boolean_t {FALSE,TRUE};

#endif