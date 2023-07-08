# filter-butterworh-c
Simple Chebyshev and Butterworth implementation in C, double precision. Works well on macOS 13.4.1.

Features

 * lowpass
 * highpass

This imlementation is based on algorithm from [https://exstrom.com/journal/sigproc/dsigproc.html](https://www.analog.com/media/en/technical-documentation/dsp-book/dsp_book_Ch20.pdf)

# Run example
make example
./example

# Steps to use a filter
Create a filter object using create_***_pass_filter(params...)

Use filter to filter incoming doubles one by one. The output is a double.

After using the filter, release the filter using free_***_passp(filter).
