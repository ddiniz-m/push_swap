# - * - Makefile - * -

PRT_SRC = ft_printf/ft_printf.c  ft_printf/ft_check.c ft_printf/ft_puthexa.c\
		ft_printf/utils.c

SRC_LIB = libft/ft_atoi.c libft/ft_lstnew.c libft/ft_lstadd_back.c\
		libft/ft_lstlast.c libft/ft_lstsize.c libft/ft_strcmp.c

SRCS = push_swap.c rulesRaw.c rules1.c rules2.c rules3.c utils.c sort.c\
		check.c binary.c stack.c $(SRC_LIB) $(PRT_SRC)

OBJS = $(SRCS:%.c=%.o)
NAME = push_swap
CC = @gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) -g $(SRCS) -o $(NAME)

run: $(NAME)
		@./push_swap -93 -15 42 15 21 27 52 63 37 -6 28 -71 -96 -72 -69 99 79 40 33 -59 -22 -47 -27 87 32 36 61 55 95 57 73 -82 -98 -92 13 -50 59 62 81 50 -16 65 75 11 38 51 35 -29 34 76 43 70 -7 49 -67 66 100 -74 -70 -26 -38 -21 -30 22 -42 -13 -24 92 -8 23 26 67 6 39 -49 9 -73 -81 10 -83 98 -31 -94 83 -79 89 -35 14 24 -53 -34 -48 72 20 -44 -18 -89 -87 -62 5 | wc -l

run500: $(NAME)
		@./push_swap 476 106 174 416 -89 419 319 -437 138 -246 400 410 490 -468 -118 411 449 429 -458 117 -244 491 -125 440 379 37 -324 153 -46 356 399 -24 32 -393 162 -147 192 -446 435 206 335 -87 422 -225 -26 107 188 -460 -133 22 189 -169 202 441 -236 387 154 -325 -10 -461 -58 -289 -428 228 12 268 -304 253 -187 -270 -350 311 -28 287 361 -367 340 493 333 -94 439 -240 -448 4 323 177 -442 -432 175 -203 -122 -249 -149 310 280 309 -252 -478 391 -322 278 -174 -243 -105 350 210 225 93 314 -78 486 329 347 -156 -275 -33 -221 -382 -459 -247 -487 -296 -103 -347 173 92 -84 464 108 -18 -109 -91 465 244 49 -131 220 -202 344 68 235 -193 499 298 -341 -212 -15 -293 -499 -165 86 -163 -136 380 -80 427 -123 367 -452 -473 230 276 462 450 398 477 169 -286 -104 -401 -474 -288 -53 336 -445 342 205 351 -272 466 372 407 -384 39 -424 57 365 339 120 343 -497 -29 -425 -353 -264 -65 183 58 -161 -368 -218 -479 257 128 -201 -180 349 -334 461 -386 301 -76 -2 97 69 -483 103 -51 -239 284 134 451 136 -30 495 386 -405 -379 330 236 -415 -39 401 -263 -258 353 -205 43 -441 -129 -176 366 200 -294 357 -329 -358 100 -36 431 -440 -482 -238 203 -77 217 56 -100 124 315 -5 5 -108 488 -170 489 327 84 195 168 123 -318 -375 -110 402 423 -186 270 27 -400 279 182 2 -7 408 -177 249 -262 -152 396 26 -132 91 -328 -290 460 444 -305 -369 -477 207 346 405 60 262 51 44 -370 87 -344 -8 355 65 -312 -414 -326 14 -420 394 -269 122 157 426 -207 171 420 -171 144 -97 -381 480 -85 -130 -470 -366 447 313 467 30 180 23 -336 413 457 -61 321 88 9 161 241 377 -354 389 63 -313 -434 243 -172 42 -419 -481 281 -308 36 -55 -35 473 -49 82 -465 252 -454 248 -25 -436 267 -159 369 -418 -155 393 -54 -208 -355 11 475 -490 472 -301 -392 -137 212 299 -413 363 0 383 -121 -444 -88 -134 385 436 224 231 341 384 -464 170 78 293 190 -284 -119 -423 -90 -72 142 -498 89 -11 312 105 -164 320 104 -160 -385 -484 -154 -68 -486 -291 19 -9 479 55 239 317 -376 -200 -456 -472 204 295 261 265 -480 208 214 -48 316 -407 -50 -95 -197 -254 54 18 325 -64 432 -475 -256 -150 -66 53 -116 73 -37 -98 213 414 -75 -276 -251 110 -421 -23 187 28 -185 -222 -206 109 -20 -494 -52 496 -226 71 140 -340 -406 20 127 -34 500 -297 -395 | wc -l

val: $(NAME)
		@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./push_swap -93 -15 42 15 21 27 52 63 37 -6 28 -71 -96 -72 -69 99 79 40 33 -59 -22 -47 -27 87 32 36 61 55 95 57 73 -82 -98 -92 13 -50 59 62 81 50 -16 65 75 11 38 51 35 -29 34 76 43 70 -7 49 -67 66 100 -74 -70 -26 -38 -21 -30 22 -42 -13 -24 92 -8 23 26 67 6 39 -49 9 -73 -81 10 -83 98 -31 -94 83 -79 89 -35 14 24 -53 -34 -48 72 20 -44 -18 -89 -87 -62 5 | wc -l

clean:
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re run val