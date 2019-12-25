TIMESTAMP=$(shell date +%Y%m%d-%H%M%S)

executive : animation.c func_shape.c img.c
	gcc animation.c func_shape.c img.c -lm -o executive
	./executive
	convert -delay 5 outputs/img*.ppm outputs/anim_${TIMESTAMP}.gif
#	rm outputs/img*.ppm
	echo ./outputs/*.ppm | xargs rm -f

