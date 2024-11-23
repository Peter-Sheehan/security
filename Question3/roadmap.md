
# Exploiting Buffer Overflow in `Question3.c`

## Objective
The goal is to exploit a buffer overflow vulnerability in the program `Question3.c` to execute the function `lonelyfunction`, which outputs:
```
Nobody ever calls me, I'm so bored.
```
It is acceptable if the program crashes afterward.

---

## Steps

### 1. Modify the `studentid`
- Open `Question3.c`.
- Replace the placeholder `studentid` with your actual numeric student ID.

```c
studentid = 12345678; // Replace with your actual student ID
```

**Example**:
```c
studentid = 20231234;
```

### 2. Compile and Test
Compile the program and run it to observe the `globalcanary` value.

**Commands**:
```bash
gcc -o question3 Question3.c
./question3
```

**Note**: If `globalcanary` contains null bytes (`0x00`), increment your `studentid` and recompile until a suitable `globalcanary` is generated.

---

### 3. Understand the Buffer Overflow
**Key Concepts**:
- **Buffer Overflow**: Writing more data into `buffer` than its size (64 bytes) to overwrite the return address.
- **Function Redirection**: Overwriting the return address to redirect the program flow to `lonelyfunction`.
- **Stack Canary Protection**: Ensure the stack canary (`xorcanary`) check passes by crafting input carefully.

---

### 4. Plan the Exploit
The stack structure is as follows:
- `buffer[64]`: 64 bytes
- `ret`: Return address

To exploit:
1. Overflow `buffer` with 64 padding bytes.
2. Overwrite `ret` with the address of `lonelyfunction`.
3. Ensure `xorcanary == (globalcanary ^ ret)`.

---

### 5. Craft the Input
**Input Structure**:
1. **Padding**: 64 bytes to fill `buffer`.
2. **Return Address**: Address of `lonelyfunction`.

**Example Input**:
```
AAAA...AAAA (64 bytes) + [Address of lonelyfunction]
```

Use a debugger (e.g., `gdb`) to find the address of `lonelyfunction`.

---

### 6. Test the Exploit
Run the program and provide the crafted input.

**Expected Output**:
```
Nobody ever calls me, I'm so bored.
```

The program may crash afterward, which is acceptable.

---

## Summary
1. Replace `studentid` in `Question3.c` with your real student ID.
2. Compile and run the program to confirm a suitable `globalcanary`.
3. Exploit the buffer overflow in `getpath()` by overflowing the `buffer` array and setting the return address to `lonelyfunction`.
4. Input the crafted payload, and the program will print:

```
Nobody ever calls me, I'm so bored.
```
