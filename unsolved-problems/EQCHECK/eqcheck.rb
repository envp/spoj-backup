t=gets.to_i
e = Array.new
t.times do
    e = gets.scan(/\d/).map(|x| x.to_i)
    if(((e[2]% e[0]) * (e[2]% e[1])) == 0)
       puts "yes" 
    else
        puts "no"
    end
end