/* function ppm_compress(input)
 * 	initialize_context_tree()
 * 	for each symbol in input
 * 		context = find_context_for_symbol(symbol, tree)
 * 		encode_symbol_using_context(symbol, context, output)
 * 		update_context_tree(symbol, tree)
 * 	end for
 * end function
 */

/* function ppm_decompress(input)
 * 	initialize_context_tree()
 * 	while not end_of_compressed_data(input)
 * 		context = current_context(tree)
 * 		symbol = decode_next_symbol(context, input)
 * 		output(symbol)
 * 		update_context_tree(symbol, tree)
 * 	end while
 * end function
 */
