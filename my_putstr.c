/*
** my_putstr.c for  in /home/sanchezcarlos/semaine2.1/tests
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Thu Oct 20 10:47:03 2016 Carlos Jose Sanchez
** Last update Wed Dec  7 13:56:38 2016 Carlos Jose Sanchez
*/
#include <stdio.h>
#include "my_midgard.h"

void	my_putstr(char *str)
{
  int	counter;
  
  counter = 0;
  while (*(str + counter) != '\0')
    {
      my_putchar(*(str + counter));
      ++counter;
    }
}
/*
**int	main()
**{
**char *str;
**str = "b0njour ;";
**my_putstr(str);
**my_putchar('\n');
**return (0);
**}
*/
