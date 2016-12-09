/*
** fight.c for  in /home/sanchezcarlos/projetMidgard
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Fri Dec  9 01:40:09 2016 Carlos Jose Sanchez
** Last update Fri Dec  9 03:23:08 2016 Carlos Jose Sanchez
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_midgard.h"


t_creature *beast_attack(t_personage *personage, t_creature *beast)
{
  int random;
  t_creature *champion;
  
  champion = personage->team->first;
  random = (rand()% 100) + 1;
  if (random <= 25)
    {
      if (beast->pm >= 3)
	{
	  beast->pm -= 3;
	  champion->pv -= 15;
	  my_putstr_color("red","Vous perdez 15 PV\n");
	}else
	my_putstr_color("yellow", "La creature n'as pas sufissamment de PM\n");
    } else if ((random > 25) && (random <= 50))
    {
      if (beast->pm >= 7)
	{
	  beast->pm -= 7;
	  champion->pv -= 30;
	  my_putstr_color("red","Vous perdez 30 PV\n"); 
	}else
	my_putstr_color("yellow", "La creature n'as pas sufissamment de PM\n");
    } else if ((random > 50) && (random <= 75))
    {
      random = (rand()% 100) + 1;
      if (random <= 50)
	{
	  random = (rand()% 20) + 1;
	  beast->pv -= random;
	  my_putstr_color("green","La creature s'est auto-attaque\n"); 
	}else if ((random > 50) && (random <= 100))
        {
	  random = (rand()% 20) + 1;
	  champion->pv -= random;
	  my_putstr_color("red","La creature vous a attaque avec gamble\n");
	}
    } else if ((random > 75) && (random <= 100))
    {
      beast->pv += 10;
      my_putstr_color("red", "La creature vous a attaque\n");
    }
  personage->team->first = champion;
  return (beast);
}
/*
int function_fight(beast)
{
  t_creature *champion;

  champion = personage->team->first;
  while ((beast->pv > 0) || (champion->pv > 0))   
    {
      if (my_strcmp(attaque, "slash") == 0)	
	{
	  if (champion->pm >= 3)
	    {
	      champion->pm -= 3;
	      beast->pv -= 15;
	      my_putstr_color("green","Vous perdez 3MP et faites 15 dégats\n");
	    }else
	    my_putstr_color("yellow", "Vouz n'avez suffisamment de PM\n");
	}
      else if (my_strcmp(attaque, "fire") == 0)
	{
	  if (champion->pm >= 7)
	    {
	      champion->pm -= 7;
	      beast->pv -= 30;
	      my_putstr_color("green","Vous perdez 7MP et faites 30 dégats\n"); 
	    }else
	    my_putstr_color("yellow", "Vouz n'avez suffisamment de PM\n");
	}
      else if (my_strcmp (attaque, "gamble") == 0)
	{
	  int adverssaire; 
	  int lanceur;
	  
	  srand (time (NULL));
	  random = (rand()% 100) + 1;
	  vie = random;
	  if (vie >= 50)
	    {
	      champion->pv -= 20;
	      my_putstr_color("green", "Vous perdez 20 points de vie, ");
	      my_putstr_color("green", "votre adverssaire 0\n"); 
	    }
	  else if (vie <= 50)			  
	    {
	      beast->pv -= 20;
	      my_putstr_color("green","Votre adverssaire");
	      my_putstr_color("green"," à perdu 20 point de vie.\n");
	    }
	}
      else if (my_strcmp (attaque, "rest") == 0)
	{
	  champion->pv += 10;
	  my_putstr_color("green", "Vous avez récupéré 10 PV\n"); 
	}
      else
	{
	  my_putstr("Veuillez choisir une attaque parmis : \n");
	  my_putstr("- slash \n");
	  my_putstr("- fire \n");
	  my_putstr("- gamble \n");
	  my_putstr("- rest \n");
	}
    }
  if (champion->pv <= 0)
    return (1);
  else
    return (0);
}
*/
