/* function lzw_compress(input)
 * 	initialize_dictionary()
 * 	while not end_of_input(input)
 * 		w = find_longest_sequence_in_dictionary(input, dictionary)
 * 		output(dictionary_index(w))
 * 		update_dictinoary(w + next_symbol, dictionary)
 * 		update_input_pointer(input)
 * 	end while
 * end function
 */

/* function lzw_decompress(input)
 * 	initialize_dictionary()
 * 	while not end_of_input(input)
 * 		read(code) from input
 * 		entry = dictionary_entry(code)
 * 		output(entry)
 * 		update_dictionary_with_previous_entry_and_first_symbol(entry, dictionary)
 * 	end while
 * end function
 */
