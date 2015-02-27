Grammaire et Langage - TD intro Projet
==============================================
Langage Lutin

Grammaire

DEC -> (var VAR | const CONST) pv
VAR -> VAR vir id | id
CONST -> CONST vir id eg val | id eg val
INST -> (ecrire EXP | lire id | id affect EXP) pv
EXP -> (EXP opM EXP | EXP opA EXP | '('EXP')' | id | val) pv
opA -> + | -
opM -> * | /