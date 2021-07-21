add_executable(deflate
	main.cpp
	huffman_encoder.h huffman_encoder.cpp
	huffman_table.h huffman_table.cpp
	node.h node.cpp
	lzss_encoder.h lzss_encoder.cpp
	bits_container.h bits_container.cpp)
