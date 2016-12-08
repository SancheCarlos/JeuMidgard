/*
** my_strdup.c for  in /home/sanchezcarlos/semaine3/jour01
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Mon Oct 24 22:19:38 2016 Carlos Jose Sanchez
** Last update Wed Nov  9 13:27:00 2016 Carlos Jose Sanchez
*/
#include <stdio.h>
#include <stdlib.h>
#include "ftl.h"

char	*my_strdup(char *str)
{
  char	*tab;
  
  tab = malloc((sizeof(*str) * my_strlen(str)) + 1);
  my_strcpy(tab, str);
  return (tab);
}
/*
**int main ()
**{
**char *tab = {"hello you"};
**char *new_str;
**new_str = my_strdup(tab);
**printf("valeur de new_str: %s\n", new_str);
**printf("adresse de str: %p\n", tab);
**printf("adresse de new_str: %p\n", new_str);  
**return (0);
**}
*/
