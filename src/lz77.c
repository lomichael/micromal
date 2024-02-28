/* function lz77_compress(input)
 * 	initialize_buffers()
 * 	while not end_of_input(input)
 * 		match = find_longest_match(input)
 * 		if match found
 * 			output(match_distance, match_length, next_symbol)
 * 		else
 * 			output(0, 0, current_symbol)
 * 		end if
 * 		update_buffers()
 * 	end while
 * end function
 */

/* function lz77_decompress(input)
 * 	while not end_of_input(input)
 * 		read(token)
 * 		if token is a match
 * 			copy_match_to_output(token, output)
 * 		else
 * 			append_literal_to_output(token, output)
 * 		end if
 * 	end while
 * end function
 */
