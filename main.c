/*
** main.c for  in /home/sanchezcarlos/projetMidgard
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Mon Dec  5 15:44:30 2016 Carlos Jose Sanchez
** Last update Thu Dec  8 23:30:33 2016 Carlos Jose Sanchez
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_midgard.h"

int main(int argc,char **argv) {
  int arret;
  char *orders;
  t_personage *personage;
  t_creature *beast;
  
  arret = 0;
  if (argc == 3) {
    if (my_strcmp(*(argv + 1), "-n") == 0) {
      my_putstr("Bonjour, ");
      my_putstr(*(argv + 2));
      my_putstr("\n");
      personage = malloc (sizeof(*personage));
      if (personage == NULL)
	{
	  my_putstr_color("red","Erreur a l'heure de creation du personage");
	  return (1);
	}
      personage->name = my_strdup(*(argv + 2));
      personage->pv = 50;
      arret = create_team(personage);
      personage->mode = my_strdup("Start");
      while (arret != 1)
    {
      if ((my_strcmp(personage->mode, "Start") == 0) && (arret != 3))
	{
	  beast = getCreature();
	  my_putstr_color("red", beast->name);
	  my_putstr_color("red", " apparu! \n");
	}
      my_putstr(beast->name);
      my_putstr(personage->mode);
      my_putstr_color("magenta", "\norders~>");
      orders = readline();
      arret = functions_jeu(arret, orders, beast, personage);
    }
    }else {
      my_putstr("le flag ne correspond pas a une option (-n) \n");
      return (0);
    }
  } else {
    my_putstr("envoyer le flag -n suivi de votre prenom pour commencer\n");
    return (0);
  }
  return (0);
}
