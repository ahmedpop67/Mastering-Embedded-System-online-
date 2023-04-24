@@ Eng. Ahmed Hassan (Learn_in_Depth.com)

.globl reset

reset:
		ldr sp, = stack_top
		bl main 
stop:   b stop
