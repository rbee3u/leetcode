defmodule Solution do
  @spec add_two_numbers(a :: ListNode.t | nil, b :: ListNode.t | nil) :: ListNode.t | nil
  def add_two_numbers(a, b), do: add_two_numbers(a, b, 0)

  def add_two_numbers(nil, nil, 0), do: nil
  def add_two_numbers(a, b, carry) do
    {val_a, next_a} = extract(a)
    {val_b, next_b} = extract(b)
    carry = carry + val_a + val_b
    %ListNode{val: rem(carry, 10), next: add_two_numbers(next_a, next_b, div(carry, 10))}
  end

  def extract(%ListNode{val: val, next: next}), do: {val, next}
  def extract(_), do: {0, nil}
end
