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
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 11/22/16
# Time: 10:58:12
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : expr $end

    1  expr : ID


##############################################################################
# States
##############################################################################

state 0
	$accept : . expr $end

	ID  shift 1

	expr  goto 2


state 1
	expr : ID .  (1)

	.  reduce 1


state 2
	$accept : expr . $end  (0)

	$end  accept


##############################################################################
# Summary
##############################################################################

3 token(s), 2 nonterminal(s)
2 grammar rule(s), 3 state(s)


##############################################################################
# End of File
##############################################################################
