#!/bin/ruby -w
loop  do
	terms = gets.chomp
	terms.split(" ").map!{|i| Integer(i)}
	puts terms
	break if terms == [0, 0, 0]
end