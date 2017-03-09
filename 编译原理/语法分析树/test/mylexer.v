#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 36 of your 30 day trial period.
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
# Date: 11/22/16
# Time: 10:57:03
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  ([a-zA-Z]|[_])([a-zA-Z]|[0-9]|[_])*


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x41 - 0x5a (26)   goto 3
	0x5f               goto 3
	0x61 - 0x7a (26)   goto 3


state 2
	^INITIAL

	0x41 - 0x5a (26)   goto 3
	0x5f               goto 3
	0x61 - 0x7a (26)   goto 3


state 3
	0x30 - 0x39 (10)   goto 3
	0x41 - 0x5a (26)   goto 3
	0x5f               goto 3
	0x61 - 0x7a (26)   goto 3

	match 1


#############################################################################
# Summary
#############################################################################

1 start state(s)
1 expression(s), 3 state(s)


#############################################################################
# End of File
#############################################################################
