/*
** team.c for  in /home/sanchezcarlos/projetMidgard
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Wed Dec  7 14:29:45 2016 Carlos Jose Sanchez
** Last update Fri Dec  9 02:52:06 2016 Carlos Jose Sanchez
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

t_creature *show_creature(t_personage *personage)
{
  t_creature *beast;
  
  my_putstr("\n");
  beast = getCreature();
  my_putstr_color("red", beast->name);
  my_putstr_color("red", " apparu! \n");
  personage->mode = my_strdup("Ib");
  return (beast);
}

int magic_box_use(t_personage *personage, t_creature *beast)
{
  int random;
  
  my_putstr_color("yellow", "Vous utilisez une magic box...\n");
  random = (rand() % 100) + 1;
  if (random <= 30)
    {
      beast->pv *= 2;
      beast->pm *= 2;
      beast->pvmax *= 2;
      beast->pmmax *= 2;
      add_creature_to_team(personage, beast);
      my_putstr_color("green", personage->name);
      my_putstr_color("green", " Vous avez reussi a capturer ");
      my_putstr_color("red", beast->name);
      my_putstr("\n\n\n");
      creature_description(beast);
      personage->mode = my_strdup("Oob");
    }else
    {
      my_putstr_color("red", beast->name);
      my_putstr_color("red", " a reussi a sortir de la magic box!\n");
      my_putstr_color("red", beast->name);
      my_putstr_color("red", " sauvage vous a attaque! \n");
      if (my_strcmp(personage->mode, "start") == 0)
	{
	  my_putstr_color("red", "et vous etes effraye\n");
	  my_putstr_color("yellow", "Vous fuyez!\n");
	} else if (my_strcmp(personage->mode, "Ib") == 0)
	beast = beast_attack(personage, beast);
    }
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
