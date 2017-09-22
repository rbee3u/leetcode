% https://www.hackerrank.com/challenges/fp-filter-positions-in-a-list
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	writeList(filterPositions(readList())).

filterPositions(L) ->
	filterPositions(L, []).
filterPositions([_O,E|T], Acc) ->
	filterPositions(T, [E|Acc]);
filterPositions(_, Acc) ->
	lists:reverse(Acc).

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
