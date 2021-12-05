use std::env;
use std::fs::File;
use std::io::{self, BufRead};

fn main() {
	let args: Vec<String> = env::args().collect();
	if let Ok(lines) = read_lines(&args[1]) {
		let mut counter: i32 = 0;
		let mut prev: i32 = -1;
		for (i, line) in lines.enumerate() {
			if let Ok(l) = line {
				let val = l.parse::<i32>().unwrap();
				if i == 0 {
					prev = val;
					continue;
				}
				if val > prev {
					counter += 1;
				}
				prev = val;
			}
		}
		println!("{}", counter);
	}
}

fn read_lines(fname: &str) -> io::Result<io::Lines<io::BufReader<File>>> {
	let file = File::open(fname)?;
	Ok(io::BufReader::new(file).lines())
}
