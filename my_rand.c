/*
** my_rand.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Fri Nov 11 11:10:40 2016 LIU Laurent
** Last update Sat Nov 12 12:51:41 2016 LIU Laurent
*/

#include "ftl.h"

int	my_rand(int n)
{
  int	random;

  random = (rand() % n) + 1;
  return (random);
}
