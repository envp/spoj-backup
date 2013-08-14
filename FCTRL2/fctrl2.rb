class Integer
  def fact
    (1..self).reduce(:*)
  end
end

t = gets.to_i

t.times do
	n = gets.to_i
	puts n.fact
end