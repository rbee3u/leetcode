defmodule Solution do
  @spec length_of_longest_substring(s :: String.t) :: integer
  def length_of_longest_substring(s) do
    l = String.to_charlist(s)
    loop_j(0, l, 0, l, :array.new(256, {:default, 0}), 0)
  end

  def loop_j(_, _, _, [], _, result), do: result
  def loop_j(i, li, j, [y | _] = lj, count, result) do
    loop_i(i, li, j, lj, array_incr(y, 1, count), result)
  end

  def loop_i(i, [x | ti] = li, j, [y | tj] = lj, count, result) do
    case :array.get(y, count) > 1 do
      true ->
        loop_i(i + 1, ti, j, lj, array_incr(x, -1, count), result)
      _ ->
        loop_j(i, li, j + 1, tj, count, max(result, j - i + 1))
    end
  end

  def array_incr(i, d, array) do
    :array.set(i, :array.get(i, array) + d, array)
  end
end
