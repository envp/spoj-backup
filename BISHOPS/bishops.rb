loop do
    n = gets
    break if n.nil?
    n = n.to_i
    if n == 1
        puts 1
    else
        puts 2*(n - 1)
    end
end