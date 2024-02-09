Notes Minishell
=======================

<br/>
<br/>
<br/>

Liste Fonctions externes autorisees :
-------------------------------------

<br/>

readline, rl_clear_history, rl_on_new_line, rl_replace_line
rl_redisplay, add_history

printf, malloc, free, write, acess, open, read, close, fork, wait,
waitpid, exit, unlink, execve, dup, dup2, pipe

wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill,
getcwd, chdir, stat, lstat, fstat, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr,
tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

<br/>
<br/>
<br/>

Documentation fonction externes autorisees :
--------------------------------------------

<br/>
<br/>

**readline** : fonction qui lis une ligne du terminal et la retourne.

**rl_clear_history** : supprime l'historique de la fonction readline et
libere la memoire associee aux donnees privee de la fonction readline.

**rl_on_new_line** : Indique aux fonctions de mise a jour que nous sommes
passes sur une nouvelle ligne (vide), generalement apres avoir affiche
une nouvelle ligne.

**rl_replace_line** : Remplace le contenus de 'rl_line_buffer' par du 
texte. Le 'point' et la 'marque' (mark) sont conserves, si possible.
Si 'clear_undo' (un parametre de la fonction) est different de zero,
la liste d'annulation associee a la ligne actuelle est effacee. 

**rl_redisplay** : Change le contenus de ce qui est affiche a l'ecran
pour refleter le contenus actuel de 'rl_line_buffer'.
add_history : place la chaine de caractere fournis en argument a la
fin de l'historique. Le champ de données associé (le cas échéant) est 
défini sur NULL.

Cas de figure lorsqu'il y a un signal 'Ctrl C' avec readline :
https://stackoverflow.com/questions/71685072/return-readline-to-its-original-state-when-recieving-sigint

<br/>

**wait3, wait4** : Les appels systeme wait3 et wait4 sont similaires a 
waitpid, mais retournent egalement des informations sur l'utilisation des 
ressources par le fils dans la structure pointee par 'rusage' (parametre
de la fonction). 'wait3' attend n'importe quel fils, et 'wait4' peut
etre utilise pour selectionner un ou des fils specifique(s) a attendre.

<br/>
<br/>

**signal** : la fonction installe le gestionnaire 'handler' pour le signal
'signum' (parametre de la fonction). 'handler' peut etre 'SIG_IGN',
'SIG_DFL' ou l'adresse d'une fonction definie par le programmeur
(un "gestionnaire de signal").

**sigaction** : Cette fonction modifie l'action effectuee par un processus
a la reception d'un signal specifique.
sigemptyset : Cette fonction vide l'ensemble de signaux fourni par 
set, tous les signaux etant exclus de cet ensemble.
sigaddset : ajoutent le signal signum de l'ensemble 'set'.
kill : Le signal par defaut de kill est TERM. Permet d'arreter un 
ou plusieurs processus.

<br/>

**getcwd** : Cette fonction copie le chemin d'acces absolu du repertoire
de travail courant dans la chaine pointee par 'buf' (parametre de la
fonction), qui est de longueur 'size' (parametre de la fonction).
chdir : Remplace le repertoire de travail courant du processus appelant
par celui indique dans le chemin path. La fonction chdir() fera en 
sorte que le répertoire nommé par le chemin pointé par l'argument path 
devienne le répertoire de travail actuel ; c'est-à-dire que le point 
de départ de la recherche de chemin pour les noms de chemin ne 
commençant pas par '/' .

<br/>

**stat, lstat, fstat** : Ces fonctions renvoient des renseignements sur 
le fichier indique, dans le tampon pointe par 'stat'. 'stat' et 'fstatat'
recuperent des renseignements sur le fichier pointe par 'pathname'.
'lstat' est identique a 'stat', sauf que dans le cas ou 'pathname'
est un lien symbolique, auquel cas il renvoie des renseignements sur
le lien lui-meme plutot que celui du fichier vise. 'fstat' est 
identique a 'stat', sauf que le fichier dont les renseignements sont
a recuperer est reference par le descripteur de fichier fd.

<br/>

**opendir** : La fonction 'opendir' ouvre un flux repertoire correspondant
au repertoire 'name', et renvoie un pointeur sur ce flux. Le flux est
positionne sur la premiere entree du repertoire.

Explication sur les fichiers, repertoires et ouverture de flux de
repertoire : 
https://www.developpez.net/forums/d1638610/c-cpp/c/parcours-d-dossier/

**readdir** : La fonction readdir() renvoie un pointeur sur une structure 
'dirent' representant l'entree suivante du flux repertoire pointe 
par 'dir'. Elle renvoie NULL a la fin du repertoire, ou en cas 
d'erreur.

**closedir** : La fonction ferme le flux de repertoire associe a 'dir'.
Apres cette invocation, le descripteur 'dir' du flux de repertoire 
n'est plus disponible.

<br/>

Parcourir des dossiers en C, explication 'errno', 'perror' :
http://sdz.tdct.org/sdz/arcourir-les-dossiers-avec-dirent-h.html

**strerror** : La fonction 'strerror' renvoie une chaine decrivant le 
code d'erreur passe en argument errnum.
perror : La fonction 'perror' affiche un message sur la sortie
d'erreur standard, decrivant la derniere erreur rencontree durant
un appel systeme ou une fonction de bibliotheque. La chaine de 
caracteres contient generalement le nom de la fonction ou s'est 
produit l'erreur.

<br/>

**isatty** : Verifie si le descripteur de fichier fournis en parametres
est ouvert et connecte a un terminal. 
ttyname : La fonction renvoie un pointeur sur le nom du peripherique
terminal associe au descripteur de fichier fd, ou NULL en cas d'erreur
(par exemple si le 'fd' n'est pas connecte a un terminal).
ttyslot : La fonction renvoie la position de l'entree du terminal en
cours dans un fichier.

<br/>

**ioctl** : La fonction modifie le comportement des peripheriques 
sous-jacents des fichiers speciaux. En particulier, de nombreuses 
caracteristiques des fichiers speciaux en mode caractere (par exemple
des terminaux) peuvent etre controlees avec des requetes ioctl.

Explication requetes ioctl :
https://www.developpez.net/forums/d1013085/c-cpp/c/but-utilite-fonction-ioctl/

<br/>

**getenv** : La fonction recherche dans la liste des variables d'environnement
une variable nommee 'name' (parametre de la fonction), et renvoie un
pointeur sur la chaine 'value'.

<br/>

**Termios** : Les fonctions termios etablissent une interface sous forme
de terminal, permettant de controler les ports de communication 
asynchrone.

**tcsetattr** : la fonction fixe les parametres du terminal (a moins que
le materiel sous-jacent ne le prenne pas en charge) en lisant la
structure 'termios' pointee par 'termios_p'

**tcgetattr** : La fonction recupere les parametres associes a l'objet
reference par 'fd' et les stocke dans la structure 'termios' pointee
par 'termios_p'. Cette fonction peut etre appele par un processus en
arriere-plan ; neanmoins, les attributs de terminal peuvent etre
modifies par la suite par le processus en avant-plan.

Explication structure et fonctions termios :
http://manpagesfr.free.fr/man/man3/termios.3.html

<br/>

**Termcap, Terminfo**

Explication : 
https://zestedesavoir.com/tutoriels/1733/termcap-et-terminfo/

getent, tgetflag, tgetnum, tgetstr, tgoto, tputs : ce sont les 
fonctions utilisee pour la creation d'interface graphique dans un
terminal.


<br/>
<br/>
<br/>

Fonctions builtins :
--------------------

echo, cd, pwd, export, unset, env, exit.

**cd :** Lorsque j'effectue un cd je dois mettre a jour PWD et OLDPWD, 
je remplace OLDPWD par PWD et je remplace PWD par le nouveau 
repertoire de travail.


**Remarque :**

Pour l'instant, lorsque j'appuie sur les fleches ca me fait des 
symboles avec [[ A ..., parce qu'on ne gere pas encore l'historique
des commandes et le fait de pouvoir le remonter avec la fleche du 
haut, et d'ailleurs les flches de gauche et droite ne sont pas 
censee faire aussi les [[ C quand j'appuie dessus dans la version 
final.

<br/>
<br/>
<br/>
<br/>
<br/>
<br/>


Basic functionality of minishell :
----------------------------------

<br/>
<br/>

**Explication minishell :**
https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218


**EXECUTION :**

- Run simple commands with absolute path (/bin/ls), relative path
(../bin/ls) and without a path (ls, cat, grep ...).

- Working (commands) history (navigating in with up/down arrows). 

- Implement pipes (|), redirections (<, >, >>) and the here-doc (<<)
-> pipex.

- Implement the following built-ins : echo (option -n only), exit,
env (with no options or arguments), export (with no option), unset
(with no options), cd, pwd.


**PARSING :**

- Handle double quotes ("") and single quotes (''), which should 
escape special characters, beside $ for double quotes.

- Handle environment variables ($ followed by a sequence of characters).

- Handle signals like in bash (ctrl + C, ctrl + \, ctrl + D).


<br/>
<br/>
<br/>



**Two Part : FRONT-END / BACK-END**

<br/>

- **FRONT-END** -> the part that deals with user input and user interaction
(commands and signal).

Chose to postpone signals until it finish the execution, because 
implementing signals from the start will just add unnecessary 
complication.

- **BACK-END** -> is where the internal work is done (the execution).

<br/>
<br/>

**BASH PARSING** - 2 phases : the **lexical analysis** (lexing) which produces
"lexems" and then the **syntax analysis** (parsing the lexems).

1 - **Lexical analysis / tokenization** : taking the input from the user
and processing it char into "tokens" (type and value).

The most important thing to us is the type of the lexems/tokens and
the order they came in (not the values).

2 - **Syntax analysis / Parsing** : scanning the stream of tokens according
to a specific grammar and then deciding what to do with them 
(generating an AST - Abstract Syntax Tree).

Parsing Abstract Syntax Tree : The Recursive Descent, The Theory of
Computation.

Theory -> what a grammar ? what a language ?

Type of grammar that is used for this project is called CFG (Context
Free Grammar). A grammar is basically a way of telling how a language
can be made, back to the example above ...


<br/>
<br/>

BASH PARSING technique -> PRECEDENCE CLIMBING :
----------------------------------------

<br/>
<br/>
<br/>

**Useful article** : 
https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing

L'objectif fondamental de l'algorithme est le suivant : traiter une 
expression comme un ensemble de sous-expressions imbriquées, où 
chaque sous-expression a en commun le niveau de priorité le plus bas 
des opérateurs qu'elle contient.

<br/>

Concepts :

- Precedence of sus-expressions
- Associativity (left associativem right associative)
- Atoms (either numbers or parenthesized expressions)
- Expressions (atoms connected by binary operators)

<br/>

The algorithm is 'operator-guided'. 

Its fundamental step is to consume
the next atom and look at the operator following it. If the operator
has precedence lower than the lowest acceptable for the current step,
the algorithm returns. Otherwise, it calls itself in a loop to handle
the sub-expression. 

In pseudo-code, it looks like this :

```
compute_expr(min_prec):

	result = compute_atom()

	while cur token is a binary operator with precedence >= min_prec:
		prec, assoc = precedence and associativity of current token
		if assoc is left :
			next_min_prec = prec + 1
		else:
			next_min_prec = prec
		rhs = compute_expr(next_min_prec)
		result = compute operator(result, rhs)

	return result
```

<br/>

Note that the algorithm makes one recursive call per binary operator.
Some of these calls are short lived - they will only consume an atom and
return it because the _while_ loop is not entered. Some are longer lived.
The initial call to **compute_expr** will compute the whole expression.

<br/>

**Handling associativity**

<br/>

Example : 
- 8 * 9 * 10 -> (8 * 9) * 10
- 8 ^ 9 ^ 10 -> (8 ^ 9) ^ 10

<br/>

**Handling sub-expressions**

<br/>

The algorithm pseudo-code presented above doesn't explain how parenthesized
sub-expressions are-handled.

Consider this expression : 2000 * (4 - 3) / 100

It's not clear how the _while_ loop can handle this. The answer is **compute_atom**. When it sees a left parenthesized, it it knows that a sub-expression will follow, so it calls **compute_expr** on the sub expression (which lasts until the matching right parenthesized), and returns
its result as the result of the atom.

So **compute_expr** is oblivious to the existence of sub-expressions.

<br/>
<br/>
<br/>

Application of PRECEDENCE CLIMBING on bash arguments :
------------------------------------

<br/>

Let's set a variable A with the value ```1```.

```export A="1"```

Let's suppose we get the following user input ;

```""$A B "CD"```

The first thing with do, is to replace ```$A``` with its value, so it becomes :

```""1 B "CD"```

Then we get rid of empty string, so we get :

```1 B "CD"```

Then we split the string by spaces (depending on the quotes), so we get three strings :

```1```, ```B```, ```"CD"```

Then we check if there is any globbing (```*``` wildcard), if there is we
replace the wildcard by the appropriate strings - the globbing algorithm
it's a backtracking algorithm, you can learn more about it :
https://www.geeksforgeeks.org/wildcard-pattern-matching/

Finally, we strip out any quotes :

```1```, ```B```, ```CD```

<br/>
<br/>
<br/>

The execution of Abstract Syntax Tree (AST)
-------------------------------------------

<br/>

What we are basically given in the execution part is an AST, and the way
we will execute it is by traversing it recursively, here is a pseudo-code example that traverses the bash arguments AST built earlier in the parsing phase.

```int execute(t_node node)
{
	if (node.type == PIPE)
		return (execute_pipe(node.left, node.right));
	else
		return (execute_simple_command(node.value));
}
```

<br/>

In the execution part, most importantly is how to manage file descriptors
and forking processes.

<br/>

The **built-ins** are a set of useful functions that are needed in the Minishell, they differ in complexity, from the easy ones like ```echo``` to
complex ones.

<br/>

After finishing the execution, we can implement the signals (```ctrl + C```, ```ctrl + \```, ```ctrl + D```).

For ```ctrl + C```, ```ctrl + \```, we can catch ```SIGINT``` and ```SIGQUIT``` respectively, but in the case of ```ctrl + D``` we have to check the ```EOF``` or the end of string (i.e. ```NULL``` character).