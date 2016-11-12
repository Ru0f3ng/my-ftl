/*
** container.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 17:46:59 2016 LIU Laurent
** Last update Sat Nov 12 12:46:55 2016 LIU Laurent
*/

#include "ftl.h"
#include <stdio.h>

int		add_container_to_ship(t_ship *ship)
{
  t_container	*node;
  
  my_putstr_color("yellow", "ajout du container en cours...\n");
  node = malloc(sizeof(*node));
  if (node == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque ");
      my_putstr_color("red", "vous avez pose le container\n");
      return (0);
    }
  node->first = NULL;
  node->last = NULL;
  node->nb_elem = 0;
  ship->container = node;
  my_putstr_color("green", "le container a ete ajoute avec succes!\n");
  return (1);
}

void	add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if (ship->container->first == NULL && ship->container->last == NULL)
    {
      ship->container->first = freight;
      ship->container->last = freight;
      freight->prev = NULL;
      freight->next = NULL;
    }
  else
    {
      ship->container->last->next = freight;
      freight->prev = ship->container->last;
      ship->container->last = freight;
      freight->next = NULL;
    }
  ship->container->nb_elem++;
}

void	del_freight_from_container(t_ship *ship, t_freight *freight)
{
  if (freight->prev == NULL && freight->next == NULL)
    {
      ship->container->first = NULL;
      ship->container->last = NULL;
    }
  else if (freight->prev == NULL)
    {
      ship->container->first = freight->next;
      ship->container->first->prev = NULL;
    }
  else if (freight->next == NULL)
    {
      ship->container->last = freight->prev;
      ship->container->last->next = NULL;
    }
  else
    {
      freight->next->prev = freight->prev;
      freight->prev->next = freight->next;
    }
  free(freight);
  ship->container->nb_elem--;
}

void		get_bonus(t_ship *ship)
{
  t_freight	*tmp;
  
  if (ship->container->nb_elem == 0)
    my_putstr_color("red", "ya rien, tu fais quoi? oyo oyo\n");
  while (ship->container->nb_elem > 0)
    {
      if ((my_strcmp(ship->container->first->item, "attackbonus")) == 0)
	{
	  ship->weapon->damage += 5;
	  my_putstr_color("blue", "attack +5\n");
	}
      else if ((my_strcmp(ship->container->first->item, "evadebonus")) == 0)
	{
	  ship->navigation_tools->evade += 3;
	  my_putstr_color("blue", "evade +3\n");
	}
      else if ((my_strcmp(ship->container->first->item, "energy")) == 0)
	{
	  ship->ftl_drive->energy++;
	  my_putstr_color("blue", "energy +3\n");
	}
      tmp = ship->container->first;
      ship->container->first = ship->container->first->next;
      del_freight_from_container(ship, tmp);
    }
}
