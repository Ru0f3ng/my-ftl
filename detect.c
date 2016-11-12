/*
** detect.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Sat Nov 12 10:18:20 2016 LIU Laurent
** Last update Sat Nov 12 12:48:03 2016 LIU Laurent
*/

#include "ftl.h"

t_freight       *create_freight()
{
  t_freight     *freight;
  int		rand;
  
  freight = malloc(sizeof(*freight));
  if (freight == NULL)
    return (0);
  rand = my_rand(100);
  if (rand < 70)
    freight->item = my_strdup("scrap");
  else
    {
      rand = my_rand(100);
      if (rand <= 33)
	freight->item = my_strdup("energy");
      else if (rand > 33 && rand <= 66)
	freight->item = my_strdup("attackbonus");
      else if (rand > 66 && rand <= 99)
	freight->item = my_strdup("evadebonus");
      else
	freight->item = my_strdup("scrap");
    }
  return (freight);
}

void			detect(t_ship *ship)
{
  t_freight		*freight;
  int			i;
  static int		d = -1;
  
  i = 0;
  if (d != ship->navigation_tools->sector)
    {
      d = ship->navigation_tools->sector;
      while (i < 10)
	{
	  freight = create_freight();
	  add_freight_to_container(ship, freight);
	  i++;
	}
      my_putstr_color("yellow", "Vous sortez votre pelle intergalactique et ");
      my_putstr_color("yellow", "cherchez les One Piece de l'espace...\n");
      my_putstr_color("green", "Vous avez trouvé des One Piece... YATAAAA!\n");
    }
  else
    {
      my_putstr_color("red", "vous avez déjà détecté cette zone, ");
      my_putstr_color("red", "petit poisson rouge!\n");
    }
}
