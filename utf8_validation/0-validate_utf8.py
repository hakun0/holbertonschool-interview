def valid_utf8(data):
    n_bytes = 0

    for num in data:
        # Keep only the last 8 bits of the integer (simulate byte)
        byte = num & 0xFF

        if n_bytes == 0:
            # Count the number of leading 1's
            mask = 0b10000000
            while mask & byte:
                n_bytes += 1
                mask >>= 1

            # 1 byte character
            if n_bytes == 0:
                continue

            # Invalid scenarios: more than 4 bytes or just 1 leading 1
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            # Continuation byte must start with 10xxxxxx
            if not (byte & 0b10000000 and not (byte & 0b01000000)):
                return False

        n_bytes = n_bytes - 1 if n_bytes else 0

    return n_bytes == 0