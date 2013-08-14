t = gets.to_i
t.times do
	x = 0
	n = gets.to_i
	n.times { x += (gets.to_i) % n}
	puts x
end