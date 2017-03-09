#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 71 of your 30 day trial period.
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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 12/27/16
# Time: 01:14:42
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ \t]+

    2  "//"[^\n]*|"/*"([^*]*|\*[^/]*)"*/"

    3  "\n"

    4  ";"

    5  ","

    6  "'"

    7  "("

    8  ")"

    9  "{"

   10  "}"

   11  "+"

   12  "-"

   13  "*"

   14  "/"

   15  "%"

   16  "||"

   17  "&&"

   18  "=="

   19  ">="

   20  "<="

   21  ">"

   22  "<"

   23  ">>"

   24  "<<"

   25  "!="

   26  "="

   27  "if"

   28  "else"

   29  "while"

   30  "for"

   31  "input"

   32  "print"

   33  "int"

   34  "char"

   35  "bool"

   36  [0-9]+

   37  ([a-zA-Z]|[_])([a-zA-Z]|[0-9]|[_])*


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 3
	0x21               goto 5
	0x25               goto 6
	0x26               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2f               goto 15
	0x30 - 0x39 (10)   goto 16
	0x3b               goto 17
	0x3c               goto 18
	0x3d               goto 19
	0x3e               goto 20
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61               goto 21
	0x62               goto 22
	0x63               goto 23
	0x64               goto 21
	0x65               goto 24
	0x66               goto 25
	0x67 - 0x68 (2)    goto 21
	0x69               goto 26
	0x6a - 0x6f (6)    goto 21
	0x70               goto 27
	0x71 - 0x76 (6)    goto 21
	0x77               goto 28
	0x78 - 0x7a (3)    goto 21
	0x7b               goto 29
	0x7c               goto 30
	0x7d               goto 31


state 2
	^INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 3
	0x21               goto 5
	0x25               goto 6
	0x26               goto 7
	0x27               goto 8
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2f               goto 15
	0x30 - 0x39 (10)   goto 16
	0x3b               goto 17
	0x3c               goto 18
	0x3d               goto 19
	0x3e               goto 20
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61               goto 21
	0x62               goto 22
	0x63               goto 23
	0x64               goto 21
	0x65               goto 24
	0x66               goto 25
	0x67 - 0x68 (2)    goto 21
	0x69               goto 26
	0x6a - 0x6f (6)    goto 21
	0x70               goto 27
	0x71 - 0x76 (6)    goto 21
	0x77               goto 28
	0x78 - 0x7a (3)    goto 21
	0x7b               goto 29
	0x7c               goto 30
	0x7d               goto 31


state 3
	0x09               goto 3
	0x20               goto 3

	match 1


state 4
	match 3


state 5
	0x3d               goto 32


state 6
	match 15


state 7
	0x26               goto 33


state 8
	match 6


state 9
	match 7


state 10
	match 8


state 11
	match 13


state 12
	match 11


state 13
	match 5


state 14
	match 12


state 15
	0x2a               goto 34
	0x2f               goto 35

	match 14


state 16
	0x30 - 0x39 (10)   goto 16

	match 36


state 17
	match 4


state 18
	0x3c               goto 36
	0x3d               goto 37

	match 22


state 19
	0x3d               goto 38

	match 26


state 20
	0x3d               goto 39
	0x3e               goto 40

	match 21


state 21
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 37


state 22
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 41
	0x70 - 0x7a (11)   goto 21

	match 37


state 23
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x67 (7)    goto 21
	0x68               goto 42
	0x69 - 0x7a (18)   goto 21

	match 37


state 24
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 43
	0x6d - 0x7a (14)   goto 21

	match 37


state 25
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 44
	0x70 - 0x7a (11)   goto 21

	match 37


state 26
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x65 (5)    goto 21
	0x66               goto 45
	0x67 - 0x6d (7)    goto 21
	0x6e               goto 46
	0x6f - 0x7a (12)   goto 21

	match 37


state 27
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 47
	0x73 - 0x7a (8)    goto 21

	match 37


state 28
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x67 (7)    goto 21
	0x68               goto 48
	0x69 - 0x7a (18)   goto 21

	match 37


state 29
	match 9


state 30
	0x7c               goto 49


state 31
	match 10


state 32
	match 25


state 33
	match 17


state 34
	0x00 - 0x29 (42)   goto 50
	0x2a               goto 51
	0x2b - 0xff (213)  goto 50


state 35
	0x00 - 0x09 (10)   goto 35
	0x0b - 0xff (245)  goto 35

	match 2


state 36
	match 24


state 37
	match 20


state 38
	match 18


state 39
	match 19


state 40
	match 23


state 41
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 52
	0x70 - 0x7a (11)   goto 21

	match 37


state 42
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61               goto 53
	0x62 - 0x7a (25)   goto 21

	match 37


state 43
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 54
	0x74 - 0x7a (7)    goto 21

	match 37


state 44
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 55
	0x73 - 0x7a (8)    goto 21

	match 37


state 45
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 27


state 46
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6f (15)   goto 21
	0x70               goto 56
	0x71 - 0x73 (3)    goto 21
	0x74               goto 57
	0x75 - 0x7a (6)    goto 21

	match 37


state 47
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 58
	0x6a - 0x7a (17)   goto 21

	match 37


state 48
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 59
	0x6a - 0x7a (17)   goto 21

	match 37


state 49
	match 16


state 50
	0x00 - 0x29 (42)   goto 50
	0x2a               goto 60
	0x2b - 0xff (213)  goto 50


state 51
	0x00 - 0x29 (42)   goto 61
	0x2a               goto 51
	0x2b - 0x2e (4)    goto 61
	0x2f               goto 62
	0x30 - 0xff (208)  goto 61


state 52
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 63
	0x6d - 0x7a (14)   goto 21

	match 37


state 53
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 64
	0x73 - 0x7a (8)    goto 21

	match 37


state 54
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 65
	0x66 - 0x7a (21)   goto 21

	match 37


state 55
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 30


state 56
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x74 (20)   goto 21
	0x75               goto 66
	0x76 - 0x7a (5)    goto 21

	match 37


state 57
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 33


state 58
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6d (13)   goto 21
	0x6e               goto 67
	0x6f - 0x7a (12)   goto 21

	match 37


state 59
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 68
	0x6d - 0x7a (14)   goto 21

	match 37


state 60
	0x2f               goto 62


state 61
	0x00 - 0x29 (42)   goto 61
	0x2a               goto 51
	0x2b - 0x2e (4)    goto 61
	0x30 - 0xff (208)  goto 61


state 62
	match 2


state 63
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 35


state 64
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 34


state 65
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 28


state 66
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 69
	0x75 - 0x7a (6)    goto 21

	match 37


state 67
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 70
	0x75 - 0x7a (6)    goto 21

	match 37


state 68
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 71
	0x66 - 0x7a (21)   goto 21

	match 37


state 69
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 31


state 70
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 32


state 71
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 29


#############################################################################
# Summary
#############################################################################

1 start state(s)
37 expression(s), 71 state(s)


#############################################################################
# End of File
#############################################################################
