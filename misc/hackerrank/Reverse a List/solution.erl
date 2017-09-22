% https://www.hackerrank.com/challenges/fp-reverse-a-list
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	writeList(reverse(readList())).

reverse(L) ->
	reverse(L, []).
reverse([H|T], Acc) ->
	reverse(T, [H|Acc]);
reverse(_, Acc) ->
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

writeList([H|T]) ->
	io:format("~p~n", [H]),
	writeList(T);
writeList(_) ->
	ok.
