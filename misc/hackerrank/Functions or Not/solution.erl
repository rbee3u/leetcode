% https://www.hackerrank.com/challenges/functions-or-not
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	{ok,[T]} = io:fread("", "~d"),
	loopCases(T).

loopCases(T) when T =< 0 ->
	ok;
loopCases(T) ->
	{ok,[N]} = io:fread("", "~d"),
	PairList = readPairList(N),
	case isFunction(PairList) of
	true -> io:format("YES~n");
	_ ->    io:format("NO~n")
	end,
	loopCases(T-1).

isFunction(PairList) ->
	PairList2 = lists:sort(PairList),
	isFunction2(PairList2).
isFunction2([{A,B1},{A,B2}|_]=[_|T]) ->
	if B1 =/= B2 ->
		false;
	true ->
		isFunction2(T)
	end;
isFunction2([_|T]) ->
	isFunction2(T);
isFunction2(_) ->
	true.

readPairList(N) ->
	[begin {ok,[A,B]} = io:fread("", "~d~d")
		, {A,B} end || _ <- lists:seq(1, N)].

