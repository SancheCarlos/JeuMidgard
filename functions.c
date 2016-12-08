/*
** functions.c for  in /home/sanchezcarlos/projetMidgard
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Wed Dec  7 18:09:59 2016 Carlos Jose Sanchez
** Last update Wed Dec  7 23:01:18 2016 Carlos Jose Sanchez
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_midgard.h"

int functions_jeu(int arret, char *orders, t_creature *beast, t_personage *personage) {
  int random;
  
  if (my_strcmp(orders, "exit") == 0) {
    return (1);
  }else if (my_strcmp(orders, "magic box") == 0) {
    random = (rand() % 100) + 1;
    printf("%d\n", random);
    if (random <= 30)
      {
	add_creature_to_team(personage, beast);
	my_putstr_color("green", personage->name);
	my_putstr_color("green", " Vous avez reussi a capturer ");
	my_putstr_color("red", beast->name);
	my_putstr("\n\n\n");
	my_putstr("description (en cours)");
      }else
      {
	my_putstr_color("red", beast->name);
	my_putstr_color("red", " sauvage vous a attaque! et vous etes effraye\n");
	my_putstr_color("yellow", "Vous fuyez!\n");
	return (5);
      }
    return (0);
  }else if (my_strcmp(orders, "help me !!!") == 0) {
    my_putstr_color("yellow", "Vous fuyez!\n");
    return (5);
  }
  return (arret);
}
