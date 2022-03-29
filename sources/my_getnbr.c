/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** fake function
*/

int finding_other(char const *str, int i, int nbr)
{
    while (str[i] >= '0' && str[i] <= '9' && nbr < 0) {
        nbr = nbr * 10 - (str[i] - '0');
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && nbr > 0) {
        nbr = nbr * 10 + (str[i] - '0');
        i++;
    }
    return (nbr);
}

int finding_nbr(char const *str, int i)
{
    int nbr = 0;
    int neg = 0;

    if (i != 0 && str[i] >= '0' && str[i] <= '9') {
        if (str[i - 1] == '-') {
            nbr = -(str[i] - '0');
            neg = 1;
            i++;
        }
    }
    if (str[i] >= '0' && str[i] <= '9' && neg == 0) {
        nbr = str[i] - '0';
        i++;
    } else if (!(str[i] >= '0' && str[i] <= '9') && nbr < 0)
        return (nbr);
    return (finding_other(str, i, nbr));
}

int getnbr(char const *str, int i)
{
    if (str[i] == '-' || str[i] == '+')
        return (finding_nbr(str, i + 1));
    return (0);
}

int my_getnbr(char const *str)
{
    int res;

    for (int i = 0; str[i] != '\0'; i++) {
        res = getnbr(str, i);
        if (res != 0)
            return (res);
        if (str[i] >= '0' && str[i] <= '9')
            return (finding_nbr(str, i));
    }
    return (0);
}
