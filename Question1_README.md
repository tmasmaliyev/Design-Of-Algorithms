Computers work with binary code, which is basically a language made of 0s and 1s. This code is the core of everything computers do, 
whether it’s playing videos or running complicated programs. Some things, like certain letters in English, fit into a single byte, but other types of data need more than one byte. 

Endianness is an important idea that helps explain how computers read and make sense of these bytes.


What is Endianness?

Endianness refers to the order in which bytes are arranged in memory. Different languages read their text in different orders. 
For example, English reads from left to right, while Arabic reads from right to left. Endianness works similarly for computers. 
If one computer reads bytes from left to right and another reads them from right to left, issues arise when these computers need to communicate.

Endianness ensures that bytes in computer memory are read in a specific order. Each computer 

Endianness comes in two primary forms: Big-endian (BE) and Little-endian (LE).

Big-endian (BE): Stores the most significant byte first (The big end). This means that the first byte (at the lowest memory address) is the largest, 
which makes the most sense to people who read left to right.

Little-endian (LE): Stores the least significant byte first (The little end). This means that the first byte (at the lowest memory address) is the smallest, 
which makes the most sense to people who read right to left.

What is Big-endian?
In a big-endian system, the most significant byte is stored at the lowest memory address. This means the “big end” comes first. 
For instance, a 32-bit integer 0x12345678 would be stored in memory as follows in a big-endian system:

![Alt text](/Picture1.png)


