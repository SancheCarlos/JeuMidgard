/*
** options.c for  in /home/sanchezcarlos/projetMidgard
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Fri Dec  9 02:39:40 2016 Carlos Jose Sanchez
** Last update Fri Dec  9 02:45:55 2016 Carlos Jose Sanchez
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_midgard.h"

void Oob_options()
{
  my_putstr_color("blue", "\n- team\n- you are the chosen one\n- lets fight");
  my_putstr_color("blue", "\n- exit\n\n");
}

void attack_options()
{
  my_putstr_color("blue", "\n- slash\n- fire\n- gamble\n- rest\n\n");
}

void creature_description(t_creature *beast)
{
  char *temp;

  //function beast img
  my_putstr_color("green", beast->name);
  my_putstr("\n");
  my_putstr_color("blue", "_______________\n");
  my_putstr_color("blue", "|  ");
  my_putstr_color("green", "PV  ");
  my_putstr_color("blue", "|  ");
  temp = my_itoa(beast->pvmax);
  my_putstr_color("green", temp);
  my_putstr_color("blue", "  |");
  my_putstr("\n");
  my_putstr_color("blue", "|  ");
  my_putstr_color("green", "PM  ");
  my_putstr_color("blue", "|  ");
  temp = my_itoa(beast->pmmax);
  my_putstr_color("green", temp);
  my_putstr_color("blue", "  |\n");
  my_putstr_color("blue", "|______|______|\n");
}
