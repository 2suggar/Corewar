# hey ladies

.name "zork"
.comment "I'M ALIIIIVE"

fork	%:coregeni
ardeftgt:

ardefgeni:
ardefgen:
	fork 	%:ardefgen

ardefinit:
	sti		r1,%:ardefl1,%1
	sti		r1,%:ardefchk,%1

ardefwrite:
ardefl1:
	sti		r4,%:ardeftgt,r2
	sti		r4,%:ardeftgt,r2
ardefchk:
	zjmp	%:ardefinit
ardefloop:
	zjmp	%:ardefwrite


coregeni:
