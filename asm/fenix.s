.name		"the knock puncher"
.comment	"il va vous les briser"

		st	r1,9
		live	%42
		fork	%:live
debut:		fork	%:attaque
		fork	%:live1
	
attaque:	fork	%:live1
		zjmp	%:debut
		zjmp	%:attaque

live1:		live	%42
		st	r1,24
		st	r1,18
		st	r1,12
		st	r1,6
         	live	%42
		live	%42
		live	%42
		live	%42
		zjmp	%-20

live:		st	r1, 6

back_wall:	fork	%:back_wall1
		fork	%:live
		zjmp	%-6

back_wall1:	st	r6,-400
		st	r6,-401
		st	r6,-402
		st	r6,-403
		st	r6,-404
		st	r6,-405
		st	r6,-406
		st	r6,-407
		st	r6,-408
		st	r6,-409
		st	r6,-410
		st	r6,-411
		st	r6,-412
		st	r6,-413
		st	r6,-414
		st	r6,-415
		st	r6,-416
		st	r6,-417
		st	r6,-418
		st	r6,-419
		st	r6,-420
		st	r6,-421
		st	r6,-422
		st	r6,-423
		st	r6,-424
		st	r6,-425
		zjmp	%:back_wall1