% https://www.hackerrank.com/challenges/fp-update-list
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	writeList(updateList(readList())).

updateList([H|T]) when H >= 0 ->
	[H|updateList(T)];
updateList([H|T]) ->
	[-H|updateList(T)];
updateList(_) ->
	[].

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
