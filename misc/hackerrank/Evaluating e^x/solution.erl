% https://www.hackerrank.com/challenges/eval-ex
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	{ok,[N]} = io:fread("", "~d"),
	writeList([exp(X) || X <- readList(N)]).

exp(X) ->
	exp(X, 1, 1, 1, 0).
exp(_X, _Numerator, _Denominator, IterCount, Acc)
	when IterCount > 10 -> Acc;
exp(X, Numerator, Denominator, IterCount, Acc) ->
	Numerator2 = Numerator * X,
	Denominator2 = Denominator * IterCount,
	IterCount2 = IterCount + 1,
	Acc2 = Acc + Numerator / Denominator,
	exp(X, Numerator2, Denominator2, IterCount2, Acc2).

readList(N) ->
	[begin {ok,[X]} = io:fread("", "~f"),
		X end || _ <- lists:seq(1, N)].

writeList([H|T]) ->
	io:format("~.4f~n", [H]),
	writeList(T);
writeList(_) ->
	ok.
