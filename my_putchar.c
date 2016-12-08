/*
** my_putchar.c for  in /home/sanchezcarlos/exosC
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Mon Oct 17 11:45:14 2016 Carlos Jose Sanchez
** Last update Wed Dec  7 13:56:59 2016 Carlos Jose Sanchez
*/
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
