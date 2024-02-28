/* function arithmetic_compress(input)
 *	initialize_model()
 *	for each symbol in input
 *		update_and_encode(symbol, model, output)
 *	end for
 *	finalize_encoding(output)
 * end function
 */

/* function arithmetic_decompress(input)
 * 	initialize_model()
 * 	while not end_of_compressed_data(input)
 * 		symbol = decode_next_symbol(model, input)
 * 		update_model(symbol, model)
 * 		append_symbol_to_output(symbol, output)
 * 	end while
 * end function
 */
