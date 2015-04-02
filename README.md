Projet Grammaire et Langage - Lutin
======================================

Description
---------

Lutin est un langage de traitement de valeurs numériques, qui fonctionne grâce aux entrées et sorties standard.
Le langage permet de déclarer des constantes ainsi que des variables et d'effectuer des opérations numériques (addition, soustraction, multiplication, division) sur ces dernières.  
Ce dépôt Git contient l'implémentation de certains aspects de la compilation de ce langage : analyse syntaxique et  lexicale, analyse statique, optimisation et enfin interprétation.

Le langage Lutin
---------

Un programme lutin est constitué d'un bloc déclaratif puis d'un bloc d'instructions.

### Déclarations

Un bloc déclaratif peut contenir :

* `var id[, id2[, idN]];` Déclaration de variable(s).
* `const id = val[, id2 = val2[, idN = valN]];` Déclaration de constante(s).

### Instructions

Un bloc d'instructions peut contenir :

* `lire id;` Lire un nombre dans l'entrée standard et l'affecter à une variable.
* `ecrire e;` Écrire dans la sortie standard le contenu d'une expression.
* `id := e;` Affecter une expression à une variable.

Une expression est expression mathématique au sens courant du terme pouvant contenir les opérations + - \* / et les opérateurs ( et ).
Exemple d'expressions valides :
* `5`
* `x` (x est une variable)
* `5 + x`
* `(5 * 3) + x`

Organisation du code
---------

Nous avons organisé le code selon les différents aspects de la compilation :

* *src/parsing* contient le nécessaire à l'analyse lexicale et syntaxique des fichiers passés en entrée
  * *src/parsing/ast* contient les classes constituant l'AST (Abstract Syntax Tree) d'un programme
  * *src/parsing/states* contient les états de l'automate de l'analyseur syntaxique
* *src/static_analysis* contient l'analyseur statique
* *src/optimization* contient l'optimiseur
* *src/interpretation* contient l'interpréteur

Construction de l'exécutable
---------

### Dépendances
* CMake >= 2.8
* Boost >= 1.50.0
* stdlib c++11

Exécuter le script *build.sh* situé à la racine du dépôt. Ce dernier construira l'exécutable *lutinc* dans un nouveau dossier *bin*.

Utilisation de lutinc
---------
```
./bin/lutinc [-p] [-a] [-e] [-o] source.lt
[-p] affiche le code source reconnu
[-a] analyse le programme de maniere statique
[-e] execute interactivement le programme
[-o] optimise les expressions et instructions
```
