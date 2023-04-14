Étapes pour compiler et exécuter le code


Pré-requis

Instalation de Qt 6.4.3 et des Librairies nécessaires
1 - Lancer l'application Qt Maintenance Tools
2 - Se connecter
3 - Sélectionner "Add or remove components" (ou l'équivalent en français)
4 - Déployer la section Qt
5 - Si ce n'est pas déjà le cas, cocher Qt 6.4.3
6 - Déployer cette même section (Qt 6.4.3)
7 - Cocher "MSVC 2019 64-Bit", "MinGW 11.2.0 64-bit"
8 - Déployer la sous-section "Additionnal Libraries"
9 - Cocher "Qt Multimedia"
10 - Appuyez sur suivant jusqu'à ce que l'installation débute
11 - Une foi l'installation terminée, simplement fermer l'outil

Variables d'environnement
1 - Lancer l'application "Edit the system environment variables" (ou l'équivalent en français)
2 - Cliquer sur le boutton "Environment Variables"
3 - Sous la zone "System variables", trouver la variable "Path" et cliquer dessus
4 - Cliquer sur le bouton "Edit"
5 - S'assurer qu'un chemin vers le dossier bin de l'installation de Qt 6.4.3 s'y trouve,
	si un autre chemin pour une autre version est déjà spécifié, la retirer temporairement
	et indiquer le chemin pour Qt 6.4.3 (normalement C:\Qt\6.4.3\msvc2019_64\bin)
6 - Effectuer les étapes 3 à 5 mais pour "User Variables" à la place
7 - Cliquer sur Ok jusqu'à ce que le programme se ferme

Préparation des fichiers
1 - Extraire l'archive du code
2 - Ouvrir le programme "x64 Native Tools Command Prompt for VS 2019"
3 - Naviger jusqu'à la racine de l'extraction
4 - Naviger dans Interface
5 - Exécuter qmake (pour Qt 6.4.3)

Compilation Visual Studio
1 - Naviger à la racine des fichiers extrait
2 - Ouvrir le fichier Tetris.sln
3 - Attendre que les tâches en arrière plan se terminent
4 - Dans l'arborétum de fichier, cliquer-droit sur le projet Interface et sélectionner "Set as
	startup project" (ou l'équivalent en français)
5 - Effectuer un clean de la solution complet
6 - Rebuild la solution au complet

Exécution
1 - Exécuter la solution (F5 ou le gros boutton vert en haut)
2 - Jouez à Tetris ! (Utiliser les flèches du clavier pour naviger les menus)
3 - Éviter de sélectionner le menu "CONTROL" puisqu'il sert à la manette de jeu
	et peu causer des bug imprévus si elle n'est pas connectée.



