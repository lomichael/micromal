/* function ans_compress(input)
 * 	initialize_state()
 * 	for each symbol in input (reverse order)
 * 		encode_symbol(symbol, state, table)
 * 	end for
 * 	output_state(state)
 * end function
 */

/* function ans_decompress(input)
 * 	read_initial_state(input)
 * 	while not end_of_state(state)
 * 		symbol = decode_symbol(state, table)
 * 		output(symbol)
 * 	end while
 * end function
 */
