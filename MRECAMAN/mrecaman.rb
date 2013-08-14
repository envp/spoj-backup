a = Hash.new
a[:0] = true
for i in 1..5000000
	temp = a[(i - 1).to_sym] - i
	if temp > 0 && a[i.to_sym].empty?
		
	end
end