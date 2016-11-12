/*
** my_put_nbr.c for  in /home/laurent/piscine/Jour05/my_put_nbr
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Sat Oct 22 19:20:01 2016 LIU Laurent
** Last update Sat Nov 12 12:51:26 2016 LIU Laurent
*/

#include "ftl.h"

void	my_putchar(char c);
int	powmax(int n);

int	powmax(int n)
{
  int	p;

  p = 1;
  while (n >= 10)
    {
      p = p * 10;
      n = n / 10;
    }
  return (p);
}

void	my_put_nbr(int n)
{
  int	tmp;
  int	pow;

  tmp = 0;
  if (n < 0)
    {
      my_putchar('-');
      n = n * -1;
    }
  pow = powmax(n);
  while (pow > 0)
    {
      tmp = n / pow;
      tmp = tmp % 10;
      my_putchar(tmp + 48);
      pow = pow / 10;
    }
}
