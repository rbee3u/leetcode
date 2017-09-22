% https://www.hackerrank.com/challenges/fp-filter-array
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	{ok,[X]} = io:fread("", "~d"),
	AnsList = [E || E <- readList()
						, E < X],
	writeList(AnsList).

readList() ->
	readList([]).
readList(L) ->
	case io:fread("", "~d") of
	{ok,[N]} ->
		readList([N|L]);
	_ ->
		lists:reverse(L)
	end.

writeList([H|T]) ->
	io:format("~p~n", [H]),
	writeList(T);
writeList(_) ->
	ok.
