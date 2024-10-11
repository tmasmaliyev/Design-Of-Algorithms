What is Endianness?

Endianness refers to the order in which bytes are arranged in memory. Let's say, different languages read their text in different orders. 
For example, English reads from left to right, while Arabic reads from right to left. Endianness works similarly for computers. 
If one computer reads bytes from left to right and another reads them from right to left, issues arise when these computers need to communicate.

Endianness ensures that bytes in computer memory are read in a specific order.

Endianness comes in two primary forms: Big-endian (BE) and Little-endian (LE).

Big-endian (BE): Stores the most significant byte first. This means that the first byte (at the lowest memory address) is the largest, 
which makes it easy to read left to right.

Little-endian (LE): Stores the least significant byte first. This means that the first byte (at the lowest memory address) is the smallest, 
which makes it easy to read right to left.

What is Big-endian?

In a big-endian system, the most significant byte is stored at the lowest memory address. This means the “big end” comes first. 
For instance, a 32-bit integer 0x12345678 would be stored in memory as follows in a big-endian system:

![Alt text](/Picture1.png)

Here, 0x12 is the most significant byte, placed at the lowest address (00), followed by 0x34, 0x56, and 0x78 at the highest address (03).

What is Little-endian?

A little-endian system stores the least significant byte (LSB) at the lowest memory address. The “little end” comes first. 
For the same 32-bit integer 0x12345678, a little-endian system would store it as:

![Alt text](/Picture2.png)

Here, 0x78 is the least significant byte, placed at the lowest address (00), followed by 0x56, 0x34, and 0x12 at the highest address (03).

Why Does Endianness Matter?

When computers with different endianness communicate, they must agree on the byte order to ensure data is correctly interpreted. 
For example, network protocols typically use big-endian format to standardize communication.


