% https://www.hackerrank.com/challenges/fp-list-length
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	Ans = listLength(readList()),
	io:format("~p~n", [Ans]).

listLength(L) ->
	listLength(L, 0).
listLength([H|T], Acc) ->
	listLength(T, Acc+1);
listLength(_, Acc) ->
	Acc.

readList() ->
	readList([]).
readList(L) ->
	case io:fread("", "~d") of
	{ok,[N]} ->
		readList([N|L]);
	_ ->
		lists:reverse(L)
	end.
