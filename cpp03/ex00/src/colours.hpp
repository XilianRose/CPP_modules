#pragma once

#define	BOLDON "\33[1m"
#define	BOLDOFF "\33[21m"
#define	UNDERLINEON "\33[4m"
#define	UNDERLINEOFF "\33[24m"
#define NC "\33[0m"

/*	4-bit	*/
#define RED "\33[0;91m"
#define GREEN "\33[0;92m"
#define YELLOW "\33[0;93m"
#define BLUE "\33[0;94m"
#define MAGENTA "\33[0;95m"
#define CYAN "\33[0;96m"

/*	8-bit	*/
/*	\033[38;5;<FG COLOR>m	*/
#define	LILAC "\33[38;5;141m"

/*	RGB	*/
/*	\033[38;2;<r>;<g>;<b>m	(foreground)*/