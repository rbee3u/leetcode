% https://www.hackerrank.com/challenges/fp-sum-of-odd-elements
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	io:format("~p~n", [sumOddElements(readList())]).

sumOddElements(L) ->
	sumOddElements(L, 0).
sumOddElements([H|T], Acc)
		when H rem 2 =:= 0 ->
	sumOddElements(T, Acc);
sumOddElements([H|T], Acc) ->
	sumOddElements(T, Acc+H);
sumOddElements(_, Acc) ->
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
