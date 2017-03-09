#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 13 of your 30 day trial period.
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
# Date: 10/30/16
# Time: 16:08:00
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  \n

    2  ^verb

    3  ^adj

    4  ^adv

    5  ^noun

    6  ^prep

    7  ^pron

    8  ^conj

    9  [a-zA-Z]+


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x0a               goto 3
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x7a (26)   goto 4


state 2
	^INITIAL

	0x0a               goto 3
	0x41 - 0x5a (26)   goto 4
	0x61               goto 5
	0x62               goto 4
	0x63               goto 6
	0x64 - 0x6d (10)   goto 4
	0x6e               goto 7
	0x6f               goto 4
	0x70               goto 8
	0x71 - 0x75 (5)    goto 4
	0x76               goto 9
	0x77 - 0x7a (4)    goto 4


state 3
	match 1


state 4
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x7a (26)   goto 4

	match 9


state 5
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x63 (3)    goto 4
	0x64               goto 10
	0x65 - 0x7a (22)   goto 4

	match 9


state 6
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x6e (14)   goto 4
	0x6f               goto 11
	0x70 - 0x7a (11)   goto 4

	match 9


state 7
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x6e (14)   goto 4
	0x6f               goto 12
	0x70 - 0x7a (11)   goto 4

	match 9


state 8
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x71 (17)   goto 4
	0x72               goto 13
	0x73 - 0x7a (8)    goto 4

	match 9


state 9
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x64 (4)    goto 4
	0x65               goto 14
	0x66 - 0x7a (21)   goto 4

	match 9


state 10
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x69 (9)    goto 4
	0x6a               goto 15
	0x6b - 0x75 (11)   goto 4
	0x76               goto 16
	0x77 - 0x7a (4)    goto 4

	match 9


state 11
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x6d (13)   goto 4
	0x6e               goto 17
	0x6f - 0x7a (12)   goto 4

	match 9


state 12
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x74 (20)   goto 4
	0x75               goto 18
	0x76 - 0x7a (5)    goto 4

	match 9


state 13
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x64 (4)    goto 4
	0x65               goto 19
	0x66 - 0x6e (9)    goto 4
	0x6f               goto 20
	0x70 - 0x7a (11)   goto 4

	match 9


state 14
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x71 (17)   goto 4
	0x72               goto 21
	0x73 - 0x7a (8)    goto 4

	match 9


state 15
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x7a (26)   goto 4

	match 3


state 16
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x7a (26)   goto 4

	match 4


state 17
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x69 (9)    goto 4
	0x6a               goto 22
	0x6b - 0x7a (16)   goto 4

	match 9


state 18
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x6d (13)   goto 4
	0x6e               goto 23
	0x6f - 0x7a (12)   goto 4

	match 9


state 19
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x6f (15)   goto 4
	0x70               goto 24
	0x71 - 0x7a (10)   goto 4

	match 9


state 20
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x6d (13)   goto 4
	0x6e               goto 25
	0x6f - 0x7a (12)   goto 4

	match 9


state 21
	0x41 - 0x5a (26)   goto 4
	0x61               goto 4
	0x62               goto 26
	0x63 - 0x7a (24)   goto 4

	match 9


state 22
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x7a (26)   goto 4

	match 8


state 23
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x7a (26)   goto 4

	match 5


state 24
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x7a (26)   goto 4

	match 6


state 25
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x7a (26)   goto 4

	match 7


state 26
	0x41 - 0x5a (26)   goto 4
	0x61 - 0x7a (26)   goto 4

	match 2


#############################################################################
# Summary
#############################################################################

1 start state(s)
9 expression(s), 26 state(s)


#############################################################################
# End of File
#############################################################################
