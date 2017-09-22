% https://www.hackerrank.com/challenges/fp-hello-world-n-times
% Enter your code here. Read input from STDIN. Print output to STDOUT
% Your class should be named solution

-module(solution).
-export([main/0]).

main() ->
	{ok,[N]} = io:fread("", "~d"),
	helloWorldNTimes(N).

helloWorldNTimes(N) when N =< 0 ->
	ok;
helloWorldNTimes(N) ->
	io:format("Hello World~n"),
	helloWorldNTimes(N - 1).
