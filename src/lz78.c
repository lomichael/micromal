/* function lz78_compress(input)
 * 	initialize_dictionary()
 * 	while not end_of_input(input)
 * 		prefix = find_longest_prefix(input, dictionary)
 * 		add_prefix_to_dictionary(prefix, dictionary)
 * 		output(dicionary_index(prefix), next_symbol)
 * 		update_input_pointer(input)
 * 	end while
 * end function
 */

/* function lz78_decompress(input)
 * 	initialize_dictionary()
 * 	while not end_of_input(input)
 * 		read(index, symbol) from input
 * 		entry = dictionary_entry(index) + symbol
 * 		output(entry)
 * 		add_entry_to_dictionary(entry, dictionary)
 * 	end while
 * end function
 */
