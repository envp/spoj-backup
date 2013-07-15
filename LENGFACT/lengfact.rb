t=gets.to_i
t.times do
  n=gets.to_f
  if(n == 0 || n==1)
      puts 1;
  else
    x=Math.log10(n)
    e = Math::E
    p = Math::PI
    puts (n * (x - Math.log10(e)) + 0.5 * Math.log10(2*p) + 0.5 * x).ceil;
  end
end