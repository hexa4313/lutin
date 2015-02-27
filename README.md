Grammaire et Langage - TD intro Projet
======================================

Grammaire
---------

* PROG → DECS INSTS
* DECS → DECS DEC | DEC | ε
* INSTS → INSTS INST | INST | ε

* DEC → (var VAR | const CONST) pv
* VAR → VAR vg id | id
* CONST → CONST vg id eg val | id eg val
* INST → (ecrire EXP | lire id | id affect EXP) pv
* EXP → (EXP opM EXP | EXP opA EXP | po EXP pf | id | val) pv
* opA → add | sub
* opM → mult | div

* affect → ':='
* pv → ';'
* vg → ','
* eg → '='
* add → '+'
* sub → '-'
* mult → '*'
* div → '/'
* po → '('
* pf → ')'
* var → 'var'
* const → 'const'
* ecrire → 'ecrire'
* lire → 'lire'
* id
* val

----------------

* P  → DL IL
* DL → DL D pv
* DL → ε
* IL → IL I pv
* IL → ε

* D → var V
* D → cst C
* V → V vg id
* V → id
* C → C vg id eq val
* C → id eq val
* I → w E
* I → r id
* I → id aff E
* E → E opM E
* E → E opA E
* E → po E pf
* E → id
* E → val
* opA → add
* opA → sub
* opM → mul
* opM → div

* aff → ':='
* pv  → ';'
* vg  → ','
* eq  → '='
* add → '+'
* sub → '-'
* mul → '*'
* div → '/'
* po  → '('
* pf  → ')'
* var → 'var'
* cst → 'const'
* w   → 'ecrire'
* r   → 'lire'
* id
* val

----------------

Les expressions regulieres
--------------------------

* keyword → 'var ' | 'const ' | 'ecrire ' | 'lire '
* id  → \[a-z A-Z] \[a-z A-z 0-9]*
* val → [0-9]+
* pv  → ';'
* aff → ':='