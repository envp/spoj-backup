+++								! set c0 = 3, @c0
>								! Move to c1, @c1
> +++++ + [						! Move to c2, set c2 = 6 counter to make 48 (ASCII 0)
	> +++++ +++					! c3 += 8
	< -							! c2 -= 1
]								! c2 = 0 , c3 = 48, @c2
> [								! Loop to move c3 -> c2, @c2
	< +
	> -
]								! c2 = 48 , c3 = 0, @c2
> +++++ ++++					! set c3 = 9 (carry detection), @c3
> +								! set c4 = 1 , @c4
>,								! read c5 = 100's, @c5
>,								! read c6 = 10's, @c6
>,								! read c7 = 1's, @c7
< < < [							! Convert ASCII numbers to   , @c5
	> -							
	> -
	> -
	< < < -
]								! c5-c6-c7 contains decimal number now, @c5
> > +
