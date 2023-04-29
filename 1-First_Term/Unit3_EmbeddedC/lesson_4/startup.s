@@ Eng. Ahmed Hassan (Learn_in_Depth.com)

.globl _reset

.section .vectors

.word stack_top
.word _reset
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler

.section .text

_reset:
		bl main 
		b .
.thumb_func

vector_handler:
	b _reset
