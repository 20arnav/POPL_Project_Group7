use std::{
    fs,
    io::prelude::*,
    net::{TcpListener, TcpStream},
};

fn handle_client(mut stream: TcpStream) {
    let mut buffer = [0; 1024];
    let mut contents = String::new();
        loop {
            let bytes_read = stream.read(&mut buffer).expect("Failed to read from client");
            if bytes_read == 0 {
                break;
            }
            let message = String::from_utf8_lossy(&buffer[0..bytes_read]);
            let s1 = "file1.txt\r\n";
            let s2 = "file2.txt\r\n";
            let s3 = "file3.txt\r\n";
            let resp1 = String::from("1");
            let resp2 = String::from("0");
            println!("Client requested for : {:?}", message);
            
            if message.eq(&s1)
            {
                contents = fs::read_to_string("file1.txt").unwrap();
                stream.write_all(&resp1.as_bytes()).expect("Failed to write to client");
                break;
            }
            else if message.eq(&s2)
            {
                contents = fs::read_to_string("file2.txt").unwrap();
                stream.write_all(&resp1.as_bytes()).expect("Failed to write to client");
                break;
            }
            else if message.eq(&s3)
            {
                contents = fs::read_to_string("file3.txt").unwrap();
                stream.write_all(&resp1.as_bytes()).expect("Failed to write to client");
                break;
            }
            else
            {
                stream.write_all(&resp2.as_bytes()).expect("Failed to write to client");
                println!("Failed to find the file");
                continue;
            }
            
        }

    let status_line = "HTTP/1.1 200 OK";
    let length = contents.len();

    let response =
        format!("{status_line}\r\nContent-Length: {length}\r\n{contents}");
    stream.write_all(response.as_bytes()).unwrap();
}

fn main() {
    let listener = TcpListener::bind("127.0.0.1:7878").expect("Failed to bind to address");
    println!("Server listening on 127.0.0.1:7878");
    for stream in listener.incoming() {
        match stream {
            Ok(client) => {
                std::thread::spawn(|| {
                    handle_client(client);
                });
            }
            Err(e) => {
                eprintln!("Failed to establish a connection: {}", e);
            }
        }
    }
}

