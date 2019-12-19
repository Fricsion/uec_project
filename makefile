TIMESTAMP=$(shell date +%Y%m%d-%H%M%S)

executive : animate2.c func_shape.c img.c
	gcc animate2.c func_shape.c img.c -lm -o executive
	./executive
	convert -delay 5 outputs/img*.ppm outputs/anim_${TIMESTAMP}.gif
	rm outputs/img*.ppm
