% https://www.hackerrank.com/challenges/area-under-curves-and-volume-of-revolving-a-curv
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	{ListZ,Left,Right} = doInput(),
	Area = areaEvalue(ListZ, Right)
		 - areaEvalue(ListZ, Left),
	Volume = volumeEvalue(ListZ, Right)
		 - volumeEvalue(ListZ, Left),
	io:format("~.1f~n", [Area]),
	io:format("~.1f~n", [Volume]).


areaEvalue(ListZ, X) ->
	lists:sum([areaIntegrate(K, X)
					|| K <- ListZ]).

areaIntegrate({A,B}, X) ->
	case B =:= (-1) of
	true ->
		A * math:log(X);
	_ ->
		A * math:pow(X, B+1) / (B+1)
	end.


volumeEvalue(ListZ, X) ->
	ListM = multiplyPolyomial(ListZ),
	lists:sum([volumeIntegrate(K, X)
					|| K <- ListM]).

volumeIntegrate(K, X) ->
	math:pi() * areaIntegrate(K, X).

multiplyPolyomial(ListZ) ->
	[{A1*A2,B1+B2} || {A1,B1} <- ListZ
		  			, {A2,B2} <- ListZ].

doInput() ->
	T = readList(),
	N = (length(T) - 2) div 2,
	{A,S} = lists:split(N, T),
	{B,[L,R]} = lists:split(N, S),
	{lists:zip(A, B),L,R}.

readList() ->
	readList([]).
readList(L) ->
	case io:fread("", "~d") of
	{ok,[N]} ->
		readList([N|L]);
	_ ->
		lists:reverse(L)
	end.
