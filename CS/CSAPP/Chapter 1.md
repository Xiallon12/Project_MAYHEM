# A Tour Of Computer Systems

#### Introduction
- A journey of the program "hello" in C, starting from compiling process
until concurrent applications.
- A program is stored in the form of a source file/source program.

![[Pasted image 20260918174238.png]]
#### 1.1
- All information in a system is represented in the computer as bits.
- Usually those bits are decided according to ASCII.
- What distinguishes data is context.

#### 1.2
- Source files in a preprocessored formatted state are then compiled into a machine instruction form or assembly, which is then assembled into object binaries that are linked together to form the final executable object program (binary).

![[Pasted image 20260918174216.png]]
#### 1.3
- Reasons to understand compilation systems:100\%
	1. Optimizing program performance.
	2. Understanding link-time errors.
	3. Avoiding security holes.
#### 1.4
- A shell is a program that prompts you for a command (or an executable) then executes it if possible.
- Hardware of a system:
	1. Buses: Transfer fixed size chunks of bits (words) between components.
	2. I/O Devices: Connect the system to the external world, through chips (motherboard) or adapters (like usb).
	3. Main Memory: Temporary storage, RAM.
	4. CPU: The engine that executes instructions from the main memory.

![[Pasted image 20260918174251.png]]

- The CPU has a program counter (PC) that points to the instruction that executed by the system. After the CPU executes the instruction, it updates the PC.
- CPU does many instructions like:
	1. Load: Copy from memory to register.
	2. Store: Copy from register to memory.
	3. Operate: Send two values to the ALU and operate on them, ​then store the result in a register.
	4. Jump: Overwrite the PC.

#### 1.5
- Cache memory is memory that is near the processor and much faster to access.
- It serves as an intermediate staging stage between the main memory and the CPU.
- It usually consists of multiple layers, typically 2 or 3.
- Its main purpose is to decrease the gap between processor and memory speed.

![[Pasted image 20260918175051.png]]

![[Pasted image 20260918175112.png]]

#### 1.6
- Memory is found in hierarchies within computers.
- Each level of memory hierarchy serves as a cache to the level below it.

#### 1.7
- An operating system (OS) is a software that acts as an abstraction layer between the hardware and the software.
- It has two main purposes:
    1. To protect hardware from misuse.
    2. To provide applications with abstractions for hardware devices.

![[Pasted image 20260918175903.png]]

- A process is the operating system’s abstraction for a running program.
- Multiple processes can run concurrently on the same system, and each process appears to have exclusive use of the hardware.
- By *concurrently*, we mean that the instructions of one process are interleaved with the instructions of another process (context switching).
- In most systems, there are more processes to run than there are CPUs to run them.
- The OS keeps track of the *program state* (context).

![[Pasted image 20260918180401.png]]

- The *kernel* is OS code that performs *system calls.*
- Modern programs consist of multiple execution units called *threads*.
- Programs view virtual memory as a *virtual address space*.
- Virtual address space consists of (from down up):
	1. Program code and data.
	2. Heap.
	3. Shared libs.
	4. Stack.
	5. Kernel Virtual memory.
- A file is a sequence of bytes, nothing more nothing less.
- In Unix-like systems, *everything* is a file.
#### 1.8
- Systems view network adapter as another I/O device.

![[Pasted image 20260918202253.png]]

#### 1.9
- **Gene Amdahl**'s law dictates that the effect of improving one part of a system on the whole system is decided by the significance of the improved part and the magnitude of its improvement.
- For example, the law of improving (decreasing) time in a system is:
![[Pasted image 20260918203541.png]]

- *Concurrency* is designing a program to tackle many tasks at once, *Parallelism* is them actually being executed together, aka an increase in overall performance.
- Parallelism can be achieved through concurrency in 3 levels:
	1. Thread-level Concurrency.
	   ![[Pasted image 20260918224932.png]]
	   ![[Pasted image 20260918224953.png]]
	   
	2. Instruction-level Parallelism.
	3. Single Instruction, Multiple Data Parallelism (SIMD).

![[Pasted image 20260918225649.png]]



