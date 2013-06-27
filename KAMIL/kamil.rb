10.times do
s=gets
p=1
s.gsub(/[DTFL]/){p*=2}
puts p
end