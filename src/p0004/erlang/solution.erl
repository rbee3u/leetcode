-spec find_median_sorted_arrays(Nums1 :: [integer()], Nums2 :: [integer()]) -> float().
find_median_sorted_arrays(Nums1, Nums2) ->
    helper(Nums1, Nums2, length(Nums1) + length(Nums2), 0).

helper([HA | _], [], 0, Acc) -> (Acc + HA) / 2;
helper([], [HB | _], 0, Acc) -> (Acc + HB) / 2;
helper([HA | _], [HB | _], 0, Acc) -> (Acc + min(HA, HB)) / 2;
helper([HA | _], [], 1, _) -> HA;
helper([], [HB | _], 1, _) -> HB;
helper([HA | _], [HB | _], 1, _) -> min(HA, HB);
helper([HA | TA], [], R, _) -> helper(TA, [], R - 2, HA);
helper([], [HB | TB], R, _) -> helper(TB, [], R - 2, HB);
helper([HA | TA] = LA, [HB | TB] = LB, R, _) ->
    if
        HA < HB ->
            helper(TA, LB, R - 2, HA);
        true ->
            helper(LA, TB, R - 2, HB)
    end.
