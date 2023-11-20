use std::{
    io::{prelude::*, BufReader},
    net::{TcpStream},
};
use std::io;


fn main() -> io::Result<()> {
    let mut client = TcpStream::connect("127.0.0.1:7878")?;
    println!("Connected to server. Type 'quit' to exit.");

    loop {
        let mut input = String::new();
        println!("Enter the filename to be sent to server. Valid filenames are: file1.txt, file2.txt and file3.txt. Enter quit to close connection");
        io::stdin().read_line(&mut input)?;
        if input.trim() == "quit" {
            break;
        }
        client.write_all(input.as_bytes())?;

        let mut buffer = [0; 1024];
        let bytes_read = client.read(&mut buffer)?;

        let ack = String::from_utf8_lossy(&buffer[0..bytes_read]);
        if ack == "1"
        {
        let buf_reader = BufReader::new(&mut client);
        let http_request: Vec<_> = buf_reader
        .lines()
        .map(|result| result.unwrap())
        .take_while(|line| !line.is_empty())
        .collect();
        println!("File contents are: {:#?}", http_request[2]);
        break;
        }
        else
        {
            println!("File not found");
            break;
        }

    }

    Ok(())
}
