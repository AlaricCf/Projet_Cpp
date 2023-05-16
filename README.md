# Projet_Cpp : Master Mind

Le Matser Mind est un jeu de réflexion entre deux joueurs. Un premier joueur choisit une combinaison secrète, le deuxième doit alors la deviner.

# Compilation/Execution

Ce jeu a été codé en C++ avec l'aide du module Platformio de VSCode afin de le compiler sur une carte Arduino ESP8266.

On trouve ainsi dans le dossier src les fichiers :
   - main.cpp : programme du jeu
   - grove_two_rgb_led_matrix.cpp : librairie de la matrice de LED

Toutes les librairies/classes personnelles sont dans le dossier lib.

Il est donc possible de compiler et de téléverser le code via VSCode en utilisant ces fichiers.

L'archive MasterMind.zip permet de compiler et de téléverser le code grâce à l'IDE Arduino. Pour cela, il s'agit de la décompresser, de lancer MasterMind.ino, de sélectionner NodeMCU 1.0 (ESP-12E Module) afin de pouvoir executer le code.

# Fonctionnement

Pour commencer, le jeu se met en attente d'une combinaison secrète de 4 couleurs.

Pour sélectionner une combinaison, on utilise les boutons de couleurs Rouge, Vert, Jaune, Bleu (les couleurs sélectionnées s'affichent sur la matrice de LED). On peut alors valider avec le bouton poussoir ou bien corriger le coup précédent en restant appuyer sur le bouton poussoir. 

Après validation, le second joueur peut essayer de trouver la combinaison secrète de la même façcon.

Correction : 
Une LED rouge indique une couleur bien positionnée, une blanche une couleur mal positionnée et une croix aucune bonne réponse/couleur.

Le joueur 2 a 8 tentatives pour parvenir à trouver la combinaison. En cas d'échec, celle-ci s'affichera à la fin.
