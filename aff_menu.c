/*
** stats.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Fri Nov 11 14:45:51 2016 LIU Laurent
** Last update Sat Nov 12 12:46:23 2016 LIU Laurent
*/

#include "ftl.h"

void	aff_help(t_ship *ship)
{
  (void)ship;
  my_putstr_color("yellow", "Liste des commandes disponibles :\n");
  my_putstr("attack\n");
  my_putstr("detect\n");
  my_putstr("jump\n");
  my_putstr("getbonus\n");
  my_putstr("controlsystem\n");
  my_putstr("repairsystem\n");
  my_putstr("stats\n");
  my_putstr("help\n");
}

void	aff_stats(t_ship *ship)
{
  my_putstr_color("yellow", "spaceship informations :\n");
  my_putstr_color("magenta", " | hull : ");
  my_put_nbr(ship->hull);
  my_putstr_color("magenta", "\n | damage : ");
  my_put_nbr(ship->weapon->damage);
  my_putstr_color("magenta", "\n | energy : ");
  my_put_nbr(ship->ftl_drive->energy);
  my_putstr_color("magenta", "\n | sector : ");
  my_put_nbr(ship->navigation_tools->sector);
  my_putstr_color("magenta", "\n | evade : ");
  my_put_nbr(ship->navigation_tools->evade);
  my_putstr("\n");
}

void    intro()
{
  my_putstr_color("clear", "");
  my_putstr_color("red", "   *        )   (          (\n");
  my_putstr_color("red", " (  `    ( /(   )\\ )  *   ))\\ )\n");
  my_putstr_color("red", " )\\))(   )\\()) (()/(` )  /(()/(\n");
  my_putstr_color("red", "((_)()\\ ((_)\\   /(_))( )(_))(_))\n");
  my_putstr_color("red", "(_()((_)_ ((_) (_))_(_(_())_))\n");
  my_putstr_color("yellow", "|  \\/  \\ \\ / / | |_ |_   _| |\n");
  my_putstr_color("yellow", "| |\\/| |\\ V /  | __|  | | | |__\n");
  my_putstr_color("yellow", "|_|  |_| |_|_____|    |_| |____|\n");
  my_putstr_color("yellow", "           |_____|                \n");
  my_putstr("\n");
  my_putstr("\n");
  my_putstr_color("yellow", "Vous pouvez à tout moment utiliser la commande");
  my_putstr_color("yellow", " \"help\" pour connaitre la liste des");
  my_putstr_color("yellow", " commandes disponibles\n");
  my_putstr_color("yellow", "(Cependant, vous devez savoir que ca vous couter\
a une action)\n");
  my_putstr("\n");
  my_putstr("\n");
}
