#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 74 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 12/29/16
# Time: 22:50:33
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : programs $end

    1  programs : programs program
    2           | program

    3  program : ID LPACE RPACE LBRACE stmts RBRACE

    4  stmts : stmt stmts
    5        | stmt

    6  stmt : declare_stmt SEMICOLON
    7       | assign_expr SEMICOLON
    8       | if_stmt
    9       | while_stmt
   10       | for_stmt
   11       | logic_expr SEMICOLON
   12       | SEMICOLON
   13       | LBRACE stmts RBRACE
   14       | print_stmt SEMICOLON
   15       | input_stmt SEMICOLON
   16       |

   17  declare_stmt : type idlist

   18  type : INT
   19       | CHAR
   20       | BOOL

   21  idlist : declare_args COMMA idlist
   22         | declare_args

   23  declare_args : ID
   24               | ID ASSIGN expr

   25  if_stmt : IF LPACE logic_expr RPACE stmt
   26          | IF LPACE logic_expr RPACE stmt ELSE stmt

   27  while_stmt : WHILE LPACE logic_expr RPACE stmt

   28  for_stmt : FOR LPACE for_expr1 SEMICOLON for_expr2 SEMICOLON for_expr3 RPACE stmt

   29  for_expr1 : assign_expr
   30            | logic_expr
   31            | declare_stmt
   32            |

   33  for_expr2 : logic_expr
   34            |

   35  for_expr3 : assign_expr
   36            | expr
   37            |

   38  print_stmt : PRINT LPACE ID RPACE
   39             | PRINT LPACE NUMBER RPACE

   40  input_stmt : INPUT LPACE ID RPACE

   41  logic_expr : if_expr OR logic_expr
   42             | if_expr AND logic_expr
   43             | if_expr

   44  if_expr : assign_expr
   45          | bool_expr

   46  assign_expr : ID ASSIGN expr

   47  bool_expr : expr EQ expr
   48            | expr GE expr
   49            | expr LE expr
   50            | expr GT expr
   51            | expr LT expr
   52            | expr GREATER expr
   53            | expr LESS expr
   54            | expr NE expr
   55            | expr

   56  expr : expr ADD term
   57       | expr SUB term
   58       | expr MOD term
   59       | term

   60  term : term MUL factor
   61       | term DIV factor
   62       | factor

   63  factor : ID
   64         | NUMBER
   65         | LPACE expr RPACE


##############################################################################
# States
##############################################################################

state 0
	$accept : . programs $end

	ID  shift 1

	programs  goto 2
	program  goto 3


state 1
	program : ID . LPACE RPACE LBRACE stmts RBRACE

	LPACE  shift 4


state 2
	$accept : programs . $end  (0)
	programs : programs . program

	$end  accept
	ID  shift 1

	program  goto 5


state 3
	programs : program .  (2)

	.  reduce 2


state 4
	program : ID LPACE . RPACE LBRACE stmts RBRACE

	RPACE  shift 6


state 5
	programs : programs program .  (1)

	.  reduce 1


state 6
	program : ID LPACE RPACE . LBRACE stmts RBRACE

	LBRACE  shift 7


7: shift-reduce conflict (shift 8, reduce 16) on ID
7: shift-reduce conflict (shift 9, reduce 16) on NUMBER
7: shift-reduce conflict (shift 10, reduce 16) on INT
7: shift-reduce conflict (shift 11, reduce 16) on CHAR
7: shift-reduce conflict (shift 12, reduce 16) on BOOL
7: shift-reduce conflict (shift 13, reduce 16) on SEMICOLON
7: shift-reduce conflict (shift 14, reduce 16) on LPACE
7: shift-reduce conflict (shift 15, reduce 16) on LBRACE
7: shift-reduce conflict (shift 16, reduce 16) on IF
7: shift-reduce conflict (shift 17, reduce 16) on WHILE
7: shift-reduce conflict (shift 18, reduce 16) on FOR
7: shift-reduce conflict (shift 19, reduce 16) on INPUT
7: shift-reduce conflict (shift 20, reduce 16) on PRINT
state 7
	program : ID LPACE RPACE LBRACE . stmts RBRACE
	stmt : .  (16)

	ID  shift 8
	NUMBER  shift 9
	INT  shift 10
	CHAR  shift 11
	BOOL  shift 12
	SEMICOLON  shift 13
	LPACE  shift 14
	LBRACE  shift 15
	IF  shift 16
	WHILE  shift 17
	FOR  shift 18
	INPUT  shift 19
	PRINT  shift 20
	.  reduce 16

	stmt  goto 21
	declare_stmt  goto 22
	assign_expr  goto 23
	stmts  goto 24
	while_stmt  goto 25
	expr  goto 26
	type  goto 27
	if_stmt  goto 28
	for_stmt  goto 29
	logic_expr  goto 30
	print_stmt  goto 31
	input_stmt  goto 32
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 8
	assign_expr : ID . ASSIGN expr
	factor : ID .  (63)

	ASSIGN  shift 37
	.  reduce 63


state 9
	factor : NUMBER .  (64)

	.  reduce 64


state 10
	type : INT .  (18)

	.  reduce 18


state 11
	type : CHAR .  (19)

	.  reduce 19


state 12
	type : BOOL .  (20)

	.  reduce 20


state 13
	stmt : SEMICOLON .  (12)

	.  reduce 12


state 14
	factor : LPACE . expr RPACE

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 39
	factor  goto 34
	term  goto 35


15: shift-reduce conflict (shift 8, reduce 16) on ID
15: shift-reduce conflict (shift 9, reduce 16) on NUMBER
15: shift-reduce conflict (shift 10, reduce 16) on INT
15: shift-reduce conflict (shift 11, reduce 16) on CHAR
15: shift-reduce conflict (shift 12, reduce 16) on BOOL
15: shift-reduce conflict (shift 13, reduce 16) on SEMICOLON
15: shift-reduce conflict (shift 14, reduce 16) on LPACE
15: shift-reduce conflict (shift 15, reduce 16) on LBRACE
15: shift-reduce conflict (shift 16, reduce 16) on IF
15: shift-reduce conflict (shift 17, reduce 16) on WHILE
15: shift-reduce conflict (shift 18, reduce 16) on FOR
15: shift-reduce conflict (shift 19, reduce 16) on INPUT
15: shift-reduce conflict (shift 20, reduce 16) on PRINT
state 15
	stmt : LBRACE . stmts RBRACE
	stmt : .  (16)

	ID  shift 8
	NUMBER  shift 9
	INT  shift 10
	CHAR  shift 11
	BOOL  shift 12
	SEMICOLON  shift 13
	LPACE  shift 14
	LBRACE  shift 15
	IF  shift 16
	WHILE  shift 17
	FOR  shift 18
	INPUT  shift 19
	PRINT  shift 20
	.  reduce 16

	stmt  goto 21
	declare_stmt  goto 22
	assign_expr  goto 23
	stmts  goto 40
	while_stmt  goto 25
	expr  goto 26
	type  goto 27
	if_stmt  goto 28
	for_stmt  goto 29
	logic_expr  goto 30
	print_stmt  goto 31
	input_stmt  goto 32
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 16
	if_stmt : IF . LPACE logic_expr RPACE stmt
	if_stmt : IF . LPACE logic_expr RPACE stmt ELSE stmt

	LPACE  shift 41


state 17
	while_stmt : WHILE . LPACE logic_expr RPACE stmt

	LPACE  shift 42


state 18
	for_stmt : FOR . LPACE for_expr1 SEMICOLON for_expr2 SEMICOLON for_expr3 RPACE stmt

	LPACE  shift 43


state 19
	input_stmt : INPUT . LPACE ID RPACE

	LPACE  shift 44


state 20
	print_stmt : PRINT . LPACE ID RPACE
	print_stmt : PRINT . LPACE NUMBER RPACE

	LPACE  shift 45


21: shift-reduce conflict (shift 8, reduce 16) on ID
21: shift-reduce conflict (shift 9, reduce 16) on NUMBER
21: shift-reduce conflict (shift 10, reduce 16) on INT
21: shift-reduce conflict (shift 11, reduce 16) on CHAR
21: shift-reduce conflict (shift 12, reduce 16) on BOOL
21: shift-reduce conflict (shift 13, reduce 16) on SEMICOLON
21: shift-reduce conflict (shift 14, reduce 16) on LPACE
21: shift-reduce conflict (shift 15, reduce 16) on LBRACE
21: reduce-reduce conflict (reduce 5, reduce 16) on RBRACE
21: shift-reduce conflict (shift 16, reduce 16) on IF
21: shift-reduce conflict (shift 17, reduce 16) on WHILE
21: shift-reduce conflict (shift 18, reduce 16) on FOR
21: shift-reduce conflict (shift 19, reduce 16) on INPUT
21: shift-reduce conflict (shift 20, reduce 16) on PRINT
state 21
	stmts : stmt . stmts
	stmts : stmt .  (5)
	stmt : .  (16)

	ID  shift 8
	NUMBER  shift 9
	INT  shift 10
	CHAR  shift 11
	BOOL  shift 12
	SEMICOLON  shift 13
	LPACE  shift 14
	LBRACE  shift 15
	IF  shift 16
	WHILE  shift 17
	FOR  shift 18
	INPUT  shift 19
	PRINT  shift 20
	.  reduce 5

	stmt  goto 21
	declare_stmt  goto 22
	assign_expr  goto 23
	stmts  goto 46
	while_stmt  goto 25
	expr  goto 26
	type  goto 27
	if_stmt  goto 28
	for_stmt  goto 29
	logic_expr  goto 30
	print_stmt  goto 31
	input_stmt  goto 32
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 22
	stmt : declare_stmt . SEMICOLON

	SEMICOLON  shift 47


23: shift-reduce conflict (shift 48, reduce 44) on SEMICOLON
state 23
	stmt : assign_expr . SEMICOLON
	if_expr : assign_expr .  (44)

	SEMICOLON  shift 48
	.  reduce 44


state 24
	program : ID LPACE RPACE LBRACE stmts . RBRACE

	RBRACE  shift 49


state 25
	stmt : while_stmt .  (9)

	.  reduce 9


state 26
	bool_expr : expr . NE expr
	bool_expr : expr .  (55)
	bool_expr : expr . EQ expr
	bool_expr : expr . GT expr
	bool_expr : expr . LE expr
	bool_expr : expr . GE expr
	bool_expr : expr . LT expr
	expr : expr . ADD term
	expr : expr . MOD term
	bool_expr : expr . LESS expr
	bool_expr : expr . GREATER expr
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	EQ  shift 53
	GE  shift 54
	LE  shift 55
	GT  shift 56
	LT  shift 57
	GREATER  shift 58
	LESS  shift 59
	NE  shift 60
	.  reduce 55


state 27
	declare_stmt : type . idlist

	ID  shift 61

	idlist  goto 62
	declare_args  goto 63


state 28
	stmt : if_stmt .  (8)

	.  reduce 8


state 29
	stmt : for_stmt .  (10)

	.  reduce 10


state 30
	stmt : logic_expr . SEMICOLON

	SEMICOLON  shift 64


state 31
	stmt : print_stmt . SEMICOLON

	SEMICOLON  shift 65


state 32
	stmt : input_stmt . SEMICOLON

	SEMICOLON  shift 66


state 33
	if_expr : bool_expr .  (45)

	.  reduce 45


state 34
	term : factor .  (62)

	.  reduce 62


state 35
	term : term . DIV factor
	term : term . MUL factor
	expr : term .  (59)

	MUL  shift 67
	DIV  shift 68
	.  reduce 59


state 36
	logic_expr : if_expr .  (43)
	logic_expr : if_expr . AND logic_expr
	logic_expr : if_expr . OR logic_expr

	OR  shift 69
	AND  shift 70
	.  reduce 43


state 37
	assign_expr : ID ASSIGN . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 71
	factor  goto 34
	term  goto 35


state 38
	factor : ID .  (63)

	.  reduce 63


state 39
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term
	factor : LPACE expr . RPACE

	RPACE  shift 72
	ADD  shift 50
	SUB  shift 51
	MOD  shift 52


state 40
	stmt : LBRACE stmts . RBRACE

	RBRACE  shift 73


state 41
	if_stmt : IF LPACE . logic_expr RPACE stmt
	if_stmt : IF LPACE . logic_expr RPACE stmt ELSE stmt

	ID  shift 8
	NUMBER  shift 9
	LPACE  shift 14

	assign_expr  goto 74
	expr  goto 26
	logic_expr  goto 75
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 42
	while_stmt : WHILE LPACE . logic_expr RPACE stmt

	ID  shift 8
	NUMBER  shift 9
	LPACE  shift 14

	assign_expr  goto 74
	expr  goto 26
	logic_expr  goto 76
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 43
	for_stmt : FOR LPACE . for_expr1 SEMICOLON for_expr2 SEMICOLON for_expr3 RPACE stmt
	for_expr1 : .  (32)

	ID  shift 8
	NUMBER  shift 9
	INT  shift 10
	CHAR  shift 11
	BOOL  shift 12
	LPACE  shift 14
	.  reduce 32

	declare_stmt  goto 77
	assign_expr  goto 78
	expr  goto 26
	type  goto 27
	for_expr1  goto 79
	logic_expr  goto 80
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 44
	input_stmt : INPUT LPACE . ID RPACE

	ID  shift 81


state 45
	print_stmt : PRINT LPACE . ID RPACE
	print_stmt : PRINT LPACE . NUMBER RPACE

	ID  shift 82
	NUMBER  shift 83


state 46
	stmts : stmt stmts .  (4)

	.  reduce 4


state 47
	stmt : declare_stmt SEMICOLON .  (6)

	.  reduce 6


state 48
	stmt : assign_expr SEMICOLON .  (7)

	.  reduce 7


state 49
	program : ID LPACE RPACE LBRACE stmts RBRACE .  (3)

	.  reduce 3


state 50
	expr : expr ADD . term

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	factor  goto 34
	term  goto 84


state 51
	expr : expr SUB . term

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	factor  goto 34
	term  goto 85


state 52
	expr : expr MOD . term

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	factor  goto 34
	term  goto 86


state 53
	bool_expr : expr EQ . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 87
	factor  goto 34
	term  goto 35


state 54
	bool_expr : expr GE . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 88
	factor  goto 34
	term  goto 35


state 55
	bool_expr : expr LE . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 89
	factor  goto 34
	term  goto 35


state 56
	bool_expr : expr GT . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 90
	factor  goto 34
	term  goto 35


state 57
	bool_expr : expr LT . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 91
	factor  goto 34
	term  goto 35


state 58
	bool_expr : expr GREATER . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 92
	factor  goto 34
	term  goto 35


state 59
	bool_expr : expr LESS . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 93
	factor  goto 34
	term  goto 35


state 60
	bool_expr : expr NE . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 94
	factor  goto 34
	term  goto 35


state 61
	declare_args : ID . ASSIGN expr
	declare_args : ID .  (23)

	ASSIGN  shift 95
	.  reduce 23


state 62
	declare_stmt : type idlist .  (17)

	.  reduce 17


state 63
	idlist : declare_args .  (22)
	idlist : declare_args . COMMA idlist

	COMMA  shift 96
	.  reduce 22


state 64
	stmt : logic_expr SEMICOLON .  (11)

	.  reduce 11


state 65
	stmt : print_stmt SEMICOLON .  (14)

	.  reduce 14


state 66
	stmt : input_stmt SEMICOLON .  (15)

	.  reduce 15


state 67
	term : term MUL . factor

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	factor  goto 97


state 68
	term : term DIV . factor

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	factor  goto 98


state 69
	logic_expr : if_expr OR . logic_expr

	ID  shift 8
	NUMBER  shift 9
	LPACE  shift 14

	assign_expr  goto 74
	expr  goto 26
	logic_expr  goto 99
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 70
	logic_expr : if_expr AND . logic_expr

	ID  shift 8
	NUMBER  shift 9
	LPACE  shift 14

	assign_expr  goto 74
	expr  goto 26
	logic_expr  goto 100
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 71
	assign_expr : ID ASSIGN expr .  (46)
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 46


state 72
	factor : LPACE expr RPACE .  (65)

	.  reduce 65


state 73
	stmt : LBRACE stmts RBRACE .  (13)

	.  reduce 13


state 74
	if_expr : assign_expr .  (44)

	.  reduce 44


state 75
	if_stmt : IF LPACE logic_expr . RPACE stmt
	if_stmt : IF LPACE logic_expr . RPACE stmt ELSE stmt

	RPACE  shift 101


state 76
	while_stmt : WHILE LPACE logic_expr . RPACE stmt

	RPACE  shift 102


state 77
	for_expr1 : declare_stmt .  (31)

	.  reduce 31


78: reduce-reduce conflict (reduce 29, reduce 44) on SEMICOLON
state 78
	for_expr1 : assign_expr .  (29)
	if_expr : assign_expr .  (44)

	SEMICOLON  reduce 29
	.  reduce 44


state 79
	for_stmt : FOR LPACE for_expr1 . SEMICOLON for_expr2 SEMICOLON for_expr3 RPACE stmt

	SEMICOLON  shift 103


state 80
	for_expr1 : logic_expr .  (30)

	.  reduce 30


state 81
	input_stmt : INPUT LPACE ID . RPACE

	RPACE  shift 104


state 82
	print_stmt : PRINT LPACE ID . RPACE

	RPACE  shift 105


state 83
	print_stmt : PRINT LPACE NUMBER . RPACE

	RPACE  shift 106


state 84
	term : term . DIV factor
	term : term . MUL factor
	expr : expr ADD term .  (56)

	MUL  shift 67
	DIV  shift 68
	.  reduce 56


state 85
	term : term . DIV factor
	term : term . MUL factor
	expr : expr SUB term .  (57)

	MUL  shift 67
	DIV  shift 68
	.  reduce 57


state 86
	term : term . DIV factor
	term : term . MUL factor
	expr : expr MOD term .  (58)

	MUL  shift 67
	DIV  shift 68
	.  reduce 58


state 87
	bool_expr : expr EQ expr .  (47)
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 47


state 88
	bool_expr : expr GE expr .  (48)
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 48


state 89
	bool_expr : expr LE expr .  (49)
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 49


state 90
	bool_expr : expr GT expr .  (50)
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 50


state 91
	bool_expr : expr LT expr .  (51)
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 51


state 92
	expr : expr . ADD term
	expr : expr . MOD term
	bool_expr : expr GREATER expr .  (52)
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 52


state 93
	expr : expr . ADD term
	expr : expr . MOD term
	bool_expr : expr LESS expr .  (53)
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 53


state 94
	bool_expr : expr NE expr .  (54)
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 54


state 95
	declare_args : ID ASSIGN . expr

	ID  shift 38
	NUMBER  shift 9
	LPACE  shift 14

	expr  goto 107
	factor  goto 34
	term  goto 35


state 96
	idlist : declare_args COMMA . idlist

	ID  shift 61

	idlist  goto 108
	declare_args  goto 63


state 97
	term : term MUL factor .  (60)

	.  reduce 60


state 98
	term : term DIV factor .  (61)

	.  reduce 61


state 99
	logic_expr : if_expr OR logic_expr .  (41)

	.  reduce 41


state 100
	logic_expr : if_expr AND logic_expr .  (42)

	.  reduce 42


101: shift-reduce conflict (shift 8, reduce 16) on ID
101: shift-reduce conflict (shift 9, reduce 16) on NUMBER
101: shift-reduce conflict (shift 10, reduce 16) on INT
101: shift-reduce conflict (shift 11, reduce 16) on CHAR
101: shift-reduce conflict (shift 12, reduce 16) on BOOL
101: shift-reduce conflict (shift 13, reduce 16) on SEMICOLON
101: shift-reduce conflict (shift 14, reduce 16) on LPACE
101: shift-reduce conflict (shift 15, reduce 16) on LBRACE
101: shift-reduce conflict (shift 16, reduce 16) on IF
101: shift-reduce conflict (shift 17, reduce 16) on WHILE
101: shift-reduce conflict (shift 18, reduce 16) on FOR
101: shift-reduce conflict (shift 19, reduce 16) on INPUT
101: shift-reduce conflict (shift 20, reduce 16) on PRINT
state 101
	if_stmt : IF LPACE logic_expr RPACE . stmt
	if_stmt : IF LPACE logic_expr RPACE . stmt ELSE stmt
	stmt : .  (16)

	ID  shift 8
	NUMBER  shift 9
	INT  shift 10
	CHAR  shift 11
	BOOL  shift 12
	SEMICOLON  shift 13
	LPACE  shift 14
	LBRACE  shift 15
	IF  shift 16
	WHILE  shift 17
	FOR  shift 18
	INPUT  shift 19
	PRINT  shift 20
	.  reduce 16

	stmt  goto 109
	declare_stmt  goto 22
	assign_expr  goto 23
	while_stmt  goto 25
	expr  goto 26
	type  goto 27
	if_stmt  goto 28
	for_stmt  goto 29
	logic_expr  goto 30
	print_stmt  goto 31
	input_stmt  goto 32
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


102: shift-reduce conflict (shift 8, reduce 16) on ID
102: shift-reduce conflict (shift 9, reduce 16) on NUMBER
102: shift-reduce conflict (shift 10, reduce 16) on INT
102: shift-reduce conflict (shift 11, reduce 16) on CHAR
102: shift-reduce conflict (shift 12, reduce 16) on BOOL
102: shift-reduce conflict (shift 13, reduce 16) on SEMICOLON
102: shift-reduce conflict (shift 14, reduce 16) on LPACE
102: shift-reduce conflict (shift 15, reduce 16) on LBRACE
102: shift-reduce conflict (shift 16, reduce 16) on IF
102: shift-reduce conflict (shift 17, reduce 16) on WHILE
102: shift-reduce conflict (shift 18, reduce 16) on FOR
102: shift-reduce conflict (shift 19, reduce 16) on INPUT
102: shift-reduce conflict (shift 20, reduce 16) on PRINT
state 102
	while_stmt : WHILE LPACE logic_expr RPACE . stmt
	stmt : .  (16)

	ID  shift 8
	NUMBER  shift 9
	INT  shift 10
	CHAR  shift 11
	BOOL  shift 12
	SEMICOLON  shift 13
	LPACE  shift 14
	LBRACE  shift 15
	IF  shift 16
	WHILE  shift 17
	FOR  shift 18
	INPUT  shift 19
	PRINT  shift 20
	.  reduce 16

	stmt  goto 110
	declare_stmt  goto 22
	assign_expr  goto 23
	while_stmt  goto 25
	expr  goto 26
	type  goto 27
	if_stmt  goto 28
	for_stmt  goto 29
	logic_expr  goto 30
	print_stmt  goto 31
	input_stmt  goto 32
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 103
	for_stmt : FOR LPACE for_expr1 SEMICOLON . for_expr2 SEMICOLON for_expr3 RPACE stmt
	for_expr2 : .  (34)

	ID  shift 8
	NUMBER  shift 9
	LPACE  shift 14
	.  reduce 34

	assign_expr  goto 74
	expr  goto 26
	logic_expr  goto 111
	for_expr2  goto 112
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 104
	input_stmt : INPUT LPACE ID RPACE .  (40)

	.  reduce 40


state 105
	print_stmt : PRINT LPACE ID RPACE .  (38)

	.  reduce 38


state 106
	print_stmt : PRINT LPACE NUMBER RPACE .  (39)

	.  reduce 39


state 107
	declare_args : ID ASSIGN expr .  (24)
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 24


state 108
	idlist : declare_args COMMA idlist .  (21)

	.  reduce 21


109: shift-reduce conflict (shift 113, reduce 25) on ELSE
state 109
	if_stmt : IF LPACE logic_expr RPACE stmt .  (25)
	if_stmt : IF LPACE logic_expr RPACE stmt . ELSE stmt

	ELSE  shift 113
	.  reduce 25


state 110
	while_stmt : WHILE LPACE logic_expr RPACE stmt .  (27)

	.  reduce 27


state 111
	for_expr2 : logic_expr .  (33)

	.  reduce 33


state 112
	for_stmt : FOR LPACE for_expr1 SEMICOLON for_expr2 . SEMICOLON for_expr3 RPACE stmt

	SEMICOLON  shift 114


113: shift-reduce conflict (shift 8, reduce 16) on ID
113: shift-reduce conflict (shift 9, reduce 16) on NUMBER
113: shift-reduce conflict (shift 10, reduce 16) on INT
113: shift-reduce conflict (shift 11, reduce 16) on CHAR
113: shift-reduce conflict (shift 12, reduce 16) on BOOL
113: shift-reduce conflict (shift 13, reduce 16) on SEMICOLON
113: shift-reduce conflict (shift 14, reduce 16) on LPACE
113: shift-reduce conflict (shift 15, reduce 16) on LBRACE
113: shift-reduce conflict (shift 16, reduce 16) on IF
113: shift-reduce conflict (shift 17, reduce 16) on WHILE
113: shift-reduce conflict (shift 18, reduce 16) on FOR
113: shift-reduce conflict (shift 19, reduce 16) on INPUT
113: shift-reduce conflict (shift 20, reduce 16) on PRINT
state 113
	if_stmt : IF LPACE logic_expr RPACE stmt ELSE . stmt
	stmt : .  (16)

	ID  shift 8
	NUMBER  shift 9
	INT  shift 10
	CHAR  shift 11
	BOOL  shift 12
	SEMICOLON  shift 13
	LPACE  shift 14
	LBRACE  shift 15
	IF  shift 16
	WHILE  shift 17
	FOR  shift 18
	INPUT  shift 19
	PRINT  shift 20
	.  reduce 16

	stmt  goto 115
	declare_stmt  goto 22
	assign_expr  goto 23
	while_stmt  goto 25
	expr  goto 26
	type  goto 27
	if_stmt  goto 28
	for_stmt  goto 29
	logic_expr  goto 30
	print_stmt  goto 31
	input_stmt  goto 32
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 114
	for_stmt : FOR LPACE for_expr1 SEMICOLON for_expr2 SEMICOLON . for_expr3 RPACE stmt
	for_expr3 : .  (37)

	ID  shift 8
	NUMBER  shift 9
	LPACE  shift 14
	.  reduce 37

	assign_expr  goto 116
	expr  goto 117
	factor  goto 34
	for_expr3  goto 118
	term  goto 35


state 115
	if_stmt : IF LPACE logic_expr RPACE stmt ELSE stmt .  (26)

	.  reduce 26


state 116
	for_expr3 : assign_expr .  (35)

	.  reduce 35


state 117
	for_expr3 : expr .  (36)
	expr : expr . ADD term
	expr : expr . MOD term
	expr : expr . SUB term

	ADD  shift 50
	SUB  shift 51
	MOD  shift 52
	.  reduce 36


state 118
	for_stmt : FOR LPACE for_expr1 SEMICOLON for_expr2 SEMICOLON for_expr3 . RPACE stmt

	RPACE  shift 119


119: shift-reduce conflict (shift 8, reduce 16) on ID
119: shift-reduce conflict (shift 9, reduce 16) on NUMBER
119: shift-reduce conflict (shift 10, reduce 16) on INT
119: shift-reduce conflict (shift 11, reduce 16) on CHAR
119: shift-reduce conflict (shift 12, reduce 16) on BOOL
119: shift-reduce conflict (shift 13, reduce 16) on SEMICOLON
119: shift-reduce conflict (shift 14, reduce 16) on LPACE
119: shift-reduce conflict (shift 15, reduce 16) on LBRACE
119: shift-reduce conflict (shift 16, reduce 16) on IF
119: shift-reduce conflict (shift 17, reduce 16) on WHILE
119: shift-reduce conflict (shift 18, reduce 16) on FOR
119: shift-reduce conflict (shift 19, reduce 16) on INPUT
119: shift-reduce conflict (shift 20, reduce 16) on PRINT
state 119
	for_stmt : FOR LPACE for_expr1 SEMICOLON for_expr2 SEMICOLON for_expr3 RPACE . stmt
	stmt : .  (16)

	ID  shift 8
	NUMBER  shift 9
	INT  shift 10
	CHAR  shift 11
	BOOL  shift 12
	SEMICOLON  shift 13
	LPACE  shift 14
	LBRACE  shift 15
	IF  shift 16
	WHILE  shift 17
	FOR  shift 18
	INPUT  shift 19
	PRINT  shift 20
	.  reduce 16

	stmt  goto 120
	declare_stmt  goto 22
	assign_expr  goto 23
	while_stmt  goto 25
	expr  goto 26
	type  goto 27
	if_stmt  goto 28
	for_stmt  goto 29
	logic_expr  goto 30
	print_stmt  goto 31
	input_stmt  goto 32
	bool_expr  goto 33
	factor  goto 34
	term  goto 35
	if_expr  goto 36


state 120
	for_stmt : FOR LPACE for_expr1 SEMICOLON for_expr2 SEMICOLON for_expr3 RPACE stmt .  (28)

	.  reduce 28


##############################################################################
# Summary
##############################################################################

State 7 contains 13 shift-reduce conflict(s)
State 15 contains 13 shift-reduce conflict(s)
State 21 contains 13 shift-reduce conflict(s)
State 21 contains 1 reduce-reduce conflict(s)
State 23 contains 1 shift-reduce conflict(s)
State 78 contains 1 reduce-reduce conflict(s)
State 101 contains 13 shift-reduce conflict(s)
State 102 contains 13 shift-reduce conflict(s)
State 109 contains 1 shift-reduce conflict(s)
State 113 contains 13 shift-reduce conflict(s)
State 119 contains 13 shift-reduce conflict(s)


35 token(s), 24 nonterminal(s)
66 grammar rule(s), 121 state(s)


##############################################################################
# End of File
##############################################################################
