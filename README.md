# Projet_Cpp : Master Mind

Le Matser Mind est un jeu de réflexion entre deux joueurs. Un premier joueur choisit une combinaison secrète, le deuxième doit alors la deviner.

# Compilation/Execution

Ce jeu a été codé en C++ avec l'aide du module Platformio de VSCode afin de le compiler sur une carte Arduino ESP8266.

On trouve ainsi dans le dossier src les fichiers :
   - main.cpp : programme du jeu
   - grove_two_rgb_led_matrix.cpp : librairie de la matrice de LED

Toutes les librairies/classes personnelles sont dans le dossier lib.

# Fonctionnement

Pour commencer, le jeu se met en attente d'une combinaison secrète de 4 couleurs.

Pour sélectionner une combinaison, on utilise les boutons de couleurs Rouge, Vert, Jaune, Bleu (les couleurs sélectionnées s'affichent sur la matrice de LED). On peut alors valider avec le bouton poussoir ou bien corriger le coup précédent en restant appuyer sur le bouton poussoir. 

Après validation, le second joueur peut essayer de trouver la combinaison secrète de la même façcon.

Correction : 
Une LED rouge indique une couleur bien positionnée, une blanche une couleur mal positionnée.

Le joueur 2 a 8 tentatives pour parvenir à trouver la combinaison. En cas d'échec, celle-ci s'affichera à la fin.
