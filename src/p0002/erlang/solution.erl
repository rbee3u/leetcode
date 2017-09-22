-spec add_two_numbers(A :: #list_node{} | null, B :: #list_node{} | null) -> #list_node{} | null.
add_two_numbers(A, B) ->
    add_two_numbers(A, B, 0).

add_two_numbers(null, null, 0) ->
    null;
add_two_numbers(A, B, Carry) ->
    {ValA, NextA} = extract(A),
    {ValB, NextB} = extract(B),
    C = Carry + ValA + ValB,
    #list_node{val = C rem 10, next = add_two_numbers(NextA, NextB, C div 10)}.

extract(#list_node{val = Val, next = Next}) -> {Val, Next};
extract(_) -> {0, null}.
