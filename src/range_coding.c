/* function range_compress(input)
 * 	initialize_model()
 * 	for each symbol in input
 * 		encode_symbol_using_ranges(symbol, model, outptu)
 * 		update_model(symbol, model)
 * 	end for
 * 	finalize_output(output)
 * end function
 */

/* function range_decompress(input)
 * 	initialize_model()
 * 	while not end_of_compressed_data(input)
 * 		symbol = decode_symbol_using_ranges(model, input)
 * 		output(symbol)
 * 		update_model(symbol, model)
 * 	end while
 * end function
 */
