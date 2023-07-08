# filter-butterworh-c
Simple Chebyshev and Butterworth implementation in C, double precision. Works well on macOS 13.4.1.

Features

 * lowpass
 * highpass
 * butterworth
 * chebyshev
 * ripple percent
   

This imlementation is based on algorithm from [https://exstrom.com/journal/sigproc/dsigproc.html](https://www.analog.com/media/en/technical-documentation/dsp-book/dsp_book_Ch20.pdf)

# Run example
make example
./example

# Steps to use a filter
Create a filter object using create_***_pass_filter(params...)

example: ChebFilter* filter = create_bw_low_pass_filter(ORDER, (double)2*M_PI*205/44100);

If fc is the cut-off frequency in hertz, the filter cut-off frequency must be expressed by PI*fc/framerate. FC should be included in the [0, 0.5] range.

Use filter to filter incoming doubles one by one. The filtered output is a double as well.

After using the filter, release the filter using free_***_passp(filter).
