- x Argument : un seul, extension .cub exacte (rejeter map.cub.txt et .cub tout court)
- Fichier : open qui échoue, fichier vide ou dossier passé en argument → erreur
- Identifiants NO SO WE EA F C : chacun présent une seule fois, dans n'importe quel ordre, espaces autorisés entre les éléments
- Textures : le chemin existe, s'ouvre et se charge en xpm (sinon erreur), pas de texte en trop après
- Couleurs F/C : exactement 3 valeurs entre 0 et 255, rien que des chiffres (255,,0, -1 ou 256 → erreur)
- Lignes vides : acceptées avant la map, interdites au milieu de la map
- Map en dernier : rien d'autre ne doit la suivre, à part des lignes vides
- Caractères : seulement 0 1 N S E W et l'espace, avec un seul joueur (zéro ou deux → erreur)
- Map fermée : chaque 0 et le joueur ne doivent jamais toucher un espace, un bord ou le bout d'une ligne plus courte (flood fill
ou vérification des 4 voisins)
- Lignes de longueurs différentes : complète-les à la même largeur pour ne pas lire hors du tableau
- Sortie : Error\n suivi d'un message, toute la mémoire libérée sur chaque chemin d'erreur (vérifie avec valgrind)
- Détails : \r en fin de ligne, tabulations, identifiant inconnu (NOO)

 1. Lire tout le fichier ligne par ligne avec get_next_line (tu ne l'as pas encore dans utils), et le stocker en char ** : tu
     pourras y revenir quand tu veux.
  2. Lire les 6 éléments (NO SO WE EA F C) : saute les lignes vides et les espaces, regarde l'identifiant, puis le reste de la
     ligne. Ils peuvent venir dans n'importe quel ordre.
  3. Refuser les doublons et les manques : garde un compteur ou un flag par identifiant, et vérifie qu'il y a exactement 6 éléments
     avant d'arriver à la map.
  4. Valider les couleurs F/C : exactement 3 nombres entre 0 et 255, séparés par des virgules. Refuse 220,,0, 256 et 1,2,3,4.
  5. Prendre la map à partir de la première ligne qui commence par 1 ou un espace, jusqu'à la fin du fichier. Une ligne vide au
     milieu de la map est une erreur.
  6. La rendre rectangulaire : complète chaque ligne avec des espaces jusqu'à la largeur max. L'indexation sera simple et le flood
     fill ne sortira jamais du tableau.
  7. Vérifier la map : seulement 01NSWE et espace, un seul joueur, et chaque 0 ou joueur entouré sur ses 4 côtés de 0, 1 ou joueur
     (ni espace, ni bord). Ça remplace le flood fill.