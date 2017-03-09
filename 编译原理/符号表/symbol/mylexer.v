#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 22 of your 30 day trial period.
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
# Date: 11/08/16
# Time: 18:46:30
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [\t]+

    2  ";"

    3  "("

    4  ")"

    5  "{"

    6  "}"

    7  "+"

    8  "-"

    9  "*"

   10  "/"

   11  "=="

   12  "if"

   13  "int"

   14  "="

   15  [0-9]+

   16  ([a-zA-Z]|[_])([a-zA-Z]|[0-9]|[_])*


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09               goto 3
	0x28               goto 4
	0x29               goto 5
	0x2a               goto 6
	0x2b               goto 7
	0x2d               goto 8
	0x2f               goto 9
	0x30 - 0x39 (10)   goto 10
	0x3b               goto 11
	0x3d               goto 12
	0x41 - 0x5a (26)   goto 13
	0x5f               goto 13
	0x61 - 0x68 (8)    goto 13
	0x69               goto 14
	0x6a - 0x7a (17)   goto 13
	0x7b               goto 15
	0x7d               goto 16


state 2
	^INITIAL

	0x09               goto 3
	0x28               goto 4
	0x29               goto 5
	0x2a               goto 6
	0x2b               goto 7
	0x2d               goto 8
	0x2f               goto 9
	0x30 - 0x39 (10)   goto 10
	0x3b               goto 11
	0x3d               goto 12
	0x41 - 0x5a (26)   goto 13
	0x5f               goto 13
	0x61 - 0x68 (8)    goto 13
	0x69               goto 14
	0x6a - 0x7a (17)   goto 13
	0x7b               goto 15
	0x7d               goto 16


state 3
	0x09               goto 3

	match 1


state 4
	match 3


state 5
	match 4


state 6
	match 9


state 7
	match 7


state 8
	match 8


state 9
	match 10


state 10
	0x30 - 0x39 (10)   goto 10

	match 15


state 11
	match 2


state 12
	0x3d               goto 17

	match 14


state 13
	0x30 - 0x39 (10)   goto 13
	0x41 - 0x5a (26)   goto 13
	0x5f               goto 13
	0x61 - 0x7a (26)   goto 13

	match 16


state 14
	0x30 - 0x39 (10)   goto 13
	0x41 - 0x5a (26)   goto 13
	0x5f               goto 13
	0x61 - 0x65 (5)    goto 13
	0x66               goto 18
	0x67 - 0x6d (7)    goto 13
	0x6e               goto 19
	0x6f - 0x7a (12)   goto 13

	match 16


state 15
	match 5


state 16
	match 6


state 17
	match 11


state 18
	0x30 - 0x39 (10)   goto 13
	0x41 - 0x5a (26)   goto 13
	0x5f               goto 13
	0x61 - 0x7a (26)   goto 13

	match 12


state 19
	0x30 - 0x39 (10)   goto 13
	0x41 - 0x5a (26)   goto 13
	0x5f               goto 13
	0x61 - 0x73 (19)   goto 13
	0x74               goto 20
	0x75 - 0x7a (6)    goto 13

	match 16


state 20
	0x30 - 0x39 (10)   goto 13
	0x41 - 0x5a (26)   goto 13
	0x5f               goto 13
	0x61 - 0x7a (26)   goto 13

	match 13


#############################################################################
# Summary
#############################################################################

1 start state(s)
16 expression(s), 20 state(s)


#############################################################################
# End of File
#############################################################################
