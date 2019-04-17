/*
** EPITECH PROJECT, 2018
** include functions
** File description:
** include functions
*/

struct variable{
    char **tbl;
    char **tbl2;
    char const *str;
    unsigned long nbr_column;
    unsigned long nbr_line;
    int len_first_line;
    int count_x;
    int count_o;
    int x_on_o;
    int i;
    int c;
    int t;
    int y;
};

typedef struct variable variable;

struct position{
    int x;
    int y;
};

typedef struct position position;

struct inc_map{
    int c;
    int rank_tbl;
};

typedef struct inc_map inc_map;

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int check_number(char *str);
int my_getnbr(char const *str);
void my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int nb_special(long nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
int low(char c);
int up(char c);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_str_isalpha(char *str);
char *my_str_islower(char *str);
char *my_str_isnum(char *str);
char *my_str_isprintable(char *str);
char *my_str_isupper(char *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int nb);
char *my_strstr(char *str, char *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void *infin_add(char *nb1, char *nb2);
int my_str_taller(char const *s1, char const *s2);
char *big_nb(char *nb1, char *nb2);
char *small_nb(char *nb1, char *nb2);
int my_str_is_equal(char *str1, char *str2);
void my_put_infinadd(int ret, char *nb, int type);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
variable nbrline(variable map);
variable nbrcolumn(variable map);
variable len(variable map);
inc_map str_array_fis(inc_map fis);
variable str_array(variable map, inc_map fis);
variable map_str(char const *str, variable map);
void x_in_angle(position *pos, variable *map);
void x_in_angle_two(position *pos, variable *map);
void x_in_angle_three(position *pos, variable *map);
void x_in_angle_four(position *pos, variable *map);
void mouv_haut_p(position *pos, variable *map);
void mouv_bas_p(position *pos, variable *map);
void mouv_gauche_p(position *pos, variable *map);
void mouv_droite_p(position *pos, variable *map);
void find_pos(position *pos, variable map);
variable check_char_nbr(variable map);
void redisp_o(variable *map);
int main(int ac, char **av);
void victory(variable *map);
void victory_two(variable *map);
void x_loose(variable *map);
int angle_one(variable *map, int count_x_keblo);
int angle_two(variable *map, int count_x_keblo);
int angle_three(variable *map, int count_x_keblo);
int angle_four(variable *map, int count_x_keblo);
inc_map str_array_sec(inc_map sec);
variable str_array_two(variable map, inc_map sec);
void usage(void);
void test_char_valid(variable map);
void vic_loose(variable map);