/*
** team.c for  in /home/sanchezcarlos/projetMidgard
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Wed Dec  7 14:29:45 2016 Carlos Jose Sanchez
** Last update Wed Dec  7 22:17:58 2016 Carlos Jose Sanchez
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_midgard.h"

//return 0 succes, return 1 erreur
int create_team(t_personage *personage)
{
  t_backpack *team;

  my_putstr_color("yellow", "Creation de mon equipe... \n");
  team = malloc(sizeof(*team));
  if (team == NULL)
    {
      my_putstr_color("red", "Impossible de creer un equipe \n");
      return (-1);
    }
  team->first = NULL;
  team->last = NULL;
  team->quantity = 0;
  personage->team = team;
  my_putstr_color("green", "Votre equipe a ete cree\n");
  return (0);
}

int add_creature_to_team(t_personage *personage, t_creature *creature)
{
  if (personage->team->first == NULL)
    {
      personage->team->first = creature;
      personage->team->last = creature;
    } else
    {
      creature->prev = personage->team->last;
      personage->team->last->next = creature;
      personage->team->last = creature;
    }
  ++personage->team->quantity;
  my_putstr_color("green", "La creature a ete ajoute a votre equipe \n");
  return (0);
}
/*
int del_creature_from_team(t_personage *personage, t_creature *creature)
{
  if (creature == personage->equipe->first)
    {
      personage->equipe->first = creature->next;
      if (personage->equipe->quantity > 1)
	personage->equipe->first->prev = NULL;
    }
  if (creature == personage->equipe->last)
    {
      personage->equipe->last = creature->prev;
      if (personage->equipe->quantity > 1)
	personage->equipe->last->next = NULL;
    }
  else
    {
      if (creature->prev != NULL)
	creature->prev->next = creature->next;
      if (creature->next != NULL)
	creature->next->prev = creature->prev;
    }
  free(creature);
  return (0);
}
*/
