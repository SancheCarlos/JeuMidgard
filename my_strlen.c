/*
** my_strlen.c for  in /home/sanchezcarlos/semaine2.1/tests
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Thu Oct 20 11:16:30 2016 Carlos Jose Sanchez
** Last update Thu Oct 20 23:29:13 2016 Carlos Jose Sanchez
*/
#include <stdio.h>

int	my_strlen(char *str)
{
  int counter;
  counter = 0;
  
  while (*(str+counter) != '\0')
    ++counter;
  return (counter);
}
/*
**int main ()
**{
**char str[15] = "Hello World";
**printf("%d\n",my_strlen(str));
**return (0);
**}
*/
