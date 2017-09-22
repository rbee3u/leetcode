% https://www.hackerrank.com/challenges/fp-list-replication
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	{ok,[S]} = io:fread("", "~d"),
	listReplicationLoop(S).

listReplicationLoop(S) ->
	case io:fread("", "~d") of
	{ok,[N]} ->
		duplicateWrite(N, S),
		listReplicationLoop(S);
	_ ->
		ok
	end.

duplicateWrite(_N, S) when S =< 0 ->
	ok;
duplicateWrite(N, S) ->
	io:format("~p~n", [N]),
	duplicateWrite(N, S-1).

