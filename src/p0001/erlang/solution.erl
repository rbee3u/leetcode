-spec two_sum(Nums :: [integer()], Target :: integer()) -> [integer()].
two_sum(Nums, Target) ->
    two_sum(Nums, 0, Target, #{}).

two_sum([Y | Rest], J, Target, Dict) ->
    X = Target - Y,
    case Dict of
        #{X := I} ->
            [I, J];
        _ ->
            two_sum(Rest, J + 1, Target, Dict#{Y => J})
    end;
two_sum(_, _, _, _) -> [].
