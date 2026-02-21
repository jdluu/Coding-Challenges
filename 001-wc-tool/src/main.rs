use std::env; // to read arguments passed in
use std::fs::File; // to read files
use std::io::{self, BufReader, Read}; // to read stdin

struct Config {
    count_bytes: bool,        // -c flag
    count_lines: bool,        // -l flag
    count_words: bool,        // -w flag
    count_chars: bool,        // -m flag
    filename: Option<String>, // filename which may exist
}

struct Counts {
    bytes: i32,
    lines: i32,
    words: i32,
    chars: i32,
}

//
fn main() -> io::Result<()> {
    // setup default config for flags
    let mut config = Config {
        count_bytes: false,
        count_lines: false,
        count_words: false,
        count_chars: false,
        filename: None,
    };

    // loop through arguments and ignore the first one which is path ccwc
    for arg in env::args().skip(1) {
        // If the arg starts with '-', its a flag and we loop through to handle clustered flags
        if arg.starts_with('-') {
            // loop through chars
            for c in arg.chars() {
                match c {
                    'c' => config.count_bytes = true,
                    'l' => config.count_lines = true,
                    'w' => config.count_words = true,
                    'm' => config.count_chars = true,
                    _ => println!("Unknown flag: {}", c),
                }
            }
        // Handles filename at end
        } else {
            config.filename = Some(arg);
        }
    }

    // if no options provided, default behavior is -c, -l, -w
    if !config.count_bytes && !config.count_lines && !config.count_words && !config.count_chars {
        config.count_bytes = true;
        config.count_lines = true;
        config.count_words = true;
    }

    // Create a Boxed Reader which does Dynamic Dispatch to handle multiple inputs sources
    let input: Box<dyn Read> = if let Some(path) = &config.filename {
        Box::new(File::open(path)?)
    } else{
        Box::new(io::stdin().lock())
    };

    // Store result of counting into object to be used for printing
    let results: Counts = perform_counts(input, &config)?;

    // print formatted results using flags to guide.
    print_results(&results, &config)
}

// separate function to count from file
fn perform_counts<R: Read>(mut reader: R, config: &Config) -> io::Result<Counts> {
    // Initialize counts
    let mut counts = Counts {
        bytes: 0,
        lines: 0,
        words: 0,
        chars: 0,
    };

    // Wrap reader in BufReader for speed.
    let mut reader = BufReader::new(reader);

    for byte_result in reader.bytes() {
        let b = byte_result?;
        counts.bytes += 1;
        if b == b'\n' {
            counts.lines += 1;
        }
    }
    Ok(counts)
}

fn print_results(results: &Counts, config: &Config) {
    if config.count_lines:
        print!("{}  ", results.lines);
    if config.count_words:
        print!("{}  ", results.words);
    if config.count_bytes:
        print!("{}  ", results.bytes);
    if config.count_chars:
        print!("{}  ", results.chars);

    if let Some(path) = &config.filename {
        print!("{}", path);
    } else {
        println!()
    }
}
