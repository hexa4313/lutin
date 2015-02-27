Grammaire et Langage - TD intro Projet
==============================================
Langage Lutin

Grammaire

PROG -> DECS INSTS
DECS -> DECS DEC | DEC | ε
INSTS -> INSTS INST | INST | ε

DEC -> (var VAR | const CONST) pv
VAR -> VAR vg id | id
CONST -> CONST vg id eg val | id eg val
INST -> (ecrire EXP | lire id | id affect EXP) pv
EXP -> (EXP opM EXP | EXP opA EXP | po EXP pf | id | val) pv
opA -> add | sub
opM -> mult | div

affect -> ':='
pv -> ';'
vg -> ','
eg -> '='
add -> '+'
sub -> '-'
mult -> '*'
div -> '/'
po -> '('
pf -> ')'