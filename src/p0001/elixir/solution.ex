defmodule Solution do
  @spec two_sum(nums :: [integer], target :: integer) :: [integer]
  def two_sum(nums, target) do
    two_sum(nums, 0, target, %{})
  end

  def two_sum([y | rest], j, target, dict) do
    x = target - y
    case dict do
      %{^x => i} ->
        [i, j]
      _ ->
        two_sum(rest, j + 1, target, Map.put(dict, y, j))
    end
  end
  def two_sum(_, _, _, _) do
    []
  end
end
