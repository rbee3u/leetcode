% https://www.hackerrank.com/challenges/fp-array-of-n-elements
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	{ok,[N]} = io:fread("", "~d"),
% Fill up these questions marks to call a function (written by you)
% Which creates an array with N elements     
	Arr = duplicate(N),
	io:format("~B~n", [length(Arr)]).
% Do not change the lines of code already present.
% That is to assist us in evaluating whether the array you created
% has, indeed N elements.

duplicate(N) ->
	duplicate(N, []).
duplicate(N, Acc) when N =< 0 ->
	lists:reverse(Acc);
duplicate(N, Acc) ->
	duplicate(N-1, [0|Acc]).
