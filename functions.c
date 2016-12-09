/*
** functions.c for  in /home/sanchezcarlos/projetMidgard
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Wed Dec  7 18:09:59 2016 Carlos Jose Sanchez
** Last update Fri Dec  9 03:21:27 2016 Carlos Jose Sanchez
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_midgard.h"

int functions_jeu(int arret, char *orders, t_creature *beast, t_personage *personage) {
  if (my_strcmp(personage->mode, "Start") == 0)
    {
      if (my_strcmp(orders, "exit") == 0) {
	return (1);
      }else if (my_strcmp(orders, "magic box") == 0) {
	arret = magic_box_use(personage, beast);
	return (arret);
      }else if (my_strcmp(orders, "help me !!!") == 0) {
	my_putstr_color("yellow", "Vous fuyez!\n");
	return (0);
      }else
	{
	  arret = 3;
	  my_putstr("Cette option n'existe pas");
	}
    }
  else if (my_strcmp(personage->mode, "Oob") == 0)
    {
      arret = functions_Oob(arret, personage, orders);
    }
  else if (my_strcmp(personage->mode, "Ib") == 0)
    {
      arret = functions_Ib(arret, personage, orders);
    }
  return (arret);
}

int	functions_Oob(int arret, t_personage *personage, char *orders)
{
  t_creature *temp;
  
  while (my_strcmp(personage->mode, "Oob") == 0)
    {
      Oob_options();
      my_putstr_color("magenta", "\norders~>");
      orders = readline();
      if (my_strcmp(orders, "team") == 0)
	{
	  temp = personage->team->first;
	  while (temp)
	    {
	      creature_description(temp);
	      temp = temp->next;
	      my_putstr("\n\n");
	    }
	} else if (my_strcmp(orders, "you are the chosen one") == 0)
	{
	  my_putstr_color("yellow", "Vous allez jouer avec ");
	  my_putstr_color("yellow", personage->team->first->name);
	} else if (my_strcmp(orders, "lets fight") == 0)
	{
	  arret = functions_Ib(arret, personage, orders);
	} else if (my_strcmp(orders, "exit") == 0)
	{
	  return (1);
	} else
	{
	  my_putstr_color("red","option non valide\n");
	}
    }
  return (arret);
}

int functions_Ib(int arret, t_personage *personage, char *orders)
{
  t_creature *beast;

  beast = show_creature(personage);
  while (my_strcmp(personage->mode, "Ib") == 0)
    {
      if (personage->team->first->pv > 0)
	{
	  my_putstr_color("yellow", "\npersonage ou midgardmon?");
	  my_putstr_color("magenta", "\norders~>");
	  orders = readline();
	  if (my_strcmp(orders, "personage") == 0)
	    {
	      arret = character_options(arret, personage, beast);
	    }
	  else if (my_strcmp(orders, "midgardmon") == 0)
	    {
	      arret = midgardmon_options(arret, personage, beast);
	      beast = beast_attack(personage, beast);
	    }
	  else
	    my_putstr_color("red", "commande inconnu\n");
	}else
	{
	  my_putstr_color("red", "votre creature ne peut pas continuer\n");
	  creature_description(personage->team->first);
	  personage->mode = my_strdup("Oob");
	}
    }
  return (arret);
}
 
int character_options(int arret, t_personage *personage, t_creature *beast)
{
  char *orders;
  
  my_putstr_color("yellow", "magic catch ou fuir?");
  my_putstr_color("magenta", "\norders~>");
  orders = readline();
  if (my_strcmp(orders, "magic catch") == 0)
    {
      arret = magic_box_use(personage, beast);
      
    }else if (my_strcmp(orders, "fuir") == 0)
    {
      my_putstr_color("yellow", "Vous fuyez\n");
      personage->mode = my_strdup("Oob");
    }else
    {
      my_putstr_color("red", "commande inconnu\n");
      arret = character_options(arret, personage, beast);
    }
  return (arret);
}

int midgardmon_options(int arret, t_personage *personage, t_creature *beast)
{
  char *orders;

  creature_description(personage->team->first);
  creature_description(beast);
  my_putstr_color("yellow", "slash, fire, gamble ou rest?");
  my_putstr_color("magenta", "\norders~>");
  orders = readline();
  if (my_strcmp(orders, "slash") == 0)
    {
      //slash funnction
    }else if (my_strcmp(orders, "fire") == 0)
    {
      //fire function
    }else if (my_strcmp(orders, "gamble") == 0)
    {
      //gamble function
    }else if (my_strcmp(orders, "rest") == 0)
    {
      //rest function
    }else
    {
      my_putstr_color("red", "commande inconnu\n");
      arret = midgardmon_options(arret, personage, beast);
    }
  if (beast->pv > 0)
    beast = beast_attack(personage, beast);
  else
    my_putstr_color("green", "votre ennemie peut pas continuer, vous gagnez\n");
  return (arret);
}
/*
int choose_midgardmon(t_personage *personage, int arret)
{
  t_creature *temp;
  int cont;
  static t_choices g_choices[] =
    {
      {1, "premiere"},
      {2, "deuxieme"},
      {3, "troisieme"},
      {4, "quatrieme"},
      {5, "cinquieme"}
    };

  cont = 0;
  temp = personage->team->first;
  while (temp)
    {
      if (cont == g_choices[cont].i)
	my_putstr_color("blue", "premiere\n");
      else if (cont == g_choices[cont].i)
	my_putstr_color("blue", "deuxieme\n");
       else if (cont == g_choices[cont].i)
	my_putstr_color("blue", "troisieme\n");
       else if (cont == g_choices[cont].i)
	my_putstr_color("blue", "quatrieme\n");
       else if (cont == g_choices[cont].i)
	my_putstr_color("blue", "cinquieme\n");
      ++cont;
      creature_description(temp);
      temp = temp->next;
      my_putstr("\n\n");
    }
  my_putstr_color("yellow", "Choisisez votre creature (premiere a cinquieme)\n");
  my_putstr_color("magenta", "option~>");
  option = readline();
  cont = 0;
  while (cont <= 5)
    {
      if (my_strcmp(option, g_choices[cont].number) == 0)
	{
	  if (option != "premiere")
	    set_first_midgardmon(personage, cont);
	  if (cont == 5)
	    {
	      my_putstr_color("red", "commande inconnu\n");
	      arret = choose_midgardmon(personage, arret);
	    }
	}
      ++count;
    }
  return (arret);
}

int set_first_midgardmon(t_personage *personage,int cont)
{
  t_creature *temp;
  int tmp;

  tmp = 0;
  temp = personage->team->first;
  while (temp)
    {
      if (cont == tmp)
	{
	  if (temp == personage->team->last)
	    {
	    }else
	    {
	      temp->prev = temp->next->prev;
*/
