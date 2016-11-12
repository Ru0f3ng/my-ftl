/*
** air_shed.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 11:17:05 2016 LIU Laurent
** Last update Sat Nov 12 12:47:35 2016 LIU Laurent
*/

#include "ftl.h"

t_ship		*create_ship()
{
  t_ship	*ship;
  
  my_putstr_color("yellow", "construction du vaisseau en cours...\n");
  ship = malloc(sizeof(*ship));
  if (ship == NULL)
    {
      my_putstr_color("red", "le vaisseau n'a pas pu etre construit ");
      my_putstr_color("red", "par manque de materiaux...NOOB!\n");
      return NULL;
    }
  ship->hull = 50;
  ship->weapon = NULL;
  ship->ftl_drive = NULL;
  ship->navigation_tools = NULL;
  ship->container = NULL;
  ship->enemy = NULL;
  my_putstr_color("green", "amelioration du vaisseau termine!\n");
  return (ship);
}

int		add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*node;
  
  my_putstr_color("yellow", "ajout des armes en cours...\n");
  node = malloc(sizeof(*node));
  if (node == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose quand ");
      my_putstr_color("red", "vous avez tente d'ajouter les armes...NOOB!\n");
      return (0);
    }
  node->damage = 10;
  node->system_state = my_strdup("online");
  ship->weapon = node;
  my_putstr_color("green", "les armes ont ete ajoutes avec succes!\n");
  return (1);
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive	*node;
  
  my_putstr_color("yellow", "ajout du reacteur en cours...\n");
  node = malloc(sizeof(*node));
  if (node == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous ");
      my_putstr_color("red", "avez pose le reacteur...NOOB!\n");
      return (0);
    }
  node->energy = 10;
  node->system_state = my_strdup("online");
  ship->ftl_drive = node;
  my_putstr_color("green", "le reacteur a ete ajoute avec succes!\n");
  return (1);
}

int			add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*node;
  
  my_putstr_color("yellow", "ajout des outils de navigations...\n");
  node = malloc(sizeof(*node));
  if (node == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous");
      my_putstr_color("red", " avez pose les outils de navigations...NOOB!\n");
      return (0);
    }
  node->sector = 0;
  node->evade = 25;
  node->system_state = my_strdup("online");
  ship->navigation_tools = node;
  my_putstr_color("green", "les outils de navigations ont ete ajoutes ");
  my_putstr_color("green", "avec succes!\n");
  return (1);
}
