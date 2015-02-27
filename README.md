Grammaire et Langage - TD intro Projet
==============================================

Grammaire
---------

* PROG -> DECS INSTS
* DECS -> DECS DEC | DEC | ε
* INSTS -> INSTS INST | INST | ε

* DEC -> (var VAR | const CONST) pv
* VAR -> VAR vg id | id
* CONST -> CONST vg id eg val | id eg val
* INST -> (ecrire EXP | lire id | id affect EXP) pv
* EXP -> (EXP opM EXP | EXP opA EXP | po EXP pf | id | val) pv
* opA -> add | sub
* opM -> mult | div

* affect -> ':='
* pv -> ';'
* vg -> ','
* eg -> '='
* add -> '+'
* sub -> '-'
* mult -> '*'
* div -> '/'
* po -> '('
* pf -> ')'
* var -> 'var'
* const -> 'const'
* ecrire -> 'ecrire'
* lire -> 'lire'
* id
* val


----------------

Defactorisé et simplifié

* P -> DL IL
* DL -> DL D
* DL -> D
* DL -> ε
* IL -> IL I
* IL -> I
* IL -> ε

* D -> var V pv
* D -> const C pv
* V -> V vg id
* V -> id
* C -> C vg id eg val
* C -> id eg val
* I -> ecrire E pv
* I -> lire id pv
* I -> id affect E pv
* E -> E opM E pv
* E -> E opA E pv
* E -> po E pf pv
* E -> id pv
* E -> val pv
* opA -> add
* opA -> sub
* opM -> mult
* opM -> div

* affect -> ':='
* pv -> ';'
* vg -> ','
* eg -> '='
* add -> '+'
* sub -> '-'
* mult -> '*'
* div -> '/'
* po -> '('
* pf -> ')'
* var -> 'var'
* const -> 'const'
* ecrire -> 'ecrire'
* lire -> 'lire'
* id
* val