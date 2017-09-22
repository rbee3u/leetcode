-spec length_of_longest_substring(S :: unicode:unicode_binary()) -> integer().
length_of_longest_substring(S) ->
    L = erlang:binary_to_list(S),
    loop_j(0, L, 0, L, array:new(256, {default, 0}), 0).

loop_j(_, _, _, [], _, Result) -> Result;
loop_j(I, LI, J, [Y | _] = LJ, Count, Result) ->
    loop_i(I, LI, J, LJ, array_incr(Y, 1, Count), Result).

loop_i(I, [X | TI] = LI, J, [Y | TJ] = LJ, Count, Result) ->
    case array:get(Y, Count) > 1 of
        true ->
            loop_i(I + 1, TI, J, LJ, array_incr(X, -1, Count), Result);
        false ->
            loop_j(I, LI, J + 1, TJ, Count, max(Result, J - I + 1))
    end.

array_incr(I, D, Array) -> array:set(I, array:get(I, Array) + D, Array).
