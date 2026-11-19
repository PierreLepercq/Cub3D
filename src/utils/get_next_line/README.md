*This project has been created as part of the 42 curriculum by llepesqu.*

# get_next_line

## Description

Le projet **get_next_line** a pour objectif d’implémenter une fonction en C capable de lire une ligne complète depuis un descripteur de fichier, et ce, **appel par appel**.

La fonction doit retourner une ligne terminée par un `\n` (si présent) ou la fin du fichier, tout en conservant son état entre plusieurs appels.  
Ce projet introduit la gestion de buffers statiques, la lecture avec `read()`, ainsi que la manipulation de chaînes et de la mémoire dynamique.

Prototype de la fonction :
```c
char *get_next_line(int fd);
```

## Instructions

### Fichiers

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

### Compilation

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

### Utilisation

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

### Bonus

La version bonus permet :
- La gestion de plusieurs descripteurs de fichiers simultanément
- L’utilisation d’un tableau statique indexé par `fd`

## Algorithm & Technical Choices

### Principe général

L’algorithme repose sur l’utilisation d’un buffer statique qui conserve les données lues entre deux appels à `get_next_line`.

1. Lecture depuis le fichier avec `read()`
2. Recherche du caractère `\n`
3. Extraction de la ligne complète
4. Nettoyage et mise à jour du buffer
5. Gestion correcte de la fin de fichier

Reutilisation des fonctions ft_strlen, ft_strdup, ft_strjoin de libft.

-> ft_strdup devient `` char	*ft_strndup(char *src, unsigned int n)``

elle duplique n bytes de src dans un nouveau ptr.

-> `` void	update_stash(char **stash, char *buf, int size)``

initialise si inexistante ou ajoute le buffer a la stash.

-> `` int	read_until_newline(int fd, char **stash, char *buf)``

read jusqu'a croiser un \n ou l'eof, puis update_stash en consequence.

-> `` char	*extract_line(char **stash, int index)``

retourne la ligne en fonction de l'index de \n, index = -1 signifie qu'il n'y a pas de \n dans la stash. Si eof, retourne la stash puis la vide.



### Justification

- Le buffer statique permet de conserver l’état entre les appels
- La lecture par blocs optimise les performances
- La séparation claire des étapes améliore la lisibilité
- La gestion rigoureuse de la mémoire évite les fuites

## Resources

### Références

- `man 2 read`
- `man 3 malloc`
- `man 3 free`
- Documentation officielle 42
- https://en.cppreference.com/w/c/io

### Utilisation de l’IA

L’IA (ChatGPT) a été utilisée comme outil d’assistance pour :
- Comprendre et expliquer l’algorithme
- Structurer la documentation (README)

Tout le code a été écrit et validé par l’auteur du projet.
