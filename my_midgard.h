#ifndef __FTL_H_
#define __FTL_H_

struct s_creature;

typedef struct  s_creature
{
  char        *name;
  int        lvl;
  int        pv;
  int        pvmax;
  int        pm;
  int        pmmax;
  struct s_creature *next;
  struct s_creature *prev;
}        t_creature;

typedef struct s_backpack
{
  int quantity;
  struct s_creature *first;
  struct s_creature *last;
} t_backpack;

typedef struct s_personage
{
  char *name;
  int pv;
  char *status;
  t_backpack *team;
  char *mode;
} t_personage;

t_creature *getCreature();
void	my_putchar(char c);
void	my_putstr(char *str);
void	creature_description(t_creature *beast);
void	my_putstr_color(const char *color, const char *str);
int	add_creature_to_team(t_personage *personage, t_creature *creature);
//int	del_creature_to_team(t_personage *personage, t_creature *creature);
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);
int	my_strcpy(char *s1, char *s2);
char *my_strdup(const char *str);
int	functions_jeu(int arret, char *orders, t_creature *beast, t_personage *personage);
int	create_team(t_personage *personage);
char	*readline(void);
char	*my_itoa(int a);
int	functions_Oob(int arret, t_personage *personage, char *orders);
int	functions_Ib(int arret, t_personage *personage, char *orders);
t_creature	*show_creature(t_personage *personage);
int magic_box_use(t_personage *personage, t_creature *beast);
int character_options(int arret, t_personage *personage, t_creature *beast);
int midgardmon_options(int arret, t_personage *personage, t_creature *beast);
t_creature *beast_attack(t_personage *personage, t_creature *beast);
void Oob_options();
#endif
