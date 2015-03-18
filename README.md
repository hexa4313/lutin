Grammaire et Langage - Lutin
======================================

Les non-terminaux
---------
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
* E → E OpM E
* E → E OpA E
* E → po E pf
* E → id
* E → val
* OpA → add
* OpA → sub
* OpM → mul
* OpM → div

Les terminaux
---------

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
* id  → [a-zA-Z][a-zA-Z0-9]*
* val → [0-9]+
