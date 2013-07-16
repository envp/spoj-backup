n=gets.to_i
n.times do
	u=gets.to_f
	puts (0.5-0.5/(u*u+u+1)).round(5)
end