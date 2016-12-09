/*
** my_itoa.c for  in /home/sanchezcarlos/projetMidgard
** 
** Made by Carlos Jose Sanchez
** Login   <sanche_c@etna-alternance.net>
** 
** Started on  Thu Dec  8 22:10:34 2016 Carlos Jose Sanchez
** Last update Thu Dec  8 22:28:56 2016 Carlos Jose Sanchez
*/
#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int a)
{
  char const digit[] = "0123456789";
  char *b;
  int temp;
  
  b = malloc(sizeof(*b));
  if (a < 0)
    {
      *b++ = '-';
      a = a * -1;
    }
  temp = a;
  do
    {
      ++b;
      temp = temp/10;
    } while(temp);
  *b = '\0';
  do
    {
      *--b = digit[a%10];
      a = a/10;
    } while(a);
  return (b);
}
