/*
** my_strcmp.c for  in /home/sanchezcarlos/semaine2.2/tests
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Fri Oct 21 14:26:28 2016 Carlos Jose Sanchez
** Last update Thu Oct 27 15:51:40 2016 Carlos Jose Sanchez
*/
#include <stdio.h>

int	my_strcmp(char *s1, char *s2)
{
  int	counter;
  counter = 0;
  
  while ((s1[counter] != '\0') || (s2[counter] != '\0'))
    {
      if (s1[counter] < s2[counter])
	return (-1);
      if (s1[counter] > s2[counter])
	return (1);
      ++counter;
    }
  return (0);
}
/*
**int main ()
**{
**char *s1 = {"hello world"};
**char *s2 = {"hello worldd"};
**printf("%d\n", my_strcmp(s1, s2));
**return (0);
**}
*/
