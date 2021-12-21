#othello game file
OBJ = main_othello.o
CAL = call_othello.o init_window.o draw_stone.o draw_player.o update_window.o judge.o
REV = check_reversi.o count_stone.o count_reversi.o
RUN = run_othello.o chose_area.o set_stone.o set_direction.o print_info.o

LDLIBS=-lncursesw
main_othello:$(OBJ) $(CAL) $(REV) $(RUN)
