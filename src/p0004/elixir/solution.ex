defmodule Solution do
  @spec find_median_sorted_arrays(nums1 :: [integer], nums2 :: [integer]) :: float
  def find_median_sorted_arrays(nums1, nums2) do
    helper(nums1, nums2, length(nums1) + length(nums2), 0)
  end

  def helper([ha | _], [], 0, acc), do: (acc + ha) / 2
  def helper([], [hb | _], 0, acc), do: (acc + hb) / 2
  def helper([ha | _], [hb | _], 0, acc), do: (acc + min(ha, hb)) / 2
  def helper([ha | _], [], 1, _), do: ha
  def helper([], [hb | _], 1, _), do: hb
  def helper([ha | _], [hb | _], 1, _), do: min(ha, hb)
  def helper([ha | ta], [], r, _), do: helper(ta, [], r - 2, ha)
  def helper([], [hb | tb], r, _), do: helper(tb, [], r - 2, hb)
  def helper([ha | ta] = la, [hb | tb] = lb, r, _) do
    if ha < hb do
      helper(ta, lb, r - 2, ha)
    else
      helper(la, tb, r - 2, hb)
    end
  end
end
