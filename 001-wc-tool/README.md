# Challenge 001: Build Your Own wc Tool

## Requirements
1. Need to read from given file.
2. user types ccwc which is an alias for wc
3. there are four possible flags
  a. -c, outputs number of bytes in a file 
  b. -l, outputs number of lines in a file
  c. -w, outputs number of words in a file
  d. -m, outputs number of chars in a file, if current locale does not support multibyte chars, this will match -c
4. if no options provided, default behavior is -c, -l, -w
5. also need to be able to read from std input if no file name given
6. Format is ccwc -flag file.txt

## Notes

### For main function
create two structs, one to store flags and file name, and then one to store counts

filename is Option<String> which means it is either String or None as a filename might not be provided.

we use std::env:args() which will pass arguments.
we also use skip(1) to skip the first element

since args are strings, we can use str function starts_with('-) to match prefix slice of a flag.

now we iterate through the arg using .chars()

we use match to set flags as true, also handles clustered flags.
we also handle unknown flags and print them.

otherwise, what's left is the filename. We use Some() for Rust's safety to specifically declare that either the filename is there or it is None.

then we check for default behavior using a basic if statement if no flags exist.







### Reference Links
#### General Knowledge
https://doc.rust-lang.org/stable/book/ch05-01-defining-structs.html

#### For main
https://doc.rust-lang.org/std/env/fn.args.html
https://doc.rust-lang.org/std/iter/trait.Iterator.html#method.skip
https://doc.rust-lang.org/std/primitive.str.html#method.starts_with
https://doc.rust-lang.org/stable/core/char/index.html
https://doc.rust-lang.org/stable/std/keyword.match.html
https://doc.rust-lang.org/std/option/enum.Option.html#variant.Some
https://doc.rust-lang.org/stable/std/boxed/index.html
https://doc.rust-lang.org/stable/std/keyword.dyn.html
https://doc.rust-lang.org/stable/std/io/trait.Read.html
https://doc.rust-lang.org/std/fs/struct.File.html
https://doc.rust-lang.org/std/io/struct.Stdin.html
#### For perform_counts
https://doc.rust-lang.org/std/io/struct.BufReader.html
https://doc.rust-lang.org/stable/std/primitive.str.html#method.bytes
https://doc.rust-lang.org/stable/std/result/index.html
https://doc.rust-lang.org/stable/std/result/enum.Result.html#variant.Ok

#### For print_results
https://doc.rust-lang.org/std/macro.print.html
